//
//  elevator.h
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/11/11.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "../calculations/calculations.h"
#include "../common/define.h"

typedef struct mdoel {
  double A;
  double B;
  double C;
} MODEL;

double MMn_queueing_simulation(MODEL MMn);
#endif
