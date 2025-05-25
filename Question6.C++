#include <iostream>

using namespace std;

// Recursive Binary Search Function
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is at mid
        if (arr[mid] == target)
            return mid;

        // If target is smaller, search in the left half
        if (arr[mid] > target)
            return binarySearchRecursive(arr, left, mid - 1, target);

        // If target is larger, search in the right half
        return binarySearchRecursive(arr, mid + 1, right, target);
    }
    return -1; // Target not found
}

// Iterative Binary Search Function
int binarySearchIterative(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;  // Element found

        if (arr[mid] > target)
            right = mid - 1;  // Search in the left half
        else
            left = mid + 1;  // Search in the right half
    }

    return -1; // Target not found
}

int main() {
    int n, target, choice;

    // Input: Sorted array
    cout << "Enter number of elements in sorted array: ";
    cin >> n;
    int arr[n];

    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the element to search: ";
    cin >> target;

    // Menu for choosing search method
    cout << "\nChoose search method:\n";
    cout << "1. Binary Search with Recursion\n";
    cout << "2. Binary Search without Recursion\n";
    cout << "Enter choice: ";
    cin >> choice;

    int result;
    if (choice == 1)
        result = binarySearchRecursive(arr, 0, n - 1, target);
    else if (choice == 2)
        result = binarySearchIterative(arr, n, target);
    else {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in array." << endl;

    return 0;
}