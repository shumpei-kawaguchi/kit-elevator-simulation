//
//  init.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/21.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "init.h"

static int ratio_pattern(void) {
  const char *TAG = __func__;
  log_write(0, TAG, START);
  int classroom[LEVEL] = {};

  for (int i = 0; i < LEVEL; i++) {
    classroom[i] = classroom_of_level[i];
  }

  int n = 0;
  while (n < CLASS) {
    int level = genRand(0, LEVEL - 1);
    if (classroom[level] > 0) {
      ratio_of_class[n] = level;
      classroom[level]--;
      n++;
    }
  }
  log_write(0, TAG, END);
  return 0;
}

int init(void) {
  const char *TAG = __func__;
  log_write(0, TAG, START);
  // Make ratio pattern.
  ratio_pattern();
  // report.
  int combination[LEVEL] = {};

  int id = 0;

  for (int i = 0; i < CLASS; i++) {
    combination[ratio_of_class[i]] += 1;
  }

  for (int i = 0; i < LEVEL; i++) {
    // csv_d("%d", combination[i]);
    id += combination[i] * pow(10, LEVEL - (i + 1));
  }

  log_write(0, TAG, "Init ratio of level.\n");
  log_write(0, TAG, END);
  return id;
}
