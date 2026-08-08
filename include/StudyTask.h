#ifndef STUDYTASK_H
#define STUDYTASK_H

#include <string>

using namespace std;

class StudyTask
{
private:
    string subject;
    string task;
    string date;
    string duration;
    bool completed;

public:
    StudyTask();

    StudyTask(
        string subject,
        string task,
        string date,
        string duration,
        bool completed = false
    );

    string getSubject() const;
    string getTask() const;
    string getDate() const;
    string getDuration() const;
    bool isCompleted() const;

    void setSubject(string subject);
    void setTask(string task);
    void setDate(string date);
    void setDuration(string duration);
    void setCompleted(bool completed);

    void displayTask() const;
};

#endif