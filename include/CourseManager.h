#ifndef COURSEMANAGER_H
#define COURSEMANAGER_H

#include "Course.h"
#include <string>

using namespace std;

const int MAX_COURSES = 10;

class CourseManager
{
private:
    Course courses[MAX_COURSES];
    int totalCourses;

public:
    CourseManager();

    bool addCourse(const Course &course);

    void displayCourses() const;

    int getTotalCourses() const;

    const Course& getCourse(int index) const;

    bool saveCourses(string username);

    bool loadCourses(string username);

    void clearCourses();
};

#endif