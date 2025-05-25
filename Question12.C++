#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    vector<vector<int>> mat;
    int rows, cols;

public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c) {
        mat.resize(rows, vector<int>(cols, 0));
    }

    // Function to input matrix elements
    void inputMatrix() {
        cout << "Enter elements for " << rows << "x" << cols << " matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }
    }

    // Function to display matrix
    void displayMatrix() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Function to add two matrices
    Matrix operator+(const Matrix &m) {
        if (rows != m.rows || cols != m.cols) {
            throw "Error: Matrices cannot be added (incompatible dimensions).";
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        return result;
    }

    // Function to multiply two matrices
    Matrix operator*(const Matrix &m) {
        if (cols != m.rows) {
            throw "Error: Matrices cannot be multiplied (incompatible dimensions).";
        }
        Matrix result(rows, m.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.mat[i][j] += mat[i][k] * m.mat[k][j];
                }
            }
        }
        return result;
    }

    // Function to compute the transpose of a matrix
    Matrix transpose() {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mat[j][i] = mat[i][j];
            }
        }
        return result;
    }
};

// Main Function
int main() {
    try {
        int r1, c1, r2, c2;
        
        // First Matrix
        cout << "Enter rows and columns for Matrix 1: ";
        cin >> r1 >> c1;
        Matrix m1(r1, c1);
        m1.inputMatrix();

        // Second Matrix
        cout << "Enter rows and columns for Matrix 2: ";
        cin >> r2 >> c2;
        Matrix m2(r2, c2);
        m2.inputMatrix();

        // Menu-driven operations
        int choice;
        do {
            cout << "\nMenu:\n";
            cout << "1. Add Matrices\n";
            cout << "2. Multiply Matrices\n";
            cout << "3. Transpose of Matrix 1\n";
            cout << "4. Transpose of Matrix 2\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    try {
                        Matrix sum = m1 + m2;
                        cout << "Sum of matrices:\n";
                        sum.displayMatrix();
                    } catch (const char *errMsg) {
                        cout << errMsg << endl;
                    }
                    break;
                }
                case 2: {
                    try {
                        Matrix product = m1 * m2;
                        cout << "Product of matrices:\n";
                        product.displayMatrix();
                    } catch (const char *errMsg) {
                        cout << errMsg << endl;
                    }
                    break;
                }
                case 3:
                    cout << "Transpose of Matrix 1:\n";
                    m1.transpose().displayMatrix();
                    break;
                case 4:
                    cout << "Transpose of Matrix 2:\n";
                    m2.transpose().displayMatrix();
                    break;
                case 5:
                    cout << "Exiting program...\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
            }
        } while (choice != 5);

    } catch (const char *errMsg) {
        cout << "Exception Caught: " << errMsg << endl;
    }

    return 0;
}