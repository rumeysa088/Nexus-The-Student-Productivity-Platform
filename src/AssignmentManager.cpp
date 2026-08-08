#include "AssignmentManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

AssignmentManager::AssignmentManager()
{
    totalAssignments = 0;
}

bool AssignmentManager::addAssignment(const Assignment &assignment)
{
    if (totalAssignments >= MAX_ASSIGNMENTS)
    {
        return false;
    }

    assignments[totalAssignments] = assignment;
    totalAssignments++;

    return true;
}

void AssignmentManager::displayAssignments() const
{
    if (totalAssignments == 0)
    {
        cout << "\nNo assignments available.\n";
        return;
    }

    cout << "\n========== MY ASSIGNMENTS ==========\n";

    for (int i = 0; i < totalAssignments; i++)
    {
        cout << "\nAssignment #" << i + 1;
        assignments[i].displayAssignment();
    }
}

bool AssignmentManager::deleteAssignment(int index)
{
    if (index < 0 || index >= totalAssignments)
    {
        return false;
    }

    for (int i = index; i < totalAssignments - 1; i++)
    {
        assignments[i] = assignments[i + 1];
    }

    totalAssignments--;

    return true;
}

bool AssignmentManager::markCompleted(int index)
{
    if (index < 0 || index >= totalAssignments)
    {
        return false;
    }

    assignments[index].setCompleted(true);

    return true;
}

int AssignmentManager::getTotalAssignments() const
{
    return totalAssignments;
}

const Assignment& AssignmentManager::getAssignment(int index) const
{
    return assignments[index];
}

void AssignmentManager::clearAssignments()
{
    totalAssignments = 0;
}

bool AssignmentManager::saveAssignments(string username)
{
    string filename = "data/assignments/" + username + ".txt";

    ofstream file(filename);

    if (!file)
    {
        return false;
    }

    for (int i = 0; i < totalAssignments; i++)
    {
        file << assignments[i].getTitle() << "|"
             << assignments[i].getCourseCode() << "|"
             << assignments[i].getDueDate() << "|"
             << assignments[i].getPriority() << "|"
             << assignments[i].isCompleted()
             << endl;
    }

    file.close();

    return true;
}

bool AssignmentManager::loadAssignments(string username)
{
    clearAssignments();

    string filename = "data/assignments/" + username + ".txt";

    ifstream file(filename);

    if (!file)
    {
        return false;
    }

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string title;
        string courseCode;
        string dueDate;
        string priority;
        string completedString;

        getline(ss, title, '|');
        getline(ss, courseCode, '|');
        getline(ss, dueDate, '|');
        getline(ss, priority, '|');
        getline(ss, completedString);

        bool completed = (completedString == "1");

        Assignment assignment(
            title,
            courseCode,
            dueDate,
            priority,
            completed
        );

        addAssignment(assignment);
    }

    file.close();

    return true;
}