#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <iostream>
#include <string>
using namespace std;

class LibraryItem {
protected:
    int itemID;
    string title;
    string author;
    int publicationYear;

public:
    LibraryItem(int itemID, string title, string author, int publicationYear);
    virtual ~LibraryItem();

    virtual void checkout() = 0;
    virtual void display() const = 0;
    virtual string getType() const = 0;

    int getItemID() const;
    string getTitle() const;
    string getAuthor() const;
    int getYear() const;
};

#endif