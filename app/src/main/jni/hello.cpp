#include "com_hsae_bowin_ndkdemo_JNIUtils.h"
#include <string.h>


#include <android/log.h>
#define TAG "projectname" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型

extern "C" JNIEXPORT jstring JNICALL
Java_com_hsae_bowin_ndkdemo_JNIUtils_getString
  (JNIEnv *env, jclass jclazz){
             LOGD("I am jni");
        return env->NewStringUTF("I am form JNI!!");
  }

//#include <jni.h>
//#include <string>
//
//#include <android/log.h>
//#define TAG "projectname" // 这个是自定义的LOG的标识
//#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
//#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
//#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
//#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
//#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型
//
//
//extern "C" JNIEXPORT jstring JNICALL
//Java_com_hsae_bowin_ndkdemo_JNIUtils_getString(
//        JNIEnv *env,
//        jclass /* this */) {
//    std::string hello = "Hello from C++";
//    LOGD("I am c++ log");
//    return env->NewStringUTF(hello.c_str());
//}
