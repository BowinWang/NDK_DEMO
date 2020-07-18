package com.hsae.bowin.ndkdemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

       String text = new JNIUtils().getString();

        TextView textView = findViewById(R.id.text);

        Log.d(TAG, "onCreate: text ======>" + text );

       textView.setText(text);
    }
}
