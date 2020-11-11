//
//  elevator.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/11/11.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "elevator.h"

#include <stdio.h>

#include "../common/define.h"
#include "../queue/customer.h"
#include "../report/log.h"
#include "move.h"

double elevator_system(void) {
  const char *TAG = __func__;
  double result = 0.0;
  customer_arrival();  // Make all customer queue.

  // MARK: Loop for customer queue.
  // Get in the box.
  int box[BOX] = {};
  for (int i = 0; i < BOX; i++) {
    box[i] = get_in_box();
  }
  // LOG
  log_write(0, TAG, "Customer get in the box!\n");
  log_write(0, TAG, "Box = ");
  for (int i = 0; i < BOX; i++) {
    log_d("%d", box[i] + 3);
  }
  log_d("\n", 0);
  // LOG end.
  result += move(box);
  // Loop end.

  // return final result.
  return result;
}
