//
//  elevator.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/11/11.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "elevator.h"

// A: 到着過程(到着時間間隔平均), B: サービス時間((処理時間平均), C: サーバー数

MODEL up_peak_traffic() {
  // １秒当たりの、到着率
  double p1 = (double)(CLASS * NUMBER_OF_PEOPLE) / (10 * 60);
  // 一人当たりの、サービス率
  double p2 = 1 / (p->average / BOX);

  MODEL model = {p1, p2, SERVER};

  return model;
}

QUEUEING queueing_simulation(MODEL MMn) {
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
