//
//  elevator.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/11/11.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "elevator.h"

#include <stdio.h>
#include <stdlib.h>

#include "../calculations/ratio.h"
#include "../common/define.h"
#include "../elevator/customer.h"
#include "../report/log.h"
#include "move.h"

#define Rand() ((double)rand() / RAND_MAX)

double service_average(void) {
  const char *TAG = __func__;
  log_write(0, TAG, START);
  int n = 100;
  double result = 0.0;

  for (int i = 0; i < n; i++) {
    int box[BOX] = {};
    for (int i = 0; i < BOX; i++) {
      box[i] = get_in_box();
    }
    result += move(box);
  }
  result /= n;
  log_write(0, TAG, END);
  return result;
}

double elevator_system(double p1, double p2) {
  int time = 0;
  int queue = 0;
  int total_queue = 0;

  while (time < 1000) {
    if (queue != 0) {
      if (Rand() < p2) {
        queue--;
      }
    }

    if (Rand() < p1) {
      queue++;
    }

    time++;
    total_queue += queue;
  }

  double result = (double)total_queue / time;
  return result;
}
