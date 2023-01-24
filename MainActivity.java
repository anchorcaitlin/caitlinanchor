package com.example.tutornotesapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;

import com.google.android.material.button.MaterialButton;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        MaterialButton addNoteButton = findViewById(R.id.addnewnotebutton);

        addNoteButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(new Intent(MainActivity.this.AddNoteActivity.class)));
            }
        });
    }
}