//
//  combination.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/20.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "combination.h"

// nCr = n!/(r! (n-r)!)
// If n < r, return 0.
int combination_calculator(int n, int r) {
  if (r == 0 || n == r)
    return 1;
  else if (r == 1)
    return n;
  else
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// 3! = 3 * 2 * 1
int factorial(int n) {
  if (n == 0) return 1;
  int fact = n;
  while (n > 1) {
    fact = fact * (n - 1);
    n -= 1;
    /* code */
  }

  return fact;
}
