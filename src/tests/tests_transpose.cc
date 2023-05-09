#include <gtest/gtest.h>
#include "../s21_matrix_oop.h"

namespace {
    TEST(TransposeTests, Test0) {
        const S21Matrix m1({
            {1.0, 2.0, 3.0},
        });

        const auto m2 = m1.Transpose();

        const S21Matrix expected({
            {1.0},
            {2.0},
            {3.0},
        });

        const bool result = (m2 == expected);
        EXPECT_TRUE(result);
    }


    TEST(TransposeTests, Test1) {
        const S21Matrix m1({
            {1.5, 2.5, 3.5, 4.5},
            {5.5, 6.5, 7.5, 8.5},
        });

        const auto m2 = m1.Transpose();

        const S21Matrix expected({
            {1.5, 5.5},
            {2.5, 6.5},
            {3.5, 7.5},
            {4.5, 8.5},
        });

        const bool result = (m2 == expected);
        EXPECT_TRUE(result);
    }


    TEST(TransposeTests, Test2) {
        const S21Matrix m1({
            {1.5},
        });

        const auto m2 = m1.Transpose();

        const S21Matrix expected({
            {1.5},
        });

        const bool result = (m2 == expected);
        EXPECT_TRUE(result);
    }

    TEST(TransposeTests, Test3) {
        const S21Matrix m1({
            { 1.5,  2.5,  3.5,  4.5},
            { 5.5,  6.5,  7.5,  8.5},
            { 9.5, 10.5, 11.5, 12.5},
            {13.5, 14.5, 15.5, 16.5},
        });

        const auto m2 = m1.Transpose();

        const S21Matrix expected({
            {1.5, 5.5,  9.5, 13.5},
            {2.5, 6.5, 10.5, 14.5},
            {3.5, 7.5, 11.5, 15.5},
            {4.5, 8.5, 12.5, 16.5},
        });

        const bool result = (m2 == expected);
        EXPECT_TRUE(result);
    }
}