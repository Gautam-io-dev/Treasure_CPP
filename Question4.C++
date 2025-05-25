#include <iostream>

using namespace std;

// Function to show the address of each character in a string
void showAddress(char *str) {
    cout << "\nCharacter Address Table:\n";
    while (*str != '\0') {
        cout << "'" << *str << "' -> " << (void *)str << endl;
        str++;
    }
}

// Function to concatenate two strings
void concatenateStrings(char *str1, char *str2, char *result) {
    while (*str1) {
        *result = *str1;
        str1++;
        result++;
    }
    while (*str2) {
        *result = *str2;
        str2++;
        result++;
    }
    *result = '\0'; // Null terminate the result string
}

// Function to compare two strings
int compareStrings(char *str1, char *str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2)
            return (*str1 > *str2) ? 1 : -1;
        str1++;
        str2++;
    }
    if (*str1 == '\0' && *str2 == '\0')
        return 0;
    return (*str1 > *str2) ? 1 : -1;
}

// Function to calculate length of string using pointers
int stringLength(char *str) {
    int length = 0;
    while (*str) {
        length++;
        str++;
    }
    return length;
}

// Function to convert all lowercase characters to uppercase
void toUpperCase(char *str) {
    while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - 32; // Convert lowercase to uppercase
        }
        str++;
    }
}

int main() {
    char str1[100], str2[100], result[200];
    int choice;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Show address of each character in string\n";
        cout << "2. Concatenate two strings\n";
        cout << "3. Compare two strings\n";
        cout << "4. Calculate length of the string\n";
        cout << "5. Convert all lowercase characters to uppercase\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character

        switch (choice) {
            case 1:
                cout << "Enter a string: ";
                cin.getline(str1, 100);
                showAddress(str1);
                break;

            case 2:
                cout << "Enter first string: ";
                cin.getline(str1, 100);
                cout << "Enter second string: ";
                cin.getline(str2, 100);
                concatenateStrings(str1, str2, result);
                cout << "Concatenated String: " << result << endl;
                break;

            case 3:
                cout << "Enter first string: ";
                cin.getline(str1, 100);
                cout << "Enter second string: ";
                cin.getline(str2, 100);
                int cmp;
                cmp = compareStrings(str1, str2);
                if (cmp == 0)
                    cout << "Strings are equal." << endl;
                else if (cmp > 0)
                    cout << "First string is greater." << endl;
                else
                    cout << "Second string is greater." << endl;
                break;

            case 4:
                cout << "Enter a string: ";
                cin.getline(str1, 100);
                cout << "Length of the string: " << stringLength(str1) << endl;
                break;

            case 5:
                cout << "Enter a string: ";
                cin.getline(str1, 100);
                toUpperCase(str1);
                cout << "Uppercase String: " << str1 << endl;
                break;

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}