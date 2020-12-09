//
//  init.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/21.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "init.h"

const int classroom_of_level[LEVEL] = {1, 3, 3, 3, 2, 2, 1};

static int ratio_pattern(void) {
  const char *TAG = __func__;
  int classroom[LEVEL] = {};

  for (int i = 0; i < LEVEL; i++) {
    classroom[i] = classroom_of_level[i];
  }

  int n = 0;
  while (n < CLASS) {
    int level = genRand(0, LEVEL - 1);
    if (classroom[level] > 0) {
      ratio_of_class[n] = level;
      classroom[level]--;
      n++;
    }
  }
  return 0;
}

int init(void) {
  const char *TAG = __func__;
  // Make ratio pattern.
  ratio_pattern();
  // report.
  int combination[LEVEL] = {};

  int id = 0;

  for (int i = 0; i < CLASS; i++) {
    combination[ratio_of_class[i]] += 1;
  }

  for (int i = 0; i < LEVEL; i++) {
    // csv_d("%d", combination[i]);
    id += combination[i] * pow(10, LEVEL - (i + 1));
  }

  return id;
}

const char *month(int month) {
  static const char month_string[12][5] = {"Jan", "Feb", "Mar", "Apr",
                                           "May", "Jun", "Jul", "Aug",
                                           "Sep", "Oct", "Nov", "Dec"};
  return month_string[month];
}

int new_csv(void) {
  FILE *file;
  // file open.
  file = fopen("./output/data.csv", "a");
  if (file == NULL) {
    printf("Cannot open file.\n");
    exit(1);
  }

  // Get time.
  time_t now = time(NULL);
  struct tm *pnow = localtime(&now);
  // Output Console and log file.
  // MM-DD,hh,mm,ss
  fprintf(file, "%s-%02d,%02d:%02d:%02d\n", month(pnow->tm_mon), pnow->tm_mday,
          pnow->tm_hour, pnow->tm_min, pnow->tm_sec);

  // Imput define.
  fprintf(file,
          "LEVEL %d,"
          "CLASS %d,"
          "NUMBER_OF_PEOPLE %d,"
          "BOX %d,"
          "END_TIME %d,"
          "SERVER %d\n",
          LEVEL, CLASS, NUMBER_OF_PEOPLE, BOX, END_TIME, SERVER);

  fprintf(file, "Classrooms,");
  for (int i = 0; i < LEVEL; i++)
    fprintf(file, "%dF=%d,", i + 3, classroom_of_level[i]);
  fprintf(file, "\n");
  // Input Category.
  fprintf(file,
          "Number,"
          "Combination,"
          "Service average,"
          "λ,"
          "μ,"
          "ρ,"
          "End time,"
          "L,"
          "System average,"
          "Tw\n");
  // File close
  fclose(file);
  return 0;
}
