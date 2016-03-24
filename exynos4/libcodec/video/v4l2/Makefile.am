lib_LTLIBRARIES = libExynosVideoApi.la

libExynosVideoApi_la_SOURCES = dec/ExynosVideoDecoder.c \
                               enc/ExynosVideoEncoder.c

libExynosVideoApi_la_LIBADD = \
                              $(MMTA_LIBS)
libExynosVideoApi_la_CFLAGS = -I$(CURDIR)/include \
                              -I$(top_srcdir)/exynos/include \
                              -I$(top_srcdir)/openmax/osal \
                               $(MMTA_CFLAGS)

if BOARD_USE_DMA_BUF
libExynosVideoApi_la_CFLAGS += -DUSE_DMA_BUF
endif

if EXYNOS_3250
libExynosVideoApi_la_CFLAGS += -DEXYNOS_3250
endif
