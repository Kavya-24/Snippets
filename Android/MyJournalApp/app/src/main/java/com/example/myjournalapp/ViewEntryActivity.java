package com.example.myjournalapp;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;
import com.bumptech.glide.Glide;
import com.google.firebase.firestore.FirebaseFirestore;
import java.text.SimpleDateFormat;
import java.util.Locale;

public class ViewEntryActivity extends AppCompatActivity {
    private FirebaseFirestore db;
    private TextView titleTextView, dateTextView, contentTextView;
    private LinearLayout imagesLayout;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_view_entry);

        db = FirebaseFirestore.getInstance();

        titleTextView = findViewById(R.id.title_text_view);
        dateTextView = findViewById(R.id.date_text_view);
        contentTextView = findViewById(R.id.content_text_view);
        imagesLayout = findViewById(R.id.images_layout);

        String entryId = getIntent().getStringExtra("ENTRY_ID");
        loadEntry(entryId);

        Button editButton = findViewById(R.id.edit_button);
        editButton.setOnClickListener(v -> {
            Intent intent = new Intent(ViewEntryActivity.this, EditEntryActivity.class);
            intent.putExtra("ENTRY_ID", entryId);
            startActivity(intent);
        });
    }


    private void loadEntry(String entryId) {
        db.collection("entries").document(entryId).get()
                .addOnSuccessListener(documentSnapshot -> {
                    JournalEntry entry = documentSnapshot.toObject(JournalEntry.class);
                    if (entry != null) {
                        updateUI(entry);
                    }
                });
    }

    private void updateUI(JournalEntry entry) {
        titleTextView.setText(entry.getTitle());
        contentTextView.setText(entry.getContent());
        SimpleDateFormat sdf = new SimpleDateFormat("MMM dd, yyyy HH:mm", Locale.getDefault());
        dateTextView.setText(sdf.format(entry.getDate()));

        for (String imageUrl : entry.getImageUrls()) {
            ImageView imageView = new ImageView(this);
            LinearLayout.LayoutParams layoutParams = new LinearLayout.LayoutParams(
                    LinearLayout.LayoutParams.MATCH_PARENT,
                    400
            );
            layoutParams.setMargins(0, 0, 0, 16);
            imageView.setLayoutParams(layoutParams);
            imageView.setScaleType(ImageView.ScaleType.CENTER_CROP);

            Glide.with(this)
                    .load(imageUrl)
                    .into(imageView);

            imagesLayout.addView(imageView);
        }
    }
}
