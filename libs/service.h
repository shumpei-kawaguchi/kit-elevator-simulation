//
//  service.h
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/12/10.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#ifndef SERVICE_H
#define SERVICE_H

#include "calculations.h"
#include "define.h"

typedef struct st_result {
  double service;
  double back;
} RESULT;

RESULT result_average(void);

#endif
