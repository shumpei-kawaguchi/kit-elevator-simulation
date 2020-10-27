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

int classroom_of_level[LEVEL] = {1, 3, 3, 3, 2, 2, 1};
int ratio_of_level[LEVEL] = {};

unsigned int classroom_of(int level) { return classroom_of_level[level]; }

unsigned int ratio_of(int level) { return ratio_of_level[level]; }

unsigned int ratio_is(int level, int value) {
  ratio_of_level[level] = value;
  return ratio_of_level[level];
}

int ratio_pattern() {
  //
  srand((unsigned int)time(NULL));
  int classroom = CLASS;
  //
  for (int i = 0; i < LEVEL; i++) {
    //
    int max = 0;
    for (int next = i; next < LEVEL; next++) {
      max += classroom_of(next);
    }
    //
    int include = 0;
    int col = classroom_of(i);
    if (max - col - classroom < 0) include = -(max - col - classroom);
    ratio_is(i, classroom_ratio(i, include, classroom));
    classroom -= ratio_of(i);
  }
  //
  int total = 0;
  for (int i = 0; i < LEVEL; i++) total += ratio_of(i);

  //
  return CLASS - total;
}

int classroom_ratio(int n, int include, int classroom) {
  int num = rand() % (classroom_of(n) + 1);
  if (num < include) num = include;
  if (num > classroom) num = classroom;
  return num;
}
