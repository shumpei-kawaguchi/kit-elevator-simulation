//
//  ratio.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/24.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "ratio.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../common/define.h"
#include "../report/log.h"
#include "random.h"

static const int classroom_of_level[LEVEL] = {1, 3, 3, 3, 2, 2, 1};
static int ratio_of_class[CLASS] = {};

// Return classroom of level.
// [NO LOG OUTPUT]
unsigned int classroom_of(int level) { return classroom_of_level[level]; }

// Return ratio of level.
// [NO LOG OUTPUT]
unsigned int ratio_of(int class) { return ratio_of_class[class]; }

// Set ratio value of level.
// [NO LOG OUTPUT]
unsigned int ratio_is(int class, int level) {
  ratio_of_class[class] = level;
  return ratio_of_class[class];
}

// Set ratio pattern.
int ratio_pattern(void) {
  const char *TAG = __func__;
  log_write(0, TAG, START);
  int classroom[LEVEL] = {};
  for (int i = 0; i < LEVEL; i++) {
    classroom[i] = classroom_of(i);
  }

  // Randomly determine the ratio of each level.
  log_write(0, TAG, "Make randomly ratio of each level.\n");

  for (int i = 0; i < CLASS; i++) {
    int level = genRand(0, LEVEL - 1);
    if (classroom[level] > 0) {
      ratio_is(i, level);
      classroom[level]--;
    } else {
      i--;
    }
  }

  log_write(0, TAG, "Done randomly ratio.\n");
  log_write(0, TAG, END);
  return 0;
}
