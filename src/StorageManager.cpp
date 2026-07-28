#include "../include/StorageManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

bool StorageManager::usernameExists(string username)
{
    ifstream file("data/users.txt");

    if (!file)
        return false;

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string fileUsername;

        getline(ss, fileUsername, '|');

        if (fileUsername == username)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

bool StorageManager::saveStudent(const Student& student)
{
    if (usernameExists(student.getUsername()))
    {
        return false;
    }

    ofstream file("data/users.txt", ios::app);

    if (!file)
        return false;

    file << student.getUsername() << "|"
         << student.getPassword() << "|"
         << student.getFullName() << "|"
         << student.getEmail() << "|"
         << student.getStudentID() << "|"
         << student.getSemester() << "|"
         << student.getDepartment() << endl;

    file.close();

    return true;
}

bool StorageManager::login(string username, string password, Student &student)
{
    ifstream file("data/users.txt");

    if (!file)
        return false;

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string u;
        string p;
        string name;
        string email;
        string id;
        string semesterStr;
        string department;

        getline(ss, u, '|');
        getline(ss, p, '|');
        getline(ss, name, '|');
        getline(ss, email, '|');
        getline(ss, id, '|');
        getline(ss, semesterStr, '|');
        getline(ss, department);

        if (u == username && p == password)
        {
            student = Student(
                u,
                p,
                name,
                email,
                id,
                stoi(semesterStr),
                department
            );

            file.close();
            return true;
        }
    }

    file.close();
    return false;
}