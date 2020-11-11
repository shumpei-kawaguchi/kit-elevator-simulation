//
//  init.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/21.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "init.h"

#include <stdio.h>

#include "../calculations/ratio.h"
#include "../report/csv.h"
#include "../report/log.h"
#include "define.h"

int init(void) {
  const char *TAG = __func__;
  log_write(0, TAG, START);
  // Make ratio pattern.
  ratio_pattern();
  int total = 0;
  // Count total and report.
  for (int i = 0; i < LEVEL; i++) {
    total += ratio_of(i);
    printf("%d\t", ratio_of(i));
    csv_d("%d", ratio_of(i));
  }
  printf("total = %d\n", total);
  csv_d(",%d,", total);
  log_write(0, TAG, "Init ratio of level.\n");
  log_write(0, TAG, END);
  return 0;
}
