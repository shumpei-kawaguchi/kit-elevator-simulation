//
//  main.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/20.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include <stdio.h>

#include "calculations/combination.h"
#include "calculations/ratio.h"
#include "common/define.h"
#include "common/init.h"
#include "queue/customer.h"

int main(void) {
  //
  init();
  //
  ratio_pattern();
  //
  int total = 0;
  for (int i = 0; i < LEVEL; i++) {
    total += ratio_of(i);
    printf("%d\t", ratio_of(i));
  }
  printf("total = %d\n", total);
  //
}
