// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, string name);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(const int input[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB);

int main() {
    int choice;

    cout << "1. Transpose Matrix (Part A)\n";
    cout << "2. Add Two Matrices (Part B)\n";
    cout << "3. Multiply Two Matrices (Part C)\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        int rows, cols;
        int A[MAX_SIZE][MAX_SIZE];
        int result[MAX_SIZE][MAX_SIZE];

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        readMatrix(A, rows, cols, "Matrix");

        cout << "\nOriginal Matrix:\n";
        printMatrix(A, rows, cols);

        transposeMatrix(A, result, rows, cols);

        cout << "\nTransposed Matrix:\n";
        printMatrix(result, cols, rows);

    } else if (choice == 2) {
        int rows, cols;
        int A[MAX_SIZE][MAX_SIZE];
        int B[MAX_SIZE][MAX_SIZE];
        int result[MAX_SIZE][MAX_SIZE];

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        readMatrix(A, rows, cols, "Matrix A");
        readMatrix(B, rows, cols, "Matrix B");

        cout << "\nMatrix A:\n";
        printMatrix(A, rows, cols);

        cout << "\nMatrix B:\n";
        printMatrix(B, rows, cols);

        addMatrices(A, B, result, rows, cols);

        cout << "\nSum (A + B):\n";
        printMatrix(result, rows, cols);

    } else if (choice == 3) {
        int rowsA, colsA, rowsB, colsB;
        int A[MAX_SIZE][MAX_SIZE];
        int B[MAX_SIZE][MAX_SIZE];
        int result[MAX_SIZE][MAX_SIZE];

        cout << "Enter rows for Matrix A: ";
        cin >> rowsA;
        cout << "Enter columns for Matrix A: ";
        cin >> colsA;

        cout << "Enter rows for Matrix B: ";
        cin >> rowsB;
        cout << "Enter columns for Matrix B: ";
        cin >> colsB;

        if (colsA != rowsB) {
            cout << "Error: Columns of Matrix A must equal Rows of Matrix B!\n";
            return 1;
        }

        readMatrix(A, rowsA, colsA, "Matrix A");
        readMatrix(B, rowsB, colsB, "Matrix B");

        cout << "\nMatrix A:\n";
        printMatrix(A, rowsA, colsA);

        cout << "\nMatrix B:\n";
        printMatrix(B, rowsB, colsB);

        multiplyMatrices(A, B, result, rowsA, colsA, colsB);

        cout << "\nProduct (A x B):\n";
        printMatrix(result, rowsA, colsB);
    }

    return 0;
}

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, string name) {
    cout << "Enter elements for " << name << ":\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(const int input[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = input[i][j];
        }
    }
}

void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}