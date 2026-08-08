#ifndef NOTEMANAGER_H
#define NOTEMANAGER_H

#include "Note.h"
#include <string>

using namespace std;

const int MAX_NOTES = 30;

class NoteManager
{
private:
    Note notes[MAX_NOTES];
    int totalNotes;

public:
    NoteManager();

    bool addNote(const Note &note);

    void displayNotes() const;

    bool deleteNote(int index);

    int getTotalNotes() const;

    const Note& getNote(int index) const;

    bool saveNotes(string username);

    bool loadNotes(string username);

    void clearNotes();
};

#endif