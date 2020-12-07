//
//  MMnQueueingSimulation.h
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/12/7.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#ifndef MMNQUEUEINGSIMULATION_H
#define MMNQUEUEINGSIMULATION_H

#include "../calculations/calculations.h"
#include "../common/define.h"

typedef struct mdoel {
  double A;
  double B;
  double C;
} MODEL;

typedef struct Queueing {
  int time;
  int queue;
  int total;
} QUEUEING;

// A: 到着過程(到着時間間隔平均), B: サービス時間((処理時間平均), C: サーバー数

QUEUEING MMn_queueing_simulation(MODEL MMn) {
  QUEUEING queueing = {0, 0, 0};
  int customer = CLASS * NUMBER_OF_PEOPLE;

  while (queueing.time < END_TIME) {
    if (queueing.queue != 0) {
      if (Rand() < (MMn.B * SERVER)) {
        queueing.queue--;
      }
    }

    if (Rand() < MMn.A && 0 < customer) {
      queueing.queue++;
      customer--;
    }

    queueing.time++;
    queueing.total += queueing.queue;

    if (queueing.queue <= 0 && customer <= 0) break;
  }

  return queueing;
}

#endif
