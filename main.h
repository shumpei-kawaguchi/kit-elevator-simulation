//
//  main.h
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/11/04.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>

#include "common/define.h"
#include "common/init.h"
#include "elevator/elevator.h"
#include "elevator/move.h"
#include "report/csv.h"
#include "report/file.h"
#include "report/log.h"

int main(void);

typedef struct item {
  int iterations;
  bool is_convergence;
} settings;

static settings setup(void) {
  const char *TAG = __func__;
  settings st = {0, true};
  new_id(7);
  new_csv();
  printf("\n[Setup] type iterations number.\n-> ");
  scanf("%d", &st.iterations);
  char c[] = "";
  printf("\n[Setup] Convergence System result?\n");
  while (strcmp(c, "y") != 0) {
    printf("(y/n)-> ");
    scanf("%s", c);
    if (strcmp(c, "n") == 0) {
      st.is_convergence = false;
      break;
    }
  }

  char l[] = "";
  printf("\n[Setup] Do you want to write log?\n");
  while (strcmp(l, "y") != 0) {
    printf("(y/n)-> ");
    scanf("%s", l);
    if (strcmp(l, "n") == 0) {
      LOG = 0;
      break;
    }
  }
  log_write(0, TAG, "Finithed setup.\n");
  return st;
}

#endif
