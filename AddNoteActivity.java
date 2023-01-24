package com.example.tutornotesapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import com.google.android.material.button.MaterialButton;

public class AddNoteActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_note);

        EditText tutorInput = findViewById(R.id.tutorinput);
        EditText studentInput = findViewById(R.id.studentinput);
        EditText descriptionInput = findViewById(R.id.descriptioninput);
        MaterialButton saveButton = findViewById(R.id.buttoninput);

        Realm.init(getApplicationContext());
        Realm realm = Realm.getDefaultInstance();

        saveButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                // Write code to save the notes
                String tutor = tutorInput.getText().toString();
                String student = studentInput.getText().toString();
                String description = descriptionInput.getText().toString();

                // Save note to the database
                realm.beginTransaction();
                Note note = realm.createObject(Note.class);
                note.setTitle(tutor);
                note.setStudent(student);
                note.setDescription(description);
                realm.commitTransaction();
                Toast.makeText(getApplicationContext(), "Session saved", Toast.LENGTH_SHORT).show();
                finish();
            }
        });

    }
}