//
//  csv.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/27.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "csv.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../calculations/ratio.h"
#include "../common/define.h"
#include "file.h"

int new_csv(void) {
  FILE *file;
  char path[32] = "";
  strcpy(path, file_path(1));
  // file open.
  file = fopen(path, "a");
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
  fprintf(file, "LEVEL=%d,CLASS=%d,NUMBER_OF_PEOPLE=%d\n", LEVEL, CLASS,
          NUMBER_OF_PEOPLE);
  fprintf(file, "Classrooms,");
  for (int i = 0; i < LEVEL; i++)
    fprintf(file, "%dF=%d,", i + 3, classroom_of(i));
  fprintf(file, "\n");
  // Input Category.
  fprintf(file, "Number,Combination,Total, Round trip for, Final result\n");
  // File close
  fclose(file);
  return 0;
}

// Add string to CSV file
int csv_s(char *string, char *value) {
  FILE *file;
  char path[32] = "";
  strcpy(path, file_path(1));
  // file open.
  file = fopen(path, "a");
  if (file == NULL) {
    printf("Cannot open file.\n");
    exit(1);
  }

  fprintf(file, string, value);

  // File close.
  fclose(file);
  return 0;
}

// Add int to CSV file
int csv_d(char *string, int value) {
  FILE *file;
  char path[32] = "";
  strcpy(path, file_path(1));
  // file open.
  file = fopen(path, "a");
  if (file == NULL) {
    printf("Cannot open file.\n");
    exit(1);
  }

  fprintf(file, string, value);

  // File close.
  fclose(file);
  return 0;
}

// Add double to CSV file
int csv_lf(char *string, double value) {
  FILE *file;
  char path[32] = "";
  strcpy(path, file_path(1));
  // file open.
  file = fopen(path, "a");
  if (file == NULL) {
    printf("Cannot open file.\n");
    exit(1);
  }

  fprintf(file, string, value);

  // File close.
  fclose(file);
  return 0;
}
