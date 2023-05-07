#include <gtest/gtest.h>
#include "../s21_matrix_oop.h"

namespace {
    TEST(InverseMatrixTests, Test0) {
        const S21Matrix m1({
            {2.0,  5.0,  7.0},
            {6.0,  3.0,  4.0},
            {5.0, -2.0, -3.0},
        });

        const S21Matrix actual = m1.InverseMatrix();
        const S21Matrix expected({
            {  1.0,  -1.0,   1.0},
            {-38.0,  41.0, -34.0},
            { 27.0, -29.0,  24.0},
        });

        const bool result = (actual == expected);
        EXPECT_TRUE(result);
    }


    TEST(InverseMatrixTests, Test1) {
        const S21Matrix m1({
            {1.0,  2.0,  3.0},
            {9.0,  8.0,  7.0},
            {4.0,  5.0,  7.0},
        });

        const S21Matrix actual = m1.InverseMatrix();
        const S21Matrix expected({
            { -2.1, -0.1,  1.0},
            {  3.5,  0.5, -2.0},
            { -1.3, -0.3,  1.0},
        });

        const bool result = (actual == expected);
        EXPECT_TRUE(result);
    }

    TEST(InverseMatrixTests, Test2) {
        const S21Matrix m1({
            {1.5, 2.5, 3.5, 4.5},
            {2.5, 2.5, 3.5, 3.5},
            {5.5, 0.5, 7.5, 4.5},
            {5.5, 0.5, 4.5, 1.5},
        });

        const S21Matrix actual = m1.InverseMatrix();
        const S21Matrix expected({
            { 1.5, -1.6, -0.63333333333333,  1.1333333333333333},
            {-1.5,  2.0,  0.16666666666666, -0.6666666666666667},
            {-2.5,  2.6,  0.96666666666666, -1.4666666666666666},
            { 2.5, -2.6, -0.63333333333333,  1.1333333333333333},
        });

        const bool result = (actual == expected);
        EXPECT_TRUE(result);
    }

    TEST(InverseMatrixTests, Test3) {
        const S21Matrix m1({
            {1.5, 2.5, 3.5, 0.5},
            {2.5, 2.5, 0.5, 3.5},
            {5.5, 0.5, 7.5, 4.5},
            {5.5, 0.5, 4.5, 1.5},
        });

        const S21Matrix actual = m1.InverseMatrix();
        const S21Matrix expected({
            { -0.107142857142857,  0.07142857142857, -0.15476190476190,  0.333333333333333},  
            {  0.285714285714285,  0.14285714285714, -0.14285714285714,  0.0              }, 
            {  0.148809523809523, -0.15476190476190,  0.14087301587301, -0.111111111111111}, 
            { -0.148809523809523,  0.15476190476190,  0.19246031746031, -0.222222222222222},
        });

        const bool result = (actual == expected);
        EXPECT_TRUE(result);
    }


    TEST(InverseMatrixTests, Test4WrongSize) {
        const S21Matrix m1({
            {1.5, 2.5, 3.5, 0.5},
            {2.5, 2.5, 0.5, 3.5},
            {5.5, 0.5, 4.5, 1.5},
        });

        EXPECT_THROW(m1.InverseMatrix(), std::range_error);
    }

    TEST(InverseMatrixTests, Test5ZeroDeterminant) {
        const S21Matrix m1({
            {1.5, 2.5, 3.5, 4.5},
            {1.5, 2.5, 3.5, 4.5},
            {5.5, 0.5, 7.5, 9.5},
            {5.5, 1.5, 7.5, 8.5},
        });

        EXPECT_THROW(m1.InverseMatrix(), std::logic_error);
    }

    TEST(InverseMatrixTests, Test6ZeroDeterminant) {
        const S21Matrix m1({
            {1.5, 2.5, 3.5, 1.5},
            {1.5, 1.5, 9.5, 1.5},
            {5.5, 0.5, 1.5, 5.5},
            {5.5, 1.5, 7.5, 5.5},
        });

        EXPECT_THROW(m1.InverseMatrix(), std::logic_error);
    }


    TEST(InverseMatrixTests, Test7) {
        const S21Matrix m1({
            {1.5, 2.5, 1.5, 1.5, 4.5},
            {1.5, 2.5, 3.5, 1.5, 0.5},
            {7.5, 1.5, 0.5, 7.5, 3.5},
            {1.5, 2.5, 1.5, 2.5, 0.5},
            {2.5, 4.5, 5.5, 9.5, 1.5},
        });
        
        const S21Matrix actual = m1.InverseMatrix();
        // TODO:
        const S21Matrix expected({
            { -0.107142857142857,  0.07142857142857, -0.15476190476190,  0.333333333333333},  
            {  0.285714285714285,  0.14285714285714, -0.14285714285714,  0.0              }, 
            {  0.148809523809523, -0.15476190476190,  0.14087301587301, -0.111111111111111}, 
            { -0.148809523809523,  0.15476190476190,  0.19246031746031, -0.222222222222222},
        });

        const bool result = (actual == expected);
        EXPECT_TRUE(result);
    }
}