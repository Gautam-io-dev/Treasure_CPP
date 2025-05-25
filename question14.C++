#include <iostream>
#include <fstream>  // For file handling

using namespace std;

void removeWhitespaces(const string &inputFile, const string &outputFile) {
    ifstream inFile(inputFile);   // Open input file
    ofstream outFile(outputFile); // Open output file

    if (!inFile || !outFile) {
        cout << "Error: Unable to open file(s)!" << endl;
        return;
    }

    char ch;
    while (inFile.get(ch)) {  // Read file character by character
        if (!isspace(ch)) {   // If character is NOT whitespace, write to output file
            outFile.put(ch);
        }
    }

    cout << "File copied successfully without whitespaces!" << endl;

    inFile.close();
    outFile.close();
}

int main() {
    string inputFile = "input.txt";   // Source file
    string outputFile = "output.txt"; // Destination file

    removeWhitespaces(inputFile, outputFile);

    return 0;
}