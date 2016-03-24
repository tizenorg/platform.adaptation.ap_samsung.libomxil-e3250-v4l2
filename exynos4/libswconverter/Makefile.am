lib_LTLIBRARIES = libswconverter.la

libswconverter_la_SOURCES = swconvertor.c

libswconverter_la_LIBADD =
libswconverter_la_CFLAGS = -I$(top_srcdir)/exynos4/include \
                           -I$(top_srcdir)/exynos/include

if BOARD_USE_NEON
libswconverter_la_SOURCES += csc_ARGB8888_to_YUV420SP_NEON.s \
                            csc_interleave_memcpy_neon.s \
                            csc_linear_to_tiled_crop_neon.s \
                            csc_linear_to_tiled_interleave_crop_neon.s \
                            csc_tiled_to_linear_crop_neon.s \
                            csc_tiled_to_linear_deinterleave_crop_neon.s

endif
