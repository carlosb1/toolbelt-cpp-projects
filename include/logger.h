#ifndef MYLOGGER
#define MYLOGGER

#if defined( __ARM_EABI__)

#include <android/log.h>
#define LOGV(TAG,...) __android_log_print(ANDROID_LOG_VERBOSE, TAG,__VA_ARGS__)
#define LOGD(TAG,...) __android_log_print(ANDROID_LOG_DEBUG  , TAG,__VA_ARGS__)
#define LOGI(TAG,...) __android_log_print(ANDROID_LOG_INFO   , TAG,__VA_ARGS__)
#define LOGW(TAG,...) __android_log_print(ANDROID_LOG_WARN   , TAG,__VA_ARGS__)
#define LOGE(TAG,...) __android_log_print(ANDROID_LOG_ERROR  , TAG,__VA_ARGS__)

#define LOGVS(TAG,MSG) __android_log_print(ANDROID_LOG_VERBOSE, TAG,"%s",MSG)
#define LOGDS(TAG,MSG) __android_log_print(ANDROID_LOG_DEBUG  , TAG,"%s",MSG)
#define LOGIS(TAG,MSG) __android_log_print(ANDROID_LOG_INFO   , TAG,"%s",MSG)
#define LOGWS(TAG,MSG) __android_log_print(ANDROID_LOG_WARN   , TAG,"%s",MSG)
#define LOGES(TAG,MSG) __android_log_print(ANDROID_LOG_ERROR  , TAG,"%s",MSG)

#else 

#ifndef QUIETLY 

#include <stdio.h>

#define GENERIC_LOG(FORMAT,TYPE_LOG,TAG,...) printf("%s: %s: " FORMAT "\n", TYPE_LOG, TAG, __VA_ARGS__)
#define DESKTOP_LOG_VERBOSE "Verbose"
#define DESKTOP_LOG_DEBUG "Debug"
#define DESKTOP_LOG_INFO "Info"
#define DESKTOP_LOG_WARN "Warn"
#define DESKTOP_LOG_ERROR "Error"

#define LOGV(TAG,FORMAT,...) GENERIC_LOG(FORMAT,DESKTOP_LOG_VERBOSE, TAG,__VA_ARGS__)
#define LOGD(TAG,FORMAT,...) GENERIC_LOG(FORMAT,DESKTOP_LOG_DEBUG  , TAG,__VA_ARGS__)
#define LOGI(TAG,FORMAT,...) GENERIC_LOG(FORMAT,DESKTOP_LOG_INFO   , TAG,__VA_ARGS__)
#define LOGW(TAG,FORMAT,...) GENERIC_LOG(FORMAT,DESKTOP_LOG_WARN   , TAG,__VA_ARGS__)
#define LOGE(TAG,FORMAT,...) GENERIC_LOG(FORMAT,DESKTOP_LOG_ERROR  , TAG,__VA_ARGS__)

#define GENERIC_LOG_NO_PARAMS(TYPE_LOG,TAG,MSG) printf("%s: %s: %s\n", TYPE_LOG,TAG,MSG)

#define LOGVS(TAG,MSG) GENERIC_LOG_NO_PARAMS(DESKTOP_LOG_VERBOSE, TAG,MSG)
#define LOGDS(TAG,MSG) GENERIC_LOG_NO_PARAMS(DESKTOP_LOG_DEBUG  , TAG,MSG)
#define LOGIS(TAG,MSG) GENERIC_LOG_NO_PARAMS(DESKTOP_LOG_INFO   , TAG,MSG)
#define LOGWS(TAG,MSG) GENERIC_LOG_NO_PARAMS(DESKTOP_LOG_WARN   , TAG,MSG)
#define LOGES(TAG,MSG) GENERIC_LOG_NO_PARAMS(DESKTOP_LOG_ERROR  , TAG,MSG)

#else

#define LOGV(TAG,FORMAT,...) do {} while(0)
#define LOGD(TAG,FORMAT,...) do {} while(0)
#define LOGI(TAG,FORMAT,...) do {} while(0)
#define LOGW(TAG,FORMAT,...) do {} while(0)
#define LOGE(TAG,FORMAT,...) do {} while(0)

#define LOGVS(TAG,MSG) do {} while(0)
#define LOGDS(TAG,MSG) do {} while(0)
#define LOGIS(TAG,MSG) do {} while(0)
#define LOGWS(TAG,MSG) do {} while(0)
#define LOGES(TAG,MSG) do {} while(0)
#endif

#endif

#endif
