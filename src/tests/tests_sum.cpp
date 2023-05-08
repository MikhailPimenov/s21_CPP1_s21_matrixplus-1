#include <gtest/gtest.h>
#include "../s21_matrix_oop.h"
#include <exception>

namespace {
     TEST(SumMatrixOperatorTests, Test0) {
        const S21Matrix m1({
            {0.0, 0.0, 0.0, 0.0},
            {0.0, 0.0, 0.0, 0.0},
            {0.0, 0.0, 0.0, 0.0},
        });

        const S21Matrix m2({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });

        const auto actual = m1 + m2;

        const S21Matrix expected({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });

        expected.Print("\t", "\n");
        actual.Print("\t", "\n");

        const bool result = (actual == expected);
        EXPECT_TRUE(result);
    }

    TEST(SumMatrixOperatorTests, Test1) {
        const S21Matrix m1({
            {1.5,  2.5,  3.5,  4.5},
            {5.5,  6.5,  7.5,  8.5},
            {9.5, 10.5, 11.5, 12.5},
        });

        const S21Matrix m2({
            {1.05,  2.05,  3.05,  4.05},
            {5.05,  6.05,  7.05,  8.05},
            {9.05, 10.05, 11.05, 12.05},
        });

        const auto actual = m1 + m2;

        const S21Matrix expected({
            { 2.55,  4.55,  6.55,  8.55},
            {10.55, 12.55, 14.55, 16.55},
            {18.55, 20.55, 22.55, 24.55},
        });

        const bool result = (actual == expected);
        EXPECT_TRUE(result);
    }

    TEST(SumMatrixOperatorTests, Test2) {
        const S21Matrix m1({
            {1.5,  2.5,  3.5,  4.5},
            {5.5,  6.5,  7.5,  8.5},
            {9.5, 10.5, 11.5, 12.5},
        });

        const S21Matrix m2({
            {1.05,  2.05,  3.05,  4.05},
            {5.05,  6.05,  7.05,  8.05},
            {9.05, 10.05, 11.05, 12.05},
        });

        const S21Matrix m3(3, 4);

        const auto actual = m1 + m2 + m3;
        
        const S21Matrix expected({
            { 2.55,  4.55,  6.55,  8.55},
            {10.55, 12.55, 14.55, 16.55},
            {18.55, 20.55, 22.55, 24.55},
        });

        const bool result = (actual == expected);
        EXPECT_TRUE(result);
    }

    TEST(SumMatrixOperatorTests, Test3) {
        const S21Matrix m1({
            {1.5,  2.5,  3.5,  4.5},
            {5.5,  6.5,  7.5,  8.5},
            {9.5, 10.5, 11.5, 12.5},
        });

        const S21Matrix m2({
            {1.05,  2.05,  3.05,  4.05},
            {5.05,  6.05,  7.05,  8.05},
            {9.05, 10.05, 11.05, 12.05},
        });

        const S21Matrix m3({
            {1.005,  2.005,  3.005,  4.005},
            {5.005,  6.005,  7.005,  8.005},
            {9.005, 10.005, 11.005, 12.005},
        });

        const auto actual = m1 + m2 + m3;
        
        const S21Matrix expected({
            { 3.555,  6.555,  9.555, 12.555},
            {15.555, 18.555, 21.555, 24.555},
            {27.555, 30.555, 33.555, 36.555},
        });

        const bool result = (actual == expected);
        EXPECT_TRUE(result);
    }

    TEST(SumMatrixOperatorTests, Test4) {
        const S21Matrix m1({
            {1.5,  2.5,  3.5,  4.5},
            {5.5,  6.5,  7.5,  8.5},
            {9.5, 10.5, 11.5, 12.5},
        });

        const S21Matrix m2({
            {1.05,  2.05,  3.05,  4.05},
            {5.05,  6.05,  7.05,  8.05},
            {9.05, 10.05, 11.05, 12.05},
        });

        const S21Matrix m3({
            {1.005,  2.005,  3.005,  4.005},
            {5.005,  6.005,  7.005,  8.005},
            {9.005, 10.005, 11.005, 12.005},
        });

        const S21Matrix m4({
            {1.0005,  2.0005,  3.0005,  4.0005},
            {5.0005,  6.0005,  7.0005,  8.0005},
            {9.0005, 10.0005, 11.0005, 12.0005},
        });

        const auto actual = m1 + m2 + m3 + m4;
        
        const S21Matrix expected({
            { 4.5555,  8.5555, 12.5555, 16.5555},
            {20.5555, 24.5555, 28.5555, 32.5555},
            {36.5555, 40.5555, 44.5555, 48.5555},
        });

        const bool result = (actual == expected);
        EXPECT_TRUE(result);
    }

    TEST(SumMatrixOperatorTests, Test5WrongSize) {
        const S21Matrix m1({
            {1.5,  2.5,  3.5,  4.5},
            {5.5,  6.5,  7.5,  8.5},
            {9.5, 10.5, 11.5, 12.5},
        });

        const S21Matrix m2({
            {1.05,  2.05,  3.05,  4.05},
            {5.05,  6.05,  7.05,  8.05},
            {9.05, 10.05, 11.05, 12.05},
        });

        const S21Matrix m3({
            {1.005,  2.005,  3.005,  4.005},
            {5.005,  6.005,  7.005,  8.005},
            {9.005, 10.005, 11.005, 12.005},
        });

        const S21Matrix m4({
            {1.0005,  2.0005,  3.0005,  4.0005},
            {5.0005,  6.0005,  7.0005,  8.0005},
            {9.0005, 10.0005, 11.0005, 12.0005},
            {9.0005, 10.0005, 11.0005, 12.0005},
            {9.0005, 10.0005, 11.0005, 12.0005},
            {9.0005, 10.0005, 11.0005, 12.0005},
        });

        EXPECT_THROW(m1 + m2 + m3 + m4, std::range_error);
    }
}