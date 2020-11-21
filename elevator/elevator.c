//
//  elevator.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/11/11.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "elevator.h"

double elevator_system(double p1, double p2) {
  int time = 0;
  int queue = 0;
  int total_queue = 0;

  while (time < END_TIME) {
    for (int i = 0; i < SERVER; i++) {
      if (queue != 0) {
        if (Rand() < p2) {
          queue--;
        }
      }
    }

    if (Rand() < p1) {
      queue++;
    }

    time++;
    total_queue += queue;
  }

  double result = (double)total_queue / time;
  return result;
}
