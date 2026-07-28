#include "../include/StorageManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

bool StorageManager::usernameExists(string username)
{
    ifstream file("../data/users.txt");

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

    ofstream file("../data/users.txt", ios::app);

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

bool StorageManager::login(string username, string password)
{
    ifstream file("../data/users.txt");

    if (!file)
        return false;

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string u, p;

        getline(ss, u, '|');
        getline(ss, p, '|');

        if (u == username && p == password)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}