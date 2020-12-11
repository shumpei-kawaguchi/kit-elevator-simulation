//
//  calculations.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/11/21.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "calculations.h"

int factanal(int x) {
  int f = x;
  while (1) {
    x--;
    if (x < 2) break;
    f = f * x;
  }
  return f;
}

double Rand(void) { return ((double)rand() / RAND_MAX); }

int genRand(int min, int max) {
  static int flag;
  if (flag == 0) {
    srand((unsigned int)time(NULL));
    rand();
    flag = 1;
  }
  return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}

double average(double total, double n) { return total / n; }

double variance(variances variances) {
  return (variances.squared_total / (variances.i + 1)) -
         pow((variances.result_total / (variances.i + 1)), 2.0);
}
