//
//  testRatio.cpp
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/24.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include <gtest/gtest.h>

#include "../common/define.h"

extern "C" {
#include "../calculations/ratio.c"
}

TEST(RatioTest, RatioTotalTest) { EXPECT_EQ(0, ratio_pattern()); }

TEST(RatioTest, ClassroomRatio) {
  EXPECT_EQ(1, classroom_ratio(LEVEL - 1, 1, 1));
}

TEST(RatioTest, RatioRange) {
  EXPECT_LE(0, classroom_ratio(2, 0, 5));
  EXPECT_GE(classroom_of_level[2], classroom_ratio(2, 0, 5));
}
