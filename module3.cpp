                 // module for library management system--
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class overdueException{
    private:
    double fine;
    public:
    overdueException(double f):fine(f){}
void showError(){
    cout<<"Book is overdue! Fine Amount is: "<<fine<<endl;
}
};

class LibraryItem{
    protected:
    int item_id;
    string title;
    string auther;
    int publication_year;
public:
    LibraryItem(int id,string t,string a,int py):item_id(id),title(t),auther(a),publication_year(py){}
    virtual void checkOut()=0;
    string get_title(){
        return title;
    }
    int getitem_id(){
        return item_id;
    }
    virtual void display()=0;
    virtual ~LibraryItem(){}
};

class Book:public LibraryItem{
    private:
    string isbn;
    string genre;
    int copies_available;
public:
    Book(int id,string t,string a,int py,string isbn,string genre,int copies):LibraryItem(id,t,a,py),isbn(isbn),genre(genre),copies_available(copies){}
void checkOut() override{
    if(copies_available>0){
        copies_available--;
        cout<<"Book Issued : "<<endl;
    }
    else{
        cout<<"No copies available for "<<endl;
    }
}
void display()override{
    cout<<"---Book Information---"<<endl;
    cout<<"Title: "<<title<<endl;
    cout<<"id: "<<item_id<<endl;
    cout<<"Author: "<<auther<<endl;
    cout<<"ISBN: "<<isbn<<endl;
    cout<<"Copies Available: "<<copies_available<<endl;
}
};
class journal:public LibraryItem{
    private:
    string issn;
    int volume,issue_number;
    public:
    journal(int id,string t,string a,int py,string issn,int vol,int issue):LibraryItem(id,t,a,py),issn(issn),volume(vol),issue_number(issue){}

void checkOut() override{
    cout<<"Journal issued successfully."<<endl;
}
void display() override{
    cout<<"---Journal Information---"<<endl;
    cout<<"Title: "<<title<<endl;
    cout<<"id: "<<item_id<<endl;
    cout<<"Author: "<<auther<<endl;
    cout<<"ISSN: "<<issn<<endl;
    cout<<"Volume: "<<volume<<endl;
    cout<<"Issue Number: "<<issue_number<<endl;
}
};
// issue record structure
struct IssueRecord{
    string roll_no;
    int item_id;
};
class library{
    LibraryItem* items[20];
    int item_count;
    IssueRecord issue_records[20];
    int record_count;
public:
    library():item_count(0),record_count(0){}
    void addItem(LibraryItem* item){
        if(item_count<20){
            items[item_count++]=item;
            cout<<"Item added successfully."<<endl;
        }
        else{
            cout<<"Library is full. Cannot add more items."<<endl;
        }
    }
    
    void searchItem(string title){
        bool found=false;
        for(int i=0;i<item_count;i++){
            if(items[i]->get_title()==title){
                items[i]->display();
                found=true;
            }
        }
        if(!found){
            cout<<"Item not found in library."<<endl;
        }
    }
void issueItem(string roll_no,int item_id){
       issue_records[record_count].roll_no=roll_no;
       issue_records[record_count].item_id=item_id;
         record_count++;
            }
    void savetoFile(){
        ofstream file("library_records.txt");
        if(file.is_open()){
            for(int i=0;i<record_count;i++){
                file<<issue_records[i].roll_no<<" "<<issue_records[i].item_id<<endl;
            }
            file.close();
            cout<<"Records saved to file successfully."<<endl;
        }
        else{
            cout<<"Error opening file for writing."<<endl;
        }
    }
    void loadfromFile(){
        ifstream file("library_records.txt");
        if(file.is_open()){
            record_count=0;
            while(file>>issue_records[record_count].roll_no>>issue_records[record_count].item_id){
                record_count++;
            }
            file.close();
            cout<<"Records loaded from file successfully."<<endl;
        }
        else{
            cout<<"Error opening file for reading."<<endl;
        }
    }
    void checkOverdue(int dayslate){
        if(dayslate>0){
            double fine=dayslate*20;
            throw overdueException(fine);
        }
    }
    ~library(){
        for(int i=0;i<item_count;i++){
            delete items[i];
        }
    }
};
int main(){
    library lib;
    lib.addItem(new Book(1,"The Great Gatsby","F. Scott Fitzgerald",1925,"978-0743273565","Fiction",5));
    lib.addItem(new journal(2,"Nature","Various",2020,"0028-0836",678,12));
    lib.searchItem("The Great Gatsby"); 
    lib.issueItem("12345",1);
    lib.savetoFile();
    lib.loadfromFile();
try{
    lib.checkOverdue(5);
}
catch(overdueException& e){
    e.showError();
}
    return 0;
}
