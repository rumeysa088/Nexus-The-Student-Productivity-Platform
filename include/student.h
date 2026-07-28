#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include <string>

using namespace std;

class Student : public User
{
private:
    string studentID;
    int semester;
    string department;

public:
    // Constructors
    Student();

    Student(string username,
            string password,
            string fullName,
            string email,
            string studentID,
            int semester,
            string department);

    // Getters
    string getStudentID() const;
    int getSemester() const;
    string getDepartment() const;

    // Setters
    void setStudentID(string studentID);
    void setSemester(int semester);
    void setDepartment(string department);

    // Display
    void displayStudent() const;
};

#endif