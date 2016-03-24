lib_LTLIBRARIES = libExynosOMX_Resourcemanager.la \
                  libExynosOMX_Basecomponent.la 


libExynosOMX_Resourcemanager_la_SOURCES = Exynos_OMX_Resourcemanager.c \
                                          Exynos_OMX_Resourcemanager.h

libExynosOMX_Resourcemanager_la_LIBADD = $(top_builddir)/openmax/osal/libExynosOMX_OSAL.la
libExynosOMX_Resourcemanager_la_CFLAGS = -I$(top_srcdir)/openmax/include/khronos \
                                         -I$(top_srcdir)/openmax/include/exynos \
                                         -I$(top_srcdir)/openmax/osal


libExynosOMX_Basecomponent_la_SOURCES = Exynos_OMX_Basecomponent.c \
                                        Exynos_OMX_Basecomponent.h \
                                        Exynos_OMX_Baseport.c \
                                        Exynos_OMX_Baseport.h

libExynosOMX_Basecomponent_la_LIBADD = $(top_builddir)/openmax/osal/libExynosOMX_OSAL.la \
                                       $(top_builddir)/openmax/component/common/libExynosOMX_Resourcemanager.la

libExynosOMX_Basecomponent_la_CFLAGS = -I$(top_srcdir)/openmax/include/khronos \
                                       -I$(top_srcdir)/openmax/include/exynos \
                                       -I$(top_srcdir)/openmax/osal
