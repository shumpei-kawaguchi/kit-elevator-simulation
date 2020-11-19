//
//  move.c
//  kit-elevator-simulation
//
//  Created by Kazusa Watanabe on 2020/10/22.
//  Copyright (c) 2020 Kazusa Watanabe. All rights reserved.
//

#include <stdio.h>

#include "../common/define.h"

static const double time[8] = {1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0};

double move(int* box) {
  double result = 0.0;
  // 何階に止まるか
  int destinations[LEVEL] = {};
  for (int i = 0; i < 10; i++) {
    destinations[box[i]] += 1;
  }
  // for (int i = 0; i < LEVEL; i++) {
  //   printf("Level %d = %d\n", i + 3, destinations[i]);
  // }
  // 移動時間
  int start_position = -2;
  for (int i = 0; i < LEVEL; i++) {
    if (0 < destinations[i]) {  // i階に行く人がいれば...
      result += time[-(start_position - i) - 1];

      start_position = i;
    }
  }
  result += time[start_position + 1];
  // printf("back = %d\n", start_position);
  return result;
}
