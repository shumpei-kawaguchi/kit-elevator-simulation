//
//  init.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/21.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "init.h"

#include <stdio.h>

#include "define.h"

int init() {
  class_number = CLASS;
  number_of_ina_class = NUMBER_OF_PEOPLE;

  printf("class: %d, number: %d\n", class_number, number_of_ina_class);

  return 0;
}
