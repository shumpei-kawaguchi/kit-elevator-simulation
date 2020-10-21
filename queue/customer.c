//
//  customer.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/21.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "customer.h"

#include <stdio.h>

customer customer_of_level(int level) {
  customer customer;
  customer.level = level;
  int array[] = {3, 6, 4, 8, 3, 5, 7, 3};
  int myclass = 0;

  for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
    printf("%d\n", array[i]);
    if (array[i] == level) {
      myclass++;
    }
  }

  customer.number_of_people = myclass * 50;
  printf("number is: %d\n", customer.number_of_people);
  return customer;
}
