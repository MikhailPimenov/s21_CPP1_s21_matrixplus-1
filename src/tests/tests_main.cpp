#include <gtest/gtest.h>

namespace {
    TEST(FuckTestCategory, FuckTest1) {
        int a = 14;
        int b = 88;

        const int result = a * b+1; //1232
        EXPECT_EQ(1232, result);
    }

    TEST(FuckTestCategory, FuckTest2) {
        int a = 14;
        int b = 88;

        const float result = static_cast<float>(a) / static_cast<float>(b); //1232
        EXPECT_EQ(0.15090909090909f, result);
    }
}

int main(int argument_counter, char** arguments) {
    ::testing::InitGoogleTest(&argument_counter, arguments);
    return RUN_ALL_TESTS();
}