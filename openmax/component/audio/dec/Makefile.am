SUBDIRS = . mp3

lib_LTLIBRARIES = libExynosOMX_Adec.la

libExynosOMX_Adec_la_SOURCES = Exynos_OMX_Adec.c\
                             Exynos_OMX_Adec.h

libExynosOMX_Adec_la_LIBADD = $(top_builddir)/openmax/osal/libExynosOMX_OSAL.la \
                            $(top_builddir)/openmax/component/common/libExynosOMX_Basecomponent.la \
                            $(top_builddir)/exynos4/libcodec/audio/alp/libsrpapi.la

libExynosOMX_Adec_la_CFLAGS = -I$(top_srcdir)/openmax/include/khronos \
                            -I$(top_srcdir)/openmax/include/exynos \
                            -I$(top_srcdir)/openmax/osal \
                            -I$(top_srcdir)/openmax/core \
                            -I$(top_srcdir)/openmax/component/common \
                            -I$(top_srcdir)/exynos4/libcodec/audio/alp/include \
                            -I$(top_srcdir)/exynos/include

