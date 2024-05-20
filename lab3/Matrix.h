#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <tuple>

#ifndef MATRIX_H
#define MATRIX_H

/* Matrix class for storing and manipulating matrices
 *
 * Create a new instance of the Matrix class by calling
 * an empty constructor or passing a vector of vectors
 * of type double or int.
 *
 * Manipulations can be performed on the matrices by direct
 * manipulation to the instance variable.  For example,
 * Matrix<double> matrix_c = matrix_a + matrix_b
 */
template<typename T>
class Matrix {
    std::vector<std::vector<T>> matrix;
    std::tuple<int, int> shape;
public:
    explicit Matrix(std::vector<std::vector<T>> matrix);
    Matrix();
    // Set the matrix to a new matrix
    void setMatrix(std::vector<std::vector<T>> matrix);
    // Get the shape of the matrix
    std::tuple<int, int> getShape() const;
    Matrix<T> operator+(Matrix<T> m2);
    Matrix<T> operator-(Matrix<T> m2);
    Matrix<T> operator*(Matrix<T> m2);
    Matrix<T> operator++();
    Matrix<T> operator--();
    Matrix<T> operator~();
    Matrix<T> operator^(int pow);
    Matrix<T> operation(char op, Matrix<T> m2);
    template<typename U>
    friend std::ostream& operator<<(std::ostream& stream, const Matrix<U>& matrix);
};
#endif