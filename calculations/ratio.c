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

int ratio_pattern() {
  //
  srand((unsigned int)time(NULL));
  //
  int ratio[LEVEL] = {};
  int classroom = CLASS;
  //
  for (int i = 0; i < LEVEL; i++) {
    //
    int max = 0;
    for (int next = i; next < LEVEL; next++) {
      max += classroom_of_level[next];
    }
    //
    int include = 0;  // kongo
    if (max - classroom_of_level[i] - classroom < 0)
      include = -(max - classroom_of_level[i] - classroom);
    ratio[i] = classroom_ratio(i, include, classroom);
    classroom -= ratio[i];
  }
  //
  int total = 0;
  for (int i = 0; i < LEVEL; i++) {
    total += ratio[i];
    printf("%d\t", ratio[i]);
  }
  printf("total = %d\n", total);
  //
  return total;
}

int classroom_ratio(int n, int include, int classroom) {
  int num = rand() % (classroom_of_level[n] + 1);
  if (num < include) num = include;
  if (num > classroom) num = classroom;
  return num;
}
