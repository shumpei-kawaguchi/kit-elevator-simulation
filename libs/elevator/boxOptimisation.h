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
#include "../sort/array.h"
#include "move.h"

#define RAMBDA (double)(CLASS * NUMBER_OF_PEOPLE) / (10 * 60)

typedef struct customer {
  int destination;
  int arrival;
  double sort;
  struct customer *next;
} CUSTOMER;

static CUSTOMER *head = NULL, *prev = NULL;
static int queue_length = 0;
static int customers = CLASS * NUMBER_OF_PEOPLE;

static inline int sort_rule(void) {
  int dest_ratio[LEVEL] = {};
  int count = 0, i = 0;
  for (CUSTOMER *h = head; h; h = h->next) {
    count++;
    dest_ratio[h->destination]++;
  }

  for (CUSTOMER *h = head; h; h = h->next) {
    i++;
    h->sort = (double)i / count;
    h->sort += 25 / (double)dest_ratio[h->destination];
  }
  return 0;
}

static CUSTOMER *sortList(void) {
  CUSTOMER *headUnsorted, *headSorted;
  CUSTOMER *max, *prevMax, *prevComp;

  headUnsorted = head; /* 未ソートリスト */
  headSorted = NULL;   /* ソート済リスト */

  while (headUnsorted != NULL) {
    max = headUnsorted; /* 最大値要素を示すポインタ */
    prevMax = NULL; /* 最大値要素の前の要素を示すポインタ */
    prevComp = headUnsorted; /* 比較対象要素の前の要素を示すポインタ */

    while (prevComp->next != NULL) {
      /* 最大値要素と比較対象要素を比較する */
      if ((prevComp->next)->sort > max->sort) {
        /* 最大値要素の更新 */
        max = prevComp->next;
        prevMax = prevComp;
      }
      /* 比較対象要素を更新 */
      prevComp = prevComp->next;
      prev = prevComp;
    }

    /* 最大値要素を未ソートリストから削除 */
    if (prevMax == NULL) {
      headUnsorted = max->next;
    } else {
      prevMax->next = max->next;
    }

    /* 最大値要素をソート済リストの先頭に追加 */
    if (headSorted == NULL) {
      headSorted = max;
      max->next = NULL;
    } else {
      max->next = headSorted;
      headSorted = max;
    }
  }

  // reset prev
  for (CUSTOMER *h = headSorted; h; h = h->next) {
    prev = h;
  }

  return headSorted;
}

static inline int *opt_box(int *box) {
  int i = 0;
  CUSTOMER *temp = NULL;
  for (CUSTOMER *h = head; h; h = h->next) {
    box[i] = h->destination;

    i++;
    if (i > BOX - 1) {
      for (int i = 0; i < BOX; i++) {
        temp = head;
        head = head->next;
        free(temp);
      }
      head = h->next;
      break;
    }
  }
  return box;
}

static inline int append_queue(int time) {
  if (customers < 1) return 0;
  CUSTOMER *temp = NULL;
  temp = (CUSTOMER *)malloc(sizeof(CUSTOMER));
  if (temp == NULL) exit(-1);

  temp->destination = ratio_of_class[genRand(0, CLASS - 1)];
  temp->arrival = time;
  temp->sort = 0.0;
  temp->next = NULL;

  if (head == NULL) {
    head = temp;
  } else {
    prev->next = temp;
  }
  prev = temp;
  queue_length++;
  customers--;
  return 0;
}

static inline int customer_waiting(double *elevators, int time) {
  while (elevators[0] > 0) {
    if (Rand() < RAMBDA) append_queue(time);
    elevators[0] -= 1.0;
    elevators[1] -= 1.0;
    elevators[2] -= 1.0;
    time++;
  }
  return time;
}

static inline int elevator_waiting(double *elevators, int time) {
  while (queue_length < BOX) {
    if (Rand() < RAMBDA) append_queue(time);
    if (elevators[1] > 0) elevators[1] -= 1.0;
    if (elevators[2] > 0) elevators[2] -= 1.0;
    time++;
  }
  return time;
}

/*
 * Optimisation service average:
 * - parameters
 *   : None (void)
 *
 * - return type: double - service average.
 */
static inline double opt_service_average(void) {
  const char *TAG = __func__;
  log_write(0, TAG, START);

  // init
  int box[BOX] = {};
  double result = 0.0;
  int rt = 0;

  double elevators[SERVER] = {};
  // int customers = CLASS * NUMBER_OF_PEOPLE;
  int time = 0;

  while (1) {
    /// rambda arrival - create queue
    // sort elevators
    sort_array(elevators, SERVER);

    // customer waiting...
    time = customer_waiting(elevators, time);
    // elevator waiting...
    time = elevator_waiting(elevators, time);
    // optimisation box from queue
    sort_rule();
    head = sortList();
    // Get in the box
    opt_box(box);

    // service
    elevators[0] = service(box);
    queue_length -= BOX;
    // customers -= BOX;

    result += elevators[0];
    rt++;

    if (customers <= 0 && queue_length <= 0) break;
  }

  CUSTOMER *temp = NULL;
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }

  log_write(0, TAG, END);
  return average(result, (double)rt + 1);
}

#endif
