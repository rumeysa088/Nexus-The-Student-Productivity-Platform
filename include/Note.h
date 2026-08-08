#ifndef NOTE_H
#define NOTE_H

#include <string>

using namespace std;

class Note
{
private:
    string title;
    string courseCode;
    string content;

public:
    Note();

    Note(string title,
         string courseCode,
         string content);

    string getTitle() const;
    string getCourseCode() const;
    string getContent() const;

    void setTitle(string title);
    void setCourseCode(string courseCode);
    void setContent(string content);

    void displayNote() const;
};

#endif