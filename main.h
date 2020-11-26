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

#include "calculations/calculations.h"
#include "common/define.h"
#include "common/init.h"
#include "elevator/elevator.h"
#include "elevator/move.h"
#include "report/csv.h"
#include "report/file.h"
#include "report/log.h"

int main(void);

typedef struct settings {
  int iterations;
} SETTINGS;

typedef struct pattern {
  int id;
  MODEL model;
  double average;
  double result;
  struct pattern *next;
} PATTERN;

//////////////
PATTERN *root = NULL, *p, *n, **q;
//////////////

static inline SETTINGS setup(void) {
  const char *TAG = __func__;
  SETTINGS st = {0};
  new_id(7);
  new_csv();
  printf("\n[Setup] type iterations number.\n-> ");
  scanf("%d", &st.iterations);

  // char l[] = "";
  // printf("\n[Setup] Do you want to write log?\n");
  // while (strcmp(l, "y") != 0) {
  //   printf("(y/n)-> ");
  //   scanf("%s", l);
  //   if (strcmp(l, "n") == 0) {
  //     LOG = 0;
  //     break;
  //   }
  // }
  log_write(0, TAG, "Finithed setup.\n");
  return st;
}

static inline MODEL up_peak_traffic() {
  p->average = service_average();
  // １秒当たりの、到着率
  double p1 = (double)(CLASS * NUMBER_OF_PEOPLE) / (10 * 60);
  // 一人当たりの、サービス率
  double p2 = 1 / (p->average / BOX);

  MODEL model = {p1, p2, SERVER};

  return model;
}

static inline double convergence() {
  variances variances = {0.0, 0.0, 0};

  double va = 0;
  double b_va = 0;
  double n = 0;

  while (n < 10) {
    double result = MMn_queueing_simulation(p->model);
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
