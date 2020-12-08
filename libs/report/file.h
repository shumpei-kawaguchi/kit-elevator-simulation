//
//  file.h
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/11/04.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../calculations/calculations.h"

#define CHARS "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

inline static const char *month(int month) {
  static const char month_string[12][5] = {"Jan", "Feb", "Mar", "Apr",
                                           "May", "Jun", "Jul", "Aug",
                                           "Sep", "Oct", "Nov", "Dec"};
  return month_string[month];
}

inline static int new_id(int length) {
  char chars[length + 2];
  for (int i = 0; i < length; i++) {
    int index = genRand(0, (strlen(CHARS) - 1));
    chars[i] = CHARS[index];
  }
  strcpy(id, chars);
  printf("log file is output/%s.log\n", id);
  // Make path
  return 0;
}

// modofier is 0 = ".log", 1 = ".csv".
inline static char *file_path(int modifier) {
  static const char file_type[2][6] = {".log", ".csv"};
  static char output_path[32] = "";
  strcpy(output_path, "./output/");
  strcat(output_path, id);
  strcat(output_path, file_type[modifier]);
  return output_path;
}

#endif
