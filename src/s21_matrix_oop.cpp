#include "s21_matrix_oop.h"
#include <iostream>


S21Matrix::S21Matrix() noexcept : rows_{0}, columns_{0}, matrix_{nullptr} {

}

S21Matrix::S21Matrix(int rows, int columns) {
    if (rows < 0 || columns < 0)
        throw -1;
    allocate(rows, columns);
    Fill();
}

S21Matrix::S21Matrix(int dimension) : S21Matrix(dimension, dimension) {

}



S21Matrix::~S21Matrix() {
    delete matrix_;
    rows_ = 0;
    columns_ = 0;
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

// S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
// }


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