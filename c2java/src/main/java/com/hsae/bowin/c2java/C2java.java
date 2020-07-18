package com.hsae.bowin.c2java;


import android.util.Log;

public class C2java {

    static {
        System.loadLibrary("native_lib");
    }
    private static final String TAG = "C2java";
    public native void callbackAdd();
    public native void callbackFormJava();
    public  native void callbackPrintString();
    public native void callbackSayHello();

    public int add(int x ,int y)
    {
       Log.d(TAG, "add: "+ "x ==" + x + "y == "+ y);
        return x+y;
    }

    public void helloFromJava(){
        Log.d(TAG, "helloFromJava: ");
    }

    public void printString(String s){
        Log.d(TAG, "printString: " + s);
    }

    public static void  sayHello(String s){
        Log.d(TAG, "sayHello: staic method" +s);
    }
}
