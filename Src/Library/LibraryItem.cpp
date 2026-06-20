#include "LibraryItem.h"

LibraryItem::LibraryItem(int itemID, string title, string author, int publicationYear) {
    this->itemID = itemID;
    this->title = title;
    this->author = author;
    this->publicationYear = publicationYear;
}

LibraryItem::~LibraryItem() {}

int LibraryItem::getItemID() const {
    return itemID;
}

string LibraryItem::getTitle() const {
    return title;
}

string LibraryItem::getAuthor() const {
    return author;
}

int LibraryItem::getYear() const {
    return publicationYear;
}