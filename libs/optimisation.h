//
//  optimisation.h
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/12/11.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#ifndef OPTIMISATION_H
#define OPTIMISATION_H

#include "calculations.h"
#include "define.h"
#include "service.h"
#include "sort.h"

typedef struct customer {
  int destination;
  int arrival;
  double sort;
  struct customer *next;
} CUSTOMER;

RESULT opt_service_average(int opt);

#endif
