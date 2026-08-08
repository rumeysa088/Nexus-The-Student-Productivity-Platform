#include "NoteManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

NoteManager::NoteManager()
{
    totalNotes = 0;
}

bool NoteManager::addNote(const Note &note)
{
    if(totalNotes >= MAX_NOTES)
    {
        return false;
    }

    notes[totalNotes] = note;
    totalNotes++;

    return true;
}

void NoteManager::displayNotes() const
{
    if(totalNotes == 0)
    {
        cout << "\nNo notes available.\n";
        return;
    }

    cout << "\n========== MY NOTES ==========\n";

    for(int i = 0; i < totalNotes; i++)
    {
        cout << "\nNote #" << i + 1;
        notes[i].displayNote();
    }
}

bool NoteManager::deleteNote(int index)
{
    if(index < 0 || index >= totalNotes)
    {
        return false;
    }

    for(int i = index; i < totalNotes - 1; i++)
    {
        notes[i] = notes[i + 1];
    }

    totalNotes--;

    return true;
}

int NoteManager::getTotalNotes() const
{
    return totalNotes;
}

const Note& NoteManager::getNote(int index) const
{
    return notes[index];
}

void NoteManager::clearNotes()
{
    totalNotes = 0;
}

bool NoteManager::saveNotes(string username)
{
    string filename = "data/notes/" + username + ".txt";

    ofstream file(filename);

    if(!file)
    {
        return false;
    }

    for(int i = 0; i < totalNotes; i++)
    {
        file << notes[i].getTitle() << "|"
             << notes[i].getCourseCode() << "|"
             << notes[i].getContent()
             << endl;
    }

    file.close();

    return true;
}

bool NoteManager::loadNotes(string username)
{
    clearNotes();

    string filename = "data/notes/" + username + ".txt";

    ifstream file(filename);

    if(!file)
    {
        return false;
    }

    string line;

    while(getline(file, line))
    {
        stringstream ss(line);

        string title;
        string courseCode;
        string content;

        getline(ss, title, '|');
        getline(ss, courseCode, '|');
        getline(ss, content);

        Note note(
            title,
            courseCode,
            content
        );

        addNote(note);
    }

    file.close();

    return true;
}