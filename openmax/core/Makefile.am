lib_LTLIBRARIES = libExynosOMX_Core.la

libExynosOMX_Core_la_SOURCES = Exynos_OMX_Component_Register.c \
                               Exynos_OMX_Component_Register.h \
                               Exynos_OMX_Core.c \
                               Exynos_OMX_Core.h

libExynosOMX_Core_la_LIBADD = $(top_builddir)/openmax/osal/libExynosOMX_OSAL.la \
                              $(top_builddir)/openmax/component/common/libExynosOMX_Basecomponent.la \
                              $(top_builddir)/openmax/component/common/libExynosOMX_Resourcemanager.la

libExynosOMX_Core_la_CFLAGS = -I$(top_srcdir)/openmax/include/khronos \
                              -I$(top_srcdir)/openmax/include/exynos \
                              -I$(top_srcdir)/openmax/osal \
                              -I$(top_srcdir)/openmax/component/common

includelibExynosOMX_Coredir = $(includedir)/libomxil-e3250
includelibExynosOMX_Core_HEADERS = $(top_srcdir)/openmax/include/khronos/OMX_Audio.h \
                                   $(top_srcdir)/openmax/include/khronos/OMX_Core.h \
                                   $(top_srcdir)/openmax/include/khronos/OMX_Image.h \
                                   $(top_srcdir)/openmax/include/khronos/OMX_IVCommon.h \
                                   $(top_srcdir)/openmax/include/khronos/OMX_Types.h \
                                   $(top_srcdir)/openmax/include/khronos/OMX_Component.h \
                                   $(top_srcdir)/openmax/include/khronos/OMX_Index.h \
                                   $(top_srcdir)/openmax/include/khronos/OMX_Other.h \
                                   $(top_srcdir)/openmax/include/khronos/OMX_Video.h \
                                   $(top_srcdir)/openmax/include/khronos/OMX_ContentPipe.h \
                                   $(top_srcdir)/openmax/include/exynos/Exynos_OMX_Def.h \
                                   $(top_srcdir)/openmax/include/exynos/Exynos_OMX_Macros.h
