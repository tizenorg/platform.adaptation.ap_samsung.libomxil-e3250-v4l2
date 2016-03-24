lib_LTLIBRARIES = libOMX.Exynos.MP3.Decoder.la
libdir = @libdir@/omx

libOMX_Exynos_MP3_Decoder_la_SOURCES = Exynos_OMX_Mp3dec.c \
                                    Exynos_OMX_Mp3dec.h \
                                    library_register.c \
                                    library_register.h

libOMX_Exynos_MP3_Decoder_la_LIBADD = $(top_builddir)/openmax/osal/libExynosOMX_OSAL.la \
                                   $(top_builddir)/openmax/component/audio/dec/libExynosOMX_Adec.la \
                                   $(top_builddir)/openmax/component/common/libExynosOMX_Basecomponent.la \
                                   $(top_builddir)/exynos4/libcodec/audio/alp/libsrpapi.la

libOMX_Exynos_MP3_Decoder_la_CFLAGS = -I$(top_srcdir)/openmax/include/khronos \
                                   -I$(top_srcdir)/openmax/include/exynos \
                                   -I$(top_srcdir)/openmax/osal \
                                   -I$(top_srcdir)/openmax/core \
                                   -I$(top_srcdir)/openmax/component/common \
                                   -I$(top_srcdir)/exynos4/libcodec/audio/alp/include \
                                   -I$(top_srcdir)/openmax/component/audio/dec


libOMX_Exynos_MP3_Decoder_la_LDFLAGS = -module -avoid-version
