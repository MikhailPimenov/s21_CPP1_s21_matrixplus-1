#include <gtest/gtest.h>

#include <exception>

#include "../s21_matrix_oop.h"

namespace {
TEST(ConstructorTests, Test0) {
  const S21Matrix m1;

  EXPECT_EQ(m1.GetRows(), 0);
  EXPECT_EQ(m1.GetColumns(), 0);
}

TEST(ConstructorTests, Test1WrongSize) {
  EXPECT_THROW(const S21Matrix m1(-1, 1), std::range_error);
  EXPECT_THROW(const S21Matrix m1(1, -1), std::range_error);
  EXPECT_THROW(const S21Matrix m1(0, 0), std::range_error);
  EXPECT_THROW(const S21Matrix m1(0, 1), std::range_error);
  EXPECT_THROW(const S21Matrix m1(1, 0), std::range_error);
  EXPECT_THROW(const S21Matrix m1(-1, -1), std::range_error);
  EXPECT_THROW(const S21Matrix m1(-9, -9), std::range_error);
}

TEST(ConstructorTests, Test2) {
  const S21Matrix m1(2, 3);

  EXPECT_EQ(m1.GetRows(), 2);
  EXPECT_EQ(m1.GetColumns(), 3);

  EXPECT_DOUBLE_EQ(m1(0, 0), 0.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 0.0);
  EXPECT_DOUBLE_EQ(m1(0, 2), 0.0);

  EXPECT_DOUBLE_EQ(m1(1, 0), 0.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 0.0);
  EXPECT_DOUBLE_EQ(m1(1, 2), 0.0);
}

TEST(ConstructorTests, Test3Square) {
  const S21Matrix m1(2);

  EXPECT_EQ(m1.GetRows(), 2);
  EXPECT_EQ(m1.GetColumns(), 2);

  EXPECT_DOUBLE_EQ(m1(0, 0), 0.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 0.0);

  EXPECT_DOUBLE_EQ(m1(1, 0), 0.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 0.0);
}

TEST(ConstructorTests, Test4Initializer) {
  const S21Matrix m1({
      {0.1, 0.2, 0.3},
      {0.4, 0.5, 0.6},
  });

  EXPECT_EQ(m1.GetRows(), 2);
  EXPECT_EQ(m1.GetColumns(), 3);

  EXPECT_DOUBLE_EQ(m1(0, 0), 0.1);
  EXPECT_DOUBLE_EQ(m1(0, 1), 0.2);
  EXPECT_DOUBLE_EQ(m1(0, 2), 0.3);

  EXPECT_DOUBLE_EQ(m1(1, 0), 0.4);
  EXPECT_DOUBLE_EQ(m1(1, 1), 0.5);
  EXPECT_DOUBLE_EQ(m1(1, 2), 0.6);
}

TEST(ConstructorTests, Test5CopyConstructor) {
  const S21Matrix m1({
      {0.1, 0.2, 0.3},
      {0.4, 0.5, 0.6},
  });

  const S21Matrix m2(m1);
  EXPECT_TRUE(m1 == m2);
}

TEST(ConstructorTests, Test6CopyConstructor) {
  const S21Matrix m1({
      {0.1, 0.2, 0.3},
      {0.4, 0.5, 0.6},
  });

  const S21Matrix m2 = m1;
  EXPECT_TRUE(m1 == m2);
}

TEST(ConstructorTests, Test7MoveConstructor) {
  S21Matrix m1({
      {0.1, 0.2, 0.3},
      {0.4, 0.5, 0.6},
  });

  const S21Matrix actual(std::move(m1));

  const S21Matrix expected({
      {0.1, 0.2, 0.3},
      {0.4, 0.5, 0.6},
  });

  EXPECT_TRUE(actual == expected);
  EXPECT_EQ(m1.GetRows(), 0);
  EXPECT_EQ(m1.GetColumns(), 0);
}

TEST(ConstructorTests, Test8MoveConstructor) {
  S21Matrix m1({
      {0.1, 0.2, 0.3},
      {0.4, 0.5, 0.6},
  });

  const S21Matrix actual = std::move(m1);

  const S21Matrix expected({
      {0.1, 0.2, 0.3},
      {0.4, 0.5, 0.6},
  });

  EXPECT_TRUE(actual == expected);
  EXPECT_EQ(m1.GetRows(), 0);
  EXPECT_EQ(m1.GetColumns(), 0);
}

TEST(AssignmentOperatorTests, Test9CopyAssignment) {
  const S21Matrix m1({
      {0.1, 0.2, 0.3},
      {0.4, 0.5, 0.6},
  });

  S21Matrix actual(5, 6);
  actual = m1;

  const S21Matrix expected({
      {0.1, 0.2, 0.3},
      {0.4, 0.5, 0.6},
  });

  EXPECT_TRUE(actual == expected);
}

TEST(AssignmentOperatorTests, Test10CopyAssignmentSelf) {
  const S21Matrix m1({
      {0.1, 0.2, 0.3},
      {0.4, 0.5, 0.6},
  });

  S21Matrix actual(m1);
  actual = actual;

  const S21Matrix expected({
      {0.1, 0.2, 0.3},
      {0.4, 0.5, 0.6},
  });

  EXPECT_TRUE(actual == expected);
}

TEST(AssignmentOperatorTests, Test11MoveAssignment) {
  S21Matrix m1({
      {0.1, 0.2, 0.3},
      {0.4, 0.5, 0.6},
  });

  S21Matrix actual(5, 6);
  actual = std::move(m1);

  const S21Matrix expected({
      {0.1, 0.2, 0.3},
      {0.4, 0.5, 0.6},
  });

  EXPECT_TRUE(actual == expected);
  EXPECT_EQ(m1.GetRows(), 0);
  EXPECT_EQ(m1.GetColumns(), 0);
}

TEST(AssignmentOperatorTests, Test12MoveAssignmentSelf) {
  S21Matrix m1({
      {0.1, 0.2, 0.3},
      {0.4, 0.5, 0.6},
  });

  S21Matrix actual = m1;
  actual = std::move(actual);

  const S21Matrix expected({
      {0.1, 0.2, 0.3},
      {0.4, 0.5, 0.6},
  });

  EXPECT_TRUE(actual == expected);
}

TEST(AssignmentOperatorTests, Test13AssignmentInitializer) {
  S21Matrix m1({
      {0.1, 0.2, 0.3},
      {0.4, 0.5, 0.6},
  });

  S21Matrix actual(m1);
  actual = {
      {0.1, 0.2, 0.3, 0.4, 0.5, 0.6}, {0.1, 0.2, 0.3, 0.4, 0.5, 0.6},
      {0.1, 0.2, 0.3, 0.4, 0.5, 0.6}, {0.1, 0.2, 0.3, 0.4, 0.5, 0.6},
      {0.1, 0.2, 0.3, 0.4, 0.5, 0.6}, {0.1, 0.2, 0.3, 0.4, 0.5, 0.6},
      {0.1, 0.2, 0.3, 0.4, 0.5, 0.6},
  };

  const S21Matrix expected({
      {0.1, 0.2, 0.3, 0.4, 0.5, 0.6},
      {0.1, 0.2, 0.3, 0.4, 0.5, 0.6},
      {0.1, 0.2, 0.3, 0.4, 0.5, 0.6},
      {0.1, 0.2, 0.3, 0.4, 0.5, 0.6},
      {0.1, 0.2, 0.3, 0.4, 0.5, 0.6},
      {0.1, 0.2, 0.3, 0.4, 0.5, 0.6},
      {0.1, 0.2, 0.3, 0.4, 0.5, 0.6},
  });

  EXPECT_TRUE(actual == expected);
}
}  // namespace
