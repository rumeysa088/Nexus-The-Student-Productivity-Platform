#ifndef ASSIGNMENTMANAGER_H
#define ASSIGNMENTMANAGER_H

#include "Assignment.h"
#include <string>

using namespace std;

const int MAX_ASSIGNMENTS = 20;

class AssignmentManager
{
private:
    Assignment assignments[MAX_ASSIGNMENTS];
    int totalAssignments;

public:
    AssignmentManager();

    bool addAssignment(const Assignment &assignment);

    void displayAssignments() const;

    bool deleteAssignment(int index);

    bool markCompleted(int index);

    int getTotalAssignments() const;

    const Assignment& getAssignment(int index) const;

    bool saveAssignments(string username);

    bool loadAssignments(string username);

    void clearAssignments();
};

#endif