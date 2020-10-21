//
//  testCustomer.cpp
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/21.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include <gtest/gtest.h>

extern "C" {
#include "../queue/customer.c"
}

TEST(CustomerTest, SetCustomer) {
  EXPECT_EQ(5, customer_of_level(5).level);
  EXPECT_EQ(150, customer_of_level(3).number_of_people);
}
