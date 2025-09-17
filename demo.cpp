

#include <iostream>
using namespace std;

class Student {
    string name;
    int age;

public:
    // Default constructor
    Student() {
        name = "Unknown";
        age = 0;
    }

    // Parameterized constructor
    Student(string n, int a) {
        name = n;
        age = a;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {
    // Using default constructor
    Student s1;
    cout << "Default Constructor:" << endl;
    s1.display();
    Student s2("name", 12);
    cout << "Parameterized Constructor:" << endl;
    s2.display();

    // Taking user input
    string n;
    int a;
    cout << "Enter name: ";
    getline(cin, n);
    cout << "Enter age: ";
    cin >> a;

    // Using parameterized constructor
    Student s3(n, a);
    cout << "Parameterized Constructor:" << endl;
    s3.display();

    return 0;
}
