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
        // TODO:
        // void SetRows(int rows);
        // TODO:
        int GetRows() const noexcept;
        // TODO:
        // void SetColumns(int columns);
        // TODO:
        int GetColumns() const noexcept;


        // core methods
        bool EqMatrix(const S21Matrix& other) const noexcept;
        //// TODO: test
        void SumMatrix(const S21Matrix& other);
        //// TODO: test
        void SubMatrix(const S21Matrix& other);
        //// TODO: test
        void MulNumber(const double number) noexcept;
        // TODO:
        void MulMatrix(const S21Matrix& other);
        // TODO:
        S21Matrix Transpose() noexcept;
        // TODO:
        S21Matrix CalcComplements();
        // TODO:
        double Determinant() const;
        // TODO:
        S21Matrix InverseMatrix() const;



        // TODO:
        friend S21Matrix operator+(const S21Matrix& left, const S21Matrix& right);
        // TODO:
        friend S21Matrix operator-(const S21Matrix& left, const S21Matrix& right);
        // TODO:
        friend S21Matrix operator*(const S21Matrix& left, const S21Matrix& right);
        friend bool operator==(const S21Matrix& left, const S21Matrix& right) noexcept;  // don't have to be friend

        // TODO:
        S21Matrix& operator+=(const S21Matrix& other);
        // TODO:
        S21Matrix& operator-=(const S21Matrix& other);
        // TODO:
        S21Matrix& operator*=(const double number) noexcept;
        // TODO:
        S21Matrix& operator*=(const S21Matrix& other);
        
        // TODO:
        double& operator()(int row, int column);
        // TODO:
        double operator()(int row, int column) const;




        void Fill(double element = 0.0) noexcept;
        void Print(const char* space = " ", const char* endline = "\n") const noexcept;


    private:
        void allocate(int rows, int columns);
        void deallocate() noexcept;
};

#endif  //  __S21_MATRIX_OOP_H_