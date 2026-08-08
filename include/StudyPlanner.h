#ifndef STUDYPLANNER_H
#define STUDYPLANNER_H

#include "StudyTask.h"
#include <string>

using namespace std;

const int MAX_STUDY_TASKS = 30;

class StudyPlanner
{
private:
    StudyTask tasks[MAX_STUDY_TASKS];
    int totalTasks;

public:
    StudyPlanner();

    bool addTask(const StudyTask &task);

    void displayTasks() const;

    bool markCompleted(int index);

    bool deleteTask(int index);

    int getTotalTasks() const;

    const StudyTask& getTask(int index) const;

    bool saveTasks(string username);

    bool loadTasks(string username);

    void clearTasks();
};

#endif