//
//  main.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/20.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "main.h"

#include <stdio.h>
#include <stdlib.h>

#include "calculations/ratio.h"
#include "common/define.h"
#include "common/init.h"
#include "elevator/move.h"
#include "queue/customer.h"
#include "report/csv.h"
#include "report/file.h"
#include "report/log.h"

static int iterations = 0;

int setup(void) {
  const char *TAG = __func__;
  int box[10] = {0, 5, 2, 2, 5, 0, 2, 0, 2, 5};
  move(box);
  new_id(7);
  new_csv();
  printf("[Setup] type iterations number.\n");
  scanf("%d", &iterations);
  log_write(0, TAG, "Finithed setup.\n");
  return 0;
}

int main(void) {
  const char *TAG = __func__;
  setup();
  log_write(0, TAG, START);
  //
  for (int i = 0; i < iterations; i++) {
    csv_d("%d,", i + 1);
    init();
    customer_arrival();
    int box[BOX] = {};
    for (int i = 0; i < BOX; i++) {
      box[i] = get_in_box();
    }
    // LOG
    log_write(0, TAG, "Customer get in the box!\n");
    log_write(0, TAG, "Box = ");
    for (int i = 0; i < BOX; i++) {
      log_d("%d", box[i] + 3);
      // printf("%d", box[i] + 3);
    }
    log_d("\n", 0);
    move(box);
    // End loop.
    csv_s("\n", "");
  }
  //
  log_write(0, TAG, END);
  exit(0);
}
