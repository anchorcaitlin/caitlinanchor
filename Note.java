package com.example.tutornotesapplication;

public class Note  {

    String tutor;
    String description;
    String student;
    long create_time;

    // create a getter and setter for these values


    public String getStudent() {
        return student;
    }

    public void setStudent(String student) {
        this.student = student;
    }

    public String getTitle() {
        return tutor;
    }

    public void setTitle(String title) {
        this.tutor = title;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public long getCreate_time() {
        return create_time;
    }

    public void setCreate_time(long create_time) {
        this.create_time = create_time;
    }
}
