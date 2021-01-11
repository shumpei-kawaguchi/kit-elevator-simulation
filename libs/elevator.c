//
//  elevator.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/11/11.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "elevator.h"

// A: 到着過程(到着時間間隔平均), B: サービス時間((処理時間平均), C: サーバー数

MODEL mmn_model(void) {
  // １秒当たりの、到着率
  double rambda = RAMBDA;
  // 一人当たりの、サービス率
  double mu = BOX / p->average.back;

  MODEL model = {rambda, mu, SERVER};

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
