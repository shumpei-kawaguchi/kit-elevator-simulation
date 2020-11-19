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
#include "elevator/customer.h"
#include "elevator/elevator.h"
#include "elevator/move.h"
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
    double average = service_average();

    // １秒当たりの、到着率
    double p1 = (double)(CLASS * NUMBER_OF_PEOPLE) / (10 * 60);
    // １秒当たりの、サービス率
    double p2 = 1 / (average / BOX);

    double final_result = elevator_system(p1, p2);

    log_write(0, TAG, "");
    log_lf("Result = %lf, ", average);
    log_lf("p1 = %lf, ", p1);
    log_lf("p2 = %lf\n", p2);
    log_write(0, TAG, "");
    log_lf("Final result = %lf\n", final_result);

    csv_lf(",%lf", average);
    csv_lf(",%lf", p1);
    csv_lf(",%lf", p2);
    csv_lf(",%lf\n", final_result);
  }
  //
  log_write(0, TAG, END);
  exit(0);
}
