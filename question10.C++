#include <iostream>
#include <cmath>  // For sqrt()

using namespace std;

class Triangle {
private:
    double base, height, side1, side2, side3;

public:
    // Default Constructor
    Triangle() : base(0), height(0), side1(0), side2(0), side3(0) {}

    // Constructor for base and height
    Triangle(double b, double h) : base(b), height(h), side1(0), side2(0), side3(0) {}

    // Constructor for three sides
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

    // Function Overloading: Area using base & height
    double area() {
        if (base > 0 && height > 0) {
            return 0.5 * base * height;
        } else if (side1 > 0 && side2 > 0 && side3 > 0) {
            // Heron's formula: √(s(s-a)(s-b)(s-c))
            double s = (side1 + side2 + side3) / 2;
            return sqrt(s * (s - side1) * (s - side2) * (s - side3));
        }
        return 0; // Invalid triangle
    }

    // Overloading Assignment Operator
    Triangle& operator=(const Triangle &t) {
        if (this != &t) { // Avoid self-assignment
            base = t.base;
            height = t.height;
            side1 = t.side1;
            side2 = t.side2;
            side3 = t.side3;
        }
        return *this;
    }

    // Overloading Equality Operator
    bool operator==(const Triangle &t) const {
        return (base == t.base && height == t.height && 
                side1 == t.side1 && side2 == t.side2 && side3 == t.side3);
    }

    // Display Function
    void display() {
        if (base > 0 && height > 0) {
            cout << "Triangle with Base = " << base << " and Height = " << height << endl;
        } else {
            cout << "Triangle with Sides = " << side1 << ", " << side2 << ", " << side3 << endl;
        }
        cout << "Area = " << area() << endl;
    }
};

// Main Function
int main() {
    // Creating triangle using base & height
    Triangle t1(5, 10);
    cout << "Triangle 1:\n";
    t1.display();

    // Creating triangle using three sides
    Triangle t2(3, 4, 5);
    cout << "\nTriangle 2:\n";
    t2.display();

    // Using assignment operator
    Triangle t3;
    t3 = t1;
    cout << "\nAfter Assignment (t3 = t1):\n";
    t3.display();

    // Checking equality operator
    if (t1 == t3) {
        cout << "\nTriangle 1 and Triangle 3 are equal.\n";
    } else {
        cout << "\nTriangle 1 and Triangle 3 are NOT equal.\n";
    }

    return 0;
}