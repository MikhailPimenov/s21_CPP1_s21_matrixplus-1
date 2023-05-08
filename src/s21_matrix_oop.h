#ifndef __S21_MATRIX_OOP_H_
#define __S21_MATRIX_OOP_H_

#include <initializer_list>

class S21Matrix final {
    private:
        // Attributes
        int rows_ = 0;
        int columns_ = 0;                   // Rows and columns
        double **matrix_ = nullptr;         // Pointer to the memory where the matrix is allocated

    public:


        S21Matrix() noexcept;               // Default constructor
        S21Matrix(int rows, int columns);
        explicit S21Matrix(int dimension);  // Constructor for square matrix
        S21Matrix(const std::initializer_list<std::initializer_list<double>>& list);

        // rule of five
        ~S21Matrix();                       // Destructor
        //// TODO: test?
        S21Matrix(const S21Matrix& other);
        //// TODO: test?
        S21Matrix(S21Matrix&& other);
        //// TODO: test?
        S21Matrix& operator=(const S21Matrix& other);
        //// TODO: test?
        S21Matrix& operator=(S21Matrix&& other) noexcept;
        


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



        friend S21Matrix operator+(const S21Matrix& left, const S21Matrix& right);
        friend S21Matrix operator-(const S21Matrix& left, const S21Matrix& right);
        friend S21Matrix operator*(const S21Matrix& left, const S21Matrix& right);
        friend bool operator==(const S21Matrix& left, const S21Matrix& right) noexcept;  // don't have to be friend

        S21Matrix& operator+=(const S21Matrix& other);
        S21Matrix& operator-=(const S21Matrix& other);
        S21Matrix& operator*=(const double number) noexcept;
        S21Matrix& operator*=(const S21Matrix& other);
        
        double& operator()(int row, int column);
        double operator()(int row, int column) const;


        void Fill(double element = 0.0) noexcept;
        void Print(const char* space = "\t", const char* endline = "\n") const noexcept;

    private:
        void allocate(int rows, int columns);
        void deallocate() noexcept;
        static void multiply(const S21Matrix& left, const S21Matrix& right, S21Matrix& result) noexcept;
        static void copyFromTo(const S21Matrix& source, S21Matrix& destination) noexcept;
        static double determinantRecursive(const S21Matrix& m);
        static void getLittleMatrix(const S21Matrix& big, S21Matrix& little, int rowToExclude, int columnToExclude) noexcept;
        static double sign(int row, int column) noexcept;
        void checkAndCorrectIndices(int& row, int& column) const;

};

#endif  //  __S21_MATRIX_OOP_H_