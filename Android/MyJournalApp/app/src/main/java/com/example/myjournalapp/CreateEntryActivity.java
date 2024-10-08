package com.example.myjournalapp;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.firestore.FirebaseFirestore;
import com.google.firebase.storage.FirebaseStorage;
import com.google.firebase.storage.StorageReference;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.UUID;

public class CreateEntryActivity extends AppCompatActivity {
    private static final int PICK_IMAGE_REQUEST = 1;

    private FirebaseFirestore db;
    private FirebaseAuth mAuth;
    private FirebaseStorage storage;
    private EditText titleEditText, contentEditText;
    private Button saveButton, addImageButton;
    private List<Uri> selectedImageUris;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_create_entry);

        db = FirebaseFirestore.getInstance();
        mAuth = FirebaseAuth.getInstance();
        storage = FirebaseStorage.getInstance();

        titleEditText = findViewById(R.id.title_edit_text);
        contentEditText = findViewById(R.id.content_edit_text);
        saveButton = findViewById(R.id.save_button);
        addImageButton = findViewById(R.id.add_image_button);

        selectedImageUris = new ArrayList<>();

        saveButton.setOnClickListener(v -> saveEntry());
        addImageButton.setOnClickListener(v -> openImageChooser());


    }

    private void openImageChooser() {
        Intent intent = new Intent();
        intent.setType("image/*");
        intent.putExtra(Intent.EXTRA_ALLOW_MULTIPLE, true);
        intent.setAction(Intent.ACTION_GET_CONTENT);
        startActivityForResult(Intent.createChooser(intent, "Select Picture"), PICK_IMAGE_REQUEST);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == PICK_IMAGE_REQUEST && resultCode == RESULT_OK) {
            if (data.getClipData() != null) {
                int count = data.getClipData().getItemCount();
                for (int i = 0; i < count; i++) {
                    Uri imageUri = data.getClipData().getItemAt(i).getUri();
                    selectedImageUris.add(imageUri);
                }
            } else if (data.getData() != null) {
                Uri imageUri = data.getData();
                selectedImageUris.add(imageUri);
            }
            Toast.makeText(this, selectedImageUris.size() + " images selected", Toast.LENGTH_SHORT).show();
        }
    }

    private void saveEntry() {
        String title = titleEditText.getText().toString().trim();
        String content = contentEditText.getText().toString().trim();
        String userId = mAuth.getCurrentUser().getUid();

        if (title.isEmpty() || content.isEmpty()) {
            Toast.makeText(this, "Title and content cannot be empty", Toast.LENGTH_SHORT).show();
            return;
        }

        db.collection("users").document(userId).get()
                .addOnSuccessListener(documentSnapshot -> {
                    String username = documentSnapshot.getString("username");
                    if (username == null || username.isEmpty()) {
                        username = "Anonymous"; // fallback if username is not set
                    }

                    JournalEntry entry = new JournalEntry();
                    entry.setTitle(title);
                    entry.setContent(content);
                    entry.setDate(new Date());
                    entry.setUserId(userId);
                    entry.setUsername(username);

                    uploadImagesAndSaveEntry(entry);
                })
                .addOnFailureListener(e -> {
                    Log.e("CreateEntryActivity", "Error fetching username", e);
                    Toast.makeText(CreateEntryActivity.this, "Error fetching user data", Toast.LENGTH_SHORT).show();
                });
    }

    private void uploadImagesAndSaveEntry(JournalEntry entry) {
        if (selectedImageUris.isEmpty()) {
            saveEntryToFirestore(entry);
            return;
        }

        List<String> imageUrls = new ArrayList<>();
        StorageReference storageRef = storage.getReference().child("journal_images").child(mAuth.getCurrentUser().getUid());

        for (Uri imageUri : selectedImageUris) {
            String imageName = UUID.randomUUID().toString();
            StorageReference imageRef = storageRef.child(imageName);

            imageRef.putFile(imageUri)
                    .addOnSuccessListener(taskSnapshot -> {
                        imageRef.getDownloadUrl()
                                .addOnSuccessListener(uri -> {
                                    imageUrls.add(uri.toString());
                                    if (imageUrls.size() == selectedImageUris.size()) {
                                        entry.setImageUrls(imageUrls);
                                        saveEntryToFirestore(entry);
                                    }
                                })
                                .addOnFailureListener(e -> {
                                    Log.e("CreateEntryActivity", "Failed to get download URL", e);
                                    Toast.makeText(CreateEntryActivity.this, "Failed to get image URL: " + e.getMessage(), Toast.LENGTH_LONG).show();
                                });
                    })
                    .addOnFailureListener(e -> {
                        Log.e("CreateEntryActivity", "Failed to upload image", e);
                        Toast.makeText(CreateEntryActivity.this, "Failed to upload image: " + e.getMessage(), Toast.LENGTH_LONG).show();
                    });
        }
    }

    private void saveEntryToFirestore(JournalEntry entry) {
        db.collection("entries")
                .add(entry)
                .addOnSuccessListener(documentReference -> {
                    Log.d("CreateEntryActivity", "Entry saved with ID: " + documentReference.getId());
                    Toast.makeText(CreateEntryActivity.this, "Entry saved successfully", Toast.LENGTH_SHORT).show();
                    setResult(RESULT_OK);
                    finish();
                })
                .addOnFailureListener(e -> {
                    Log.e("CreateEntryActivity", "Error saving entry", e);
                    Toast.makeText(CreateEntryActivity.this, "Error saving entry: " + e.getMessage(), Toast.LENGTH_LONG).show();
                });
    }
}