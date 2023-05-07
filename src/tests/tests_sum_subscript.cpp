#include <gtest/gtest.h>
#include "../s21_matrix_oop.h"
#include <exception>

namespace {
    TEST(SumMatrixTests, SumTest1) {
        S21Matrix m1(4, 7);
        m1.Fill(0.9);

        S21Matrix m2(4, 7);
        m2.Fill(0.9);

        S21Matrix expected(4, 7);
        expected.Fill(1.8);
        
        m1.SumMatrix(m2);
        const bool result = (m1 == expected);
        EXPECT_TRUE(result);
    }

    TEST(SumMatrixTests, SumTest2) {
        S21Matrix m1(4, 7);
        m1.Fill(0.9);

        S21Matrix m2(4, 7);
        m2.Fill(0.11);

        S21Matrix expected(4, 7);
        expected.Fill(1.01);
        
        m1.SumMatrix(m2);
        const bool result = (m1 == expected);
        EXPECT_TRUE(result);
    }

    TEST(SumMatrixTests, SumTest3WrongSize) {
        S21Matrix m1(4, 7);
        m1.Fill(0.9);

        S21Matrix m2(4, 8);
        m2.Fill(0.11);
        
        EXPECT_THROW(m1.SumMatrix(m2), std::range_error);
    }

    TEST(SumMatrixTests, SumTest4) {
        S21Matrix m1(4, 7);
        m1.Fill(0.9);
        m1(0, 0) = 0.2;

        S21Matrix m2(4, 7);
        m2.Fill(0.11);
        m2(0, 0) = 0.2;

        S21Matrix expected(4, 7);
        expected.Fill(1.01);
        expected(0, 0) = 0.4;
        
        m1.SumMatrix(m2);
        const bool result = (m1 == expected);
        EXPECT_TRUE(result);
    }

    TEST(SumMatrixTests, SumTest5) {
        S21Matrix m1({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });
        
        const S21Matrix m2({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });

        const S21Matrix expected({
            { 2.0,  4.0,  6.0,  8.0},
            {10.0, 12.0, 14.0, 16.0},
            {18.0, 20.0, 22.0, 24.0},
        });

        m1.SumMatrix(m2);
        const bool result = (m1 == expected);
        EXPECT_TRUE(result);
    }

    TEST(SumMatrixTests, SumTest6WrongSize) {
        S21Matrix m1({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });
        
        const S21Matrix m2({
            {1.0,  2.0,  4.0},
            {5.0,  6.0,  8.0},
            {9.0, 10.0, 12.0},
        });

        const S21Matrix expected({
            { 2.0,  4.0,  6.0,  8.0},
            {10.0, 12.0, 14.0, 16.0},
            {18.0, 20.0, 22.0, 24.0},
        });

        EXPECT_THROW(m1.SumMatrix(m2), std::range_error);
    }








    TEST(SumMatrixOperatorPlusEqualTests, SumTest1) {
        S21Matrix m1(4, 7);
        m1.Fill(0.9);

        S21Matrix m2(4, 7);
        m2.Fill(0.9);

        S21Matrix expected(4, 7);
        expected.Fill(1.8);
        
        m1 += m2;
        const bool result = (m1 == expected);
        EXPECT_TRUE(result);
    }

    TEST(SumMatrixOperatorPlusEqualTests, SumTest2) {
        S21Matrix m1(4, 7);
        m1.Fill(0.9);

        S21Matrix m2(4, 7);
        m2.Fill(0.11);

        S21Matrix expected(4, 7);
        expected.Fill(1.01);
        
        m1 += m2;
        const bool result = (m1 == expected);
        EXPECT_TRUE(result);
    }

    TEST(SumMatrixOperatorPlusEqualTests, SumTest3WrongSize) {
        S21Matrix m1(4, 7);
        m1.Fill(0.9);

        S21Matrix m2(4, 8);
        m2.Fill(0.11);
        
        EXPECT_THROW(m1 += m2, std::range_error);
    }

    TEST(SumMatrixOperatorPlusEqualTests, SumTest4) {
        S21Matrix m1(4, 7);
        m1.Fill(0.9);
        m1(0, 0) = 0.2;

        S21Matrix m2(4, 7);
        m2.Fill(0.11);
        m2(0, 0) = 0.2;

        S21Matrix expected(4, 7);
        expected.Fill(1.01);
        expected(0, 0) = 0.4;
        
        m1 += m2;
        const bool result = (m1 == expected);
        EXPECT_TRUE(result);
    }

    TEST(SumMatrixOperatorPlusEqualTests, SumTest5) {
        S21Matrix m1({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });
        
        const S21Matrix m2({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });

        const S21Matrix expected({
            { 2.0,  4.0,  6.0,  8.0},
            {10.0, 12.0, 14.0, 16.0},
            {18.0, 20.0, 22.0, 24.0},
        });

        m1 += m2;
        const bool result = (m1 == expected);
        EXPECT_TRUE(result);
    }

    TEST(SumMatrixOperatorPlusEqualTests, SumTest6WrongSize) {
        S21Matrix m1({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });
        
        const S21Matrix m2({
            {1.0,  2.0,  4.0},
            {5.0,  6.0,  8.0},
            {9.0, 10.0, 12.0},
        });

        const S21Matrix expected({
            { 2.0,  4.0,  6.0,  8.0},
            {10.0, 12.0, 14.0, 16.0},
            {18.0, 20.0, 22.0, 24.0},
        });

        EXPECT_THROW(m1 += m2, std::range_error);
    }
}