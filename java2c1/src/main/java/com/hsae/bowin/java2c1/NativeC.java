package com.hsae.bowin.java2c1;

public class NativeC {
    static {
        System.loadLibrary("native_lib");
    }
    public native int add (int a,int b);
    public native String getString(String sentence);
    public native int[] GetArray(int[] input);
}
