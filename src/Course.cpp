#include "Course.h"
#include <iostream>

using namespace std;

// Default Constructor
Course::Course()
{
    courseCode = "";
    courseName = "";
    creditHours = 0;
    grade = "";
}

// Parameterized Constructor
Course::Course(string courseCode,
               string courseName,
               int creditHours,
               string grade)
{
    this->courseCode = courseCode;
    this->courseName = courseName;
    this->creditHours = creditHours;
    this->grade = grade;
}

// Getters
string Course::getCourseCode() const
{
    return courseCode;
}

string Course::getCourseName() const
{
    return courseName;
}

int Course::getCreditHours() const
{
    return creditHours;
}

string Course::getGrade() const
{
    return grade;
}

// Setters
void Course::setCourseCode(string courseCode)
{
    this->courseCode = courseCode;
}

void Course::setCourseName(string courseName)
{
    this->courseName = courseName;
}

void Course::setCreditHours(int creditHours)
{
    this->creditHours = creditHours;
}

void Course::setGrade(string grade)
{
    this->grade = grade;
}

// Display
void Course::displayCourse() const
{
    cout << "\n===== Course Information =====\n";
    cout << "Course Code : " << courseCode << endl;
    cout << "Course Name : " << courseName << endl;
    cout << "Credit Hours: " << creditHours << endl;
    cout << "Grade       : " << grade << endl;
}