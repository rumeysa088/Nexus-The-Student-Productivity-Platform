#include "Note.h"
#include <iostream>

using namespace std;

Note::Note()
{
    title = "";
    courseCode = "";
    content = "";
}

Note::Note(string title,
           string courseCode,
           string content)
{
    this->title = title;
    this->courseCode = courseCode;
    this->content = content;
}

string Note::getTitle() const
{
    return title;
}

string Note::getCourseCode() const
{
    return courseCode;
}

string Note::getContent() const
{
    return content;
}

void Note::setTitle(string title)
{
    this->title = title;
}

void Note::setCourseCode(string courseCode)
{
    this->courseCode = courseCode;
}

void Note::setContent(string content)
{
    this->content = content;
}

void Note::displayNote() const
{
    cout << "\n========== NOTE ==========\n";
    cout << "Title       : " << title << endl;
    cout << "Course Code : " << courseCode << endl;
    cout << "Content     : " << content << endl;
}