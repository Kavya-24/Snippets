package com.example.myjournalapp;

import android.content.Intent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import androidx.annotation.NonNull;
import androidx.appcompat.app.AlertDialog;
import androidx.recyclerview.widget.RecyclerView;
import com.bumptech.glide.Glide;
import com.google.firebase.firestore.FirebaseFirestore;
import java.text.SimpleDateFormat;
import java.util.List;
import java.util.Locale;

public class JournalAdapter extends RecyclerView.Adapter<JournalAdapter.JournalViewHolder> {
    private List<JournalEntry> entries;
    private OnEntryClickListener listener;
    private FirebaseFirestore db;

    public JournalAdapter(List<JournalEntry> entries) {
        this.entries = entries;
        this.db = FirebaseFirestore.getInstance();
    }

    public interface OnEntryClickListener {
        void onEntryClick(JournalEntry entry);
    }

    public void setOnEntryClickListener(OnEntryClickListener listener) {
        this.listener = listener;
    }

    @NonNull
    @Override
    public JournalViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_journal_entry, parent, false);
        return new JournalViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull JournalViewHolder holder, int position) {
        JournalEntry entry = entries.get(position);
        holder.bind(entry);
    }

    @Override
    public int getItemCount() {
        return entries.size();
    }

    public void updateEntries(List<JournalEntry> newEntries) {
        this.entries.clear();
        this.entries.addAll(newEntries);
        notifyDataSetChanged();
    }
    class JournalViewHolder extends RecyclerView.ViewHolder {
        private TextView usernameTextView;
        private TextView titleTextView;
        private TextView contentTextView;
        private ImageView imageView;
        private TextView timestampTextView;
        private ImageView deleteButton;
        private ImageView shareButton;

        JournalViewHolder(@NonNull View itemView) {
            super(itemView);
            usernameTextView = itemView.findViewById(R.id.journal_row_username);
            titleTextView = itemView.findViewById(R.id.journal_title_list);
            contentTextView = itemView.findViewById(R.id.journal_thought_list);
            imageView = itemView.findViewById(R.id.journal_image_list);
            timestampTextView = itemView.findViewById(R.id.journal_timestamp_list);
            deleteButton = itemView.findViewById(R.id.journal_row_delete_button);
            shareButton = itemView.findViewById(R.id.journal_row_share_button);

            itemView.setOnClickListener(v -> {
                int position = getAdapterPosition();
                if (position != RecyclerView.NO_POSITION && listener != null) {
                    listener.onEntryClick(entries.get(position));
                }
            });

            deleteButton.setOnClickListener(v -> {
                int position = getAdapterPosition();
                if (position != RecyclerView.NO_POSITION) {
                    showDeleteConfirmationDialog(entries.get(position));
                }
            });

            shareButton.setOnClickListener(v -> {
                int position = getAdapterPosition();
                if (position != RecyclerView.NO_POSITION) {
                    shareEntry(entries.get(position));
                }
            });
        }

        void bind(JournalEntry entry) {
            usernameTextView.setText(entry.getUsername()); // You might want to fetch the actual username
            titleTextView.setText(entry.getTitle());
            contentTextView.setText(entry.getContent());

            SimpleDateFormat sdf = new SimpleDateFormat("EEEE, MMM d", Locale.getDefault());
            timestampTextView.setText(sdf.format(entry.getDate()));

            // Load the first image if available
            if (entry.getImageUrls() != null && !entry.getImageUrls().isEmpty()) {
                Glide.with(itemView.getContext())
                        .load(entry.getImageUrls().get(0))
                        .placeholder(R.drawable.placeholder_image)
                        .into(imageView);
            } else {
                imageView.setImageResource(R.drawable.placeholder_image);
            }
        }

        private void showDeleteConfirmationDialog(JournalEntry entry) {
            new AlertDialog.Builder(itemView.getContext())
                    .setTitle("Delete Entry")
                    .setMessage("Are you sure you want to delete this entry?")
                    .setPositiveButton("Yes", (dialog, which) -> deleteEntry(entry))
                    .setNegativeButton("No", null)
                    .show();
        }

        private void deleteEntry(JournalEntry entry) {
            db.collection("entries").document(entry.getId())
                    .delete()
                    .addOnSuccessListener(aVoid -> {
                        entries.remove(entry);
                        notifyDataSetChanged();
                    })
                    .addOnFailureListener(e -> {
                        // Handle the error
                    });
        }

        private void shareEntry(JournalEntry entry) {
            Intent shareIntent = new Intent(Intent.ACTION_SEND);
            shareIntent.setType("text/plain");
            shareIntent.putExtra(Intent.EXTRA_SUBJECT, entry.getTitle());
            shareIntent.putExtra(Intent.EXTRA_TEXT, entry.getContent());
            itemView.getContext().startActivity(Intent.createChooser(shareIntent, "Share Journal Entry"));
        }
    }
}