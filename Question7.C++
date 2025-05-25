#include <iostream>

using namespace std;

// Recursive function to calculate GCD (Euclidean Algorithm)
int gcdRecursive(int a, int b) {
    if (b == 0)
        return a;
    return gcdRecursive(b, a % b);
}

// Iterative function to calculate GCD
int gcdIterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2, choice;

    // Taking input from user
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Menu for choosing method
    cout << "\nChoose method to calculate GCD:\n";
    cout << "1. Using Recursion\n";
    cout << "2. Without Recursion\n";
    cout << "Enter choice: ";
    cin >> choice;

    int result;
    if (choice == 1)
        result = gcdRecursive(num1, num2);
    else if (choice == 2)
        result = gcdIterative(num1, num2);
    else {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    // Display result
    cout << "GCD of " << num1 << " and " << num2 << " is: " << result << endl;

    return 0;
}