#include "StudyPlanner.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

StudyPlanner::StudyPlanner()
{
    totalTasks = 0;
}

bool StudyPlanner::addTask(const StudyTask &task)
{
    if(totalTasks >= MAX_STUDY_TASKS)
    {
        return false;
    }

    tasks[totalTasks] = task;
    totalTasks++;

    return true;
}

void StudyPlanner::displayTasks() const
{
    if(totalTasks == 0)
    {
        cout << "\nNo study tasks available.\n";
        return;
    }

    cout << "\n========== STUDY PLANNER ==========\n";

    for(int i = 0; i < totalTasks; i++)
    {
        cout << "\nTask #" << i + 1;
        tasks[i].displayTask();
    }
}

bool StudyPlanner::markCompleted(int index)
{
    if(index < 0 || index >= totalTasks)
    {
        return false;
    }

    tasks[index].setCompleted(true);

    return true;
}

bool StudyPlanner::deleteTask(int index)
{
    if(index < 0 || index >= totalTasks)
    {
        return false;
    }

    for(int i = index; i < totalTasks - 1; i++)
    {
        tasks[i] = tasks[i + 1];
    }

    totalTasks--;

    return true;
}

int StudyPlanner::getTotalTasks() const
{
    return totalTasks;
}

const StudyTask& StudyPlanner::getTask(int index) const
{
    return tasks[index];
}

void StudyPlanner::clearTasks()
{
    totalTasks = 0;
}

bool StudyPlanner::saveTasks(string username)
{
    string filename = "data/study/" + username + ".txt";

    ofstream file(filename);

    if(!file)
    {
        return false;
    }

    for(int i = 0; i < totalTasks; i++)
    {
        file << tasks[i].getSubject() << "|"
             << tasks[i].getTask() << "|"
             << tasks[i].getDate() << "|"
             << tasks[i].getDuration() << "|"
             << tasks[i].isCompleted()
             << endl;
    }

    file.close();

    return true;
}

bool StudyPlanner::loadTasks(string username)
{
    clearTasks();

    string filename = "data/study/" + username + ".txt";

    ifstream file(filename);

    if(!file)
    {
        return false;
    }

    string line;

    while(getline(file, line))
    {
        stringstream ss(line);

        string subject;
        string task;
        string date;
        string duration;
        string completedString;

        getline(ss, subject, '|');
        getline(ss, task, '|');
        getline(ss, date, '|');
        getline(ss, duration, '|');
        getline(ss, completedString);

        bool completed = (completedString == "1");

        StudyTask studyTask(
            subject,
            task,
            date,
            duration,
            completed
        );

        addTask(studyTask);
    }

    file.close();

    return true;
}