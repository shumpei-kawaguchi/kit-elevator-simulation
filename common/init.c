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
#include "../report/log.h"
#include "define.h"

int init() {
  const char *TAG = __func__;
  log_write(0, TAG, START);
  for (int i = 0; i < LEVEL; i++) ratio_is(i, 0);
  log_write(0, TAG, "Init ratio of level.");
  log_write(0, TAG, END);
  return 0;
}
