#include <iostream>
#include <fstream>  // File handling
using namespace std;

class Student {
private:
    int rollNo;
    char name[50];
    int classYear;
    float totalMarks;

public:
    // Function to input student details
    void inputStudent() {
        cout << "\nEnter Roll No.: ";
        cin >> rollNo;
        cin.ignore(); // To clear newline from buffer
        cout << "Enter Name: ";
        cin.getline(name, 50);
        cout << "Enter Class Year: ";
        cin >> classYear;
        cout << "Enter Total Marks: ";
        cin >> totalMarks;
    }

    // Function to display student details
    void displayStudent() const {
        cout << "\nRoll No.: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nClass Year: " << classYear;
        cout << "\nTotal Marks: " << totalMarks << endl;
    }

    // Function to write student data to file
    void writeToFile() {
        ofstream file("students.dat", ios::binary | ios::app);
        if (!file) {
            cout << "Error: Could not open file!\n";
            return;
        }
        file.write(reinterpret_cast<char*>(this), sizeof(*this));
        file.close();
    }

    // Function to read student data from file
    static void readFromFile() {
        ifstream file("students.dat", ios::binary);
        if (!file) {
            cout << "Error: Could not open file or file does not exist!\n";
            return;
        }

        Student s;
        cout << "\nStudent Records from File:\n";
        while (file.read(reinterpret_cast<char*>(&s), sizeof(s))) {
            s.displayStudent();
        }
        file.close();
    }
};

// Main function
int main() {
    Student s;
    int n = 5; // Number of students

    cout << "Enter details of " << n << " students:\n";
    for (int i = 0; i < n; i++) {
        s.inputStudent();
        s.writeToFile();
    }

    // Reading and displaying student records from file
    cout << "\nRetrieving data from file...\n";
    Student::readFromFile();

    return 0;
}