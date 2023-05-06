#ifndef __S21_MATRIX_OOP_H_
#define __S21_MATRIX_OOP_H_

class S21Matrix final {
    private:
        // Attributes
        int rows_ = 0;
        int columns_ = 0;                   // Rows and columns
        double **matrix_ = nullptr;         // Pointer to the memory where the matrix is allocated

    public:
        S21Matrix() noexcept;               // Default constructor
        ~S21Matrix();                       // Destructor

        S21Matrix(int rows, int columns);
        S21Matrix(int dimension);           // Constructor for square matrix


        int GetRows() const noexcept;
        int GetColumns() const noexcept;


        void SumMatrix(const S21Matrix& other); 
        // Other methods..


        void Fill(double element = 0.0) noexcept;
        void Print(const char* space = " ", const char* endline = "\n") const noexcept;


    private:
        void allocate(int rows, int columns);
        void deallocate() noexcept;
};

#endif  //  __S21_MATRIX_OOP_H_