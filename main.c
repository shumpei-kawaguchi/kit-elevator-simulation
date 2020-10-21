//
//  main.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/20.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include <stdio.h>

#include "calculations/combination.h"

int main(void) {
  int comb = combinations(7, 5);
  printf("%d\n", comb);

  int fact = factorial(3);
  printf("%d\n", fact);
}
