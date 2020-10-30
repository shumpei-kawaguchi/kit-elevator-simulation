//
//  testLog.cpp
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/30.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include <gtest/gtest.h>

extern "C"
{
#include "../report/log.c"
}

TEST(CustomerTest, SetCustomer)
{
  EXPECT_EQ(0, log_write());
}
