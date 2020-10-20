#include <gtest/gtest.h>

extern "C" {
#include "../calculations/combination.c"
}

class FactorialTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

TEST(FactorialTest, HandlesZeroInput) { EXPECT_EQ(1, factorial(0)); }

TEST(FactorialTest, HandlesPositiveInput) {
  EXPECT_EQ(1, factorial(1));
  EXPECT_EQ(2, factorial(2));
  EXPECT_EQ(6, factorial(3));
  EXPECT_EQ(40320, factorial(8));
}
