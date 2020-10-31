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
  char TAG[6] = "init";
  log_write(0, TAG, "init start.");
  for (int i = 0; i < LEVEL; i++) ratio_is(i, 0);
  return 0;
}
