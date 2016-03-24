lib_LTLIBRARIES = libOMX.Exynos.M2V.Decoder.la
libdir = @libdir@/omx

libOMX_Exynos_M2V_Decoder_la_SOURCES = Exynos_OMX_Mpeg2dec.c \
                                    Exynos_OMX_Mpeg2dec.h \
                                    library_register.c \
                                    library_register.h

libOMX_Exynos_M2V_Decoder_la_LIBADD = $(top_builddir)/openmax/osal/libExynosOMX_OSAL.la \
                                   $(top_builddir)/openmax/component/video/dec/libExynosOMX_Vdec.la \
                                   $(top_builddir)/openmax/component/common/libExynosOMX_Basecomponent.la \
                                   $(top_builddir)/exynos4/libcodec/video/v4l2/libExynosVideoApi.la \
                                   $(top_builddir)/exynos/libv4l2/libexynosv4l2.la


libOMX_Exynos_M2V_Decoder_la_CFLAGS = -I$(top_srcdir)/openmax/include/khronos \
                                   -I$(top_srcdir)/openmax/include/exynos \
                                   -I$(top_srcdir)/openmax/osal \
                                   -I$(top_srcdir)/openmax/core \
                                   -I$(top_srcdir)/openmax/component/common \
                                   -I$(top_srcdir)/openmax/component/video/dec \
                                   -I$(top_srcdir)/exynos4/include \
                                   -I$(top_srcdir)/exynos4/libcsc\
                                   -I$(top_srcdir)/exynos4/libcodec/video/v4l2/include \
                                   -I$(top_srcdir)/exynos/include

libOMX_Exynos_M2V_Decoder_la_CFLAGS += $(MM_COMMON_CFLAGS)
libOMX_Exynos_M2V_Decoder_la_LIBADD += $(MM_COMMON_LIBS)

if BOARD_USE_ANB
libOMX_Exynos_M2V_Decoder_la_CFLAGS += -DUSE_ANB
endif

if BOARD_NONBLOCK_MODE_PROCESS
libOMX_Exynos_M2V_Decoder_la_CFLAGS += -DNONBLOCK_MODE_PROCESS
endif

if BOARD_USE_DMA_BUF
libOMX_Exynos_M2V_Decoder_la_CFLAGS += -DUSE_DMA_BUF
endif

libOMX_Exynos_M2V_Decoder_la_CFLAGS += -DTBM_BUF_FD

libOMX_Exynos_M2V_Decoder_la_LDFLAGS = -module -avoid-version
