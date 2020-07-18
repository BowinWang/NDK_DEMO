package com.hsae.bowin.ndkdemo;

public class JNIUtils {
    {
        System.loadLibrary("native_hello");
    }
    public native String getString();
}
