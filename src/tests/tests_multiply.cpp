#include <gtest/gtest.h>
#include "../s21_matrix_oop.h"
#include <exception>

namespace {
     TEST(SumMatrixOperatorTests, Test0) {
        const S21Matrix m1({
            {0.0, 0.0, 0.0},
            {0.0, 0.0, 0.0},
            {0.0, 0.0, 0.0},
            {0.0, 0.0, 0.0},
        });

        const S21Matrix m2({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });

        const auto actual = m1 * m2;

        const S21Matrix expected({
            {0.0, 0.0, 0.0},
            {0.0, 0.0, 0.0},
            {0.0, 0.0, 0.0},
        });

        const bool result = (actual == expected);
        EXPECT_TRUE(result);
    }

}