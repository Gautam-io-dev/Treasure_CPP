#include <iostream>
#include <cctype>   // For tolower() function
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    // Array to store letter frequency (26 letters from 'a' to 'z')
    vector<int> frequency(26, 0);
    string inputText;

    // Check if command-line arguments are given
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            inputText += argv[i]; // Append arguments to a single string
            inputText += " ";     // Add space between words
        }
    } else {
        // If no command-line input, prompt user
        cout << "Enter text: ";
        getline(cin, inputText);
    }

    // Count occurrences of each letter
    for (char ch : inputText) {
        if (isalpha(ch)) {   // Check if it's a letter
            ch = tolower(ch); // Convert to lowercase
            frequency[ch - 'a']++; // Update count
        }
    }

    // Display the frequency table
    cout << "\nLetter Frequency Table:\n";
    cout << "-----------------------\n";
    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (frequency[ch - 'a'] > 0) {  // Only show letters that appear
            cout << ch << " : " << frequency[ch - 'a'] << endl;
        }
    }

    return 0;
}