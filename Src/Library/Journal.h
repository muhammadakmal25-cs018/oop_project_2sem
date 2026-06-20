#ifndef JOURNAL_H
#define JOURNAL_H

#include "LibraryItem.h"

class Journal : public LibraryItem {
private:
    string ISSN;
    int volume;
    int issueNumber;

public:
    Journal(int itemID, string title, string author, int publicationYear, string ISSN, int volume, int issueNumber);

    void checkout() override;
    void display() const override;
    string getType() const override;

    string getISSN() const;
    int getVolume() const;
    int getIssueNumber() const;
};

#endif