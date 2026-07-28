#include "../include/Student.h"
#include <iostream>

using namespace std;

// Default Constructor
Student::Student()
    : User()
{
    studentID = "";
    semester = 1;
    department = "";
}

// Parameterized Constructor
Student::Student(string username,
                 string password,
                 string fullName,
                 string email,
                 string studentID,
                 int semester,
                 string department)
    : User(username, password, fullName, email)
{
    this->studentID = studentID;
    this->semester = semester;
    this->department = department;
}

// Getters
string Student::getStudentID() const
{
    return studentID;
}

int Student::getSemester() const
{
    return semester;
}

string Student::getDepartment() const
{
    return department;
}

// Setters
void Student::setStudentID(string studentID)
{
    this->studentID = studentID;
}

void Student::setSemester(int semester)
{
    this->semester = semester;
}

void Student::setDepartment(string department)
{
    this->department = department;
}

// Display
void Student::displayStudent() const
{
    cout << "\n===== Student Information =====\n";

    displayUser();

    cout << "Student ID : " << studentID << endl;
    cout << "Semester   : " << semester << endl;
    cout << "Department : " << department << endl;
}