#include <iostream>
#include <string>
#include "User.h"
#include "Student.h"
#include "StorageManager.h"
#include "Course.h"
#include "CourseManager.h"
#include "Assignment.h"
#include "AssignmentManager.h"
#include "Note.h"
#include "NoteManager.h"
#include "StudyTask.h"
#include "StudyPlanner.h"

using namespace std;

void signUp();
void login();
void dashboard(Student &currentStudent);
void addCourse(CourseManager &manager);
void assignmentMenu(AssignmentManager &manager, string username);
void addAssignment(AssignmentManager &manager);
void addNote(NoteManager &manager);
void noteMenu(NoteManager &manager, string username);
void addStudyTask(StudyPlanner &planner);
void studyPlannerMenu(StudyPlanner &planner, string username);
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
    NoteManager noteManager;
    StudyPlanner studyPlanner;

    string username = currentStudent.getUsername();

    // Load all saved data when the student logs in
    courseManager.loadCourses(username);
    assignmentManager.loadAssignments(username);
    noteManager.loadNotes(username);
    studyPlanner.loadTasks(username);

    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "Welcome, " << currentStudent.getFullName() << endl;
        cout << "=====================================\n";

        cout << "1. Courses\n";
        cout << "2. Assignments\n";
        cout << "3. Notes\n";
        cout << "4. Study Planner\n";
        cout << "5. Save Data\n";
        cout << "6. Load Data\n";
        cout << "7. Logout\n";

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
                    if(courseManager.saveCourses(username))
                        cout << "\nCourses Saved!\n";
                    else
                        cout << "\nUnable to Save Courses!\n";
                    break;

                case 4:
                    if(courseManager.loadCourses(username))
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
            assignmentMenu(assignmentManager, username);
            break;

        // ==========================================
        // NOTES
        // ==========================================
        case 3:
            noteMenu(noteManager, username);
            break;

        // ==========================================
        // STUDY PLANNER
        // ==========================================
        case 4:
            studyPlannerMenu(studyPlanner, username);
            break;

        // ==========================================
        // SAVE ALL DATA
        // ==========================================
        case 5:
        {
            bool coursesSaved =
                courseManager.saveCourses(username);

            bool assignmentsSaved =
                assignmentManager.saveAssignments(username);

            bool notesSaved =
                noteManager.saveNotes(username);

            bool studyTasksSaved =
                studyPlanner.saveTasks(username);

            cout << "\n========== SAVE STATUS ==========\n";

            cout << "Courses: "
                 << (coursesSaved ? "Saved" : "Failed")
                 << endl;

            cout << "Assignments: "
                 << (assignmentsSaved ? "Saved" : "Failed")
                 << endl;

            cout << "Notes: "
                 << (notesSaved ? "Saved" : "Failed")
                 << endl;

            cout << "Study Tasks: "
                 << (studyTasksSaved ? "Saved" : "Failed")
                 << endl;

            break;
        }

        // ==========================================
        // LOAD ALL DATA
        // ==========================================
        case 6:
        {
            bool coursesLoaded =
                courseManager.loadCourses(username);

            bool assignmentsLoaded =
                assignmentManager.loadAssignments(username);

            bool notesLoaded =
                noteManager.loadNotes(username);

            bool studyTasksLoaded =
                studyPlanner.loadTasks(username);

            cout << "\n========== LOAD STATUS ==========\n";

            cout << "Courses: "
                 << (coursesLoaded ? "Loaded" : "Not Found")
                 << endl;

            cout << "Assignments: "
                 << (assignmentsLoaded ? "Loaded" : "Not Found")
                 << endl;

            cout << "Notes: "
                 << (notesLoaded ? "Loaded" : "Not Found")
                 << endl;

            cout << "Study Tasks: "
                 << (studyTasksLoaded ? "Loaded" : "Not Found")
                 << endl;

            break;
        }

        // ==========================================
        // LOGOUT
        // ==========================================
        case 7:
            cout << "\nLogging Out...\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while(choice != 7);
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
void addNote(NoteManager &manager)
{
    string title;
    string courseCode;
    string content;

    cin.ignore();

    cout << "\n========== ADD NOTE ==========\n";

    cout << "Title: ";
    getline(cin, title);

    cout << "Course Code: ";
    getline(cin, courseCode);

    cout << "Content: ";
    getline(cin, content);

    Note note(
        title,
        courseCode,
        content
    );

    if(manager.addNote(note))
    {
        cout << "\nNote Added Successfully!\n";
    }
    else
    {
        cout << "\nMaximum number of notes reached!\n";
    }
}
void noteMenu(NoteManager &manager, string username)
{
    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "             NOTES\n";
        cout << "=====================================\n";

        cout << "1. Add Note\n";
        cout << "2. View Notes\n";
        cout << "3. Delete Note\n";
        cout << "4. Save Notes\n";
        cout << "5. Load Notes\n";
        cout << "6. Back\n";

        cout << "\nChoice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            addNote(manager);
            break;

        case 2:
            manager.displayNotes();
            break;

        case 3:
        {
            int number;

            cout << "\nEnter note number to delete: ";
            cin >> number;

            if(manager.deleteNote(number - 1))
                cout << "\nNote deleted successfully!\n";
            else
                cout << "\nInvalid note number!\n";

            break;
        }

        case 4:
            if(manager.saveNotes(username))
                cout << "\nNotes Saved!\n";
            else
                cout << "\nUnable to Save Notes!\n";
            break;

        case 5:
            if(manager.loadNotes(username))
                cout << "\nNotes Loaded!\n";
            else
                cout << "\nNo Saved Notes Found!\n";
            break;

        case 6:
            cout << "\nReturning to Dashboard...\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while(choice != 6);
}
void addStudyTask(StudyPlanner &planner)
{
    string subject;
    string task;
    string date;
    string duration;

    cin.ignore();

    cout << "\n========== ADD STUDY TASK ==========\n";

    cout << "Subject: ";
    getline(cin, subject);

    cout << "Task: ";
    getline(cin, task);

    cout << "Date (DD-MM-YYYY): ";
    getline(cin, date);

    cout << "Duration: ";
    getline(cin, duration);

    StudyTask newTask(
        subject,
        task,
        date,
        duration
    );

    if(planner.addTask(newTask))
        cout << "\nStudy Task Added Successfully!\n";
    else
        cout << "\nMaximum number of study tasks reached!\n";
}
void studyPlannerMenu(StudyPlanner &planner, string username)
{
    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "          STUDY PLANNER\n";
        cout << "=====================================\n";

        cout << "1. Add Study Task\n";
        cout << "2. View Study Tasks\n";
        cout << "3. Mark Completed\n";
        cout << "4. Delete Study Task\n";
        cout << "5. Save Study Tasks\n";
        cout << "6. Load Study Tasks\n";
        cout << "7. Back\n";

        cout << "\nChoice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            addStudyTask(planner);
            break;

        case 2:
            planner.displayTasks();
            break;

        case 3:
        {
            int number;

            cout << "\nEnter task number to mark completed: ";
            cin >> number;

            if(planner.markCompleted(number - 1))
                cout << "\nStudy Task marked as completed!\n";
            else
                cout << "\nInvalid task number!\n";

            break;
        }

        case 4:
        {
            int number;

            cout << "\nEnter task number to delete: ";
            cin >> number;

            if(planner.deleteTask(number - 1))
                cout << "\nStudy Task deleted successfully!\n";
            else
                cout << "\nInvalid task number!\n";

            break;
        }

        case 5:
            if(planner.saveTasks(username))
                cout << "\nStudy Tasks Saved!\n";
            else
                cout << "\nUnable to Save Study Tasks!\n";
            break;

        case 6:
            if(planner.loadTasks(username))
                cout << "\nStudy Tasks Loaded!\n";
            else
                cout << "\nNo Saved Study Tasks Found!\n";
            break;

        case 7:
            cout << "\nReturning to Dashboard...\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while(choice != 7);
}