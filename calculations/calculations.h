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

#include "../common/define.h"
#include "random.h"

static inline double average(double total, double n) { return total / n; }

static inline double variance(histgram hist) {
  return average(hist.deviation, hist.i + 1) -
         pow(average(hist.total, hist.i + 1), 2);
}

#endif
