lib_LTLIBRARIES = libsrpapi.la

libsrpapi_la_SOURCES = dec/srp_api.c

libsrpapi_la_CFLAGS = -I$(CURDIR)/include \
                      -I$(top_srcdir)/openmax/osal

includelibsrpapidir = $(includedir)/srpapi
includelibsrpapi_HEADERS = $(CURDIR)/include/srp_api.h \
                           $(CURDIR)/include/srp_ioctl.h \
                           $(CURDIR)/include/srp_error.h
