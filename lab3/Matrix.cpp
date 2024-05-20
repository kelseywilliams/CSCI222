#include "Matrix.h"

// Constructor for class Matrix with parameter of type vector of vectors
template<typename T>
Matrix<T>::Matrix(std::vector<std::vector<T>> matrix){
    this->setMatrix(matrix);
    this->shape = this->getShape();
}
template Matrix<double>::Matrix(std::vector<std::vector<double>> matrix);
template Matrix<int>::Matrix(std::vector<std::vector<int>> matrix);

// Constructor for class Matrix with no parameter.
template<typename T>
Matrix<T>::Matrix(){
    this->matrix.push_back(std::vector<T>());
    this->shape = this->getShape();
}
template Matrix<double>::Matrix();
template Matrix<int>::Matrix();

// Set instance variable matrix
template<typename T>
void Matrix<T>::setMatrix(std::vector<std::vector<T>> matrix){
    this->matrix = matrix;
    this->shape = this->getShape();
}
template void Matrix<double>::setMatrix(std::vector<std::vector<double>> matrix);
template void Matrix<int>::setMatrix(std::vector<std::vector<int>> matrix);

// Return shape of matrix as tuple of ints
template<typename T>
std::tuple<int, int> Matrix<T>::getShape() const{
    // Go through each row of the matrix to ensure that they are of equal length.
    for (int i = 0; i < this->matrix.size() - 1; i++) {
        if (this->matrix[i].size() != this->matrix[i + 1].size()){
            std::cerr << "Matrix rows must be of equal length.";
            exit(1);
        }
    }
    return std::make_tuple(this->matrix.size(), this->matrix[0].size());
}

template<typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T> m2){
    return this->operation('+', m2);
}
template Matrix<double> Matrix<double>::operator+(Matrix<double> m2);
template Matrix<int> Matrix<int>::operator+(Matrix<int> m2);

template<typename T>
Matrix<T> Matrix<T>::operator-(Matrix<T> m2){
    return this->operation('-', m2);
}
template Matrix<double> Matrix<double>::operator-(Matrix<double> m2);
template Matrix<int> Matrix<int>::operator-(Matrix<int> m2);

template<typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T> m2){
    return this->operation('*', m2);
}
template Matrix<double> Matrix<double>::operator*(Matrix<double> m2);
template Matrix<int> Matrix<int>::operator*(Matrix<int> m2);

template<typename T> Matrix<T> Matrix<T>::operator++(){
    int row = std::get<0>(shape);
    int col = std::get<1>(shape);
    // Iterate through each row each element in each column and increment it
    for (int i; i < row; i++){
        for (int j = 0; j < col; j++){
            this->matrix[i][j]++;
        }
    }
    return *this;
}
template Matrix<double> Matrix<double>::operator++();
template Matrix<int> Matrix<int>::operator++();

template<typename T>
Matrix<T> Matrix<T>::operator--(){
    int row = std::get<0>(shape);
    int col = std::get<1>(shape);
    for (int i; i < row; i++){
        for (int j = 0; j < col; j++){
            this->matrix[i][j]--;
        }
    }
    return *this;
}
template Matrix<double> Matrix<double>::operator--();
template Matrix<int> Matrix<int>::operator--();

template<typename T>
Matrix<T> Matrix<T>::operator~(){
    int row = std::get<0>(shape);
    int col = std::get<1>(shape);
    this->shape = std::make_tuple(col, row);

    std::vector<T> inner;
    std::vector<std::vector<T>> outer;
    inner.resize(0);
    outer.resize(0);

    for (int i = 0; i < col; i++){
        for (int j = 0; j < row; j++){
            inner.push_back(this->matrix[j][i]);
        }
        outer.push_back(inner);
        inner.clear();
    }
    this->setMatrix(outer);
    return *this;
}
template Matrix<double> Matrix<double>::operator~();
template Matrix<int> Matrix<int>::operator~();

template<typename T>
Matrix<T> Matrix<T>::operator^(int pow){
    Matrix<T> temp = *this;
    for (int i = 1; i < pow; i++){
        temp = (temp * *this);
    }
    this->matrix = temp.matrix;
    return *this;
}
template Matrix<double> Matrix<double>::operator^(int pow);
template Matrix<int> Matrix<int>::operator^(int pow);

// Function responsible for addition, subtraction, and multiplication operations.
template<typename T>
Matrix<T> Matrix<T>::operation(char op, Matrix<T> m2){
    Matrix<T> m3;

    // Create temporary matrix
    std::vector<T> inner;
    std::vector<std::vector<T>> outer;
    inner.resize(0);
    outer.resize(0);

    // Get the shape of the two matrices involved in the operation
    int row, row2, col, col2;
    row = std::get<0>(this->shape);
    row2 = std::get<0>(m2.getShape());
    col = std::get<1>(this->shape);
    col2 = std::get<1>(m2.getShape());

    // Set requirements for square matrices
    if ((op == '+' || op == '-') && row != row2 && col != col2){
        std::cerr << "Matrices are incompatible.";
        exit(1);
    }
    // Set requirments for equal col on the first matrix and row on the second
    if ((op == '*') && col != row2){
        std::cerr << "Matrices are incompatible.";
        exit(1);
    }

    // Perform calculations on matrices
    double temp;
    for (int i = 0; i < col; i++){
        for (int j = 0; j < row2; j++){
            switch(op){
                case '+':
                    inner.push_back(this->matrix[i][j] + m2.matrix[i][j]);
                    break;
                case '-':
                    inner.push_back(this->matrix[i][j] - m2.matrix[i][j]);
                    break;
                case '*':
                    temp = 0;
                    for (int k = 0; k < row2; k++)
                        temp += this->matrix[i][k] * m2.matrix[k][j];
                    inner.push_back(temp);
                    break;
                default:
                    std::cerr << "Error: op is not a recognized operator in Matrix<T> Matrix<T>::operation(char op, Matrix<T> m2)";
                    exit(1);
            }
        }
        outer.push_back(inner);
        inner.clear();
    }
    m3.setMatrix(outer);
    return m3;
}
template Matrix<double> Matrix<double>::operation(char op, Matrix<double> m2);
template Matrix<int> Matrix<int>::operation(char op, Matrix<int> m2);

template<typename T>
std::ostream& operator<<(std::ostream& stream, const Matrix<T>& matrix){
    std::tuple<int, int> shape = matrix.getShape();
    int rows = std::get<0>(shape);
    int colm = std::get<1>(shape);

    stream << "[";
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < matrix.matrix[i].size(); j++){
            stream << matrix.matrix[i][j];
            if (i == rows - 1 && j == colm - 1) stream << "]";
            else stream << " ";
        }
        std::cout << std::endl;
    }return stream;
}
template std::ostream& operator<< <double>(std::ostream& stream, const Matrix<double>& matrix);
template std::ostream& operator<< <int>(std::ostream& stream, const Matrix<int>& matrix);