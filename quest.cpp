#include <iostream>
#include <vector>
#include <memory>

class Matrix {
private:
    std::unique_ptr<std::vector<std::vector<double>>> data;
    size_t rows;
    size_t cols;

public:
    // Constructor
    Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
        data = std::make_unique<std::vector<std::vector<double>>>(rows, std::vector<double>(cols, 0));
    }

    // Overload () operator for element access
    double& operator()(size_t row, size_t col) {
        return (*data)[row][col];
    }

    const double& operator()(size_t row, size_t col) const {
        return (*data)[row][col];
    }

    // Overload + operator for matrix addition
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw std::invalid_argument("Matrix dimensions must match for addition.");

        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result(i, j) = (*this)(i, j) + other(i, j);
            }
        }
        return result;
    }

    // Overload - operator for matrix subtraction
    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw std::invalid_argument("Matrix dimensions must match for subtraction.");

        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result(i, j) = (*this)(i, j) - other(i, j);
            }
        }
        return result;
    }

    // Overload * operator for matrix multiplication
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows)
            throw std::invalid_argument("Matrix dimensions are incompatible for multiplication.");

        Matrix result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                for (size_t k = 0; k < cols; ++k) {
                    result(i, j) += (*this)(i, k) * other(k, j);
                }
            }
        }
        return result;
    }

    // Overload * operator for scalar multiplication
    Matrix operator*(double scalar) const {
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result(i, j) = (*this)(i, j) * scalar;
            }
        }
        return result;
    }

    // Friend function to calculate determinant
    friend double determinant(const Matrix& matrix);

    // Print the matrix
    void print() const {
        for (const auto& row : *data) {
            for (double value : row) {
                std::cout << value << " ";
            }
            std::cout << "\n";
        }
    }
};

// Helper function to calculate the determinant
double determinantHelper(const std::vector<std::vector<double>>& mat, size_t n) {
    if (n == 1)
        return mat[0][0];
    if (n == 2)
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];

    double det = 0.0;
    std::vector<std::vector<double>> subMat(n - 1, std::vector<double>(n - 1));

    for (size_t x = 0; x < n; ++x) {
        size_t subi = 0;
        for (size_t i = 1; i < n; ++i) {
            size_t subj = 0;
            for (size_t j = 0; j < n; ++j) {
                if (j == x) continue;
                subMat[subi][subj++] = mat[i][j];
            }
            ++subi;
        }
        det += ((x % 2 == 0) ? 1 : -1) * mat[0][x] * determinantHelper(subMat, n - 1);
    }

    return det;
}

// Friend function implementation
double determinant(const Matrix& matrix) {
    if (matrix.rows != matrix.cols)
        throw std::invalid_argument("Determinant is defined only for square matrices.");
    return determinantHelper(*(matrix.data), matrix.rows);
}

// Main Function
int main() {
    Matrix mat(3, 3);
    mat(0, 0) = 6; mat(0, 1) = 1; mat(0, 2) = 1;
    mat(1, 0) = 4; mat(1, 1) = -2; mat(1, 2) = 5;
    mat(2, 0) = 2; mat(2, 1) = 8; mat(2, 2) = 7;

    std::cout << "Matrix:\n";
    mat.print();

    std::cout << "\nDeterminant: " << determinant(mat) << "\n";

    Matrix scalarMultiplication = mat * 2;
    std::cout << "\nMatrix after scalar multiplication by 2:\n";
    scalarMultiplication.print();

    return 0;
}