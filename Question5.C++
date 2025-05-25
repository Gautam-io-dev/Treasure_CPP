#include <iostream>

using namespace std;

// Function to merge two sorted arrays
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int mergedArr[]) {
    int i = 0, j = 0, k = 0;

    // Merge elements from both arrays in sorted order
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            mergedArr[k++] = arr1[i++];
        } else {
            mergedArr[k++] = arr2[j++];
        }
    }

    // Copy any remaining elements from arr1
    while (i < size1) {
        mergedArr[k++] = arr1[i++];
    }

    // Copy any remaining elements from arr2
    while (j < size2) {
        mergedArr[k++] = arr2[j++];
    }
}

int main() {
    int size1, size2;

    // Input first sorted array
    cout << "Enter size of first sorted array: ";
    cin >> size1;
    int arr1[size1];
    cout << "Enter " << size1 << " elements in sorted order: ";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    // Input second sorted array
    cout << "Enter size of second sorted array: ";
    cin >> size2;
    int arr2[size2];
    cout << "Enter " << size2 << " elements in sorted order: ";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    // Merged sorted array
    int mergedArr[size1 + size2];
    mergeSortedArrays(arr1, size1, arr2, size2, mergedArr);

    // Print the merged sorted array
    cout << "Merged Sorted Array: ";
    for (int i = 0; i < size1 + size2; i++) {
        cout << mergedArr[i] << " ";
    }
    cout << endl;

    return 0;
}