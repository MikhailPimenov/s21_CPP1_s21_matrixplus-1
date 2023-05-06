#include "s21_matrix_oop.h"
#include <iostream>

bool are_equal(double a, double b, double epsilon = 1e-6) {
    return (a > b) ? (a - b < epsilon) : (b - a < epsilon);
} 

S21Matrix::S21Matrix() noexcept : rows_{0}, columns_{0}, matrix_{nullptr} {

}

S21Matrix::S21Matrix(int rows, int columns) {
    if (rows <= 0 || columns <= 0)
        throw -1;
    allocate(rows, columns);
    Fill();
}

S21Matrix::S21Matrix(int dimension) : S21Matrix(dimension, dimension) {

}


S21Matrix::~S21Matrix() {
    deallocate();
}


// TODO: think of how to unite with copying operator= to avoid code duplication
S21Matrix::S21Matrix(const S21Matrix& other) {
    allocate(other.rows_, other.columns_);

    for (int row = 0; row < rows_; ++row)
        for (int column = 0; column < columns_; ++column)
            matrix_[row][column] = other.matrix_[row][column];            
}

S21Matrix::S21Matrix(S21Matrix&& other) {
    allocate(other.rows_, other.columns_);

    matrix_ = other.matrix_;
    
    other.matrix_ = nullptr;
    other.rows_ = 0;
    other.columns_ = 0;
}

// TODO: think of how to unite with copy constructor to avoid code duplication
S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
    if (&other == this)
        return *this;
    
    allocate(other.rows_, other.columns_);

    for (int row = 0; row < rows_; ++row)
        for (int column = 0; column < columns_; ++column)
            matrix_[row][column] = other.matrix_[row][column];            

    return *this;
}


void S21Matrix::allocate(int rows, int columns) {
    matrix_ = reinterpret_cast<double**>(new char[rows * sizeof(double*) + rows * columns * sizeof(double)]);

    if (!matrix_)
        throw -1;


    for (int row = 0; row < rows; ++row)
        *(matrix_ + row) = reinterpret_cast<double*>((reinterpret_cast<double**>((reinterpret_cast<double*>(matrix_) + row * columns)) + rows));

    rows_ = rows;
    columns_ = columns;
}

void S21Matrix::deallocate() noexcept {
    delete matrix_;
    
    rows_ = 0;
    columns_ = 0;
}

// void S21Matrix::SetRows(int rows) {
//     if (rows == rows_)
//         return;

//     if (rows < 0)
//         throw -1;

    
//     S21Matrix temporary(rows, columns_);

//     const int minRow = rows < rows_ ? rows : rows_;

//     for (int row = 0; row < minRow; ++row) {
//         for (int column = 0; column < columns_; ++column) {
//             temporary(row, column) = operator()(row, column);
//         }
//     }

//     operator=(std::move(temporary));
// }

// void S21Matrix::SetColumns(int rows) {
// }



int S21Matrix::GetRows() const noexcept {
    return rows_;
}

int S21Matrix::GetColumns() const noexcept {
    return columns_;
}



bool S21Matrix::EqMatrix(const S21Matrix& other) const noexcept {
    if (rows_ != other.rows_ || columns_ != other.columns_)
        return false;

    for (int row = 0; row < rows_; ++row)
        for (int column = 0; column < columns_; ++column)
            if (!are_equal(matrix_[row][column], other.matrix_[row][column]))
                return false;
    return true;
}







bool operator==(const S21Matrix& left, const S21Matrix& right) noexcept {
    return left.EqMatrix(right);
}








// TODO: exception
double& S21Matrix::operator()(int row, int column) {
    if (row >= rows_ || column >= columns_)
        throw -1;

    return matrix_[row][column];
}
double S21Matrix::operator()(int row, int column) const {
    return operator()(row, column);
}




void S21Matrix::Fill(double element) noexcept {
    for (int row = 0; row < rows_; ++row)
        for (int column = 0; column < columns_; ++column)
            matrix_[row][column] = element;
}

void S21Matrix::Print(const char* space, const char* endline) const noexcept {
    for (int row = 0; row < rows_; ++row) {
        for (int column = 0; column < columns_; ++column) {
            std::cout << matrix_[row][column] << space;
        }
        std::cout << endline;
    }
}