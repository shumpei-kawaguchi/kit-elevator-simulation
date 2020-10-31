//
//  testLog.cpp
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/30.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include <gtest/gtest.h>

#include "../common/define.h"

extern "C" {
#include "../calculations/random.c"
#include "../report/log.c"
}

TEST(LogTest, WriteLog) {
  char func[] = "LogTest";
  char message[] = "Write test, this is message.";
  EXPECT_EQ(0, log_write(0, func, message));
  EXPECT_EQ(0, log_write(1, func, message));
  EXPECT_EQ(0, log_write(2, func, message));
}
