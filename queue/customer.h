//
//  customer.h
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/21.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#ifndef CUSTOMER_H
#define CUSTOMER_H

typedef struct node {
  int level;
  int number_of_people;
  struct node *next;
} customer;

customer customer_of_level(int level);

#endif
