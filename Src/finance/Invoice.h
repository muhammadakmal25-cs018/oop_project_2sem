#ifndef INVOICE_H
#define INVOICE_H

#include <iostream>
#include <string>
using namespace std;

class Invoice {
private:
    static int invoiceCounter;
    int invoiceID;
    string date;
    string* items;
    int itemCount;
    double totalAmount;

public:
    Invoice(string date = "", int itemCount = 0);
    Invoice(const Invoice& other);
    Invoice& operator=(const Invoice& other);
    ~Invoice();

    void setItem(int index, string item);
    void setTotalAmount(double totalAmount);
    void displayInvoice() const;

    friend ostream& operator<<(ostream& out, const Invoice& inv);
};

#endif