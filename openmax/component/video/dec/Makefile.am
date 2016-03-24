SUBDIRS = . h264 mpeg4 mpeg2 vc1

lib_LTLIBRARIES = libExynosOMX_Vdec.la

libExynosOMX_Vdec_la_SOURCES = Exynos_OMX_Vdec.c \
                               Exynos_OMX_Vdec.h \
                               Exynos_OMX_VdecControl.c \
                               Exynos_OMX_VdecControl.h

libExynosOMX_Vdec_la_LIBADD = \
                              $(top_builddir)/openmax/osal/libExynosOMX_OSAL.la \
                              $(top_builddir)/openmax/component/common/libExynosOMX_Basecomponent.la \
                              $(top_builddir)/exynos/libcsc/libcsc.la

libExynosOMX_Vdec_la_CFLAGS = \
                              -I$(top_srcdir)/openmax/include/khronos \
                              -I$(top_srcdir)/openmax/include/exynos \
                              -I$(top_srcdir)/openmax/osal \
                              -I$(top_srcdir)/openmax/core \
                              -I$(top_srcdir)/openmax/component/common \
                              -I$(top_srcdir)/openmax/component/video/dec \
                              -I$(top_srcdir)/exynos4/libcodec/video/v4l2/include \
                              -I$(top_srcdir)/exynos/include \
                              -I$(top_srcdir)/exynos/libcsc

libExynosOMX_Vdec_la_CFLAGS += $(MM_COMMON_CFLAGS)
libExynosOMX_Vdec_la_LIBADD += $(MM_COMMON_LIBS)

if BOARD_USE_DMA_BUF
libExynosOMX_Vdec_la_CFLAGS += -DUSE_ANB
endif
