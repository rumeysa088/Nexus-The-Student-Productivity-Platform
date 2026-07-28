#include "CourseManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

CourseManager::CourseManager()
{
    totalCourses = 0;
}

bool CourseManager::addCourse(const Course &course)
{
    if (totalCourses >= MAX_COURSES)
    {
        return false;
    }

    courses[totalCourses] = course;
    totalCourses++;

    return true;
}

void CourseManager::displayCourses() const
{
    if (totalCourses == 0)
    {
        cout << "\nNo courses available.\n";
        return;
    }

    cout << "\n========== MY COURSES ==========\n";

    for (int i = 0; i < totalCourses; i++)
    {
        cout << "\nCourse " << i + 1 << endl;
        courses[i].displayCourse();
    }
}

int CourseManager::getTotalCourses() const
{
    return totalCourses;
}


const Course& CourseManager::getCourse(int index) const
{
    return courses[index];
}

void CourseManager::clearCourses()
{
    totalCourses = 0;
}
bool CourseManager::saveCourses(string username)
{
   string filename = "data/courses/" + username + ".txt";

    ofstream file(filename);

    if (!file)
        return false;

    for(int i=0;i<totalCourses;i++)
    {
        file << courses[i].getCourseCode() << "|"
             << courses[i].getCourseName() << "|"
             << courses[i].getCreditHours() << "|"
             << courses[i].getGrade() << endl;
    }

    file.close();

    return true;
}
bool CourseManager::loadCourses(string username)
{
    clearCourses();

    string filename = "data/courses/" + username + ".txt";

    ifstream file(filename);

    if(!file)
        return false;

    string line;

    while(getline(file,line))
    {
        stringstream ss(line);

        string code;
        string name;
        string credits;
        string grade;

        getline(ss,code,'|');
        getline(ss,name,'|');
        getline(ss,credits,'|');
        getline(ss,grade);

        addCourse(
            Course(
                code,
                name,
                stoi(credits),
                grade
            )
        );
    }

    file.close();

    return true;
}