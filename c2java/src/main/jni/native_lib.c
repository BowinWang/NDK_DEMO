//
// Created by bowin on 2020/7/18.
//
#include "com_hsae_bowin_c2java_C2java.h"
/*
 * Class:     com_hsae_bowin_c2java_C2java
 * Method:    callbackAdd
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_hsae_bowin_c2java_C2java_callbackAdd
(JNIEnv * env, jobject jobj){
    //得到 字节码
    //得到方法
    //实例化
    // 调用发放
    char* classname = "com/hsae/bowin/c2java/C2java";
    jclass jclazz = (*env)->FindClass(env,classname);
    jmethodID method =(*env)-> GetMethodID(env, jclazz,"add","(II)I");
//    jobject jobject1 = (*env)->AllocObject(env,jclazz);
//    jstring  jst = (*env)->NewStringUTF(env,"I am bowin!");
    jint value = (*env)->CallIntMethod(env, jobj, method,2,3);
}


/*
 * Class:     com_hsae_bowin_c2java_C2java
 * Method:    callbackFormJava
 * Signature: ()V
 */

JNIEXPORT void JNICALL Java_com_hsae_bowin_c2java_C2java_callbackFormJava
(JNIEnv * env, jobject jobj){
    char* classname = "com/hsae/bowin/c2java/C2java";
    jclass jclazz = (*env)->FindClass(env,classname);
    jmethodID method =(*env)-> GetMethodID(env, jclazz,"helloFromJava", "()V");
    (*env)->CallVoidMethod(env, jobj, method);
}

/*
 * Class:     com_hsae_bowin_c2java_C2java
 * Method:    callbackPrintString
 * Signature: ()V
 */

JNIEXPORT void JNICALL Java_com_hsae_bowin_c2java_C2java_callbackPrintString
(JNIEnv * env, jobject jobj){
    char* classname = "com/hsae/bowin/c2java/C2java";
    jclass jclazz = (*env)->FindClass(env,classname);
    jmethodID method =(*env)-> GetMethodID(env, jclazz,"printString","(Ljava/lang/String;)V");
    jobject jobject1 = (*env)->AllocObject(env,jclazz);
    jstring  jst = (*env)->NewStringUTF(env,"I am bowin!");
    (*env)->CallVoidMethod(env, jobj, method,jst);
}

/*
 * Class:     com_hsae_bowin_c2java_C2java
 * Method:    callbackSayHello
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_hsae_bowin_c2java_C2java_callbackSayHello
(JNIEnv * env, jobject jboj){
    char* classname = "com/hsae/bowin/c2java/C2java";
    jclass jclazz = (*env)->FindClass(env,classname);
    jmethodID method =(*env)-> GetStaticMethodID(env, jclazz,"sayHello","(Ljava/lang/String;)V");
//    jobject jobject1 = (*env)->AllocObject(env,jclazz);
    jstring  jst = (*env)->NewStringUTF(env,"I am bowin222!");
    (*env)->CallStaticVoidMethod(env, jclazz,method,jst);
}