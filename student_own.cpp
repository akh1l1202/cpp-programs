#include <iostream>
using namespace std;

class student {
private:
    int rno;
    string name;
    float marks[3];
    float total;
    float average;

public:
    student() {
        rno = 0;
        name = "";
        marks[0] = 0.0, marks[1] = 0.0, marks[2] = 0.0;
        total = 0.0;
        average = 0.0;
    }

    void input() {
        cout<<"Enter Roll Number: ";
        cin>>rno;
        cout<<"Enter Name: ";
        cin>>name;
        cout<<"Enter marks of 3 subjects: ";
        total = 0;

        cout<<"Enter Name: "<<name<<"\n";
        cout<<"Enter Marks of 3 subjects: ";
        for (int i=0;i<3;i++) {
            cin>>marks[i];
            total+=marks[i];
        }
        average = total/3.0;
    }

    void display() {
        cout<<"Roll Number: "<<rno<<"\n";
        cout<<"Name: "<<name<<"\n";
        cout<<"Marks: ";
        for (int i=0;i<3;i++) {
            cout<<marks[i]<<" ";
        }
        cout<<"\nTotal: "<<total<<"\n";
        cout<<"Average: "<<average<<"\n";
        cout<<"LOLOLOLOLOLOLOLOLOLOLOLOLOLOLOOLOLOLOLOLOLOLOLOLOLOLOLO\n";
    }
};

int main() {
    int n;
    cout<<"Enter number of students: ";
    cin>>n;

    student* students = new student[n];

    for (int i=0;i<n;i++) {
        cout<<"Enter details of student "<<i+1<<":\n";
        students[i].input();
    }
}
