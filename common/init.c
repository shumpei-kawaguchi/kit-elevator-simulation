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
  // report.
  int combination[LEVEL] = {};
  for (int i = 0; i < CLASS; i++) {
    combination[ratio_of(i)] += 1;
  }
  for (int i = 0; i < LEVEL; i++) {
    csv_d("%d", combination[i]);
  }
  log_write(0, TAG, "Init ratio of level.\n");
  log_write(0, TAG, END);
  return 0;
}
