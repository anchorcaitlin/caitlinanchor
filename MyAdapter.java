package com.example.tutornotesapplication;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;
import io.realm.RealmResults;

public class MyAdapter extends RecyclerView.Adapter<MyAdapter.MyViewHolder>{

    Context context;
    RealmResults<Note> notesList;

    public MyAdapter(Context context, RealmResults<Note> notesList) {
        this.context = context;
        this.notesList = notesList;
    }

    @NonNull
    @Override
    public MyViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        return new MyViewHolder(LayoutInflater.from(context).inflate(R.layout.item_view,parent,false));
    }

    @Override
    public void onBindViewHolder(@NonNull MyViewHolder holder, int position) {
        Note note = notesList.get(position);
        holder.tutorOutput.setText(note.getTitle());
    }

    @Override
    public int getItemCount() {
        return 0;
    }

    public class MyViewHolder extends RecyclerView.ViewHolder{

        TextView tutorOutput;
        TextView studentOutput;
        TextView descriptionOutput;

        public MyViewHolder(@NonNull View itemView) {
            super(itemView);
            tutorOutput = itemView.findViewById(R.id.tutoroutput);
            studentOutput = itemView.findViewById(R.id.studentoutput);
            descriptionOutput = itemView.findViewById(R.id.descriptionoutput);

        }
    }
}
