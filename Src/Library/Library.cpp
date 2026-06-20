#include "Library.h"

Library::~Library() {
    for (auto item : catalog)
        delete item;
}

void Library::addItem(LibraryItem* item) {
    catalog.push_back(item);
}

void Library::displayAllItems() const {
    cout << "\n===== LIBRARY CATALOG =====\n";
    for (auto item : catalog)
        item->display();
}

void Library::searchByTitle(string t) const {
    bool found = false;
    for (auto item : catalog) {
        if (item->getTitle() == t) {
            cout << "\nItem Found:\n";
            item->display();
            found = true;
        }
    }
    if (!found)
        cout << "No item found with title: " << t << endl;
}

void Library::issueItem(string rollNo, int itemID) {
    for (auto item : catalog) {
        if (item->getItemID() == itemID) {
            item->checkout();
            issuedItems.push_back({rollNo, itemID});
            return;
        }
    }
    cout << "Item not found!\n";
}

void Library::returnItem(string rollNo, int itemID, int lateDays) {
    cout << "Returning item ID " << itemID << " by " << rollNo << endl;
    if (lateDays > 0) {
        double fine = lateDays * 20;
        throw OverdueException(fine);
    }
}

void Library::saveToFile(string filename) {
    ofstream fout(filename);
    if (!fout) {
        cout << "File cannot open!\n";
        return;
    }

    for (auto item : catalog) {
        if (item->getType() == "Book") {
            Book* b = dynamic_cast<Book*>(item);
            fout << "Book,"
                 << b->getItemID() << ","
                 << b->getTitle() << ","
                 << b->getAuthor() << ","
                 << b->getYear() << ","
                 << b->getISBN() << ","
                 << b->getGenre() << ","
                 << b->getCopiesAvailable() << endl;
        }
        else if (item->getType() == "Journal") {
            Journal* j = dynamic_cast<Journal*>(item);
            fout << "Journal,"
                 << j->getItemID() << ","
                 << j->getTitle() << ","
                 << j->getAuthor() << ","
                 << j->getYear() << ","
                 << j->getISSN() << ","
                 << j->getVolume() << ","
                 << j->getIssueNumber() << endl;
        }
    }

    fout.close();
    cout << "Catalog saved successfully.\n";
}

void Library::loadFromFile(string filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "File cannot open!\n";
        return;
    }

    for (auto item : catalog)
        delete item;
    catalog.clear();

    string type;
    while (getline(fin, type, ',')) {
        if (type == "Book") {
            string idStr, title, author, yearStr, isbn, genre, copiesStr;
            getline(fin, idStr, ',');
            getline(fin, title, ',');
            getline(fin, author, ',');
            getline(fin, yearStr, ',');
            getline(fin, isbn, ',');
            getline(fin, genre, ',');
            getline(fin, copiesStr);

            addItem(new Book(stoi(idStr), title, author, stoi(yearStr),
                             isbn, genre, stoi(copiesStr)));
        }
        else if (type == "Journal") {
            string idStr, title, author, yearStr, issn, volStr, issueStr;
            getline(fin, idStr, ',');
            getline(fin, title, ',');
            getline(fin, author, ',');
            getline(fin, yearStr, ',');
            getline(fin, issn, ',');
            getline(fin, volStr, ',');
            getline(fin, issueStr);

            addItem(new Journal(stoi(idStr), title, author, stoi(yearStr),
                                issn, stoi(volStr), stoi(issueStr)));
        }
    }

    fin.close();
    cout << "Catalog loaded successfully.\n";
}