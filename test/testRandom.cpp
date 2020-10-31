//
//  testRandom.cpp
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/31.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include <gtest/gtest.h>

extern "C" {
#include "../calculations/random.c"
}

TEST(RandomTest, genRand_Test_GE) {
  int min = 0;
  int max = 5;
  int result = genRand(min, max);
  EXPECT_GE(max, result);
  printf("genRand_Test_GE result: [%d]\n", result);
}

TEST(RandomTest, genRand_Test_LE) {
  int min = 0;
  int max = 5;
  int result = genRand(min, max);
  EXPECT_LE(min, result);
  printf("genRand_Test_LE result: [%d]\n", result);
}

TEST(RandomTest, getRandomCharsLower_Test) {
  printf("getRandomCharsLower result: [%s]\n", getRandomCharsLower(7));
}
