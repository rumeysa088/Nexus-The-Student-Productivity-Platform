#include "StudyTask.h"
#include <iostream>

using namespace std;

StudyTask::StudyTask()
{
    subject = "";
    task = "";
    date = "";
    duration = "";
    completed = false;
}

StudyTask::StudyTask(
    string subject,
    string task,
    string date,
    string duration,
    bool completed
)
{
    this->subject = subject;
    this->task = task;
    this->date = date;
    this->duration = duration;
    this->completed = completed;
}

string StudyTask::getSubject() const
{
    return subject;
}

string StudyTask::getTask() const
{
    return task;
}

string StudyTask::getDate() const
{
    return date;
}

string StudyTask::getDuration() const
{
    return duration;
}

bool StudyTask::isCompleted() const
{
    return completed;
}

void StudyTask::setSubject(string subject)
{
    this->subject = subject;
}

void StudyTask::setTask(string task)
{
    this->task = task;
}

void StudyTask::setDate(string date)
{
    this->date = date;
}

void StudyTask::setDuration(string duration)
{
    this->duration = duration;
}

void StudyTask::setCompleted(bool completed)
{
    this->completed = completed;
}

void StudyTask::displayTask() const
{
    cout << "\n-----------------------------\n";
    cout << "Subject  : " << subject << endl;
    cout << "Task     : " << task << endl;
    cout << "Date     : " << date << endl;
    cout << "Duration : " << duration << endl;
    cout << "Status   : ";

    if(completed)
        cout << "Completed" << endl;
    else
        cout << "Pending" << endl;

    cout << "-----------------------------\n";
}