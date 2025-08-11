#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    float marks[3];
    float total;
    float average;

public:
    // Constructor to initialize and input student data
    Student() {
        rollNumber = 0;
        name = "";
        for (int i = 0; i < 3; i++)
            marks[i] = 0.0f;
        total = 0.0f;
        average = 0.0f;
    }

    void input() {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cin.ignore(); // clear newline from buffer
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter marks for 3 subjects: ";
        total = 0;
        for (int i = 0; i < 3; i++) {
            cin >> marks[i];
            total += marks[i];
        }
        average = total / 3;
    }

    void display() const {
        cout << "Roll Number: " << rollNumber << "\n";
        cout << "Name: " << name << "\n";
        cout << "Marks: ";
        for (int i = 0; i < 3; i++)
            cout << marks[i] << " ";
        cout << "\nTotal: " << total << "\n";
        cout << "Average: " << average << "\n";
        cout << "-------------------------\n";
    }

    float getAverage() const {
        return average;
    }

    int getRollNumber() const {
        return rollNumber;
    }

    string getName() const {
        return name;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student* students = new Student[n];

    // Input student data
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        students[i].input();
    }

    cout << "\n--- Student Details ---\n";
    for (int i = 0; i < n; i++) {
        students[i].display();
    }

    // Find student with highest average
    int highestIndex = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].getAverage() > students[highestIndex].getAverage()) {
            highestIndex = i;
        }
    }

    cout << "\nStudent with highest average:\n";
    cout << "Roll Number: " << students[highestIndex].getRollNumber() << "\n";
    cout << "Name: " << students[highestIndex].getName() << "\n";
    cout << "Average Marks: " << students[highestIndex].getAverage() << "\n";

    delete[] students;
    return 0;
}

