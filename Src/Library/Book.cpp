#include "Book.h"

Book::Book(int itemID, string title, string author, int publicationYear, string ISBN, string genre, int copiesAvailable)
    : LibraryItem(itemID, title, author, publicationYear) {
    this->ISBN = ISBN;
    this->genre = genre;
    this->copiesAvailable = copiesAvailable;
}

void Book::checkout() {
    if (copiesAvailable > 0) {
        copiesAvailable--;
        cout << "Book issued successfully: " << title << endl;
    } else {
        cout << "No copies available for " << title << endl;
    }
}

void Book::display() const {
    cout << "\n[Book]\n";
    cout << "ID: " << itemID << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Year: " << publicationYear << endl;
    cout << "ISBN: " << ISBN << endl;
    cout << "Genre: " << genre << endl;
    cout << "Copies Available: " << copiesAvailable << endl;
}

string Book::getType() const {
    return "Book";
}

string Book::getISBN() const {
    return ISBN;
}

string Book::getGenre() const {
    return genre;
}

int Book::getCopiesAvailable() const {
    return copiesAvailable;
}