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
static int ratio_of_level[LEVEL] = {};

// Return classroom of level.
// [NO LOG OUTPUT]
unsigned int classroom_of(int level) { return classroom_of_level[level]; }

// Return ratio of level.
// [NO LOG OUTPUT]
unsigned int ratio_of(int level) { return ratio_of_level[level]; }

// Set ratio value of level.
// [NO LOG OUTPUT]
unsigned int ratio_is(int level, int value) {
  ratio_of_level[level] = value;
  return ratio_of_level[level];
}

// Set ratio pattern.
int ratio_pattern(void) {
  const char *TAG = __func__;
  log_write(0, TAG, START);
  int classroom = CLASS;
  int total = 0;
  log_write(0, TAG, "Init classroom, total.\n");

  // Randomly determine the ratio of each level.
  log_write(0, TAG, "Make randomly ratio of each level.\n");
  for (int i = 0; i < LEVEL; i++) {
    int max = 0;
    int min = 0;
    int col = classroom_of(i);
    for (int next = i; next < LEVEL; next++) max += classroom_of(next);

    if (max - col - classroom < 0) min = -(max - col - classroom);
    ratio_is(i, classroom_ratio(i, min, classroom));
    classroom -= ratio_of(i);
  }
  log_write(0, TAG, "Done randomly ratio.\n");

  // Check total value.
  for (int i = 0; i < LEVEL; i++) total += ratio_of(i);
  if (CLASS - total != 0) {
    log_write(1, TAG, "Wrong total. EXIT code 1.\n");
    exit(1);
  }
  log_write(0, TAG, END);
  return 0;
}

// Return randam ratio.
// [NO LOG OUTPUT]
int classroom_ratio(int n, int min, int classroom) {
  int max = classroom_of(n);
  if (max > classroom) max = classroom;
  int num = genRand(min, max);
  return num;
}
