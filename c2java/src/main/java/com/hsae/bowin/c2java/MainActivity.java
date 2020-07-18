package com.hsae.bowin.c2java;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

public class MainActivity extends AppCompatActivity {

    private C2java mC2java = new C2java();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mC2java.callbackFormJava();
        mC2java.callbackPrintString();
        mC2java.callbackAdd();
        mC2java.callbackSayHello();
    }
}
