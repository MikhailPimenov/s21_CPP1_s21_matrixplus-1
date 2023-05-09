#include <gtest/gtest.h>
#include "../s21_matrix_oop.h"

namespace {
    TEST(PrintVisualTests, Test0) {
        S21Matrix m1({
            {1.1, 2.2, 3.3, 4.4},
            {5.5, 6.6, 7.7, 8.8},
        });
        m1.Print();
        EXPECT_TRUE(true);
    }

    TEST(PrintVisualTests, Test1) {
        S21Matrix m1(3, 4);
        m1.Fill();
        m1.Print();
        EXPECT_TRUE(true);
    }
}