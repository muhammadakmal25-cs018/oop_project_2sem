#include <iostream>
using namespace std;

class Student {
public:
    string name;
    float gpa;

    Student() {
        name = "";
        gpa = 0;
    }
    Student(string n,float g) {
        name=n;
        gpa=g;
    }
};
class Reports {
public:
    static void generateReport(Student students[], int size) {
        cout << "\n===== CAMPUS REPORT =====\n";

        for (int i=0;i<size;i++) {
            cout<<students[i].name<<" GPA: "<<students[i].gpa<<endl;
        }
    }
};
class Utils {
public:
    static void sortByGPA(Student students[],int size) {
        for (int i=0;i<size - 1; i++) {
            for (int j=i+1;j<size;j++) {
                if (students[i].gpa<students[j].gpa) {
                    swap(students[i],students[j]);
                }
            }
        }
    }
    static void searchStudent(Student students[], int size,string name) {
        for (int i=0;i<size;i++) {
            if (students[i].name == name) {
                cout<<"\nStudent Found\n";
                cout<<students[i].name<<" GPA: "<<students[i].gpa<<endl;
                return;
            }
        }
        cout << "\nStudent Not Found\n";
    }
};
int main() {

    Student* students = new Student[3];

    students[0] = Student("Ali", 3.4);
    students[1] = Student("Ahmed", 3.9);
    students[2] = Student("Usman", 3.2);

    Utils::sortByGPA(students, 3);

    Reports::generateReport(students, 3);

    Utils::searchStudent(students, 3, "Ahmed");
    delete[] students;

    return 0;
}