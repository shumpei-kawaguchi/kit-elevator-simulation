//
//  array.h
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/12/8.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>

static inline void sort_array(double *array, int length) {
  for (int i = 0; i < length - 1; i++) {
    double min = array[i];
    int k = i;

    for (int j = i + 1; j < length; j++) {
      if (min > array[j]) {
        min = array[j];
        k = j;
      }
    }

    double tmp = array[i];
    array[i] = array[k];
    array[k] = tmp;
  }

  return;
}

#endif
