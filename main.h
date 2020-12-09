//
//  main.h
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/11/04.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>

#include "libs/calculations.h"
#include "libs/define.h"
#include "libs/elevator.h"
#include "libs/init.h"
#include "libs/move.h"

int main(void);

//////////////
PATTERN *root = NULL, *p;
//////////////

static inline double convergence() {
  variances variances = {0.0, 0.0, 0};

  double va = 0;
  double b_va = 0;
  double n = 0;

  while (n < 10) {
    p->queueing = queueing_simulation(p->model);
    double L = average(p->queueing.total, p->queueing.time + 1);
    double result = L / p->model.A;
    variances.result_total += result;
    variances.squared_total += pow(result, 2.0);
    if (variances.i > 0) {
      b_va = va;
      va = variance(variances);
    }
    if (fabs(b_va - va) < 0.01) {
      n++;
    }
    variances.i++;
  }

  return average(variances.result_total, (double)variances.i + 1);
}

#endif
