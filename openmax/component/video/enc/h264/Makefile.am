lib_LTLIBRARIES = libOMX.Exynos.AVC.Encoder.la
libdir = @prefix@/lib/omx

libOMX_Exynos_AVC_Encoder_la_SOURCES = Exynos_OMX_H264enc.c \
                                    Exynos_OMX_H264enc.h \
                                    library_register.c \
                                    library_register.h

libOMX_Exynos_AVC_Encoder_la_LIBADD = $(top_builddir)/openmax/osal/libExynosOMX_OSAL.la \
                                   $(top_builddir)/openmax/component/video/enc/libExynosOMX_Venc.la \
                                   $(top_builddir)/openmax/component/common/libExynosOMX_Basecomponent.la \
                                   $(top_builddir)/exynos4/libcodec/video/v4l2/libExynosVideoApi.la \
                                   $(top_builddir)/exynos/libv4l2/libexynosv4l2.la


libOMX_Exynos_AVC_Encoder_la_CFLAGS = -I$(top_srcdir)/openmax/include/khronos \
                                   -I$(top_srcdir)/openmax/include/exynos \
                                   -I$(top_srcdir)/openmax/osal \
                                   -I$(top_srcdir)/openmax/core \
                                   -I$(top_srcdir)/openmax/component/common \
                                   -I$(top_srcdir)/openmax/component/video/enc \
                                   -I$(top_srcdir)/exynos4/include \
                                   -I$(top_srcdir)/exynos4/libcsc \
                                   -I$(top_srcdir)/exynos4/libcodec/video/v4l2/include \
                                   -I$(top_srcdir)/exynos/include

if BOARD_NONBLOCK_MODE_PROCESS
libOMX_Exynos_AVC_Encoder_la_CFLAGS += -DNONBLOCK_MODE_PROCESS
endif

if BOARD_USE_METADATABUFFERTYPE
libOMX_Exynos_AVC_Encoder_la_CFLAGS += -DUSE_METADATABUFFERTYPE
endif

libOMX_Exynos_AVC_Encoder_la_LDFLAGS = -module -avoid-version
