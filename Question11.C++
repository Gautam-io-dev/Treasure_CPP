#include <iostream>

using namespace std;

int main() {
    double p, q;

    // Taking input from the user
    cout << "Enter two numbers (p and q): ";
    cin >> p >> q;

    try {
        // Checking for division by zero
        if (q == 0) {
            throw "Error: Division by zero is not allowed!";
        }
        // If q is not zero, perform division
        cout << "Result (p / q) = " << (p / q) << endl;
    }
    catch (const char *errMsg) {
        // Handling the exception
        cout << errMsg << endl;
    }

    return 0;
}