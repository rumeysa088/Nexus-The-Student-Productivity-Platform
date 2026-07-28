#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include "Student.h"

class StorageManager
{
public:
    static bool usernameExists(string username);

    static bool saveStudent(const Student &student);

    static bool login(string username, string password, Student &student);
};

#endif