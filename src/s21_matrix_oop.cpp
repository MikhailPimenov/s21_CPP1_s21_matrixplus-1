#include "s21_matrix_oop.h"
#include <iostream>
#include <exception>
#include <cassert>

bool are_equal(double a, double b, double epsilon = 1e-6) {
    return (a > b) ? (a - b < epsilon) : (b - a < epsilon);
} 

S21Matrix::S21Matrix() noexcept : rows_{0}, columns_{0}, matrix_{nullptr} {

}

S21Matrix::S21Matrix(int rows, int columns) {
    if (rows <= 0 || columns <= 0)
        throw std::range_error("Invalid rows or/and columns!");
    allocate(rows, columns);
    Fill();
}

S21Matrix::S21Matrix(int dimension) : S21Matrix(dimension, dimension) {

}

S21Matrix::S21Matrix(const std::initializer_list<std::initializer_list<double>>& list) {
    const std::size_t rows = list.size();
    if (rows == 0u)
        throw std::range_error("Invalid rows in initializer list!");

    const std::size_t columns = list.begin()->size();
    if (columns == 0u)
        throw std::range_error("Invalid columns in initializer list!");
        
    for (const auto& line : list)
        if (line.size() != columns)
            throw std::range_error("Invvalid columns in initializer list! Matrix is not rectangular!");


    allocate(rows, columns);

    std::size_t row = 0u;
    for (const auto& line : list) {
        std::size_t column = 0u;
        for (double element : line) {
            matrix_[row][column] = element;
            ++column;
        }
        ++row;
    }
}


S21Matrix::~S21Matrix() {
    deallocate();
}


// TODO: think of how to unite with copying operator= to avoid code duplication
S21Matrix::S21Matrix(const S21Matrix& other) {
    allocate(other.rows_, other.columns_);
    copyFromTo(other, *this);
}

S21Matrix::S21Matrix(S21Matrix&& other) {
    matrix_ = other.matrix_;
    rows_ = other.rows_;
    columns_ = other.columns_;
    
    other.matrix_ = nullptr;
    other.rows_ = 0;
    other.columns_ = 0;
}

// TODO: think of how to unite with copy constructor to avoid code duplication
S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
    if (&other == this)
        return *this;
    
    // Copy-swap idiom
    // https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom

    S21Matrix temporary(other.rows_, other.columns_);
    copyFromTo(other, temporary);

    deallocate();
    *this = std::move(temporary);            

    return *this;
}

// TODO: use copy-swap idiom!
S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
    if (&other == this)
        return *this;
    
    allocate(other.rows_, other.columns_);
    copyFromTo(other, *this);
    return *this;
}

void S21Matrix::allocate(int rows, int columns) {
    matrix_ = reinterpret_cast<double**>(new char[rows * sizeof(double*) + rows * columns * sizeof(double)]);

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
//         throw std::range_error("Invalid rows!");;

    
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


void S21Matrix::SumMatrix(const S21Matrix& other) {
    if (rows_ != other.rows_ || columns_ != other.columns_)
        throw std::range_error("Invalid rows or/and columns!");;

    for (int row = 0; row < rows_; ++row)
        for (int column = 0; column < columns_; ++column)
            matrix_[row][column] += other.matrix_[row][column];
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
    if (rows_ != other.rows_ || columns_ != other.columns_)
        throw std::range_error("Invalid rows or/and columns!");

    for (int row = 0; row < rows_; ++row)
        for (int column = 0; column < columns_; ++column)
            matrix_[row][column] -= other.matrix_[row][column];
}     

void S21Matrix::MulNumber(const double number) noexcept {
    for (int row = 0; row < rows_; ++row)
        for (int column = 0; column < columns_; ++column)
            matrix_[row][column] *= number;
} 

void S21Matrix::MulMatrix(const S21Matrix& other) {
    if (columns_ != other.rows_)
        throw std::range_error("Invalid rows or/and columns!");;

    S21Matrix result(rows_, other.columns_);
    multiply(*this, other, result);
    *this = std::move(result);
}

S21Matrix S21Matrix::Transpose() const noexcept {
    S21Matrix result(columns_, rows_);
    for (int row = 0; row < rows_; ++row)
        for (int column = 0; column < columns_; ++column)
            result.matrix_[column][row] = matrix_[row][column];
    return result;
}
        




bool operator==(const S21Matrix& left, const S21Matrix& right) noexcept {
    return left.EqMatrix(right);
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
    SumMatrix(other);
    return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
    SubMatrix(other);
    return *this;
}

S21Matrix& S21Matrix::operator*=(const double number) noexcept {
    MulNumber(number);
    return *this;
}
        
S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
    MulMatrix(other);
    return *this;
}







double& S21Matrix::operator()(int row, int column) {
    if (row >= rows_ || column >= columns_)
        throw std::out_of_range("Rows or/and columns out of range!");

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

void S21Matrix::multiply(const S21Matrix& left, const S21Matrix& right, S21Matrix& result) noexcept {
    const int sum_length = left.columns_;
    const int rows = left.rows_;
    const int columns = right.columns_;

    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            double sum = 0.0;
            for (int s = 0; s < sum_length; ++s) {
                sum += left.matrix_[row][s] * right.matrix_[s][column];
            }
            result.matrix_[row][column] = sum;
        }
    }
}

void S21Matrix::copyFromTo(const S21Matrix& source, S21Matrix& destination) noexcept {
    assert(source.rows_ == destination.rows_ && "Rows are not equal!");
    assert(source.columns_ == destination.columns_ && "Columns are not equal!");

    if (source.rows_ && source.columns_) {
        assert(source.matrix_ && "Matrix is null!");
        assert(destination.matrix_ && "Matrix is null!");
    }

    for (int row = 0; row < source.rows_; ++row) 
        for (int column = 0; column < source.columns_; ++column)
            destination.matrix_[row][column] = source.matrix_[row][column];
}
