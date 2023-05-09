#include <gtest/gtest.h>
#include "../s21_matrix_oop.h"
#include <exception>

namespace {
    TEST(BraceOperatorTests, Test0) {
        S21Matrix actual(3, 4);

        double i = 1.0;
        for (int row = 0; row < 3; ++row) {
            for (int column = 0; column < 4; ++column) {
                actual(row, column) = i;
                ++i;
            }
        } 

        const S21Matrix expected({
            {1.0,  2.0,  3.0,  4.0},
            {5.0,  6.0,  7.0,  8.0},
            {9.0, 10.0, 11.0, 12.0},
        });

        const bool result = (actual == expected);
        EXPECT_TRUE(result);
    }

    TEST(BraceOperatorTests, Test1) {
        S21Matrix actual(10, 10);

        double i = 1.0;
        for (int row = 0; row < 10; ++row) {
            for (int column = 0; column < 10; ++column) {
                actual(row, column) = i;
                ++i;
            }
        } 

        const S21Matrix expected({
            { 1.0,  2.0,  3.0,  4.0,  5.0,  6.0,  7.0,  8.0,  9.0,  10.0},
            {11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0,  20.0},
            {21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0,  30.0},
            {31.0, 32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0, 39.0,  40.0},
            {41.0, 42.0, 43.0, 44.0, 45.0, 46.0, 47.0, 48.0, 49.0,  50.0},
            {51.0, 52.0, 53.0, 54.0, 55.0, 56.0, 57.0, 58.0, 59.0,  60.0},
            {61.0, 62.0, 63.0, 64.0, 65.0, 66.0, 67.0, 68.0, 69.0,  70.0},
            {71.0, 72.0, 73.0, 74.0, 75.0, 76.0, 77.0, 78.0, 79.0,  80.0},
            {81.0, 82.0, 83.0, 84.0, 85.0, 86.0, 87.0, 88.0, 89.0,  90.0},
            {91.0, 92.0, 93.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0, 100.0},
        });

        const bool result = (actual == expected);
        EXPECT_TRUE(result);
    }


    TEST(BraceOperatorTests, Test2WrongIndex) {
        S21Matrix actual(10, 10);

        EXPECT_THROW(actual(11, 1), std::out_of_range);
    }

    TEST(BraceOperatorTests, Test3WrongIndex) {
        S21Matrix actual(10, 10);

        EXPECT_THROW(actual(0, 15), std::out_of_range);
    }

    TEST(BraceOperatorTests, Test4WrongIndex) {
        S21Matrix actual(10, 10);

        EXPECT_THROW(actual(15, 15), std::out_of_range);
    }

    TEST(BraceOperatorTests, Test5WrongIndex) {
        S21Matrix actual(10, 10);

        EXPECT_THROW(actual(-15, -15), std::out_of_range);
    }

    TEST(BraceOperatorTests, Test6) {
        const S21Matrix m1({
            { 1.0,  2.0,  3.0,  4.0,  5.0,  6.0,  7.0,  8.0,  9.0,  10.0},
            {11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0,  20.0},
            {21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0,  30.0},
            {31.0, 32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0, 39.0,  40.0},
            {41.0, 42.0, 43.0, 44.0, 45.0, 46.0, 47.0, 48.0, 49.0,  50.0},
            {51.0, 52.0, 53.0, 54.0, 55.0, 56.0, 57.0, 58.0, 59.0,  60.0},
            {61.0, 62.0, 63.0, 64.0, 65.0, 66.0, 67.0, 68.0, 69.0,  70.0},
            {71.0, 72.0, 73.0, 74.0, 75.0, 76.0, 77.0, 78.0, 79.0,  80.0},
            {81.0, 82.0, 83.0, 84.0, 85.0, 86.0, 87.0, 88.0, 89.0,  90.0},
            {91.0, 92.0, 93.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0, 100.0},
        });

        
        EXPECT_DOUBLE_EQ(m1(0, 0),  1.0);
        EXPECT_DOUBLE_EQ(m1(1, 1), 12.0);
        EXPECT_DOUBLE_EQ(m1(2, 2), 23.0);
        EXPECT_DOUBLE_EQ(m1(3, 3), 34.0);
        EXPECT_DOUBLE_EQ(m1(4, 4), 45.0);

        EXPECT_DOUBLE_EQ(m1(0, 1),  2.0);
        EXPECT_DOUBLE_EQ(m1(0, 2),  3.0);
        EXPECT_DOUBLE_EQ(m1(0, 3),  4.0);
        EXPECT_DOUBLE_EQ(m1(0, 9), 10.0);

        EXPECT_DOUBLE_EQ(m1(1, 0), 11.0);
        EXPECT_DOUBLE_EQ(m1(2, 0), 21.0);
        EXPECT_DOUBLE_EQ(m1(3, 0), 31.0);
        EXPECT_DOUBLE_EQ(m1(9, 0), 91.0);

    }

    TEST(BraceOperatorTests, Test7PythonStyleIndices) {
        const S21Matrix m1({
            { 1.0,  2.0,  3.0,  4.0,  5.0,  6.0,  7.0,  8.0,  9.0,  10.0},
            {11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0,  20.0},
            {21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0,  30.0},
            {31.0, 32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0, 39.0,  40.0},
            {41.0, 42.0, 43.0, 44.0, 45.0, 46.0, 47.0, 48.0, 49.0,  50.0},
            {51.0, 52.0, 53.0, 54.0, 55.0, 56.0, 57.0, 58.0, 59.0,  60.0},
            {61.0, 62.0, 63.0, 64.0, 65.0, 66.0, 67.0, 68.0, 69.0,  70.0},
            {71.0, 72.0, 73.0, 74.0, 75.0, 76.0, 77.0, 78.0, 79.0,  80.0},
            {81.0, 82.0, 83.0, 84.0, 85.0, 86.0, 87.0, 88.0, 89.0,  90.0},
            {91.0, 92.0, 93.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0, 100.0},
        });

        
        EXPECT_DOUBLE_EQ(m1(-1, -1), 100.0);
        EXPECT_DOUBLE_EQ(m1(-2, -2),  89.0);
        EXPECT_DOUBLE_EQ(m1(-3, -3),  78.0);
        EXPECT_DOUBLE_EQ(m1(-4, -4),  67.0);

        EXPECT_DOUBLE_EQ(m1(0,  -1), 10.0);
        EXPECT_DOUBLE_EQ(m1(0,  -2),  9.0);
        EXPECT_DOUBLE_EQ(m1(0,  -3),  8.0);
        EXPECT_DOUBLE_EQ(m1(0,  -9),  2.0);
        EXPECT_DOUBLE_EQ(m1(0, -10),  1.0);

        EXPECT_DOUBLE_EQ(m1( -1, 0), 91.0);
        EXPECT_DOUBLE_EQ(m1( -2, 0), 81.0);
        EXPECT_DOUBLE_EQ(m1( -3, 0), 71.0);
        EXPECT_DOUBLE_EQ(m1( -9, 0), 11.0);
        EXPECT_DOUBLE_EQ(m1(-10, 0),  1.0);
    }


    TEST(BraceOperatorTests, Test8PythonStyleIndices) {
        S21Matrix m1({
            { 1.0,  2.0,  3.0,  4.0,  5.0,  6.0,  7.0,  8.0,  9.0,  10.0},
            {11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0,  20.0},
            {21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0,  30.0},
            {31.0, 32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0, 39.0,  40.0},
            {41.0, 42.0, 43.0, 44.0, 45.0, 46.0, 47.0, 48.0, 49.0,  50.0},
            {51.0, 52.0, 53.0, 54.0, 55.0, 56.0, 57.0, 58.0, 59.0,  60.0},
            {61.0, 62.0, 63.0, 64.0, 65.0, 66.0, 67.0, 68.0, 69.0,  70.0},
            {71.0, 72.0, 73.0, 74.0, 75.0, 76.0, 77.0, 78.0, 79.0,  80.0},
            {81.0, 82.0, 83.0, 84.0, 85.0, 86.0, 87.0, 88.0, 89.0,  90.0},
            {91.0, 92.0, 93.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0, 100.0},
        });

        
        m1(-5, -5) = 999.999;
        EXPECT_DOUBLE_EQ(m1(-5, -5), 999.999);
    }
}