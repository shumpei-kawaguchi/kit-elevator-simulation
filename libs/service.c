//
//  service.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/12/10.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "service.h"

static const double TRAFFIC_TIME[8] = {12.2, 15.3, 18.4, 20.7,
                                       22.7, 24.9, 27.1, 29.3};

static int get_in_box(void) { return ratio_of_class[genRand(0, CLASS - 1)]; }

static RESULT result(int *box) {
  RESULT r = {0.0, 0.0};
  int stop = 0;

  double result = 0.0;
  result += 11.784;

  // 何階に止まるか
  int destinations[LEVEL] = {};
  for (int i = 0; i < BOX; i++) {
    destinations[box[i]] += 1;
  }

  // 移動時間
  int start_position = -2;
  for (int i = 0; i < LEVEL; i++) {
    if (0 < destinations[i]) {  // i階に行く人がいれば...
      stop++;
      result += TRAFFIC_TIME[-(start_position - i) - 1];
      r.service += result;
      result += 17.92;

      start_position = i;
    }
  }

  r.service /= stop;
  r.back = TRAFFIC_TIME[start_position + 1];
  return r;
}

RESULT result_average(void) {
  int box[BOX] = {};
  for (int i = 0; i < BOX; i++) {
    box[i] = get_in_box();
  }
  RESULT r = result(box);
  printf("result: service = %lf, back = %lf", r.service, r.back);
  return r;
}
