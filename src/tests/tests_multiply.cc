#include <gtest/gtest.h>

#include <exception>

#include "../s21_matrix_oop.h"

namespace {
TEST(MultiplyMatrixOperatorTests, Test0) {
  const S21Matrix m1({
      {0.0, 0.0, 0.0},
      {0.0, 0.0, 0.0},
      {0.0, 0.0, 0.0},
      {0.0, 0.0, 0.0},
  });

  const S21Matrix m2({
      {1.0, 2.0, 3.0, 4.0},
      {5.0, 6.0, 7.0, 8.0},
      {9.0, 10.0, 11.0, 12.0},
  });

  const auto actual = m1 * m2;

  const S21Matrix expected({
      {0.0, 0.0, 0.0, 0.0},
      {0.0, 0.0, 0.0, 0.0},
      {0.0, 0.0, 0.0, 0.0},
      {0.0, 0.0, 0.0, 0.0},
  });

  const bool result = (actual == expected);
  EXPECT_TRUE(result);
}

TEST(MultiplyMatrixOperatorTests, Test1) {
  const S21Matrix m1({
      {0.0, 0.0, 0.0},
      {0.0, 0.0, 0.0},
      {0.0, 0.0, 0.0},
      {0.0, 0.0, 0.0},
  });

  const S21Matrix m2({
      {1.0, 2.0, 3.0, 4.0},
      {5.0, 6.0, 7.0, 8.0},
      {9.0, 10.0, 11.0, 12.0},
  });

  const auto actual = m2 * m1;

  const S21Matrix expected({
      {0.0, 0.0, 0.0},
      {0.0, 0.0, 0.0},
      {0.0, 0.0, 0.0},
  });

  const bool result = (actual == expected);
  EXPECT_TRUE(result);
}

TEST(MultiplyMatrixOperatorTests, Test2) {
  const S21Matrix m1({
      {1.0, 2.0, 3.0},
      {4.0, 5.0, 6.0},
      {7.0, 8.0, 9.0},
      {10.0, 11.0, 12.0},
  });

  const S21Matrix m2({
      {1.0, 2.0, 3.0, 4.0},
      {5.0, 6.0, 7.0, 8.0},
      {9.0, 10.0, 11.0, 12.0},
  });

  const auto actual = m1 * m2;

  const S21Matrix expected({
      {38.0, 44.0, 50.0, 56.0},
      {83.0, 98.0, 113.0, 128.0},
      {128.0, 152.0, 176.0, 200.0},
      {173.0, 206.0, 239.0, 272.0},
  });

  const bool result = (actual == expected);
  EXPECT_TRUE(result);
}

TEST(MultiplyMatrixOperatorTests, Test3) {
  const S21Matrix m1({
      {1.5, 2.5, 3.5},
  });

  const S21Matrix m2({
      {1.5},
      {5.5},
      {9.5},
  });

  const auto actual = m1 * m2;

  const S21Matrix expected({
      {49.25},
  });

  const bool result = (actual == expected);
  EXPECT_TRUE(result);
}

TEST(MultiplyMatrixOperatorTests, Test4) {
  const S21Matrix m1({
      {1.005, 2.005, 3.005, 4.005},
      {5.005, 6.005, 7.005, 8.005},
      {9.005, 10.005, 11.005, 12.005},
      {13.005, 14.005, 15.005, 16.005},
      {17.005, 18.005, 19.005, 20.005},
      {21.005, 22.005, 23.005, 24.005},
      {25.005, 26.005, 27.005, 28.005},
  });

  const S21Matrix m2({
      {101.05, 102.05, 103.05, 104.05, 105.05, 106.05, 107.05, 108.05},
      {109.05, 110.05, 111.05, 112.05, 113.05, 114.05, 115.05, 116.05},
      {117.05, 118.05, 119.05, 120.05, 121.05, 122.05, 123.05, 124.05},
      {125.05, 126.05, 127.05, 128.05, 129.05, 130.05, 131.05, 132.05},
  });

  const auto actual = m1 * m2;

  const S21Matrix expected({
      {1172.761, 1182.781, 1192.801, 1202.821, 1212.841, 1222.861, 1232.881,
       1242.901},
      {2981.561, 3007.581, 3033.601, 3059.621, 3085.641, 3111.661, 3137.681,
       3163.701},
      {4790.361, 4832.381, 4874.401, 4916.421, 4958.441, 5000.461, 5042.481,
       5084.501},
      {6599.161, 6657.181, 6715.201, 6773.221, 6831.241, 6889.261, 6947.281,
       7005.301},
      {8407.961, 8481.981, 8556.001, 8630.021, 8704.041, 8778.061, 8852.081,
       8926.101},
      {10216.761, 10306.781, 10396.801, 10486.821, 10576.841, 10666.861,
       10756.881, 10846.901},
      {12025.561, 12131.581, 12237.601, 12343.621, 12449.641, 12555.661,
       12661.681, 12767.701},
  });

  const bool result = (actual == expected);
  EXPECT_TRUE(result);
}

TEST(MultiplyMatrixOperatorTests, Test5) {
  const S21Matrix m1({
      {1.05, 2.05, 3.05},
      {4.05, 5.05, 6.05},
      {7.05, 8.05, 9.05},
      {10.05, 11.05, 12.05},
      {13.05, 14.05, 15.05},
      {16.05, 17.05, 18.05},
      {19.05, 20.05, 21.05},
  });

  const S21Matrix m2({
      {11.05, 12.05, 13.05, 14.05, 15.05, 16.05, 17.05, 18.05, 19.05},
      {20.05, 21.05, 22.05, 23.05, 24.05, 25.05, 26.05, 27.05, 28.05},
      {29.05, 30.05, 31.05, 32.05, 33.05, 34.05, 35.05, 36.05, 37.05},
  });

  const auto actual = m1 * m2;

  const S21Matrix expected({
      {141.3075, 147.4575, 153.6075, 159.7575, 165.9075, 172.0575, 178.2075,
       184.3575, 190.5075},
      {321.7575, 336.9075, 352.0575, 367.2075, 382.3575, 397.5075, 412.6575,
       427.8075, 442.9575},
      {502.2075, 526.3575, 550.5075, 574.6575, 598.8075, 622.9575, 647.1075,
       671.2575, 695.4075},
      {682.6575, 715.8075, 748.9575, 782.1075, 815.2575, 848.4075, 881.5575,
       914.7075, 947.8575},
      {863.1075, 905.2575, 947.4075, 989.5575, 1031.7075, 1073.8575, 1116.0075,
       1158.1575, 1200.3075},
      {1043.5575, 1094.7075, 1145.8575, 1197.0075, 1248.1575, 1299.3075,
       1350.4575, 1401.6075, 1452.7575},
      {1224.0075, 1284.1575, 1344.3075, 1404.4575, 1464.6075, 1524.7575,
       1584.9075, 1645.0575, 1705.2075},
  });

  const bool result = (actual == expected);
  EXPECT_TRUE(result);
}

TEST(MultiplyMatrixOperatorTests, Test6) {
  const S21Matrix m1({
      {1.05, 2.05, 3.05, 4.05},
  });

  const S21Matrix m2({
      {1.005, 2.005},
      {3.005, 4.005},
      {5.005, 6.005},
      {7.005, 8.005},
  });

  const auto actual = m1 * m2;

  const S21Matrix expected({
      {50.851, 61.051},
  });

  const bool result = (actual == expected);
  EXPECT_TRUE(result);
}

TEST(MultiplyMatrixOperatorTests, Test7) {
  const S21Matrix m1({
      {50.851, 61.051},
  });

  const S21Matrix m2({
      {1.005, 2.005, 3.005},
      {4.005, 5.005, 6.005},
  });

  const auto actual = m1 * m2;

  const S21Matrix expected({
      {295.61451, 407.51651, 519.41851},
  });

  const bool result = (actual == expected);
  EXPECT_TRUE(result);
}

TEST(MultiplyMatrixOperatorTests, Test8) {
  const S21Matrix m1({
      {295.61451, 407.51651, 519.41851},
  });

  const S21Matrix m2({
      {1.5, 2.5},
      {3.5, 4.5},
      {5.5, 6.5},
  });

  const auto actual = m1 * m2;

  const S21Matrix expected({
      {4726.531355, 5949.080885},
  });

  const bool result = (actual == expected);
  EXPECT_TRUE(result);
}

TEST(MultiplyMatrixOperatorTests, Test9Several) {
  const S21Matrix m1({
      {1.05, 2.05, 3.05, 4.05},
  });

  const S21Matrix m2({
      {1.005, 2.005},
      {3.005, 4.005},
      {5.005, 6.005},
      {7.005, 8.005},
  });

  const S21Matrix m3({
      {1.005, 2.005, 3.005},
      {4.005, 5.005, 6.005},
  });

  const S21Matrix m4({
      {1.5, 2.5},
      {3.5, 4.5},
      {5.5, 6.5},
  });

  const S21Matrix actual = m1 * m2 * m3 * m4;

  const S21Matrix expected({
      {4726.531355, 5949.080885},
  });

  const bool result = (actual == expected);
  EXPECT_TRUE(result);
}

TEST(MultiplyMatrixOperatorTests, Test10WrongSize) {
  const S21Matrix m1({
      {1.05, 2.05, 3.05, 4.05, 0.0},
  });

  const S21Matrix m2({
      {1.005, 2.005},
      {3.005, 4.005},
      {5.005, 6.005},
      {7.005, 8.005},
  });

  const S21Matrix m3({
      {1.005, 2.005, 3.005},
      {4.005, 5.005, 6.005},
  });

  const S21Matrix m4({
      {1.5, 2.5},
      {3.5, 4.5},
      {5.5, 6.5},
  });

  EXPECT_THROW(m1 * m2 * m3 * m4, std::range_error);
}

TEST(MultiplyMatrixOperatorTests, Test11WrongSize) {
  const S21Matrix m1({
      {1.05, 2.05, 3.05, 4.05},
  });

  const S21Matrix m2({
      {1.005, 2.005},
      {3.005, 4.005},
      {5.005, 6.005},
      {7.005, 8.005},
      {0.0, 0.0},
  });

  const S21Matrix m3({
      {1.005, 2.005, 3.005},
      {4.005, 5.005, 6.005},
  });

  const S21Matrix m4({
      {1.5, 2.5},
      {3.5, 4.5},
      {5.5, 6.5},
  });

  EXPECT_THROW(m1 * m2 * m3 * m4, std::range_error);
}

TEST(MultiplyMatrixOperatorTests, Test12WrongSize) {
  const S21Matrix m1({
      {1.05, 2.05, 3.05, 4.05},
  });

  const S21Matrix m2({
      {1.005, 2.005},
      {3.005, 4.005},
      {5.005, 6.005},
      {7.005, 8.005},
  });

  const S21Matrix m3({
      {1.005, 2.005, 3.005, 0.0},
      {4.005, 5.005, 6.005, 0.0},
      {0.0, 0.0, 0.0, 0.0},
  });

  const S21Matrix m4({
      {1.5, 2.5},
      {3.5, 4.5},
      {5.5, 6.5},
  });

  EXPECT_THROW(m1 * m2 * m3 * m4, std::range_error);
}

TEST(MultiplyNumberOperatorTests, Test13) {
  const S21Matrix m1({
      {1.05, 2.05, 3.05, 4.05},
  });

  const double number = 2.0;
  const S21Matrix expected({
      {2.1, 4.1, 6.1, 8.1},
  });

  const S21Matrix actual = m1 * number;

  EXPECT_TRUE(actual == expected);
}

TEST(MultiplyNumberOperatorTests, Test14) {
  const S21Matrix m1({
      {1.05, 2.05, 3.05, 4.05},
  });

  const double number = 2.0;
  const S21Matrix expected({
      {2.1, 4.1, 6.1, 8.1},
  });

  const S21Matrix actual = number * m1;

  EXPECT_TRUE(actual == expected);
}

TEST(MultiplyNumberOperatorTests, Test15) {
  const S21Matrix m1({
      {1.05, 2.05, 3.05, 4.05},
      {5.05, 6.05, 7.05, 8.05},
      {9.05, 10.05, 11.05, 12.05},
  });

  const double number = 2.0;
  const S21Matrix expected({
      {2.1, 4.1, 6.1, 8.1},
      {10.1, 12.1, 14.1, 16.1},
      {18.1, 20.1, 22.1, 24.1},
  });

  const S21Matrix actual = m1 * number;

  EXPECT_TRUE(actual == expected);
}

TEST(MultiplyNumberOperatorTests, Test16) {
  const S21Matrix m1({
      {1.05, 2.05, 3.05, 4.05},
      {5.05, 6.05, 7.05, 8.05},
      {9.05, 10.05, 11.05, 12.05},
  });

  const double number = 2.0;
  const S21Matrix expected({
      {2.1, 4.1, 6.1, 8.1},
      {10.1, 12.1, 14.1, 16.1},
      {18.1, 20.1, 22.1, 24.1},
  });

  const S21Matrix actual = number * m1;

  EXPECT_TRUE(actual == expected);
}
}  // namespace