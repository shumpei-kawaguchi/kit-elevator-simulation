
//
//  variance.h
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/11/22.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#ifndef VARIANCE_H
#define VARIANCE_H

#include <math.h>

typedef struct Variances {
  double squared_total;
  double result_total;
  int i;
} variances;

static inline double variance(variances variances) {
  return (variances.squared_total / (variances.i + 1)) -
         pow((variances.result_total / (variances.i + 1)), 2.0);
}

#endif
