package com.example.myjournalapp;

import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;
import com.google.firebase.firestore.FirebaseFirestore;

public class EditEntryActivity extends AppCompatActivity {
    private FirebaseFirestore db;
    private EditText titleEditText, contentEditText;
    private Button updateButton;
    private String entryId;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_edit_entry);

        db = FirebaseFirestore.getInstance();

        titleEditText = findViewById(R.id.title_edit_text);
        contentEditText = findViewById(R.id.content_edit_text);
        updateButton = findViewById(R.id.update_button);

        entryId = getIntent().getStringExtra("ENTRY_ID");
        if (entryId == null) {
            Toast.makeText(this, "Error: No entry ID provided", Toast.LENGTH_SHORT).show();
            finish();
            return;
        }

        loadEntry();

        updateButton.setOnClickListener(v -> updateEntry());
    }

    private void loadEntry() {
        db.collection("entries").document(entryId).get()
                .addOnSuccessListener(documentSnapshot -> {
                    JournalEntry entry = documentSnapshot.toObject(JournalEntry.class);
                    if (entry != null) {
                        titleEditText.setText(entry.getTitle());
                        contentEditText.setText(entry.getContent());
                    } else {
                        Toast.makeText(this, "Error: Entry not found", Toast.LENGTH_SHORT).show();
                        finish();
                    }
                })
                .addOnFailureListener(e -> {
                    Toast.makeText(this, "Error loading entry: " + e.getMessage(), Toast.LENGTH_SHORT).show();
                    finish();
                });
    }

    private void updateEntry() {
        String title = titleEditText.getText().toString().trim();
        String content = contentEditText.getText().toString().trim();

        if (title.isEmpty() || content.isEmpty()) {
            Toast.makeText(this, "Please fill all fields", Toast.LENGTH_SHORT).show();
            return;
        }

        db.collection("entries").document(entryId)
                .update("title", title, "content", content)
                .addOnSuccessListener(aVoid -> {
                    Toast.makeText(EditEntryActivity.this, "Entry updated successfully", Toast.LENGTH_SHORT).show();
                    finish();
                })
                .addOnFailureListener(e -> Toast.makeText(EditEntryActivity.this, "Error updating entry: " + e.getMessage(), Toast.LENGTH_SHORT).show());
    }
}