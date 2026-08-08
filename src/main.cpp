#include <iostream>
#include <string>
#include "User.h"
#include "Student.h"
#include "StorageManager.h"
#include "CourseManager.h"
#include "AssignmentManager.h"
#include "Assignment.h"

using namespace std;

void signUp();
void login();
void dashboard(Student &currentStudent);
void addCourse(CourseManager &manager);
void assignmentMenu(AssignmentManager &manager, string username);
void addAssignment(AssignmentManager &manager);
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
    CourseManager courseManager;
    AssignmentManager assignmentManager;

    // Load saved data automatically when the student logs in
    courseManager.loadCourses(currentStudent.getUsername());
    assignmentManager.loadAssignments(currentStudent.getUsername());

    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "Welcome, " << currentStudent.getFullName() << endl;
        cout << "=====================================\n";

        cout << "1. Courses\n";
        cout << "2. Assignments\n";
        cout << "3. Save Data\n";
        cout << "4. Load Data\n";
        cout << "5. Logout\n";

        cout << "\nChoice: ";
        cin >> choice;

        switch(choice)
        {
        // ==========================================
        // COURSES
        // ==========================================
        case 1:
        {
            int courseChoice;

            do
            {
                cout << "\n========== COURSES ==========\n";
                cout << "1. Add Course\n";
                cout << "2. View Courses\n";
                cout << "3. Save Courses\n";
                cout << "4. Load Courses\n";
                cout << "5. Back\n";

                cout << "\nChoice: ";
                cin >> courseChoice;

                switch(courseChoice)
                {
                case 1:
                    addCourse(courseManager);
                    break;

                case 2:
                    courseManager.displayCourses();
                    break;

                case 3:
                    if(courseManager.saveCourses(currentStudent.getUsername()))
                        cout << "\nCourses Saved!\n";
                    else
                        cout << "\nUnable to Save Courses!\n";
                    break;

                case 4:
                    if(courseManager.loadCourses(currentStudent.getUsername()))
                        cout << "\nCourses Loaded!\n";
                    else
                        cout << "\nNo Saved Courses Found!\n";
                    break;

                case 5:
                    cout << "\nReturning to Dashboard...\n";
                    break;

                default:
                    cout << "\nInvalid Choice!\n";
                }

            } while(courseChoice != 5);

            break;
        }

        // ==========================================
        // ASSIGNMENTS
        // ==========================================
        case 2:
            assignmentMenu(
                assignmentManager,
                currentStudent.getUsername()
            );
            break;

        // ==========================================
        // SAVE ALL DATA
        // ==========================================
        case 3:
        {
            bool coursesSaved =
                courseManager.saveCourses(
                    currentStudent.getUsername()
                );

            bool assignmentsSaved =
                assignmentManager.saveAssignments(
                    currentStudent.getUsername()
                );

            if(coursesSaved)
                cout << "\nCourses Saved!\n";
            else
                cout << "\nUnable to Save Courses!\n";

            if(assignmentsSaved)
                cout << "Assignments Saved!\n";
            else
                cout << "Unable to Save Assignments!\n";

            break;
        }

        // ==========================================
        // LOAD ALL DATA
        // ==========================================
        case 4:
        {
            bool coursesLoaded =
                courseManager.loadCourses(
                    currentStudent.getUsername()
                );

            bool assignmentsLoaded =
                assignmentManager.loadAssignments(
                    currentStudent.getUsername()
                );

            if(coursesLoaded)
                cout << "\nCourses Loaded!\n";
            else
                cout << "\nNo Saved Courses Found!\n";

            if(assignmentsLoaded)
                cout << "Assignments Loaded!\n";
            else
                cout << "No Saved Assignments Found!\n";

            break;
        }

        // ==========================================
        // LOGOUT
        // ==========================================
        case 5:
            cout << "\nLogging Out...\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while(choice != 5);
}

void addAssignment(AssignmentManager &manager)
{
    string title;
    string courseCode;
    string dueDate;
    string priority;

    cin.ignore();

    cout << "\n========== ADD ASSIGNMENT ==========\n";

    cout << "Title: ";
    getline(cin, title);

    cout << "Course Code: ";
    getline(cin, courseCode);

    cout << "Due Date (DD-MM-YYYY): ";
    getline(cin, dueDate);

    cout << "Priority (High/Medium/Low): ";
    getline(cin, priority);

    Assignment assignment(
        title,
        courseCode,
        dueDate,
        priority,
        false
    );

    if (manager.addAssignment(assignment))
    {
        cout << "\nAssignment Added Successfully!\n";
    }
    else
    {
        cout << "\nMaximum number of assignments reached!\n";
    }
}

void assignmentMenu(AssignmentManager &manager, string username)
{
    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "          ASSIGNMENT MANAGER\n";
        cout << "=====================================\n";

        cout << "1. Add Assignment\n";
        cout << "2. View Assignments\n";
        cout << "3. Mark Completed\n";
        cout << "4. Delete Assignment\n";
        cout << "5. Save Assignments\n";
        cout << "6. Load Assignments\n";
        cout << "7. Back\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addAssignment(manager);
            break;

        case 2:
            manager.displayAssignments();
            break;

        case 3:
        {
            int number;

            cout << "\nEnter assignment number to mark completed: ";
            cin >> number;

            if (manager.markCompleted(number - 1))
                cout << "\nAssignment marked as completed!\n";
            else
                cout << "\nInvalid assignment number!\n";

            break;
        }

        case 4:
        {
            int number;

            cout << "\nEnter assignment number to delete: ";
            cin >> number;

            if (manager.deleteAssignment(number - 1))
                cout << "\nAssignment deleted successfully!\n";
            else
                cout << "\nInvalid assignment number!\n";

            break;
        }

        case 5:
        {
            if(manager.saveAssignments(username))
        cout << "\nAssignments Saved!\n";
    else
        cout << "\nUnable to Save Assignments!\n";
    break;

        }

        case 6:
        {
             if(manager.loadAssignments(username))
            cout << "\nAssignments Loaded!\n";
        else
            cout << "\nNo Saved Assignments Found!\n";
        break;
        }

        case 7:
            cout << "\nReturning to dashboard...\n";
            break;

        default:
            cout << "\nInvalid choice!\n";
        }

    } while (choice != 7);
}