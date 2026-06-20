#include <iostream>
using namespace std;

// ================= MODULE 1 =================
#include "person/Student.h"
#include "person/Faculty.h"
#include "person/Staff.h"

// ================= MODULE 2 =================
#include "course/Course.h"
#include "course/Enrollment.h"

// ================= MODULE 3 =================
#include "library/Library.h"

// ================= MODULE 4 =================
#include "finance/FeeRecord.h"
#include "finance/Invoice.h"

// ================= MODULE 5 =================
#include "HostelManagement/HostelManager.h"

// ================= MODULE 6 =================
#include "Reports&Utilities/Reports.h"
#include "Reports&Utilities/Utils.h"

int main() {
    system("color 08");
    cout << "=========================================\n";
    cout << "   STUDENT CAMPUS MANAGEMENT SYSTEM\n";
    cout << "=========================================\n";

    // =========================================================
    // MODULE 1 : PERSON MANAGEMENT
    // =========================================================
    cout << "\n\n========== MODULE 1 : PERSON MANAGEMENT ==========\n";

    Student s1("Ali Khan", "12345-1111111-1", 20, "03001234567", "23-CS-01", 3, 3.8);

    Student s2("Ahmed Raza", "12345-2222222-2", 21, "03007654321","23-CS-02", 4, 3.2);

    Faculty f1("Dr. Hamza", "11111-1111111-1", 40, "03112223333", "F101", "Computer Science", "Professor");

    Staff st1("Usman", "22222-2222222-2", 35, "03221112222","S101", "Lab Assistant", 50000);

    s1.displayInfo();
    s2.displayInfo();
    f1.displayInfo();
    st1.displayInfo();

    // =========================================================
    // MODULE 2 : COURSE & ENROLLMENT
    // =========================================================
    cout << "\n\n========== MODULE 2 : COURSE & ENROLLMENT ==========\n";

    Course c1("CS101", "Object Oriented Programming", 3, &f1, 1);
    Course c2("CS102", "Digital Logic Design", 3, &f1, 2);

    try {
        c1.enrollStudent(&s1);
        c1.enrollStudent(&s2);   // exceeds capacity -> waiting list
    }
    catch (CapacityExceededException e) {
        e.showError();
    }

    cout << c1;
    c1.showEnrolledStudents();
    c1.showWaitingList();

    Enrollment e1(&s1, &c1, "20-06-2026", 'A');
    Enrollment e2(&s2, &c2, "20-06-2026", 'B');

    e1.displayEnrollment();
    e2.displayEnrollment();

    // =========================================================
    // MODULE 3 : LIBRARY MANAGEMENT
    // =========================================================
    cout << "\n\n========== MODULE 3 : LIBRARY MANAGEMENT ==========\n";

    Library lib;

    lib.addItem(new Book(1, "C++ Basics", "Bjarne Stroustrup", 2020, "ISBN101", "Programming", 2));

    lib.addItem(new Journal(2, "AI Journal", "John Smith", 2024, "ISSN202", 5, 2));

    lib.displayAllItems();

    cout << "\nSearching book by title:\n";
    lib.searchByTitle("C++ Basics");

    cout << "\nIssuing item:\n";
    lib.issueItem("23-CS-01", 1);

    try {
        cout << "\nReturning item with late days:\n";
        lib.returnItem("23-CS-01", 1, 3);   // fine will be generated
    }
    catch (OverdueException e) {
        e.showError();
    }

    lib.saveToFile("library.txt");

    // =========================================================
    // MODULE 4 : FEE & FINANCE MANAGEMENT
    // =========================================================
    cout << "\n\n========== MODULE 4 : FEE & FINANCE MANAGEMENT ==========\n";

    FeeRecord fr1(&s1, 50000, 15000, 500, 30000);
    FeeRecord fr2(&s2, 50000, 15000, 0, 40000);

    fr1.displayFeeRecord();
    fr2.displayFeeRecord();

    cout << "\nPayment of 10000 added for Ali Khan:\n";
    fr1 -= 10000;
    fr1.displayFeeRecord();

    Invoice inv("20-06-2026", 3);
    inv.setItem(0, "Semester Fee");
    inv.setItem(1, "Hostel Fee");
    inv.setItem(2, "Library Fine");
    inv.setTotalAmount(65500);

    cout << inv;

    // =========================================================
    // MODULE 5 : HOSTEL MANAGEMENT
    // =========================================================
    cout << "\n\n========== MODULE 5 : HOSTEL MANAGEMENT ==========\n";

    HostelBlock hb("A Block", 3);

    hb.setRoom(0, Room(101, "single", 1));
    hb.setRoom(1, Room(102, "double", 1));
    hb.setRoom(2, Room(201, "triple", 2));

    HostelManager hm(hb);

    hm.allocateRoom(&s1, 101);
    hm.allocateRoom(&s2, 102);

    cout << "\nHostel Report after allocation:\n";
    hm.generateReport();

    cout << "\nVacating room 102 for Ahmed:\n";
    hm.vacateRoom(&s2, 102);

    cout << "\nHostel Report after vacating:\n";
    hm.generateReport();

    // =========================================================
    // MODULE 6 : REPORTS & UTILITIES
    // =========================================================
    cout << "\n\n========== MODULE 6 : REPORTS & UTILITIES ==========\n";

    Student* students[2] = { &s1, &s2 };

    cout << "\n----- Student Report -----\n";
    Reports::studentReport(students, 2);

    FeeRecord records[2] = { fr1, fr2 };
    cout << "\n----- Fee Report -----\n";
    Reports::feeReport(records, 2);

    cout << "\n----- Library Report -----\n";
    Reports::libraryReport(lib);

    cout << "\nSorting students by GPA...\n";
    Utils::sortStudentsByGPA(students, 2);

    cout << "\nStudent Report after GPA sorting:\n";
    Reports::studentReport(students, 2);

    cout << "\nSearching student by Roll No 23-CS-01:\n";
    Utils::searchStudentByRollNo(students, 2, "23-CS-01");

    cout << "\n=========================================\n";
    cout << "   SCMS PROJECT EXECUTED SUCCESSFULLY\n";
    cout << "=========================================\n";

    return 0;
}