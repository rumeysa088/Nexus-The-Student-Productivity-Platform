#ifndef COURSE_H
#define COURSE_H

#include <string>

using namespace std;

class Course
{
private:
    string courseCode;
    string courseName;
    int creditHours;
    string grade;

public:
    // Constructors
    Course();

    Course(string courseCode,
           string courseName,
           int creditHours,
           string grade);

    // Getters
    string getCourseCode() const;
    string getCourseName() const;
    int getCreditHours() const;
    string getGrade() const;

    // Setters
    void setCourseCode(string courseCode);
    void setCourseName(string courseName);
    void setCreditHours(int creditHours);
    void setGrade(string grade);

    // Display
    void displayCourse() const;
};

#endif