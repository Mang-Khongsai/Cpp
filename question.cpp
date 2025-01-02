#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// Forward declaration of the Matrix class
class Matrix;

// Function to calculate determinant using recursion (friend function)
double determinant(const Matrix& mat);

class Matrix {
private:
    int rows, cols;
    std::shared_ptr<std::vector<std::vector<int>>> data; // Smart pointer to handle matrix data

public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c) {
        data = std::make_shared<std::vector<std::vector<int>>>(rows, std::vector<int>(cols, 0));  // Initialize matrix with 0s
    }

    // Setter for matrix elements
    void setElement(int r, int c, int value) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            (*data)[r][c] = value;
        }
    }

    // Getter for matrix elements
    int getElement(int r, int c) const {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            return (*data)[r][c];
        }
        return 0;  // Out-of-bounds
    }

    // Overload operator+ for matrix addition
    Matrix operator+(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            throw runtime_error("Matrix dimensions must match for addition.");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.setElement(i, j, (*data)[i][j] + (*other.data)[i][j]);
            }
        }
        return result;
    }

    // Overload operator- for matrix subtraction
    Matrix operator-(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            throw runtime_error("Matrix dimensions must match for subtraction.");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.setElement(i, j, (*data)[i][j] - (*other.data)[i][j]);
            }
        }
        return result;
    }

    // Overload operator* for matrix multiplication
    Matrix operator*(const Matrix& other) {
        if (cols != other.rows) {
            throw runtime_error("Matrix dimensions must match for multiplication.");
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                int sum = 0;
                for (int k = 0; k < cols; k++) {
                    sum += (*data)[i][k] * (*other.data)[k][j];
                }
                result.setElement(i, j, sum);
            }
        }
        return result;
    }

    // Overload operator* for scalar multiplication
    Matrix operator*(int scalar) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.setElement(i, j, (*data)[i][j] * scalar);
            }
        }
        return result;
    }

    // Function to print matrix
    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << (*data)[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Allow the friend function to access private members of the class
    friend double determinant(const Matrix& mat);
};

// Friend function to calculate determinant using recursion
double determinant(const Matrix& mat) {
    if (mat.rows != mat.cols) {
        throw runtime_error("Matrix must be square to calculate determinant.");
    }

    int n = mat.rows;

    // Base case: if the matrix is 1x1
    if (n == 1) {
        return mat.getElement(0, 0);
    }

    // Base case: if the matrix is 2x2
    if (n == 2) {
        return mat.getElement(0, 0) * mat.getElement(1, 1) - mat.getElement(0, 1) * mat.getElement(1, 0);
    }

    // Recursive case for larger matrices
    double det = 0;
    for (int col = 0; col < n; col++) {
        // Create a submatrix by excluding the first row and the current column
        Matrix subMatrix(n - 1, n - 1);
        for (int i = 1; i < n; i++) {
            int subCol = 0;
            for (int j = 0; j < n; j++) {
                if (j != col) {
                    subMatrix.setElement(i - 1, subCol++, mat.getElement(i, j));
                }
            }
        }
        // Add or subtract the determinant of the submatrix
        det += (col % 2 == 0 ? 1 : -1) * mat.getElement(0, col) * determinant(subMatrix);
    }
    return det;
}

int main() {
    // Create two 3x3 matrices
    Matrix mat1(3, 3);
    mat1.setElement(0, 0, 1);
    mat1.setElement(0, 1, 2);
    mat1.setElement(0, 2, 3);
    mat1.setElement(1, 0, 4);
    mat1.setElement(1, 1, 5);
    mat1.setElement(1, 2, 6);
    mat1.setElement(2, 0, 7);
    mat1.setElement(2, 1, 8);
    mat1.setElement(2, 2, 9);

    Matrix mat2(3, 3);
    mat2.setElement(0, 0, 9);
    mat2.setElement(0, 1, 8);
    mat2.setElement(0, 2, 7);
    mat2.setElement(1, 0, 6);
    mat2.setElement(1, 1, 5);
    mat2.setElement(1, 2, 4);
    mat2.setElement(2, 0, 3);
    mat2.setElement(2, 1, 2);
    mat2.setElement(2, 2, 1);

    // Print matrices
    cout << "Matrix 1:" << endl;
    mat1.print();
    cout << "Matrix 2:" << endl;
    mat2.print();

    // Matrix Addition
    Matrix matSum = mat1 + mat2;
    cout << "Matrix Sum:" << endl;
    matSum.print();

    // Matrix Subtraction
    Matrix matDiff = mat1 - mat2;
    cout << "Matrix Difference:" << endl;
    matDiff.print();

    // Matrix Multiplication
    Matrix matProd = mat1 * mat2;
    cout << "Matrix Product:" << endl;
    matProd.print();

    // Scalar Multiplication
    Matrix matScalar = mat1 * 2;
    cout << "Matrix after Scalar Multiplication:" << endl;
    matScalar.print();

    // Calculate the determinant of mat1
    double det = determinant(mat1);
    cout << "Determinant of Matrix 1: " << det << endl;

    return 0;
}
