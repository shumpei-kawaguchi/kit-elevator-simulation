//
//  testCombination.cpp
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/20.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include <gtest/gtest.h>

extern "C" {
#include "../calculations/combination.c"
}

// CombinationTest
TEST(CombinationTest, HandlesZeroInput) { EXPECT_EQ(1, combinations(7, 0)); }

TEST(CombinationTest, HandlesEqualInput) { EXPECT_EQ(1, combinations(7, 7)); }

TEST(CombinationTest, HandlesOneInput) { EXPECT_EQ(7, combinations(7, 1)); }

TEST(CombinationTest, HandlesPositiveInput) {
  EXPECT_EQ(21, combinations(7, 2));
  EXPECT_EQ(21, combinations(7, 5));
  EXPECT_EQ(10, combinations(5, 3));
  EXPECT_EQ(3, combinations(3, 2));
}

TEST(CombinationTest, HandlesNegativeInput) {
  EXPECT_EQ(0, combinations(5, 7));
}

// FactorialTest
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
