/*
 *
 * Copyright 2015 Samsung Electronics Co. LTD
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <sys/stat.h>

/* 2D Configurable tiled memory access (TM)
 * Return the linear address from tiled position (x, y) */
unsigned int Tile2D_To_Linear(unsigned int width, unsigned int height,
						unsigned int xpos, unsigned int ypos, int crFlag)
{
  int  tileNumX;
  int  tileX, tileY;
  int  tileAddr;
  int  offset;
  int  addr;

  width = ((width + 15) / 16)*16;
  tileNumX = width / 16;

  /* crFlag - 0: Y plane, 1: CbCr plane */
  if (crFlag == 0)
  {
    tileX = xpos / 16;
    tileY = ypos / 16;
    tileAddr = tileY * tileNumX + tileX;
    offset = (ypos & 15) * 16 + (xpos & 15);
    addr = (tileAddr << 8) | offset;
  }
  else
  {
    tileX = xpos / 16;
    tileY = ypos /  8;
    tileAddr = tileY * tileNumX + tileX;
    offset = (ypos & 7) * 16 + (xpos & 15);
    addr = (tileAddr << 7) | offset;
  }

  return addr;
}

void Tile2D_To_YUV420(unsigned char *Y_plane, unsigned char *Cb_plane, unsigned char *Cr_plane,
			unsigned int y_addr, unsigned int c_addr, unsigned int width, unsigned int height)
{
  int x, y, j, k, l;
  int out_of_width, actual_width;
  unsigned int base_addr, data;

  printf("height = %d  width = %d y_addr= %x  c_addr = %x \n", height, width, y_addr, c_addr);

  // y: 0, 16, 32, ...
  for (y = 0; y < height; y += 16)
  {
    // x: 0, 16, 32, ...
    for (x = 0; x < width; x += 16)
    {
      out_of_width = (x + 16) > width ? 1 : 0;
      base_addr = y_addr + Tile2D_To_Linear(width, height, x, y, 0);

      for (k = 0; (k < 16) && ((y + k) < height); k++)
      {
        actual_width = out_of_width ? ((width%4)?((width%16) / 4 + 1) : ((width%16) / 4)) : 4;
        for (l = 0; l < actual_width; l++)
        {
          data = *((unsigned int*)(base_addr + 16*k + l*4));
          for (j = 0; (j < 4) && (x + l*4 + j) < width; j++)
          {
            Y_plane[(y+k)*width + x + l*4 +j] = (data>>(8*j))&0xff;
          }
        }
      }
    }
  }

  for (y = 0; y < height/2; y += 8)
  {
    for (x = 0; x < width; x += 16)
    {
      out_of_width = (x + 16) > width ? 1 : 0;
      base_addr = c_addr + Tile2D_To_Linear(width, height/2, x, y, 1);
      for (k = 0; (k < 8) && ((y+k) < height/2); k++)
      {
        actual_width = out_of_width ? ((width%4) ? ((width%16) / 4 + 1) : ((width%16) / 4)) : 4;
        for (l = 0; l < actual_width; l++)
        {
          data = *((unsigned int*)(base_addr + 16*k + l*4));
          for (j = 0; (j < 2) && (x/2 + l*2 +j) < width/2; j++)
          {
            Cb_plane[(y+k)*width/2 + x/2 + l*2 +j] = (data>> (8*2*j))&0xff;
            Cr_plane[(y+k)*width/2 + x/2 + l*2 +j] = (data>>(8*2*j+8))&0xff;
          }
        }
      }
    }
  }
}

int main (int argc, char **argv)
{
  int i = 0;
  int j = 0;
  int size = 0;

  char filename[100]={0};
  FILE *fp_in = NULL;
  FILE *fp_out = NULL;

  unsigned int width;
  unsigned int height;
  unsigned int num_frame;

  struct stat input_file_info;

  unsigned char* Y_plane = NULL;
  unsigned char* Cb_plane = NULL;
  unsigned char* Cr_plane = NULL;

  unsigned int* c_addr = NULL;
  unsigned int* y_addr = NULL;

  if(argc != 4)
  {
    printf("Usage : NV12T_converter [file_path] width height ex)NV12T_converter out.yuv 1280 720\n");
    return 0;
  }

  strcpy(filename, argv[1]);
  width = atoi(argv[2]);
  height = atoi(argv[3]);
  printf("file path=%s, width = %d, height = %d \n", filename, width, height);

  /**/
  Y_plane = (unsigned char*)malloc(width * height);
  Cb_plane = (unsigned char*)malloc(width * height);
  Cr_plane = (unsigned char*)malloc(width * height);

  c_addr = (unsigned int*)malloc(width * height);
  y_addr = (unsigned int*)malloc(width * height);

  fp_in = fopen(filename, "r");
  if (fp_in == NULL)
    printf ("Input file cannot open!! \n");

  fp_out = fopen("output_linear.yuv", "ab");
  if (fp_out == NULL)
    printf ("Output file cannot open !! \n");

  printf("file open success: %s \n", filename);

  stat(filename, &input_file_info);
  num_frame = input_file_info.st_size / (width*height*3/2);

  printf("file size = %d, num_frame = %d \n", input_file_info.st_size, num_frame);

  for (i=0; i < num_frame; i++)
  {
    memset(Y_plane, 0xff, width * height);
    memset(Cb_plane, 0xff, width * height);
    memset(Cr_plane, 0xff, width * height);
    memset(c_addr, 0xff, width * height);
    memset(y_addr, 0xff, width * height);

    size = fread(y_addr, 1, width * height, fp_in);
    printf("[fread] y_addr size = %d \n", size);
    size = fread(c_addr, 1, (width * height)/2, fp_in);
    printf("[fread] c_addr size = %d \n", size);
    printf("[tiled_transcode] y_addr: 0x%x  c_addr: 0x%x \n", y_addr, c_addr);

    Tile2D_To_YUV420(Y_plane, Cb_plane, Cr_plane, y_addr, c_addr, width, height);
    printf (" Y_plane %02x %02x %02x %02x %02x \n", Y_plane[0], Y_plane[1], Y_plane[2], Y_plane[3], Y_plane[4]);

    size = fwrite(Y_plane, 1, width * height, fp_out);
    printf("write Y_plane size = %d \n", size);
    size = fwrite(Cb_plane, 1, (width * height / 4), fp_out);
    printf("write Cb_plane size = %d \n", size);
    size = fwrite(Cr_plane, 1, (width * height / 4), fp_out);
    printf("write Cr_plane size = %d \n", size);
    printf("count = %d \n", i);
  }

  free(Y_plane);
  free(Cb_plane);
  free(Cr_plane);
  free(c_addr);
  free(y_addr);

  fclose (fp_in);
  fclose (fp_out);

 return 0;
}
