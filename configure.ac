#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.65])
AC_INIT([libomxil-e3250], [0.1])
AM_INIT_AUTOMAKE([tar-ustar])
#AC_CONFIG_HEADERS([config.h])

# Set to 'm4' the directory where the extra autoconf macros are stored
AC_CONFIG_MACRO_DIR([m4])

PKG_CHECK_MODULES(MM_COMMON, mm-common)
AC_SUBST(MM_COMMON_CFLAGS)
AC_SUBST(MM_COMMON_LIBS)

AC_CONFIG_FILES([
    omxil-e3250-v4l2.pc
    srp.pc
    Makefile
    exynos4/Makefile
    exynos4/libcodec/Makefile
    exynos4/libcodec/audio/Makefile
    exynos4/libcodec/audio/alp/Makefile
    exynos4/libcodec/video/Makefile
    exynos4/libcodec/video/v4l2/Makefile
    exynos4/libion_exynos/Makefile
    exynos4/libswconverter/Makefile
    exynos/Makefile
    exynos/libv4l2/Makefile
    exynos/libcsc/Makefile
    openmax/Makefile
    openmax/osal/Makefile
    openmax/core/Makefile
    openmax/component/Makefile
    openmax/component/common/Makefile
    openmax/component/audio/Makefile
    openmax/component/audio/dec/Makefile
    openmax/component/audio/dec/mp3/Makefile
    openmax/component/video/Makefile
    openmax/component/video/dec/Makefile
    openmax/component/video/dec/h264/Makefile
    openmax/component/video/dec/mpeg2/Makefile
    openmax/component/video/dec/mpeg4/Makefile
    openmax/component/video/dec/vc1/Makefile
    openmax/component/video/enc/Makefile
    openmax/component/video/enc/h264/Makefile
    openmax/component/video/enc/mpeg4/Makefile
])

# Checks for programs.
AC_PROG_CC
AM_PROG_AS

# Check for libtool
AM_PROG_LIBTOOL

# Checks for libraries.

# Check for pthread
AC_SEARCH_LIBS([pthread_create], [pthread], [], [AC_MSG_ERROR([pthread is required])])

# Check for libdl
AC_SEARCH_LIBS([dlopen], [dl], [], [AC_MSG_ERROR([libdl is required])])

# Checks for header files.
AC_CHECK_HEADERS([fcntl.h stdlib.h string.h sys/ioctl.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_MMAP
AC_FUNC_REALLOC
AC_CHECK_FUNCS([gettimeofday memmove memset munmap])

AC_DEFINE([SLP_PLATFORM])
AC_DEFINE([USE_IMMEDIATE_DISPLAY])

dnl use dlog ------------------------------------------------------------------
AC_ARG_ENABLE(dlog, AC_HELP_STRING([--enable-dlog], [using dlog]),
        [
          case "${enableval}" in
           yes) USE_DLOG=yes ;;
           no)  USE_DLOG=no ;;
           *)   AC_MSG_ERROR(bad value ${enableval} for --enable-dlog) ;;
          esac
        ],[USE_DLOG=no])

if test "x$USE_DLOG" = "xyes"; then
        PKG_CHECK_MODULES(DLOG, dlog)
        AC_SUBST(DLOG_CFLAGS)
        AC_SUBST(DLOG_LIBS)
fi
AM_CONDITIONAL(USE_DLOG, test "x$USE_DLOG" = "xyes")
dnl end -----------------------------------------------------------------------

AC_ARG_ENABLE([exynos3250], AC_HELP_STRING([--enable-exynos3250], [Enable exynos3250 specific code]),
        [
         case "${enableval}" in
          yes) EXYNOS_3250=yes ;;
          no)  EXYNOS_3250=no ;;
          *)   AC_MSG_ERROR(bad value ${enableval} for --enable-exynos3250) ;;
         esac
        ],
        [EXYNOS_3250=no])
AM_CONDITIONAL([EXYNOS_3250], [test "x$EXYNOS_3250" = "xyes"])

AC_ARG_ENABLE(s3dsupport, AC_HELP_STRING([--enable-s3dsupport], [use s3d support]),
        [
          case "${enableval}" in
           yes) BOARD_USE_S3D_SUPPORT=yes ;;
           no)  BOARD_USE_S3D_SUPPORT=no ;;
           *)   AC_MSG_ERROR(bad value ${enableval} for --enable-s3dsupport) ;;
          esac
        ],
        [BOARD_USE_S3D_SUPPORT=no])
AM_CONDITIONAL([BOARD_USE_S3D_SUPPORT], [test "x$BOARD_USE_S3D_SUPPORT" = "xyes"])

AC_ARG_ENABLE(mfcfps, AC_HELP_STRING([--enable-mfc-fps], [use mfc fps]),
        [
          case "${enableval}" in
           yes) BOARD_USE_MFC_FPS=yes ;;
           no)  BOARD_USE_MFC_FPS=no ;;
           *)   AC_MSG_ERROR(bad value ${enableval} for --enable-mfc-fps) ;;
          esac
        ],
        [BOARD_USE_MFC_FPS=no])
AM_CONDITIONAL([BOARD_USE_MFC_FPS], [test "x$BOARD_USE_MFC_FPS" = "xyes"])

AC_ARG_ENABLE(blockmodeprocess, AC_HELP_STRING([--enable-nonblock-mode-process], [non-block mode process]),
        [
          case "${enableval}" in
           yes) BOARD_NONBLOCK_MODE_PROCESS=yes ;;
           no)  BOARD_NONBLOCK_MODE_PROCESS=no ;;
           *)   AC_MSG_ERROR(bad value ${enableval} for --enable-nonblock-mode-process) ;;
          esac
        ],
        [BOARD_NONBLOCK_MODE_PROCESS=yes])
AM_CONDITIONAL([BOARD_NONBLOCK_MODE_PROCESS], [test "x$BOARD_NONBLOCK_MODE_PROCESS" = "xyes"])

AC_ARG_ENABLE(anb, AC_HELP_STRING([--enable-anb], [use anb]),
        [
          case "${enableval}" in
           yes) BOARD_USE_ANB=yes ;;
           no)  BOARD_USE_ANB=no ;;
           *)   AC_MSG_ERROR(bad value ${enableval} for --enable-anb) ;;
          esac
        ],
        [BOARD_USE_ANB=no])
AM_CONDITIONAL([BOARD_USE_ANB], [test "x$BOARD_USE_ANB" = "xyes"])

AC_ARG_ENABLE(metadatabuffertype, AC_HELP_STRING([--enable-metadata-buffertype], [use metadata buffertype]),
        [
          case "${enableval}" in
           yes) BOARD_USE_METADATABUFFERTYPE=yes ;;
           no)  BOARD_USE_METADATABUFFERTYPE=no ;;
           *)   AC_MSG_ERROR(bad value ${enableval} for --enable-metadata-buffertype) ;;
          esac
        ],
        [BOARD_USE_METADATABUFFERTYPE=no])
AM_CONDITIONAL([BOARD_USE_METADATABUFFERTYPE], [test "x$BOARD_USE_METADATABUFFERTYPE" = "xyes"])

AC_ARG_ENABLE(storemetadata, AC_HELP_STRING([--enable-store-metadata], [use store metadata]),
        [
          case "${enableval}" in
           yes) BOARD_USE_STOREMETADATA=yes ;;
           no)  BOARD_USE_STOREMETADATA=no ;;
           *)   AC_MSG_ERROR(bad value ${enableval} for --enable-store-metadata) ;;
          esac
        ],
        [BOARD_USE_STOREMETADATA=no])
AM_CONDITIONAL([BOARD_USE_STOREMETADATA], [test "x$BOARD_USE_STOREMETADATA" = "xyes"])

AC_ARG_ENABLE(dmabuf, AC_HELP_STRING([--enable-use-dmabuf], [use dma buf]),
        [
          case "${enableval}" in
           yes) BOARD_USE_DMA_BUF=yes ;;
           no)  BOARD_USE_DMA_BUF=no ;;
           *)   AC_MSG_ERROR(bad value ${enableval} for --enable-use-dambuf) ;;
          esac
        ],
        [BOARD_USE_DMA_BUF=no])
AM_CONDITIONAL([BOARD_USE_DMA_BUF], [test "x$BOARD_USE_DMA_BUF" = "xyes"])

AC_ARG_ENABLE(drm, AC_HELP_STRING([--enable-use-drm], [use drm]),
        [
          case "${enableval}" in
           yes) BOARD_USE_DRM=yes ;;
           no)  BOARD_USE_DRM=no ;;
           *)   AC_MSG_ERROR(bad value ${enableval} for --enable-use-drm) ;;
          esac
        ],
        [BOARD_USE_DRM=no])
AM_CONDITIONAL([BOARD_USE_DRM], [test "x$BOARD_USE_DRM" = "xyes"])

AC_ARG_ENABLE(neon, AC_HELP_STRING([--enable-neon], [neon]),
        [
          case "${enableval}" in
           yes) BOARD_USE_NEON=yes ;;
           no)  BOARD_USE_NEON=no ;;
           *)   AC_MSG_ERROR(bad value ${enableval} for --enable-neon) ;;
          esac
        ],
        [BOARD_USE_NEON=no])
AM_CONDITIONAL([BOARD_USE_NEON], [test "x$BOARD_USE_NEON" = "xyes"])

AC_OUTPUT
