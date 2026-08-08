#include "Assignment.h"
#include <iostream>

using namespace std;

// Default Constructor
Assignment::Assignment()
{
    title = "";
    courseCode = "";
    dueDate = "";
    priority = "";
    completed = false;
}

// Parameterized Constructor
Assignment::Assignment(string title,
                       string courseCode,
                       string dueDate,
                       string priority,
                       bool completed)
{
    this->title = title;
    this->courseCode = courseCode;
    this->dueDate = dueDate;
    this->priority = priority;
    this->completed = completed;
}

// Getters
string Assignment::getTitle() const
{
    return title;
}

string Assignment::getCourseCode() const
{
    return courseCode;
}

string Assignment::getDueDate() const
{
    return dueDate;
}

string Assignment::getPriority() const
{
    return priority;
}

bool Assignment::isCompleted() const
{
    return completed;
}

// Setters
void Assignment::setTitle(string title)
{
    this->title = title;
}

void Assignment::setCourseCode(string courseCode)
{
    this->courseCode = courseCode;
}

void Assignment::setDueDate(string dueDate)
{
    this->dueDate = dueDate;
}

void Assignment::setPriority(string priority)
{
    this->priority = priority;
}

void Assignment::setCompleted(bool completed)
{
    this->completed = completed;
}

// Display
void Assignment::displayAssignment() const
{
    cout << "\n========== Assignment ==========\n";
    cout << "Title       : " << title << endl;
    cout << "Course Code : " << courseCode << endl;
    cout << "Due Date    : " << dueDate << endl;
    cout << "Priority    : " << priority << endl;
    cout << "Status      : "
         << (completed ? "Completed" : "Pending")
         << endl;
}