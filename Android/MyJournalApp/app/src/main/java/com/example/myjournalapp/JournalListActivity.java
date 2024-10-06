package com.example.myjournalapp;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.widget.SearchView;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.firestore.FirebaseFirestore;
import com.google.firebase.firestore.Query;
import com.google.firebase.firestore.QueryDocumentSnapshot;
import com.google.firebase.firestore.ListenerRegistration;

import java.util.ArrayList;
import java.util.List;

public class JournalListActivity extends AppCompatActivity {
    private FirebaseFirestore db;
    private FirebaseAuth mAuth;
    private RecyclerView recyclerView;
    private JournalAdapter adapter;
    private FloatingActionButton fabAddEntry;
    private ListenerRegistration firestoreListener;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_journal_list);

        db = FirebaseFirestore.getInstance();
        mAuth = FirebaseAuth.getInstance();

        recyclerView = findViewById(R.id.recycler_view);
        fabAddEntry = findViewById(R.id.fab_add_entry);

        // Initialize the adapter with an empty list
        adapter = new JournalAdapter(new ArrayList<>());
        recyclerView.setAdapter(adapter);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));

        // Set the click listener
        adapter.setOnEntryClickListener(entry -> {
            Intent intent = new Intent(JournalListActivity.this, ViewEntryActivity.class);
            intent.putExtra("ENTRY_ID", entry.getId());
            startActivity(intent);
        });
        fabAddEntry.setOnClickListener(v -> startActivity(new Intent(JournalListActivity.this, CreateEntryActivity.class)));


    }


    @Override
    protected void onStart() {
        super.onStart();
        loadJournalEntries();
    }

    @Override
    protected void onStop() {
        super.onStop();
        if (firestoreListener != null) {
            firestoreListener.remove();
        }
    }

    private void loadJournalEntries() {
        String userId = mAuth.getCurrentUser().getUid();
        firestoreListener = db.collection("entries")
                .whereEqualTo("userId", userId)
                .orderBy("date", Query.Direction.DESCENDING)
                .addSnapshotListener((value, error) -> {
                    if (error != null) {
                        Log.e("JournalListActivity", "Error loading entries", error);
                        return;
                    }

                    List<JournalEntry> entries = new ArrayList<>();
                    for (QueryDocumentSnapshot doc : value) {
                        JournalEntry entry = doc.toObject(JournalEntry.class);
                        entry.setId(doc.getId());
                        entries.add(entry);
                    }

                    runOnUiThread(() -> {
                        adapter.updateEntries(entries);
                        adapter.notifyDataSetChanged();
                    });
                });
    }
}