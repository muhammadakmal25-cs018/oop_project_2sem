#include "Journal.h"

Journal::Journal(int itemID, string title, string author, int publicationYear,  string ISSN, int volume, int issueNumber)
    : LibraryItem(itemID, title, author, publicationYear) {
    this->ISSN = ISSN;
    this->volume = volume;
    this->issueNumber = issueNumber;
}

void Journal::checkout() {
    cout << "Journal issued successfully: " << title << endl;
}

void Journal::display() const {
    cout << "\n[Journal]\n";
    cout << "ID: " << itemID << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Year: " << publicationYear << endl;
    cout << "ISSN: " << ISSN << endl;
    cout << "Volume: " << volume << endl;
    cout << "Issue Number: " << issueNumber << endl;
}

string Journal::getType() const {
    return "Journal";
}

string Journal::getISSN() const {
    return ISSN;
}

int Journal::getVolume() const {
    return volume;
}

int Journal::getIssueNumber() const {
    return issueNumber;
}