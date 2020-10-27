//
//  customer.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/21.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "customer.h"

#include <stdio.h>

#include "../calculations/ratio.h"
#include "../common/define.h"

static unsigned int customer_queue[LEVEL] = {};

int customer_arrival() {
  int total = 0;
  for (int i = 0; i < LEVEL; i++) {
    customer_queue[i] = ratio_of(i) * NUMBER_OF_PEOPLE;
    total += customer_queue[i];
  }

  return CLASS * NUMBER_OF_PEOPLE - total;
}
