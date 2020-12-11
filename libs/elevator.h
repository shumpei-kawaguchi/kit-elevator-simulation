//
//  elevator.h
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/11/11.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "calculations.h"
#include "define.h"

MODEL mmn_model(void);
QUEUEING queueing_simulation(MODEL MMn);
#endif
