SUBDIRS = . h264 mpeg4

lib_LTLIBRARIES = libExynosOMX_Venc.la

libExynosOMX_Venc_la_SOURCES = Exynos_OMX_Venc.c \
                               Exynos_OMX_Venc.h \
                               Exynos_OMX_VencControl.c \
                               Exynos_OMX_VencControl.h

libExynosOMX_Venc_la_LIBADD = $(top_builddir)/openmax/osal/libExynosOMX_OSAL.la \
                              $(top_builddir)/openmax/component/common/libExynosOMX_Basecomponent.la \
                              $(top_builddir)/exynos/libcsc/libcsc.la

libExynosOMX_Venc_la_CFLAGS = -I$(top_srcdir)/openmax/include/khronos \
                              -I$(top_srcdir)/openmax/include/exynos \
                              -I$(top_srcdir)/openmax/osal \
                              -I$(top_srcdir)/openmax/core \
                              -I$(top_srcdir)/openmax/component/common \
                              -I$(top_srcdir)/openmax/component/video/enc \
                              -I$(top_srcdir)/exynos4/libcodec/video/v4l2/include \
                              -I$(top_srcdir)/exynos/include \
                              -I$(top_srcdir)/exynos/libcsc 

if BOARD_USE_METADATABUFFERTYPE
libExynosOMX_Venc_la_CFLAGS += -DUSE_METADATABUFFERTYPE
endif

if BOARD_USE_STOREMETADATA
libExynosOMX_Venc_la_CFLAGS += -DUSE_STOREMETADATA
endif
