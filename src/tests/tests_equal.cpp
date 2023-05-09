#include <gtest/gtest.h>
#include "../s21_matrix_oop.h"

namespace {
     TEST(EqMatrixTests, Test0) {
        S21Matrix m1(4, 7);
        m1.Fill(0.9);
        m1(1, 2) = 0.7;

        S21Matrix m2(4, 7);
        m2.Fill(0.9);
        m2(1, 2) = 0.7;

        const bool result = m1.EqMatrix(m2);
        EXPECT_TRUE(result);
    }

    TEST(EqMatrixTests, Test1) {
        S21Matrix m1(4, 7);
        m1.Fill(0.9);
        
        S21Matrix m2(4, 7);
        m2.Fill(0.9);

        const bool result = m1.EqMatrix(m2);
        EXPECT_TRUE(result);
    }

    TEST(EqMatrixTests, Test2) {
        S21Matrix m1(4, 7);
        m1.Fill(0.99875);
        
        S21Matrix m2(4, 7);
        m2.Fill(0.99875);

        const bool result = m1.EqMatrix(m2);
        EXPECT_TRUE(result);
    }

    TEST(EqMatrixTests, Test3Not) {
        S21Matrix m1(4, 7);
        m1.Fill(0.99875);
        
        S21Matrix m2(4, 7);
        m2.Fill(0.99875);

        m2(0, 0) = 1.0;

        const bool result = m1.EqMatrix(m2);
        EXPECT_FALSE(result);
    }

    TEST(EqMatrixTests, Test4Not) {
        S21Matrix m1(4, 7);
        m1.Fill(0.99875);
        
        S21Matrix m2(4, 8);
        m2.Fill(0.99875);

        const bool result = m1.EqMatrix(m2);
        EXPECT_FALSE(result);
    }




    TEST(EqMatrixOperatorTests, Test0) {
        S21Matrix m1(4, 7);
        m1.Fill(0.9);
        m1(2, 1) = 0.5;
        
        S21Matrix m2(4, 7);
        m2.Fill(0.9);
        m2(2, 1) = 0.5;

        const bool result = m1 == m2;
        EXPECT_TRUE(result);
    }

    TEST(EqMatrixOperatorTests, Test1) {
        S21Matrix m1(4, 7);
        m1.Fill(0.9);
        
        S21Matrix m2(4, 7);
        m2.Fill(0.9);

        const bool result = m1 == m2;
        EXPECT_TRUE(result);
    }

    TEST(EqMatrixOperatorTests, Test2) {
        S21Matrix m1(4, 7);
        m1.Fill(0.99875);
        
        S21Matrix m2(4, 7);
        m2.Fill(0.99875);

        const bool result = m1 == m2;
        EXPECT_TRUE(result);
    }

    TEST(EqMatrixOperatorTests, Test3Not) {
        S21Matrix m1(4, 7);
        m1.Fill(0.99875);
        
        S21Matrix m2(4, 7);
        m2.Fill(0.99875);

        m2(0, 0) = 1.0;

        const bool result = m1 == m2;
        EXPECT_FALSE(result);
    }

    TEST(EqMatrixOperatorTests, Test4Not) {
        S21Matrix m1(4, 7);
        m1.Fill(0.99875);
        
        S21Matrix m2(4, 8);
        m2.Fill(0.99875);

        const bool result = m1 == m2;
        EXPECT_FALSE(result);
    }

    TEST(EqMatrixOperatorTests, Test5Not) {
        S21Matrix m1(4, 7);
        m1.Fill(0.99875);
        
        S21Matrix m2(5, 8);
        m2.Fill(0.99875);

        const bool result = m1 == m2;
        EXPECT_FALSE(result);
    }

    TEST(EqMatrixOperatorTests, Test6) {
        S21Matrix m1({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });
        
        S21Matrix m2({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });

        const bool result = (m1 == m2);
        EXPECT_TRUE(result);
    }

    TEST(EqMatrixOperatorTests, Test7) {
        S21Matrix m1({
            {1.0,  2.0},
            {5.0,  6.0},
            {9.0, 10.0},
        });
        
        S21Matrix m2({
            {1.0,  2.0},
            {5.0,  6.0},
            {9.0, 10.0},
        });

        const bool result = (m1 == m2);
        EXPECT_TRUE(result);
    }

    TEST(EqMatrixOperatorTests, Test8Not) {
        S21Matrix m1({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });
        
        S21Matrix m2({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
        });

        const bool result = (m1 == m2);
        EXPECT_FALSE(result);
    }

    TEST(EqMatrixOperatorTests, Test9Not) {
        S21Matrix m1({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });
        
        S21Matrix m2({
            {1.0,  2.0,  3.0},
            {5.0,  6.0,  7.0},
            {9.0, 10.0, 11.0},
        });

        const bool result = (m1 == m2);
        EXPECT_FALSE(result);
    }

     TEST(EqMatrixOperatorTests, Test10Not) {
        S21Matrix m1({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });
        
        S21Matrix m2({
            {1.0,  2.0,  3.0},
            {5.0,  6.0,  7.0},
        });

        const bool result = (m1 == m2);
        EXPECT_FALSE(result);
    }
}