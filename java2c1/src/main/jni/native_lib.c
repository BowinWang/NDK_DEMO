//
// Created by bowin on 2020/7/17.
//
#include "com_hsae_bowin_java2c1_NativeC.h"

#include <android/log.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>

#define TAG "projectname" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型

/*
 * Class:     com_hsae_bowin_java2c1_NativeC
 * Method:    add
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_hsae_bowin_java2c1_NativeC_add
        (JNIEnv* env , jobject jobject1, jint data, jint data1){
//    LOGD("data ==> %d, data1 ==> %d" ,data,data1);
    int datam = data + data1;
    LOGD("data + data1 = %d  ",datam);

    return datam;
}

/**
 * 将一个jstring转换成一个c语言的char* 类型.
 */
char* _JString2CStr(JNIEnv* env, jstring jstr) {
    char* rtn = NULL;
    jclass clsstring = (*env)->FindClass(env, "java/lang/String");
    jstring strencode = (*env)->NewStringUTF(env,"GB2312");
    jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray)(*env)->CallObjectMethod(env, jstr, mid, strencode); // String .getByte("GB2312");
    jsize alen = (*env)->GetArrayLength(env, barr);
    jbyte* ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
    if(alen > 0) {
        rtn = (char*)malloc(alen+1); //"\0"
        memcpy(rtn, ba, alen);
        rtn[alen]=0;
    }
    (*env)->ReleaseByteArrayElements(env, barr, ba,0);
    return rtn;
}

/*
 * Class:     com_hsae_bowin_java2c1_NativeC
 * Method:    getString
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_hsae_bowin_java2c1_NativeC_getString
        (JNIEnv* env, jobject jobject1, jstring jstring1){


    char* fromC = "I am form JNI";
    char* fromJAVA = _JString2CStr(env,jstring1);
//    char* fromJAVA = (*env)->GetStringUTFChars(env,jstring1,NULL);
//    (*env)->ReleaseStringChars(env,jstring1,fromJAVA);
    strcat(fromJAVA,fromC);
    return (*env)->NewStringUTF(env,fromJAVA);
}

/*
 * Class:     com_hsae_bowin_java2c1_NativeC
 * Method:    GetArray
 * Signature: ([I)[I
 */

JNIEXPORT jintArray JNICALL Java_com_hsae_bowin_java2c1_NativeC_GetArray
        (JNIEnv * env, jobject jobject1, jintArray jintArray1){
//    // 得到数组长度
//    //得到元素
//    //遍历数组
    int size = (*env)->GetArrayLength(env,jintArray1);
    jint* intArray =(*env)->GetIntArrayElements(env,jintArray1,JNI_FALSE); //JNI_FALSE  使用原先的每部空间
    int i;
    for(i = 0; i<size;i++)
    {
        *(intArray+i) += 10;
        LOGD("Array == %d",*(intArray+i));
    }

//1.新建长度len数组
    jintArray jarr = (*env)->NewIntArray(env,size);
    //2.获取数组指针
    jint *arr = (*env)->GetIntArrayElements(env,jarr, NULL);
    //3.赋值

    for(i=0; i < size; i++){
        *(arr+i) = *(intArray+i);
    }
    //4.释放资源
    (*env)->ReleaseIntArrayElements(env,jarr, arr, 0);
    //5.返回数组
    return jarr;
}
