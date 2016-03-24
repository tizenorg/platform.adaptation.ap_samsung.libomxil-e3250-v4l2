/*
 *
 * Copyright 2012 Samsung Electronics S.LSI Co. LTD
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * @file        Exynos_OSAL_Log.c
 * @brief
 * @author      Yunji Kim (yunji.kim@samsung.com)
 * @version     2.0.0
 * @history
 *   2012.02.20 : Create
 */
#ifndef SLP_PLATFORM /* build env */
#include <utils/Log.h>
#else
#ifdef USE_DLOG
#include <dlog.h>
#define DLOG_TAG "OMX_LOG"
#endif
#include <stdlib.h>
#include <stdarg.h>
#endif

#include "Exynos_OSAL_Log.h"

#ifdef SLP_PLATFORM /* build env */
static int component_debug_level = -1;
#endif

void _Exynos_OSAL_Log(EXYNOS_LOG_LEVEL logLevel, const char *tag, const char *msg, ...)
{
#ifndef SLP_PLATFORM
    va_list argptr;

    va_start(argptr, msg);

    switch (logLevel) {
    case EXYNOS_LOG_TRACE:
        __android_log_vprint(ANDROID_LOG_DEBUG, tag, msg, argptr);
        break;
    case EXYNOS_LOG_INFO:
        __android_log_vprint(ANDROID_LOG_INFO, tag, msg, argptr);
        break;
    case EXYNOS_LOG_WARNING:
        __android_log_vprint(ANDROID_LOG_WARN, tag, msg, argptr);
        break;
    case EXYNOS_LOG_ERROR:
        __android_log_vprint(ANDROID_LOG_ERROR, tag, msg, argptr);
        break;
    default:
        __android_log_vprint(ANDROID_LOG_VERBOSE, tag, msg, argptr);
    }

    va_end(argptr);
#else
#ifdef USE_DLOG
    va_list argptr;

    if (component_debug_level < 0) {
        component_debug_level = getenv("OMX_DEBUG") ? atoi(getenv("OMX_DEBUG")) : OMX_DEBUG_LEVEL;
    } else {
        if ((int)logLevel < component_debug_level) return;
    }

    va_start(argptr, msg);

    switch (logLevel) {
    case EXYNOS_LOG_VERVOSE:
    case EXYNOS_LOG_TRACE:
        SLOG_VA (LOG_DEBUG, DLOG_TAG, msg, argptr);
        break;
    case EXYNOS_LOG_INFO:
        SLOG_VA (LOG_INFO, DLOG_TAG, msg, argptr);
        break;
    case EXYNOS_LOG_WARNING:
        SLOG_VA (LOG_WARN, DLOG_TAG, msg, argptr);
        break;
    case EXYNOS_LOG_ERROR:
        SLOG_VA (LOG_ERROR, DLOG_TAG, msg, argptr);
        break;
    default:
        SLOG_VA (LOG_DEBUG, DLOG_TAG, msg, argptr);
        break;
    }

    va_end(argptr);
#else
    va_list argptr;

    if (component_debug_level < 0) {
        component_debug_level = getenv("OMX_DEBUG") ? atoi(getenv("OMX_DEBUG")) : OMX_DEBUG_LEVEL;
    } else {
        if ((int)logLevel < component_debug_level) return;
    }

    va_start(argptr, msg);
    vprintf(msg, argptr);
    va_end(argptr);
    printf("\n");
#endif
#endif
}
