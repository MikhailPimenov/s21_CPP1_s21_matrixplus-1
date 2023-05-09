#include <gtest/gtest.h>

#include <exception>

#include "../s21_matrix_oop.h"

namespace {
TEST(SubMatrixTests, SubTest1) {
  S21Matrix m1(4, 7);
  m1.Fill(0.9);

  S21Matrix m2(4, 7);
  m2.Fill(0.9);

  S21Matrix expected(4, 7);
  expected.Fill(0.0);

  m1.SubMatrix(m2);
  const bool result = (m1 == expected);
  EXPECT_TRUE(result);
}

TEST(SubMatrixTests, SubTest2) {
  S21Matrix m1(4, 7);
  m1.Fill(0.9);

  S21Matrix m2(4, 7);
  m2.Fill(0.11);

  S21Matrix expected(4, 7);
  expected.Fill(0.79);

  m1.SubMatrix(m2);
  const bool result = (m1 == expected);
  EXPECT_TRUE(result);
}

TEST(SubMatrixTests, SubTest3WrongSize) {
  S21Matrix m1(4, 7);
  m1.Fill(0.9);

  S21Matrix m2(4, 8);
  m2.Fill(0.11);

  EXPECT_THROW(m1.SubMatrix(m2), std::range_error);
}

TEST(SubMatrixTests, SubTest4) {
  S21Matrix m1(4, 7);
  m1.Fill(0.9);
  m1(0, 0) = 0.2;

  S21Matrix m2(4, 7);
  m2.Fill(0.11);
  m2(0, 0) = 0.2;

  S21Matrix expected(4, 7);
  expected.Fill(0.79);
  expected(0, 0) = 0.0;

  m1.SubMatrix(m2);
  const bool result = (m1 == expected);
  EXPECT_TRUE(result);
}

TEST(SubMatrixTests, SubTest5) {
  S21Matrix m1({
      {1.0, 2.0, 3.0, 4.0},
      {5.0, 6.0, 7.0, 8.0},
      {9.0, 10.0, 11.0, 12.0},
  });

  const S21Matrix m2({
      {1.0, 2.0, 3.0, 4.0},
      {5.0, 6.0, 7.0, 8.0},
      {9.0, 10.0, 11.0, 12.0},
  });

  S21Matrix expected(3, 4);
  expected.Fill(0.0);

  m1.SubMatrix(m2);
  const bool result = (m1 == expected);
  EXPECT_TRUE(result);
}

TEST(SubMatrixTests, SubTest6WrongSize) {
  S21Matrix m1({
      {1.0, 2.0, 3.0, 4.0},
      {5.0, 6.0, 7.0, 8.0},
      {9.0, 10.0, 11.0, 12.0},
  });

  const S21Matrix m2({
      {1.0, 2.0, 4.0},
      {5.0, 6.0, 8.0},
      {9.0, 10.0, 12.0},
  });

  EXPECT_THROW(m1.SubMatrix(m2), std::range_error);
}

TEST(SubMatrixOperatorMinusEqualTests, SubTest1) {
  S21Matrix m1(4, 7);
  m1.Fill(0.9);

  S21Matrix m2(4, 7);
  m2.Fill(0.9);

  S21Matrix expected(4, 7);
  expected.Fill(0.0);

  m1 -= m2;
  const bool result = (m1 == expected);
  EXPECT_TRUE(result);
}

TEST(SubMatrixOperatorMinusEqualTests, SubTest2) {
  S21Matrix m1(4, 7);
  m1.Fill(0.9);

  S21Matrix m2(4, 7);
  m2.Fill(0.11);

  S21Matrix expected(4, 7);
  expected.Fill(0.79);

  m1 -= m2;
  const bool result = (m1 == expected);
  EXPECT_TRUE(result);
}

TEST(SubMatrixOperatorMinusEqualTests, SubTest3WrongSize) {
  S21Matrix m1(4, 7);
  m1.Fill(0.9);

  S21Matrix m2(4, 8);
  m2.Fill(0.11);

  EXPECT_THROW(m1 -= m2, std::range_error);
}

TEST(SubMatrixOperatorMinusEqualTests, SubTest4) {
  S21Matrix m1(4, 7);
  m1.Fill(0.9);
  m1(0, 0) = 0.2;

  S21Matrix m2(4, 7);
  m2.Fill(0.11);
  m2(0, 0) = 0.2;

  S21Matrix expected(4, 7);
  expected.Fill(0.79);
  expected(0, 0) = 0.0;

  m1 -= m2;
  const bool result = (m1 == expected);
  EXPECT_TRUE(result);
}

TEST(SubMatrixOperatorMinusEqualTests, SubTest5) {
  S21Matrix m1({
      {1.0, 2.0, 3.0, 4.0},
      {5.0, 6.0, 7.0, 8.0},
      {9.0, 10.0, 11.0, 12.0},
  });

  const S21Matrix m2({
      {1.0, 2.0, 3.0, 4.0},
      {5.0, 6.0, 7.0, 8.0},
      {9.0, 10.0, 11.0, 12.0},
  });

  S21Matrix expected(3, 4);
  expected.Fill(0.0);

  m1 -= m2;
  const bool result = (m1 == expected);
  EXPECT_TRUE(result);
}

TEST(SubMatrixOperatorMinusEqualTests, SubTest6WrongSize) {
  S21Matrix m1({
      {1.0, 2.0, 3.0, 4.0},
      {5.0, 6.0, 7.0, 8.0},
      {9.0, 10.0, 11.0, 12.0},
  });

  const S21Matrix m2({
      {1.0, 2.0, 4.0},
      {5.0, 6.0, 8.0},
      {9.0, 10.0, 12.0},
  });

  const S21Matrix expected({
      {2.0, 4.0, 6.0, 8.0},
      {10.0, 12.0, 14.0, 16.0},
      {18.0, 20.0, 22.0, 24.0},
  });

  EXPECT_THROW(m1 -= m2, std::range_error);
}
}  // namespace