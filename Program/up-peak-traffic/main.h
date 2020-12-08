//
//  main.h
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/12/8.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#ifndef MAIN_H
#define MAIN_H

#include "../../libs/common/define.h"
#include "../../libs/common/init.h"
#include "../../libs/elevator/MMnQueueingSimulation.h"
#include "../../libs/elevator/move.h"
#include "../../libs/elevator/upPeakTraffic.h"
#include "../../libs/report/csv.h"
#include "../../libs/report/file.h"
#include "../../libs/report/log.h"

typedef struct settings {
  int iterations;
} SETTINGS;

typedef struct pattern {
  int id;
  MODEL model;
  QUEUEING queueing;
  double average;
  double result;
  struct pattern *next;
} PATTERN;

//////////////
PATTERN *root = NULL, *p;
//////////////

SETTINGS setup(void);
int main(void);

static inline double convergence() {
  variances variances = {0.0, 0.0, 0};

  double va = 0;
  double b_va = 0;
  double n = 0;

  while (n < 10) {
    p->queueing = MMn_queueing_simulation(p->model);
    double L = average(p->queueing.total, p->queueing.time + 1);
    double result = L / p->model.rambda;
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

static inline void process_print(int iterations, int i) {
  printf("\r%3.2f％ %.2fsec", ((double)i + 1) * 100 / (double)iterations,
         (double)clock() / CLOCKS_PER_SEC);
  fflush(stdout);
  return;
}

#endif
