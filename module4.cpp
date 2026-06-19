#include<iostream>
#include<string>
using namespace std;

class Fee_Record{
    private:
    string student_name;
    int sem_fee;
    int hosta_fee;
    int library_fine;
    int total_paid;
    int balance;
public:
Fee_Record(string name,int semfee,int hostalfee,int fine){
    student_name=name;
    sem_fee=semfee;
    hosta_fee=hostalfee;
    library_fine=fine;
    total_paid=0;
    balance=sem_fee+hosta_fee+library_fine;
}
Fee_Record(const Fee_Record &record){
    student_name=record.student_name;
    sem_fee=record.sem_fee;
    hosta_fee=record.hosta_fee;
    library_fine=record.library_fine;
    total_paid=record.total_paid;
    balance=record.balance;
}
    Fee_Record& operator=(const Fee_Record &record){
        if(this!=&record){
            student_name=record.student_name;
            sem_fee=record.sem_fee;
            hosta_fee=record.hosta_fee;
            library_fine=record.library_fine;
            total_paid=record.total_paid;
            balance=record.balance;
        }
        return *this;
    }
    void operator-=(int amount){
        total_paid+=amount;
        balance-=amount;
        if(balance<0){
            balance=0;
        }
    }
        void display(){
            cout<<"Student Name: "<<student_name<<endl;
            cout<<"Semester Fee: "<<sem_fee<<endl;
            cout<<"Hostal Fee: "<<hosta_fee<<endl;
            cout<<"Library Fine: "<<library_fine<<endl;
            cout<<"Total Paid: "<<total_paid<<endl;
            cout<<"Balance: "<<balance<<endl;
        }
};
class Invoice{
    private:
    static int invoice_counter;
    int invoice_id;
    string date;
    string* items;
    int items_count;
    double total_amount;
public:
    Invoice(string d,int count,double amount){
        invoice_id=++invoice_counter;
        date=d;
        items_count=count;
        total_amount=amount;
        items=new string[items_count];
    }
    Invoice(const Invoice &invoice){
        invoice_id=invoice.invoice_id;
        date=invoice.date;
        items_count=invoice.items_count;
        total_amount=invoice.total_amount;
        items=new string[items_count];
        for(int i=0;i<items_count;i++){
            items[i]=invoice.items[i];
        }
    }
    void setitem(int index,string item){
        if(index>=0 && index<items_count){
            items[index]=item;
        }
    }
    void display_invoice(){
        cout<<"Invoice ID: "<<invoice_id<<endl;
        cout<<"Date: "<<date<<endl;
        cout<<"Items: "<<endl;
        for(int i=0;i<items_count;i++){
            cout<<"- "<<items[i]<<endl;
        }
        cout<<"Total Amount: "<<total_amount<<endl;
    }
    ~Invoice(){
        delete[] items;
        cout<<"Invoice Distructor called"<<endl;   
    }
};
int Invoice::invoice_counter =0;

int main(){
            
}