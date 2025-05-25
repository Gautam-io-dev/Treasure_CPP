#include <iostream>
#include <string>

using namespace std;

// Base class: Person
class Person {
protected:
    string name;

public:
    // Constructor
    Person(string n) : name(n) {}

    // Virtual display function for runtime polymorphism
    virtual void display() {
        cout << "Name: " << name << endl;
    }

    // Virtual destructor
    virtual ~Person() {}
};

// Derived class: Student (inherits from Person)
class Student : public Person {
protected:
    string course;
    int marks;
    int year;

public:
    // Constructor
    Student(string n, string c, int m, int y) : Person(n), course(c), marks(m), year(y) {}

    // Overriding display function
    void display() override {
        cout << "\n--- Student Details ---\n";
        cout << "Name: " << name << endl;
        cout << "Course: " << course << endl;
        cout << "Marks: " << marks << endl;
        cout << "Year: " << year << endl;
    }
};

// Derived class: Employee (inherits from Person)
class Employee : public Person {
protected:
    string department;
    double salary;

public:
    // Constructor
    Employee(string n, string dept, double sal) : Person(n), department(dept), salary(sal) {}

    // Overriding display function
    void display() override {
        cout << "\n--- Employee Details ---\n";
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: $" << salary << endl;
    }
};

// Main function
int main() {
    Person *ptr;  // Pointer to base class (for runtime polymorphism)

    // Creating a Student object dynamically
    Student s("Alice", "Computer Science", 95, 2);
    ptr = &s;
    ptr->display();  // Calls Student's display() due to virtual function

    // Creating an Employee object dynamically
    Employee e("Bob", "HR", 50000);
    ptr = &e;
    ptr->display();  // Calls Employee's display() due to virtual function

    return 0;
}