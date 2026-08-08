#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <string>

using namespace std;

class Assignment
{
private:
    string title;
    string courseCode;
    string dueDate;
    string priority;
    bool completed;

public:
    // Constructors
    Assignment();

    Assignment(string title,
               string courseCode,
               string dueDate,
               string priority,
               bool completed);

    // Getters
    string getTitle() const;
    string getCourseCode() const;
    string getDueDate() const;
    string getPriority() const;
    bool isCompleted() const;

    // Setters
    void setTitle(string title);
    void setCourseCode(string courseCode);
    void setDueDate(string dueDate);
    void setPriority(string priority);
    void setCompleted(bool completed);

    // Display
    void displayAssignment() const;
};

#endif