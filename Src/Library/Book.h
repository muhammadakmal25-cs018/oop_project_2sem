#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"

class Book : public LibraryItem {
private:
    string ISBN;
    string genre;
    int copiesAvailable;

public:
    Book(int itemID, string title, string author, int publicationYear, string ISBN, string genre, int copiesAvailable);

    void checkout() override;
    void display() const override;
    string getType() const override;

    string getISBN() const;
    string getGenre() const;
    int getCopiesAvailable() const;
};

#endif