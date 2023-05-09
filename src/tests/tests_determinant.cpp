#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

namespace {
TEST(DeterminantTests, Test0) {
  const S21Matrix m1({
      {1.0, 2.0, 3.0},
      {3.0, 3.0, 3.0},
      {7.0, 2.0, 3.0},
  });

  const double actual = m1.Determinant();
  const double expected = -18.0;
  EXPECT_DOUBLE_EQ(actual, expected);
}

TEST(DeterminantTests, Test1) {
  const S21Matrix m1({{1.5}});

  const double actual = m1.Determinant();
  const double expected = 1.5;
  EXPECT_DOUBLE_EQ(actual, expected);
}

TEST(DeterminantTests, Test2) {
  const S21Matrix m1({
      {5.0, 2.0, 3.0},
      {3.0, 3.0, 3.0},
      {7.0, 2.0, 3.0},
  });

  const double actual = m1.Determinant();
  const double expected = -6.0;
  EXPECT_DOUBLE_EQ(actual, expected);
}

TEST(DeterminantTests, Test3) {
  const S21Matrix m1({
      {5.0, 2.0, 3.0, 7.0},
      {3.0, 3.0, 3.0, 6.0},
      {7.0, 2.0, 3.0, 2.0},
      {7.0, 1.0, 1.0, 2.0},
  });

  const double actual = m1.Determinant();
  const double expected = -90.0;
  EXPECT_DOUBLE_EQ(actual, expected);
}

TEST(DeterminantTests, Test4) {
  const S21Matrix m1({
      {5.0, 2.0, 3.0, 6.0, 7.0},
      {3.0, 3.0, 1.0, 3.0, 6.0},
      {2.0, 3.0, 2.0, 4.0, 6.0},
      {7.0, 9.0, 2.0, 3.0, 2.0},
      {7.0, 1.0, 8.0, 1.0, 2.0},
  });

  const double actual = m1.Determinant();
  const double expected = -2234.0;
  EXPECT_DOUBLE_EQ(actual, expected);
}

TEST(DeterminantTests, Test5) {
  const S21Matrix m1({
      {5.5, 2.0, 3.0, 6.0, 7.0},
      {3.0, 3.5, 1.0, 3.5, 6.5},
      {2.0, 3.5, 2.0, 4.0, 6.0},
      {7.5, 9.0, 2.0, 3.0, 2.0},
      {7.0, 1.5, 8.0, 1.5, 2.0},
  });

  const double actual = m1.Determinant();
  const double expected = -2285.4375;
  EXPECT_DOUBLE_EQ(actual, expected);
}

TEST(DeterminantTests, Test6) {
  const S21Matrix m1({
      {5.5, 2.0, 3.0, 6.0, 7.0},
      {3.0, 3.5, 1.0, 3.5, 6.5},
      {2.0, 3.5, 2.0, 4.0, 6.0},
      {2.0, 3.5, 2.0, 4.0, 6.0},
      {7.0, 1.5, 8.0, 1.5, 2.0},
  });

  const double actual = m1.Determinant();
  const double expected = 0.0;
  EXPECT_DOUBLE_EQ(actual, expected);
}

TEST(DeterminantTests, Test7) {
  const S21Matrix m1({
      {5.5, 2.0, 3.0, 6.0, 6.0},
      {3.0, 3.5, 1.0, 3.5, 3.5},
      {2.0, 3.5, 4.0, 4.0, 4.0},
      {2.0, 3.5, 2.0, 5.0, 5.0},
      {7.0, 1.5, 8.0, 1.5, 1.5},
  });

  const double actual = m1.Determinant();
  const double expected = 0.0;
  EXPECT_DOUBLE_EQ(actual, expected);
}

TEST(DeterminantTests, Test8WrongSize) {
  const S21Matrix m1({
      {5.5, 2.0, 3.0, 6.0, 6.0},
      {3.0, 3.5, 1.0, 3.5, 3.5},
      {2.0, 3.5, 2.0, 5.0, 5.0},
      {7.0, 1.5, 8.0, 1.5, 1.5},
  });

  EXPECT_THROW(m1.Determinant(), std::range_error);
}

TEST(DeterminantTests, Test9WrongSize) {
  const S21Matrix m1({
      {5.5, 3.0, 6.0, 6.0},
      {3.0, 1.0, 3.5, 3.5},
      {2.0, 4.0, 4.0, 4.0},
      {2.0, 2.0, 5.0, 5.0},
      {7.0, 8.0, 1.5, 1.5},
  });

  EXPECT_THROW(m1.Determinant(), std::range_error);
}
}  // namespace