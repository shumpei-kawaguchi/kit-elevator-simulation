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
      r.service += result * destinations[i];
      result += 17.92;

      start_position = i;
    }
  }

  r.service /= BOX;
  r.back = result + TRAFFIC_TIME[start_position + 1];
  return r;
}

RESULT result_average(void) {
  // init
  int box[BOX] = {};
  variances va_service = {0.0, 0.0, 0};
  variances va_back = {0.0, 0.0, 0};
  double va_s = 0, b_va_s = 0, va_b = 0, b_va_b = 0;
  int n = 0;
  RESULT pt_retult = {0.0, 0.0};

  while (n < 10) {
    for (int i = 0; i < BOX; i++) {
      box[i] = get_in_box();
    }
    pt_retult = result(box);

    va_service.result_total += pt_retult.service;
    va_service.squared_total += pow(pt_retult.service, 2.0);
    va_back.result_total += pt_retult.back;
    va_back.squared_total += pow(pt_retult.back, 2.0);

    if (va_service.i > 0) {
      b_va_s = va_s;
      va_s = variance(va_service);
    }
    if (va_back.i > 0) {
      b_va_b = va_b;
      va_b = variance(va_back);
    }

    if (fabs(b_va_s - va_s) < 0.01 && fabs(b_va_b - va_b) < 0.01) n++;
    va_service.i++;
    va_back.i++;
  }

  pt_retult.service =
      average(va_service.result_total, (double)va_service.i + 1);
  pt_retult.back = average(va_back.result_total, (double)va_back.i + 1);

  return pt_retult;
}
