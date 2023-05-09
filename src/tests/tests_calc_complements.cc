#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

namespace {
TEST(CalcComplementsTests, Test0) {
  const S21Matrix m1({
      {1.0, 2.0, 3.0},
      {0.0, 4.0, 2.0},
      {5.0, 2.0, 1.0},
  });

  const S21Matrix actual = m1.CalcComplements();
  const S21Matrix expected({
      {0.0, 10.0, -20.0},
      {4.0, -14.0, 8.0},
      {-8.0, -2.0, 4.0},
  });

  const bool result = (actual == expected);
  EXPECT_TRUE(result);
}

TEST(CalcComplementsTests, Test1) {
  const S21Matrix m1({
      {1.0, 2.0, 3.0},
      {4.0, 5.0, 6.0},
      {7.0, 8.0, 9.0},
  });

  const S21Matrix actual = m1.CalcComplements();
  const S21Matrix expected({
      {-3.0, 6.0, -3.0},
      {6.0, -12.0, 6.0},
      {-3.0, 6.0, -3.0},
  });

  const bool result = (actual == expected);
  EXPECT_TRUE(result);
}

TEST(CalcComplementsTests, Test2WrongSize) {
  const S21Matrix m1({
      {1.0, 2.0, 3.0},
      {4.0, 5.0, 6.0},
  });

  EXPECT_THROW(m1.CalcComplements(), std::range_error);
}

TEST(CalcComplementsTests, Test3WrongSize) {
  const S21Matrix m1({
      {1.0},
      {4.0},
  });

  EXPECT_THROW(m1.CalcComplements(), std::range_error);
}
}  // namespace