#include <gtest/gtest.h>
#include "../s21_matrix_oop.h"

namespace {
    TEST(AddTests, AddTest1) {
        S21Matrix m1(4,7);
        m1.Fill(0.9);
        m1.Print();
        
        int a = 14;
        int b = 88;

        const int result = a * b+1; //1232
        EXPECT_EQ(1232, result);
    }

    TEST(AddTests, AddTest2) {
        int a = 14;
        int b = 88;

        const float result = static_cast<float>(a) / static_cast<float>(b); //1232
        EXPECT_EQ(0.15090909090909f, result);
    }
}