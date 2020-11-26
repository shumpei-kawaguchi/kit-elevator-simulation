//
//  elevator.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/11/11.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "elevator.h"

// A: 到着過程(到着時間間隔平均), B: サービス時間((処理時間平均), C: サーバー数
typedef struct Queueing {
  int time;
  int queue;
  int total;
} queueing;

double MMn_queueing_simulation(MODEL MMn) {
  queueing queueing = {0, 0, 0};

  while (queueing.time < END_TIME) {
    // for (int i = 0; i < MMn.C; i++) {
    if (queueing.queue != 0) {
      if (Rand() < (MMn.B * SERVER)) {
        queueing.queue--;
      }
    }
    // }

    if (Rand() < MMn.A) {
      queueing.queue++;
    }

    queueing.time++;
    queueing.total += queueing.queue;
  }

  return average((double)queueing.total, queueing.time + 1);
}
