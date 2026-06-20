#include "Invoice.h"

int Invoice::invoiceCounter = 1000;

Invoice::Invoice(string date, int itemCount) {
    invoiceID = ++invoiceCounter;
    this->date = date;
    this->itemCount = itemCount;
    totalAmount = 0;

    if (itemCount > 0)
        items = new string[itemCount];
    else
        items = nullptr;
}

Invoice::Invoice(const Invoice& other) {
    invoiceID = other.invoiceID;
    date = other.date;
    itemCount = other.itemCount;
    totalAmount = other.totalAmount;

    if (itemCount > 0) {
        items = new string[itemCount];
        for (int i = 0; i < itemCount; i++)
            items[i] = other.items[i];
    } else {
        items = nullptr;
    }
}

Invoice& Invoice::operator=(const Invoice& other) {
    if (this != &other) {
        delete[] items;

        invoiceID = other.invoiceID;
        date = other.date;
        itemCount = other.itemCount;
        totalAmount = other.totalAmount;

        if (itemCount > 0) {
            items = new string[itemCount];
            for (int i = 0; i < itemCount; i++)
                items[i] = other.items[i];
        } else {
            items = nullptr;
        }
    }
    return *this;
}

Invoice::~Invoice() {
    delete[] items;
}

void Invoice::setItem(int index, string item) {
    if (index >= 0 && index < itemCount)
        items[index] = item;
}

void Invoice::setTotalAmount(double totalAmount) {
    this->totalAmount = totalAmount;
}

void Invoice::displayInvoice() const {
    cout << "\n===== Invoice =====\n";
    cout << "Invoice ID: " << invoiceID << endl;
    cout << "Date: " << date << endl;
    cout << "Items:\n";
    for (int i = 0; i < itemCount; i++)
        cout << "- " << items[i] << endl;
    cout << "Total Amount: " << totalAmount << endl;
}

ostream& operator<<(ostream& out, const Invoice& inv) {
    out << "\n===== Invoice =====\n";
    out << "Invoice ID: " << inv.invoiceID << endl;
    out << "Date: " << inv.date << endl;
    out << "Items:\n";
    for (int i = 0; i < inv.itemCount; i++)
        out << "- " << inv.items[i] << endl;
    out << "Total Amount: " << inv.totalAmount << endl;
    return out;
}