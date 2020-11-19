//
//  customer.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/21.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "customer.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../calculations/random.h"
#include "../calculations/ratio.h"
#include "../common/define.h"
#include "../report/log.h"

int get_in_box(void) {
  // bool condition = false;
  int destination = 0;

  destination = ratio_of(genRand(0, CLASS - 1));

  // do {
  //   destination = genRand(0, LEVEL - 1);
  //   if (customer_queue[destination] != 0) {
  //     customer_queue[destination] -= 1;
  //     condition = true;
  //   }
  // } while (condition != true);
  return destination;
}
