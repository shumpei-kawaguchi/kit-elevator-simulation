//
//  boxOptimisation.h
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/12/7.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#ifndef BOXOPTIMISATION_H
#define BOXOPTIMISATION_H

/*
 * NOTE:
 * - Useable function service(int* box)
 *   return type: double - it's a round trip time.
 */

#include "../calculations/calculations.h"
#include "../common/define.h"
#include "../report/csv.h"
#include "../report/log.h"
#include "move.h"

/*
 * Optimisation box:
 * - parameters
 *   : None (void)?
 *
 * - return type: int[BOX] - optimisation box.
 */

typedef struct customer {
  int destination;
  int arrival;
  struct customer* next;
} CUSTOMER;

static inline int opt_box(void) {
  return ratio_of_class[genRand(0, CLASS - 1)];
}

static CUSTOMER *head = NULL, *temp = NULL, *prev = NULL;
static int queue_length = 0;  // struct customer size

static inline int append_queue(int time) {
  temp = (CUSTOMER*)malloc(sizeof(CUSTOMER));
  if (temp == NULL) exit(-1);

  temp->destination = ratio_of_class[genRand(0, CLASS - 1)];
  temp->arrival = time;
  temp->next = NULL;

  if (head == NULL) {
    head = temp;
  } else {
    prev->next = temp;
  }
  prev = temp;
  queue_length++;
  printf("append!");
  return 0;
}

/*
 * Optimisation service average:
 * - parameters
 *   : None (void)
 *
 * - return type: double - service average.
 */

static inline double opt_service_average(void) {
  const char* TAG = __func__;
  log_write(0, TAG, START);

  // init
  int box[BOX] = {};
  double result = 0.0;
  int rt = 0;

  // new
  double rambda = (double)(CLASS * NUMBER_OF_PEOPLE) / (10 * 60);
  double elevators[] = {0.0, 0.0, 0.0};
  int customers = CLASS * NUMBER_OF_PEOPLE;
  int time = 0;

  while (customers > 0) {
    /// rambda arrival - create queue
    // sort elevators
    for (int i = 0; i < 2; i++) {
      double min = elevators[i];
      int k = i;

      for (int j = i + 1; j < 3; j++) {
        if (min > elevators[j]) {
          min = elevators[j];
          k = j;
        }
      }

      int tmp = elevators[i];
      elevators[i] = elevators[k];
      elevators[k] = tmp;
    }

    for (int i = 0; i < 3; i++) {
      printf("e[%d] = %lf\n", i, elevators[i]);
    }

    // customer waiting...
    while (elevators[0] > 0) {
      if (Rand() < rambda) append_queue(time);
      elevators[0] -= 1;
      elevators[1] -= 1;
      elevators[2] -= 1;
      time++;
    }

    // elevator waiting...
    while (queue_length < 10) {
      if (Rand() < rambda) append_queue(time);
      if (elevators[1] > 0) elevators[1] -= 1;
      if (elevators[2] > 0) elevators[2] -= 1;
      time++;
    }

    // mim queue length 10
    // optimisation box from queue
    opt_box();

    int i = 0;
    for (CUSTOMER* h = head; h; h = h->next) {
      if (i > 9) break;
      box[i] = h->destination;
      i++;
    }

    for (int i = 0; i < 10; i++) {
      printf("box[%d] = %d\n", i, box[i]);
    }

    // service
    elevators[0] = service(box);
    queue_length -= BOX;
    customers -= BOX;

    result += elevators[0];
    printf("customers: %d\n", customers);
    rt++;
  }

  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }

  log_write(0, TAG, END);
  printf("rt: %d, average: %lf\n", rt, average(result, (double)rt + 1));
  return average(result, (double)rt + 1);
}

#endif
