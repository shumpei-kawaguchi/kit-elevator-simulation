//
//  move.c
//  kit-elevator-simulation
//
//  Created by Kazusa Watanabe on 2020/10/22.
//  Copyright (c) 2020 Kazusa Watanabe. All rights reserved.
//

#include <stdio.h>

#include "../common/define.h"

static const double time[8] = {12.2, 15.3, 18.4, 20.7, 22.7, 24.9, 27.1, 29.3};

double move(int* box) {
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
      result += time[-(start_position - i) - 1];

      start_position = i;
    }
  }
  result += time[start_position + 1];
  return result;
}
