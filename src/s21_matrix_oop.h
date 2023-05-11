#ifndef __S21_MATRIX_OOP_H_
#define __S21_MATRIX_OOP_H_

#include <initializer_list>

class S21Matrix {
 private:
  using List = std::initializer_list<std::initializer_list<double>>;

 private:
  // Attributes
  int rows_ = 0;
  int columns_ = 0;
  double** matrix_ = nullptr;

 public:
  S21Matrix() noexcept;  // Default constructor
  S21Matrix(int rows, int columns);
  explicit S21Matrix(int dimension);  // Constructor for square matrix

  /*
  To create matrix like that:
  S21Matrix m({
      {1.0,  2.0,  3.0,  4.0},
      {5.0,  6.0,  7.0,  8.0},
      {9.0, 10.0, 11.0, 12.0},
  });
  */
  explicit S21Matrix(const List& list);

  // rule of five
  ~S21Matrix();  // Destructor
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other) noexcept;

  /*
  To modify matrix like that:
  m = {
      {1.0,  2.0,  3.0,  4.0},
      {5.0,  6.0,  7.0,  8.0},
      {9.0, 10.0, 11.0, 12.0},
  };
  */
  S21Matrix& operator=(const List& list);

  // getters and setters
  void SetRows(int rows);
  int GetRows() const noexcept;
  void SetColumns(int columns);
  int GetColumns() const noexcept;

  // core methods
  bool EqMatrix(const S21Matrix& other) const noexcept;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double number) noexcept;
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() const noexcept;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;

  // operators
  friend S21Matrix operator+(const S21Matrix& left, const S21Matrix& right);
  friend S21Matrix operator-(const S21Matrix& left, const S21Matrix& right);
  friend S21Matrix operator*(const S21Matrix& left, const S21Matrix& right);
  friend S21Matrix operator*(const S21Matrix& left, double right) noexcept;
  friend S21Matrix operator*(double left, const S21Matrix& right) noexcept;
  friend bool operator==(
      const S21Matrix& left,
      const S21Matrix& right) noexcept;  // don't have to be friend

  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const double number) noexcept;
  S21Matrix& operator*=(const S21Matrix& other);

  double& operator()(int row, int column);
  double operator()(int row, int column) const;

  void Fill(double element = 0.0) noexcept;
  void Print(const char* space = "\t",
             const char* endline = "\n") const noexcept;

 private:
  // create/destroy
  void allocate(int rows, int columns);
  void deallocate() noexcept;
  static void copyFromTo(const S21Matrix& source,
                         S21Matrix& destination) noexcept;
  static void copyFromTo(const List& list, S21Matrix& destination) noexcept;

  static void multiply(const S21Matrix& left, const S21Matrix& right,
                       S21Matrix& result) noexcept;

  // determinant
  static double determinantRecursive(const S21Matrix& m);
  static void getLittleMatrix(const S21Matrix& big, S21Matrix& little,
                              int rowToExclude, int columnToExclude) noexcept;
  static double sign(int row, int column) noexcept;

  // indices
  void checkAndCorrectIndices(int& row, int& column) const;

  static void checkIfListIsRectangular(const List& list);
};

#endif  //  __S21_MATRIX_OOP_H_