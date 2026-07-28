#include <iostream>
#include "../include/User.h"
#include "../include/Student.h"
#include "../include/StorageManager.h"

using namespace std;

int main()
{
    Student student(
        "rumaisa123",
        "pass123",
        "Rumaisa Abbasi",
        "rumaisa@gmail.com",
        "24K-1234",
        2,
        "Computer Science"
    );

    if (StorageManager::saveStudent(student))
    {
        cout << "Student registered successfully!\n";
    }
    else
    {
        cout << "Username already exists!\n";
    }

    return 0;
}