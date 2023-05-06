#include "s21_matrix_oop.h"
#include <iostream>


S21Matrix::S21Matrix() : rows_{0}, columns_{0}, matrix_{nullptr} {

}

S21Matrix::S21Matrix(int rows, int columns) {
    if (rows < 0 || columns < 0)
        throw -1;
    allocate(rows, columns);
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

int S21Matrix::GetRows() const noexcept {
    return rows_;
}

int S21Matrix::GetColumns() const noexcept {
    return columns_;
}


void S21Matrix::Print(const char* space, const char* endline) const noexcept {
    for (int row = 0; row < rows_; ++row) {
        for (int column = 0; column = columns_; ++column) {
            std::cout << matrix_[row][column] << space;
        }
        std::cout << endline;
    }
}