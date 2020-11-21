//
//  move.h
//  kit-elevator-simulation
//
//  Created by kazusa watanabe on 2020/10/22.
//  Copyright (c) 2020 \Kazusa Watanabe. All rights reserved.
//

#ifndef MOVE_H
#define MOVE_H

#include "../calculations/calculations.h"
#include "../common/define.h"
#include "../report/csv.h"
#include "../report/log.h"

static const double time_to_move[8] = {12.2, 15.3, 18.4, 20.7,
                                       22.7, 24.9, 27.1, 29.3};

static inline double service(int* box) {
  double result = 0.0;
  // 何階に止まるか
  int destinations[LEVEL] = {};
  for (int i = 0; i < BOX; i++) {
    destinations[box[i]] += 1;
  }
  // 移動時間
  int start_position = -2;
  for (int i = 0; i < LEVEL; i++) {
    if (0 < destinations[i]) {  // i階に行く人がいれば...
      result += time_to_move[-(start_position - i) - 1];

      start_position = i;
    }
  }
  result += time_to_move[start_position + 1];
  return result;
}

static inline int get_in_box(void) {
  return ratio_of_class[genRand(0, CLASS - 1)];
}

static inline double service_average(void) {
  const char* TAG = __func__;
  log_write(0, TAG, START);

  // init
  histgram hist = {0.0, 0.0, 0.0, 0.0, 0, 0};

  while (hist.n < 10 || hist.n_variance == 0.0) {
    int box[BOX] = {};
    for (int i = 0; i < BOX; i++) {
      box[i] = get_in_box();
    }
    double time = service(box);
    hist.total += time;

    // convergence
    if (hist.i > 0) {
      hist.deviation += pow(time, 2.0);
      hist.b_variance = hist.n_variance;
      hist.n_variance = variance(hist);
      if (fabs(hist.b_variance - hist.n_variance) < 0.01) hist.n++;
    }
    hist.i++;
  }

  csv_d(",%d", hist.i);

  hist.total /= hist.i;
  log_write(0, TAG, END);
  return hist.total;
}

#endif
