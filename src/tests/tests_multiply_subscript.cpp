#include <gtest/gtest.h>

#include <exception>

#include "../s21_matrix_oop.h"

namespace {
TEST(MulNumberTests, Test1) {
  S21Matrix m1(4, 7);
  m1.Fill(0.9);

  const double number = 0.0;

  S21Matrix expected(4, 7);
  expected.Fill(0.0);

  m1.MulNumber(number);
  const bool result = (m1 == expected);
  EXPECT_TRUE(result);
}

TEST(MulNumberTests, Test2) {
  S21Matrix m1(4, 7);
  m1.Fill(0.9);

  const double number = 2.0;

  S21Matrix expected(4, 7);
  expected.Fill(1.8);

  m1.MulNumber(number);
  const bool result = (m1 == expected);
  EXPECT_TRUE(result);
}

TEST(MulNumberTests, Test3) {
  S21Matrix m1({
      {1.0, 2.0, 3.0, 4.0},
      {5.0, 6.0, 7.0, 8.0},
      {9.0, 10.0, 11.0, 12.0},
  });

  const double number = 2.0;

  const S21Matrix expected({
      {2.0, 4.0, 6.0, 8.0},
      {10.0, 12.0, 14.0, 16.0},
      {18.0, 20.0, 22.0, 24.0},
  });

  m1.MulNumber(number);
  const bool result = (m1 == expected);
  EXPECT_TRUE(result);
}

TEST(MulNumberTests, Test4) {
  S21Matrix m1({
      {1.05, 2.05, 3.025, 4.025},
      {5.05, 6.05, 7.025, 8.025},
      {9.05, 10.05, 11.025, 12.025},
  });

  const double number = 2.0;

  const S21Matrix expected({
      {2.1, 4.1, 6.05, 8.05},
      {10.1, 12.1, 14.05, 16.05},
      {18.1, 20.1, 22.05, 24.05},
  });

  m1.MulNumber(number);
  const bool result = (m1 == expected);
  EXPECT_TRUE(result);
}

TEST(MulNumberOperatorTests, Test1) {
  S21Matrix m1(4, 7);
  m1.Fill(0.9);

  const double number = 0.0;

  S21Matrix expected(4, 7);
  expected.Fill(0.0);

  m1 *= number;
  const bool result = (m1 == expected);
  EXPECT_TRUE(result);
}

TEST(MulNumberOperatorTests, Test2) {
  S21Matrix m1(4, 7);
  m1.Fill(0.9);

  const double number = 2.0;

  S21Matrix expected(4, 7);
  expected.Fill(1.8);

  m1 *= number;
  const bool result = (m1 == expected);
  EXPECT_TRUE(result);
}

TEST(MulNumberOperatorTests, Test3) {
  S21Matrix m1({
      {1.0, 2.0, 3.0, 4.0},
      {5.0, 6.0, 7.0, 8.0},
      {9.0, 10.0, 11.0, 12.0},
  });

  const double number = 2.0;

  const S21Matrix expected({
      {2.0, 4.0, 6.0, 8.0},
      {10.0, 12.0, 14.0, 16.0},
      {18.0, 20.0, 22.0, 24.0},
  });

  m1 *= number;
  const bool result = (m1 == expected);
  EXPECT_TRUE(result);
}

TEST(MulNumberOperatorTests, Test4) {
  S21Matrix m1({
      {1.05, 2.05, 3.025, 4.025},
      {5.05, 6.05, 7.025, 8.025},
      {9.05, 10.05, 11.025, 12.025},
  });

  const double number = 2.0;

  const S21Matrix expected({
      {2.1, 4.1, 6.05, 8.05},
      {10.1, 12.1, 14.05, 16.05},
      {18.1, 20.1, 22.05, 24.05},
  });

  m1 *= number;
  const bool result = (m1 == expected);
  EXPECT_TRUE(result);
}

TEST(MulMatrixSubscriptionTests, Test1) {
  S21Matrix m1({
      {1.0, 2.0, 3.0, 4.0},
      {5.0, 6.0, 7.0, 8.0},
      {9.0, 10.0, 11.0, 12.0},
  });

  const S21Matrix m2({
      {1.0, 2.0, 3.0, 4.0, 5.0},
      {6.0, 7.0, 8.0, 9.0, 10.0},
      {11.0, 12.0, 13.0, 14.0, 15.0},
      {16.0, 17.0, 18.0, 19.0, 20.0},
  });

  const S21Matrix expected({
      {110.0, 120.0, 130.0, 140.0, 150.0},
      {246.0, 272.0, 298.0, 324.0, 350.0},
      {382.0, 424.0, 466.0, 508.0, 550.0},
  });

  m1.MulMatrix(m2);
  const bool result = (m1 == expected);
  EXPECT_TRUE(result);
}

TEST(MulMatrixSubscriptionTests, Test2) {
  S21Matrix m1({
      {1.0, 2.0, 3.0, 4.0},
      {5.0, 6.0, 7.0, 8.0},
      {9.0, 10.0, 11.0, 12.0},
  });

  const S21Matrix m2({
      {1.0},
      {2.0},
      {3.0},
      {4.0},
  });

  const S21Matrix expected({
      {30.0},
      {70.0},
      {110.0},
  });

  m1.MulMatrix(m2);
  const bool result = (m1 == expected);
  EXPECT_TRUE(result);
}

TEST(MulMatrixSubscriptionTests, Test3) {
  S21Matrix m1({
      {1.0, 2.0, 3.0, 4.0},
      {5.0, 6.0, 7.0, 8.0},
      {9.0, 10.0, 11.0, 12.0},
  });

  const S21Matrix m2({
      {1.0, 2.0},
      {3.0, 4.0},
      {5.0, 6.0},
      {7.0, 8.0},
  });

  const S21Matrix expected({
      {50.0, 60.0},
      {114.0, 140.0},
      {178.0, 220.0},
  });

  m1.MulMatrix(m2);
  const bool result = (m1 == expected);
  EXPECT_TRUE(result);
}

TEST(MulMatrixSubscriptionTests, Test4WrongSize) {
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

  EXPECT_THROW(m1.MulMatrix(m2), std::range_error);
}

TEST(MulMatrixSubscriptionTests, Test5WrongSize) {
  S21Matrix m1({
      {1.0, 2.0, 3.0, 4.0},
      {5.0, 6.0, 7.0, 8.0},
      {9.0, 10.0, 11.0, 12.0},
  });

  const S21Matrix m2({
      {1.0, 2.0},
      {3.0, 4.0},
      {5.0, 6.0},
  });

  EXPECT_THROW(m1.MulMatrix(m2), std::range_error);
}

TEST(MulMatrixSubscriptionOperatorTests, Test1) {
  S21Matrix m1({
      {1.0, 2.0, 3.0, 4.0},
      {5.0, 6.0, 7.0, 8.0},
      {9.0, 10.0, 11.0, 12.0},
  });

  const S21Matrix m2({
      {1.0, 2.0, 3.0, 4.0, 5.0},
      {6.0, 7.0, 8.0, 9.0, 10.0},
      {11.0, 12.0, 13.0, 14.0, 15.0},
      {16.0, 17.0, 18.0, 19.0, 20.0},
  });

  const S21Matrix expected({
      {110.0, 120.0, 130.0, 140.0, 150.0},
      {246.0, 272.0, 298.0, 324.0, 350.0},
      {382.0, 424.0, 466.0, 508.0, 550.0},
  });

  m1 *= m2;
  const bool result = (m1 == expected);
  EXPECT_TRUE(result);
}

TEST(MulMatrixSubscriptionOperatorTests, Test2) {
  S21Matrix m1({
      {1.0, 2.0, 3.0, 4.0},
      {5.0, 6.0, 7.0, 8.0},
      {9.0, 10.0, 11.0, 12.0},
  });

  const S21Matrix m2({
      {1.0},
      {2.0},
      {3.0},
      {4.0},
  });

  const S21Matrix expected({
      {30.0},
      {70.0},
      {110.0},
  });

  m1 *= m2;
  const bool result = (m1 == expected);
  EXPECT_TRUE(result);
}

TEST(MulMatrixSubscriptionOperatorTests, Test3) {
  S21Matrix m1({
      {1.0, 2.0, 3.0, 4.0},
      {5.0, 6.0, 7.0, 8.0},
      {9.0, 10.0, 11.0, 12.0},
  });

  const S21Matrix m2({
      {1.0, 2.0},
      {3.0, 4.0},
      {5.0, 6.0},
      {7.0, 8.0},
  });

  const S21Matrix expected({
      {50.0, 60.0},
      {114.0, 140.0},
      {178.0, 220.0},
  });

  m1 *= m2;
  const bool result = (m1 == expected);
  EXPECT_TRUE(result);
}

TEST(MulMatrixSubscriptionOperatorTests, Test4WrongSize) {
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

  EXPECT_THROW(m1 *= m2, std::range_error);
}

TEST(MulMatrixSubscriptionOperatorTests, Test5WrongSize) {
  S21Matrix m1({
      {1.0, 2.0, 3.0, 4.0},
      {5.0, 6.0, 7.0, 8.0},
      {9.0, 10.0, 11.0, 12.0},
  });

  const S21Matrix m2({
      {1.0, 2.0},
      {3.0, 4.0},
      {5.0, 6.0},
  });

  EXPECT_THROW(m1 *= m2, std::range_error);
}

}  // namespace