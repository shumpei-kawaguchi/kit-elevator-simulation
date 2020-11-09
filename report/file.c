//
//  file.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/11/04.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "file.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../calculations/random.h"
#include "log.h"

static const char file_type[2][6] = {".log", ".csv"};
static const char month_string[12][5] = {"Jan", "Feb", "Mar", "Apr",
                                         "May", "Jun", "Jul", "Aug",
                                         "Sep", "Oct", "Nov", "Dec"};

const char *month(int month) { return month_string[month]; }

static char id[9] = "test";
static char output_path[32] = "";

int new_id(int length) {
  const char *TAG = __func__;
  char chars[length + 2];
  for (int i = 0; i < length; i++) {
    chars[i] = getRandomCharLower();
  }
  strcpy(id, chars);
  printf("log file is output/%s.log\n", id);
  // Make path
  log_write(2, TAG, id);
  return 0;
}

// modofier is 0 = ".log", 1 = ".csv".
char *file_path(int modifier) {
  strcpy(output_path, "./output/");
  strcat(output_path, id);
  strcat(output_path, file_type[modifier]);
  return output_path;
}
