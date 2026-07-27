#include "../include/User.h"
#include <iostream>

using namespace std;

// Default Constructor
User::User()
{
    username = "";
    password = "";
    fullName = "";
    email = "";
}

// Parameterized Constructor
User::User(string username, string password,
           string fullName, string email)
{
    this->username = username;
    this->password = password;
    this->fullName = fullName;
    this->email = email;
}

// Getters
string User::getUsername() const
{
    return username;
}

string User::getPassword() const
{
    return password;
}

string User::getFullName() const
{
    return fullName;
}

string User::getEmail() const
{
    return email;
}

// Setters
void User::setUsername(string username)
{
    this->username = username;
}

void User::setPassword(string password)
{
    this->password = password;
}

void User::setFullName(string fullName)
{
    this->fullName = fullName;
}

void User::setEmail(string email)
{
    this->email = email;
}

// Display
void User::displayUser() const
{
    cout << "\n===== User Information =====\n";
    cout << "Name     : " << fullName << endl;
    cout << "Username : " << username << endl;
    cout << "Email    : " << email << endl;
}