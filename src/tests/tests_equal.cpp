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

}  // namespace