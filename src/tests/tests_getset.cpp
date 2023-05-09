#include <gtest/gtest.h>
#include "../s21_matrix_oop.h"
#include <exception>

namespace {
    TEST(GetSetTests, Test0Decrease) {
        S21Matrix actual({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });
        
        actual.SetColumns(3);
        const S21Matrix expected({
            {1.0,  2.0,  3.0},
            {5.0,  6.0,  7.0},
            {9.0, 10.0, 11.0},
        });

        const bool result = (actual == expected);
        EXPECT_TRUE(result);
    }

    TEST(GetSetTests, Test1Increase) {
        S21Matrix actual({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });
        
        actual.SetColumns(5);
        const S21Matrix expected({
            {1.0,  2.0,  3.0,  4.0, 0.0},
            {5.0,  6.0,  7.0,  8.0, 0.0},
            {9.0, 10.0, 11.0, 12.0, 0.0},
        });

        const bool result = (actual == expected);
        EXPECT_TRUE(result);
    }

    TEST(GetSetTests, Test2Decrease) {
        S21Matrix actual({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });
        
        actual.SetColumns(2);
        const S21Matrix expected({
            {1.0,  2.0},
            {5.0,  6.0},
            {9.0, 10.0},
        });

        const bool result = (actual == expected);
        EXPECT_TRUE(result);
    }

    TEST(GetSetTests, Test3Increase) {
        S21Matrix actual({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });
        
        actual.SetColumns(6);
        const S21Matrix expected({
            {1.0,  2.0,  3.0,  4.0, 0.0, 0.0},
            {5.0,  6.0,  7.0,  8.0, 0.0, 0.0},
            {9.0, 10.0, 11.0, 12.0, 0.0, 0.0},
        });

        const bool result = (actual == expected);
        EXPECT_TRUE(result);
    }







    TEST(GetSetTests, Test4Decrease) {
        S21Matrix actual({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });
        
        actual.SetRows(2);
        const S21Matrix expected({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
        });

        const bool result = (actual == expected);
        EXPECT_TRUE(result);
    }

    TEST(GetSetTests, Test5Increase) {
        S21Matrix actual({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });
        
        actual.SetRows(5);
        const S21Matrix expected({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
            {0.0,  0.0,  0.0,  0.0},
            {0.0,  0.0,  0.0,  0.0},
        });

        const bool result = (actual == expected);
        EXPECT_TRUE(result);
    }

    TEST(GetSetTests, Test6Decrease) {
        S21Matrix actual({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });
        
        actual.SetRows(2);
        const S21Matrix expected({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
        });

        const bool result = (actual == expected);
        EXPECT_TRUE(result);
    }

    TEST(GetSetTests, Test7Increase) {
        S21Matrix actual({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });
        
        actual.SetRows(6);
        const S21Matrix expected({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
            {0.0,  0.0,  0.0,  0.0},
            {0.0,  0.0,  0.0,  0.0},
            {0.0,  0.0,  0.0,  0.0},
        });

        const bool result = (actual == expected);
        EXPECT_TRUE(result);
    }

    TEST(GetSetTests, Test8WrongSize) {
        S21Matrix actual({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });
        
        EXPECT_THROW(actual.SetRows(-6), std::range_error);
    }

    TEST(GetSetTests, Test9WrongSize) {
        S21Matrix actual({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });
        
        EXPECT_THROW(actual.SetColumns(-6), std::range_error);
    }

    TEST(GetSetTests, Test10) {
        S21Matrix actual({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });
        
        EXPECT_EQ(actual.GetRows(), 3);
    }

    TEST(GetSetTests, Test11) {
        S21Matrix actual({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });
        
        EXPECT_EQ(actual.GetColumns(), 4);
    }


  TEST(GetSetTests, Test12Same) {
        S21Matrix actual({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });
        
        actual.SetColumns(4);
        const S21Matrix expected({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });

        const bool result = (actual == expected);
        EXPECT_TRUE(result);
    }

    TEST(GetSetTests, Test13Same) {
        S21Matrix actual({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });
        
        actual.SetRows(3);
        const S21Matrix expected({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });

        const bool result = (actual == expected);
        EXPECT_TRUE(result);
    }

}