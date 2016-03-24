lib_LTLIBRARIES = libExynosOMX_OSAL.la

libExynosOMX_OSAL_la_SOURCES = Exynos_OSAL_Event.c \
                               Exynos_OSAL_Event.h \
                               Exynos_OSAL_Queue.c \
                               Exynos_OSAL_Queue.h \
                               Exynos_OSAL_ETC.c \
                               Exynos_OSAL_ETC.h \
                               Exynos_OSAL_Mutex.c \
                               Exynos_OSAL_Mutex.h \
                               Exynos_OSAL_Thread.c \
                               Exynos_OSAL_Thread.h \
                               Exynos_OSAL_Memory.c \
                               Exynos_OSAL_Memory.h \
                               Exynos_OSAL_Semaphore.c \
                               Exynos_OSAL_Semaphore.h \
                               Exynos_OSAL_Library.c \
                               Exynos_OSAL_Library.h \
                               Exynos_OSAL_Log.c \
                               Exynos_OSAL_Log.h \
                               Exynos_OSAL_Platform_Specific.c \
                               Exynos_OSAL_Platform_Specific.h \
                               Exynos_OSAL_SharedMemory.c \
                               Exynos_OSAL_SharedMemory.h

libExynosOMX_OSAL_la_LIBADD = $(top_builddir)/exynos4/libion_exynos/libion_exynos.la

libExynosOMX_OSAL_la_CFLAGS = -I$(top_srcdir)/exynos4/include \
                              -I$(top_srcdir)/openmax/include/khronos \
                              -I$(top_srcdir)/openmax/include/exynos \
                              -I$(top_srcdir)/openmax/osal \
                              -I$(top_srcdir)/openmax/component/common \
                              -I$(top_srcdir)/openmax/component/video/dec \
                              -I$(top_srcdir)/exynos/include \
                              -I$(top_srcdir)/exynos4/libcodec/video/v4l2/include

if USE_DLOG
libExynosOMX_OSAL_la_CFLAGS += $(DLOG_CFLAGS) -DUSE_DLOG
libExynosOMX_OSAL_la_LIBADD += $(DLOG_LIBS)
endif