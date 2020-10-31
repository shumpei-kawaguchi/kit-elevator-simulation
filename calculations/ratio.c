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
#include "random.h"

static int classroom_of_level[LEVEL] = {1, 3, 3, 3, 2, 2, 1};
static int ratio_of_level[LEVEL] = {};

// Return classroom of level.
unsigned int classroom_of(int level) { return classroom_of_level[level]; }

// Return ratio of level.
unsigned int ratio_of(int level) { return ratio_of_level[level]; }

// Set ratio value of level.
unsigned int ratio_is(int level, int value) {
  ratio_of_level[level] = value;
  return ratio_of_level[level];
}

// Set ratio pattern.
int ratio_pattern() {
  int classroom = CLASS;
  int total = 0;

  for (int i = 0; i < LEVEL; i++) {
    int max = 0;
    int include = 0;
    int col = classroom_of(i);
    for (int next = i; next < LEVEL; next++) max += classroom_of(next);

    if (max - col - classroom < 0) include = -(max - col - classroom);
    ratio_is(i, classroom_ratio(i, include, classroom));
    classroom -= ratio_of(i);
  }

  for (int i = 0; i < LEVEL; i++) total += ratio_of(i);
  return CLASS - total;
}

// Return randam ratio.
int classroom_ratio(int n, int min, int classroom) {
  int max = classroom_of(n);
  if (max > classroom) max = classroom;
  int num = genRand(min, max);
  return num;
}
