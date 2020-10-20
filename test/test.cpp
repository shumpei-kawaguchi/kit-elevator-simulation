#include <gtest/gtest.h>

TEST(SampleTest, SampleTestOk) { EXPECT_EQ(1, 1); }
TEST(SampleTest, SampleTestNg) { EXPECT_EQ(1, 0); }
