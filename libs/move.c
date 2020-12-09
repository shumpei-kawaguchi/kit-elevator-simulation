//
//  move.c
//  kit-elevator-simulation
//
//  Created by kazusa watanabe on 2020/12/9.
//  Copyright (c) 2020 \Kazusa Watanabe. All rights reserved.
//

#include "move.h"

static const double TRAFFIC_TIME[8] = {12.2, 15.3, 18.4, 20.7,
                                       22.7, 24.9, 27.1, 29.3};

static int get_in_box(void) { return ratio_of_class[genRand(0, CLASS - 1)]; }

static double service(int* box) {
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
      result += TRAFFIC_TIME[-(start_position - i) - 1];

      start_position = i;
    }
  }
  result += TRAFFIC_TIME[start_position + 1];
  return result;
}

double service_average(void) {
  // init
  int box[BOX] = {};
  variances variances = {0.0, 0.0, 0};
  double va = 0, b_va = 0, n = 0;
  double result = 0.0;

  while (n < 10) {
    for (int i = 0; i < BOX; i++) {
      box[i] = get_in_box();
    }
    result = service(box);

    variances.result_total += result;
    variances.squared_total += pow(result, 2.0);

    if (variances.i > 0) {
      b_va = va;
      va = variance(variances);
    }
    if (fabs(b_va - va) < 0.01) n++;

    variances.i++;
  }

  return average(variances.result_total, (double)variances.i + 1);
}
