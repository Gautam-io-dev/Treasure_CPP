#include <iostream>
#include <vector>
#include <unordered_set>
#include <limits> // For input handling

using namespace std;

// Function to remove duplicates and return a unique array
vector<int> removeDuplicates(const vector<int>& arr) {
    unordered_set<int> seen; // Stores unique elements
    vector<int> uniqueArr;   // Stores the final result

    for (int num : arr) {
        // If the number is not in the set, add it to the result
        if (seen.find(num) == seen.end()) {
            uniqueArr.push_back(num);
            seen.insert(num);
        }
    }

    return uniqueArr;
}

int main() {
    int n;

    // Get the size of the array
    cout << "Enter the number of elements: ";
    while (!(cin >> n) || n <= 0) {  // Handle invalid input
        cout << "Invalid input! Please enter a positive integer: ";
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
    }

    vector<int> arr(n);

    // Get the array elements from the user
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        while (!(cin >> arr[i])) {  // Handle non-integer input
            cout << "Invalid input! Please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Remove duplicates
    vector<int> uniqueArr = removeDuplicates(arr);

    // Display the result
    cout << "Array after removing duplicates: ";
    for (int num : uniqueArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}