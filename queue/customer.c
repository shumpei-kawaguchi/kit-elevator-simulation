//
//  customer.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/21.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "customer.h"

#include <stdio.h>
#include <stdlib.h>

#include "../calculations/ratio.h"
#include "../common/define.h"
#include "../report/log.h"

static unsigned int customer_queue[LEVEL] = {};

// Return customer of level in queue.
// [NO LOG OUTPUT]
unsigned int customer_of(int level) { return customer_queue[level]; }

// Set customer of level.
// [NO LOG OUTPUT]
unsigned int customer_is(int level, int value) {
  customer_queue[level] = value;
  return customer_queue[level];
}

// Init customer queue.
int customer_arrival() {
  const char *TAG = __func__;
  log_write(0, TAG, START);
  int total = 0;

  for (int i = 0; i < LEVEL; i++) {
    customer_queue[i] = ratio_of(i) * NUMBER_OF_PEOPLE;
    total += customer_queue[i];
  }

  if (CLASS * NUMBER_OF_PEOPLE - total != 0) {
    log_write(1, TAG, "Wrong total. EXIT code 1.");
    exit(1);
  }
  log_write(0, TAG, END);
  return 0;
}
