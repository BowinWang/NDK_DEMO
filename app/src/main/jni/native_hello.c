//
// Created by bowin on 2020/7/17.
//
#include "com_hsae_bowin_ndkdemo_JNIUtils.h"

jstring Java_com_hsae_bowin_ndkdemo_JNIUtils_getString
        (JNIEnv* env, jclass jclazz){

    char* text = "I am form c";
    return (*env)->NewStringUTF(env,text);

}