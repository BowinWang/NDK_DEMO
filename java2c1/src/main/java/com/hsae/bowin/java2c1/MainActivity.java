package com.hsae.bowin.java2c1;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "JNItest";

    private NativeC nativeC = new NativeC();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        add(1,2);
        getString();
        GetArray();
    }

    public void add(int a,int b ){
        Log.d(TAG, "add: a ====>" +a + "b ===>"+ b);
        int result = nativeC.add(a,b);
        Log.d(TAG, "add: ====>" + result);
    }

    public void getString() {
        String mString = "I am form JAVA";
        String result = nativeC.getString(mString);
        Log.d(TAG, "getString: " + result);
    }

    public void GetArray() {

        int array[] = {1,2,3,4,5};
        int array1[];
        array1 = nativeC.GetArray(array);
        for (int i = 0; i <array1.length ; i++) {
            Log.d(TAG, "GetArray: " + array1[i]);
        }

    }
}
