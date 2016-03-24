lib_LTLIBRARIES = libcsc.la

libcsc_la_SOURCES = csc.c \
                    csc_helper.c

libcsc_la_LIBADD = $(top_builddir)/exynos4/libswconverter/libswconverter.la

libcsc_la_CFLAGS = -I$(top_srcdir)/exynos/include \
                   -I$(top_srcdir)/openmax/include/exynos \
                   -I$(top_srcdir)/openmax/include/khronos \
                   -I$(top_srcdir)/openmax/osal \
                   -I$(top_srcdir)/exynos4/include
