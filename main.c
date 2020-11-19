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

#include "calculations/factanal.h"
#include "calculations/ratio.h"
#include "common/define.h"
#include "common/init.h"
#include "elevator/elevator.h"
#include "elevator/move.h"
#include "queue/customer.h"
#include "report/csv.h"
#include "report/file.h"
#include "report/log.h"

static int iterations = 0;

int setup(void) {
  const char *TAG = __func__;
  new_id(7);
  new_csv();
  printf("[Setup] type iterations number.\n");
  scanf("%d", &iterations);
  log_write(0, TAG, "Finithed setup.\n");
  return 0;
}

int main(void) {
  // printf("%d\n", factanal(1));
  const char *TAG = __func__;
  setup();
  log_write(0, TAG, START);
  //
  for (int i = 0; i < iterations; i++) {
    csv_d("%d,", i + 1);
    init();
    double result = elevator_system();
    printf("result = %lf\n", result);
    csv_lf(",%lf", result);
    csv_s("\n", "");
  }
  //
  log_write(0, TAG, END);
  exit(0);
}
