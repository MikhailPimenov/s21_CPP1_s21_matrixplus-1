#include "s21_matrix_oop.h"

#include <cassert>
#include <exception>
#include <iostream>

static bool are_equal(double a, double b, double epsilon = 1e-6) {
  return (a > b) ? (a - b < epsilon) : (b - a < epsilon);
}

S21Matrix::S21Matrix() noexcept : rows_{0}, columns_{0}, matrix_{nullptr} {}

S21Matrix::S21Matrix(int rows, int columns) {
  if (rows <= 0 || columns <= 0)
    throw std::range_error("Invalid rows or/and columns!");
  allocate(rows, columns);
  Fill();
}

S21Matrix::S21Matrix(int dimension) : S21Matrix(dimension, dimension) {}

S21Matrix::S21Matrix(const List& list) {
  checkIfListIsRectangular(list);
  allocate(list.size(), list.begin()->size());
  copyFromTo(list, *this);
}

S21Matrix::~S21Matrix() { deallocate(); }

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

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (&other == this) return *this;

  // Copy-swap idiom
  // https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom
  S21Matrix temporary(other);

  // move assignment operator is called, same as operator=(temporary)
  // do not actually have to call operator=(std::move(temporary)) or *this =
  // std::move(temporary) because temporary is about to be destroyed and
  // compiler knows it and calls operator=(S21Matrix&&). But it is still up to
  // the compiler which operator to call: operator=(S21Matrix&&) or
  // operator=(const S21Matrix&), so to be sure operator=(S21Matrix&&) will be
  // called casting temporary to r-value reference using std::move
  *this = std::move(temporary);

  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
  if (&other == this) return *this;

  deallocate();

  matrix_ = other.matrix_;
  rows_ = other.rows_;
  columns_ = other.columns_;

  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.columns_ = 0;

  return *this;
}

S21Matrix& S21Matrix::operator=(const List& list) {
  checkIfListIsRectangular(list);

  if (list.size() != static_cast<long long unsigned>(rows_) ||
      list.begin()->size() != static_cast<long long unsigned>(columns_)) {
    deallocate();
    allocate(list.size(), list.begin()->size());
  }

  copyFromTo(list, *this);
  return *this;
}

void S21Matrix::SetRows(int rows) {
  if (rows == rows_) return;

  if (rows <= 0) throw std::range_error("Invalid rows!");
  ;

  S21Matrix temporary(rows, columns_);

  const int minRow = rows < rows_ ? rows : rows_;

  for (int row = 0; row < minRow; ++row) {
    for (int column = 0; column < columns_; ++column) {
      temporary(row, column) = matrix_[row][column];
    }
  }

  for (int row = minRow; row < temporary.rows_; ++row) {
    for (int column = 0; column < columns_; ++column) {
      temporary(row, column) = 0.0;
    }
  }

  // move assignment operator is called, same as operator=(temporary)
  // do not actually have to call operator=(std::move(temporary)) or *this =
  // std::move(temporary) because temporary is about to be destroyed and
  // compiler knows it and calls operator=(S21Matrix&&). But it is still up to
  // the compiler which operator to call: operator=(S21Matrix&&) or
  // operator=(const S21Matrix&), so to be sure operator=(S21Matrix&&) will be
  // called casting temporary to r-value reference using std::move
  *this = std::move(temporary);
}

int S21Matrix::GetRows() const noexcept { return rows_; }

void S21Matrix::SetColumns(int columns) {
  if (columns == columns_) return;

  if (columns <= 0) throw std::range_error("Invalid columns!");
  ;

  S21Matrix temporary(rows_, columns);

  const int minColumns = columns < columns_ ? columns : columns_;

  for (int row = 0; row < rows_; ++row) {
    for (int column = 0; column < minColumns; ++column) {
      temporary(row, column) = matrix_[row][column];
    }
  }

  for (int row = 0; row < rows_; ++row) {
    for (int column = minColumns; column < temporary.columns_; ++column) {
      temporary(row, column) = 0.0;
    }
  }

  // move assignment operator is called, same as operator=(temporary)
  // do not actually have to call operator=(std::move(temporary)) or *this =
  // std::move(temporary) because temporary is about to be destroyed and
  // compiler knows it and calls operator=(S21Matrix&&). But it is still up to
  // the compiler which operator to call: operator=(S21Matrix&&) or
  // operator=(const S21Matrix&), so to be sure operator=(S21Matrix&&) will be
  // called casting temporary to r-value reference using std::move
  *this = std::move(temporary);
}

int S21Matrix::GetColumns() const noexcept { return columns_; }

bool S21Matrix::EqMatrix(const S21Matrix& other) const noexcept {
  if (rows_ != other.rows_ || columns_ != other.columns_) return false;

  for (int row = 0; row < rows_; ++row)
    for (int column = 0; column < columns_; ++column)
      if (!are_equal(matrix_[row][column], other.matrix_[row][column]))
        return false;
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || columns_ != other.columns_)
    throw std::range_error("Invalid rows or/and columns!");
  ;

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
    throw std::range_error("Invalid rows or/and columns!");

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

S21Matrix S21Matrix::CalcComplements() const {
  if (rows_ != columns_)
    throw std::range_error(
        "Matrix is not square to calculate algebraic complements!");

  S21Matrix result(rows_);
  S21Matrix little(rows_ - 1);
  for (int row = 0; row < rows_; ++row) {
    for (int column = 0; column < columns_; ++column) {
      getLittleMatrix(*this, little, row, column);
      result(row, column) = sign(row, column) * little.Determinant();
    }
  }

  return result;
}

double S21Matrix::Determinant() const {
  if (rows_ != columns_)
    throw std::range_error(
        "Matrix is not square, it is impossible to calculate determinant!");

  return determinantRecursive(*this);
}

S21Matrix S21Matrix::InverseMatrix() const {
  if (rows_ != columns_)
    throw std::range_error("Matrix is not square to calculate inverse matrix!");

  const double determinant = Determinant();

  if (are_equal(determinant, 0.0, 1e-12))
    throw std::invalid_argument(
        "Determinant is zero, it is impossible to calculate inverse matrix!");

  S21Matrix result = CalcComplements();
  result = result.Transpose();

  result *= (1.0 / determinant);
  return result;
}

S21Matrix operator+(const S21Matrix& left, const S21Matrix& right) {
  S21Matrix result(left);
  result.SumMatrix(right);
  return result;
}

S21Matrix operator-(const S21Matrix& left, const S21Matrix& right) {
  S21Matrix result(left);
  result.SubMatrix(right);
  return result;
}

S21Matrix operator*(const S21Matrix& left, const S21Matrix& right) {
  S21Matrix result(left);
  result.MulMatrix(right);
  return result;
}

S21Matrix operator*(const S21Matrix& left, double right) noexcept {
  S21Matrix result(left);
  result.MulNumber(right);
  return result;
}

S21Matrix operator*(double left, const S21Matrix& right) noexcept {
  return (right * left);
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
  checkAndCorrectIndices(row, column);
  return matrix_[row][column];
}

double S21Matrix::operator()(int row, int column) const {
  checkAndCorrectIndices(row, column);
  return matrix_[row][column];
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

void S21Matrix::allocate(int rows, int columns) {
  matrix_ = reinterpret_cast<double**>(
      new char[rows * sizeof(double*) + rows * columns * sizeof(double)]);

  for (int row = 0; row < rows; ++row)
    *(matrix_ + row) = reinterpret_cast<double*>(
        (reinterpret_cast<double**>(
             (reinterpret_cast<double*>(matrix_) + row * columns)) +
         rows));

  rows_ = rows;
  columns_ = columns;
}

void S21Matrix::deallocate() noexcept {
  delete[] matrix_;
  matrix_ = nullptr;

  rows_ = 0;
  columns_ = 0;
}

void S21Matrix::copyFromTo(const S21Matrix& source,
                           S21Matrix& destination) noexcept {
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

void S21Matrix::copyFromTo(const List& source,
                           S21Matrix& destination) noexcept {
  assert(source.size() == static_cast<long long unsigned>(destination.rows_) &&
         "Rows are not equal!");
  assert(source.begin()->size() ==
             static_cast<long long unsigned>(destination.columns_) &&
         "Columns are not equal!");

  std::size_t row = 0u;
  for (const auto& line : source) {
    std::size_t column = 0u;
    for (double element : line) {
      destination.matrix_[row][column] = element;
      ++column;
    }
    ++row;
  }
}

void S21Matrix::multiply(const S21Matrix& left, const S21Matrix& right,
                         S21Matrix& result) noexcept {
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

double S21Matrix::determinantRecursive(const S21Matrix& m) {
  assert(m.rows_ == m.columns_ &&
         "Matrix is not square, it is impossible to calculate determinant!");
  if (m.rows_ <= 1) return m.matrix_[0][0];

  if (m.rows_ == 2)
    return m.matrix_[0][0] * m.matrix_[1][1] -
           m.matrix_[0][1] * m.matrix_[1][0];

  S21Matrix little(m.rows_ - 1);
  double sum = 0.0;
  for (int column = 0; column < m.columns_; ++column) {
    getLittleMatrix(m, little, 0, column);
    sum +=
        m.matrix_[0][column] * sign(0, column) * determinantRecursive(little);
  }
  return sum;
}

void S21Matrix::getLittleMatrix(const S21Matrix& big, S21Matrix& little,
                                int rowToExclude,
                                int columnToExclude) noexcept {
  assert(rowToExclude < big.rows_ && columnToExclude < big.columns_ &&
         "Rows or/and columns are invalid!");

  int rowLittle = 0;
  for (int rowBig = 0; rowBig < big.rows_; ++rowBig) {
    if (rowBig == rowToExclude) continue;

    int columnLittle = 0;
    for (int columnBig = 0; columnBig < big.columns_; ++columnBig) {
      if (columnBig == columnToExclude) continue;

      little(rowLittle, columnLittle) = big(rowBig, columnBig);
      ++columnLittle;
    }
    ++rowLittle;
  }
}

double S21Matrix::sign(int row, int column) noexcept {
  return ((row + column) % 2) ? -1.0 : 1.0;
}

void S21Matrix::checkAndCorrectIndices(int& row, int& column) const {
  if (row < -rows_ || rows_ <= row || column < -columns_ || columns_ <= column)
    throw std::out_of_range("Rows or/and columns out of range!");

  // Python-style indices: when '-1' means 'length - 1', '-2' means 'length - 2'
  // and so on
  if (-rows_ <= row && row < 0) row += rows_;
  if (-columns_ <= column && column < 0) column += columns_;
}

void S21Matrix::checkIfListIsRectangular(const List& list) {
  const std::size_t rows = list.size();
  if (rows == 0u) throw std::range_error("Invalid rows in initializer list!");

  const std::size_t columns = list.begin()->size();
  if (columns == 0u)
    throw std::range_error("Invalid columns in initializer list!");

  for (const auto& line : list)
    if (line.size() != columns)
      throw std::range_error(
          "Invvalid columns in initializer list! Matrix is not rectangular!");
}