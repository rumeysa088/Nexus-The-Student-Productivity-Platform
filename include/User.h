#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User
{
private:
    string username;
    string password;
    string fullName;
    string email;

public:
    // Constructors
    User();
    User(string username, string password,
         string fullName, string email);

    // Getters
    string getUsername() const;
    string getPassword() const;
    string getFullName() const;
    string getEmail() const;

    // Setters
    void setUsername(string username);
    void setPassword(string password);
    void setFullName(string fullName);
    void setEmail(string email);

    // Utility
    void displayUser() const;
};

#endif