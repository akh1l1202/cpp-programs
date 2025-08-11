#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks[3];
    float total;
    float average;
    char grade;
    static int count;  // static member to count number of students

    void calculateTotalAndAverage() {
        total = 0;
        for(int i = 0; i < 3; i++) {
            total += marks[i];
        }
        average = total / 3.0f;
        assignGrade();
    }

    void assignGrade() {
        if(average >= 90) grade = 'A';
        else if(average >= 75) grade = 'B';
        else grade = 'C';
    }

public:
    // Default constructor
    Student() {
        rollNo = 0;
        name = "";
        total = 0;
        average = 0;
        grade = 'C';
        for (int i = 0; i < 3; i++) marks[i] = 0;
        count++;
    }

    // Parameterized input function
    void input() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore();  // to clear newline from input buffer
        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter marks for 3 subjects: ";
        for(int i = 0; i < 3; i++) {
            cin >> marks[i];
        }
        calculateTotalAndAverage();
    }

    void display() const {
        cout << "Roll No: " << rollNo << "\n";
        cout << "Name: " << name << "\n";
        cout << "Marks: ";
        for(int i = 0; i < 3; i++) {
            cout << marks[i] << " ";
        }
        cout << "\nTotal: " << total << "\n";
        cout << "Average: " << average << "\n";
        cout << "Grade: " << grade << "\n";
        cout << "---------------------------\n";
    }

    float getAverage() const {
        return average;
    }

    float getTotal() const {
        return total;
    }

    int getRollNo() const {
        return rollNo;
    }

    static int getCount() {
        return count;
    }
};

// Initialize static member
int Student::count = 0;

// Function to display all students
void displayAllStudents(Student* students, int n) {
    cout << "\n*** All Student Records ***\n";
    for (int i = 0; i < n; i++) {
        students[i].display();
    }
}

// Function to find student with highest average
Student* studentWithHighestAverage(Student* students, int n) {
    if(n == 0) return nullptr;
    Student* topStudent = &students[0];
    for (int i = 1; i < n; i++) {
        if (students[i].getAverage() > topStudent->getAverage()) {
            topStudent = &students[i];
        }
    }
    return topStudent;
}

// Variation #2: Sort students by total marks in descending order
void sortByTotalDescending(Student* students, int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1-i; j++) {
            if(students[j].getTotal() < students[j+1].getTotal()) {
                swap(students[j], students[j+1]);
            }
        }
    }
}

// Variation #5: Search student by roll number
Student* searchByRollNo(Student* students, int n, int rollNo) {
    for(int i = 0; i < n; i++) {
        if(students[i].getRollNo() == rollNo) {
            return &students[i];
        }
    }
    return nullptr;
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student* students = new Student[n];  // dynamic allocation

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i+1 << ":\n";
        students[i].input();
    }

    displayAllStudents(students, n);

    Student* topStudent = studentWithHighestAverage(students, n);
    if(topStudent != nullptr) {
        cout << "\nStudent with highest average:\n";
        topStudent->display();
    }

    // Sort by total marks descending
    sortByTotalDescending(students, n);
    cout << "\nStudents sorted by total marks (descending):\n";
    displayAllStudents(students, n);

    // Search student by roll number
    int searchRollNo;
    cout << "Enter roll number to search: ";
    cin >> searchRollNo;
    Student* foundStudent = searchByRollNo(students, n, searchRollNo);
    if(foundStudent != nullptr) {
        cout << "\nStudent found:\n";
        foundStudent->display();
    } else {
        cout << "Student with roll number " << searchRollNo << " not found.\n";
    }

    cout << "Total Student objects created: " << Student::getCount() << "\n";

    delete[] students;
    return 0;
}
