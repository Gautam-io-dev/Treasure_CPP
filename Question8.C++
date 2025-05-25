#include <iostream>

using namespace std;

class Matrix {
private:
    int rows, cols;
    int mat[10][10]; // Fixed size for simplicity, can be dynamically allocated for larger matrices

public:
    // Constructor
    Matrix(int r = 0, int c = 0) : rows(r), cols(c) {}

    // Function to input matrix
    void inputMatrix() {
        cout << "Enter elements of " << rows << "x" << cols << " matrix:\n";
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
                cout << mat[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // Function to add two matrices
    Matrix operator+(const Matrix &m) {
        if (rows != m.rows || cols != m.cols) {
            cout << "Error: Matrices must be of same dimension for addition!" << endl;
            return Matrix(0, 0);
        }

        Matrix sum(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                sum.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        return sum;
    }

    // Function to multiply two matrices
    Matrix operator*(const Matrix &m) {
        if (cols != m.rows) {
            cout << "Error: Column of first matrix must be equal to row of second matrix for multiplication!" << endl;
            return Matrix(0, 0);
        }

        Matrix product(rows, m.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                product.mat[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    product.mat[i][j] += mat[i][k] * m.mat[k][j];
                }
            }
        }
        return product;
    }

    // Function to compute transpose
    Matrix transpose() {
        Matrix trans(cols, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                trans.mat[j][i] = mat[i][j];
            }
        }
        return trans;
    }
};

int main() {
    int choice;
    int r1, c1, r2, c2;

    do {
        cout << "\n===== Matrix Operations Menu =====\n";
        cout << "1. Sum of Matrices\n";
        cout << "2. Product of Matrices\n";
        cout << "3. Transpose of a Matrix\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { // Sum of matrices
                cout << "Enter rows and columns of matrices: ";
                cin >> r1 >> c1;
                Matrix A(r1, c1), B(r1, c1);

                cout << "Enter first matrix:\n";
                A.inputMatrix();
                cout << "Enter second matrix:\n";
                B.inputMatrix();

                Matrix sum = A + B;
                cout << "Sum of matrices:\n";
                sum.displayMatrix();
                break;
            }

            case 2: { // Product of matrices
                cout << "Enter rows and columns of first matrix: ";
                cin >> r1 >> c1;
                cout << "Enter rows and columns of second matrix: ";
                cin >> r2 >> c2;

                if (c1 != r2) {
                    cout << "Matrix multiplication not possible (cols of first != rows of second)!" << endl;
                    break;
                }

                Matrix A(r1, c1), B(r2, c2);
                cout << "Enter first matrix:\n";
                A.inputMatrix();
                cout << "Enter second matrix:\n";
                B.inputMatrix();

                Matrix product = A * B;
                cout << "Product of matrices:\n";
                product.displayMatrix();
                break;
            }

            case 3: { // Transpose of a matrix
                cout << "Enter rows and columns of matrix: ";
                cin >> r1 >> c1;
                Matrix A(r1, c1);

                cout << "Enter matrix:\n";
                A.inputMatrix();

                Matrix trans = A.transpose();
                cout << "Transpose of matrix:\n";
                trans.displayMatrix();
                break;
            }

            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}