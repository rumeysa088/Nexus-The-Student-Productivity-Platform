#include <iostream>
#include <string>
#include "User.h"
#include "Student.h"
#include "StorageManager.h"
#include "CourseManager.h"

using namespace std;

void signUp();
void login();
void dashboard(Student &currentStudent);
void addCourse(CourseManager &manager);

int main()
{
    int choice;

    do
    {
        cout << "\n=========================================\n";
        cout << "              N E X U S\n";
        cout << "      Your Academic Command Center\n";
        cout << "=========================================\n";

        cout << "1. Sign Up\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            signUp();
            break;

        case 2:
    login();
    break;

        case 3:
            cout << "\nThank you for using Nexus!\n";
            break;

        default:
            cout << "\nInvalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}
void signUp()
{
    string username;
    string password;
    string fullName;
    string email;
    string studentID;
    string department;
    int semester;

    cout << "\n========== SIGN UP ==========\n";

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    cin.ignore();

    cout << "Full Name: ";
    getline(cin, fullName);

    cout << "Email: ";
    getline(cin, email);

    cout << "Student ID: ";
    getline(cin, studentID);

    cout << "Semester: ";
    cin >> semester;

    cin.ignore();

    cout << "Department: ";
    getline(cin, department);

    Student student(
        username,
        password,
        fullName,
        email,
        studentID,
        semester,
        department
    );

    if (StorageManager::saveStudent(student))
    {
        cout << "\nAccount created successfully!\n";
    }
    else
    {
        cout << "\nUsername already exists!\n";
    }
}
void login()
{
    string username;
    string password;

    cout << "\n========== LOGIN ==========\n";

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    Student currentStudent;

    if (StorageManager::login(username, password, currentStudent))
    {
        cout << "\n=====================================\n";
        cout << "Login Successful!\n";
        cout << "Welcome, "
             << currentStudent.getFullName()
             << "!\n";
        cout << "=====================================\n";

        dashboard(currentStudent);
    }
    else
    {
        cout << "\nInvalid Username or Password!\n";
    }
}
void addCourse(CourseManager &manager)
{
    string code;
    string name;
    string grade;
    int credits;

    cin.ignore();

    cout << "\n===== ADD COURSE =====\n";

    cout << "Course Code: ";
    getline(cin, code);

    cout << "Course Name: ";
    getline(cin, name);

    cout << "Credit Hours: ";
    cin >> credits;

    cin.ignore();

    cout << "Grade: ";
    getline(cin, grade);

    Course course(code, name, credits, grade);

    if(manager.addCourse(course))
        cout << "\nCourse Added Successfully!\n";
    else
        cout << "\nMaximum Courses Reached!\n";
}
void dashboard(Student &currentStudent)
{
    CourseManager manager;

    manager.loadCourses(currentStudent.getUsername());

    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "Welcome, " << currentStudent.getFullName() << endl;
        cout << "=====================================\n";

        cout << "1. Add Course\n";
        cout << "2. View Courses\n";
        cout << "3. Save Courses\n";
        cout << "4. Load Courses\n";
        cout << "5. Logout\n";

        cout << "\nChoice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            addCourse(manager);
            break;

        case 2:
            manager.displayCourses();
            break;

        case 3:
            if(manager.saveCourses(currentStudent.getUsername()))
                cout << "\nCourses Saved!\n";
            else
                cout << "\nUnable to Save!\n";
            break;

        case 4:
            if(manager.loadCourses(currentStudent.getUsername()))
                cout << "\nCourses Loaded!\n";
            else
                cout << "\nNo Saved Courses Found!\n";
            break;

        case 5:
            cout << "\nLogging Out...\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while(choice != 5);
}