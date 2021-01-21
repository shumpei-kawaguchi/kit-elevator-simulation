//
//  calculations.h
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/11/21.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "define.h"

typedef struct Variances {
  double squared_total;
  double result_total;
  int i;
} variances;

long factanal(int x);
double Rand(void);
int genRand(int min, int max);
double average(double total, double n);
double variance(variances variances);

#endif
