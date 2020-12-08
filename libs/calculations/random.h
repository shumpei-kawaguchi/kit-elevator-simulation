//
//  random.h
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/31.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#ifndef RANDOM_H
#define RANDOM_H

#include <stdlib.h>
#include <time.h>

static inline double Rand() { return ((double)rand() / RAND_MAX); };

static inline int genRand(int min, int max) {
  static int flag;
  if (flag == 0) {
    srand((unsigned int)time(NULL));
    rand();
    flag = 1;
  }
  return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}

#endif
