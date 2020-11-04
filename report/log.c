//
//  log.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/27.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "log.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "file.h"

static const char type_name[3][7] = {"INFO", "ERROR", "DEBUG"};

// Write log to .log file.
// log_type 0 = "INFO", 1 = "ERROR", 2 = "DEBUG"
int log_write(int log_type, const char *func, char *message) {
  log_header();
  FILE *outputfile;
  char path[32] = "";
  strcpy(path, file_path(0));
  // File open.
  outputfile = fopen(path, "a");
  if (outputfile == NULL) {
    printf("cannot open file\n");
    exit(1);
  }

  fprintf(outputfile, "%s/[%s] %s\n", type_name[log_type], func, message);
  printf("%s/[%s] %s\n", type_name[log_type], func, message);
  fclose(outputfile);
  return 0;
}

// Write log header.
// MM-dd hh:mm:ss
int log_header(void) {
  time_t now = time(NULL);
  struct tm *pnow = localtime(&now);
  char month[][5] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                     "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

  FILE *outputfile;
  char path[32] = "";
  strcpy(path, file_path(0));
  // File open.
  outputfile = fopen(path, "a");
  if (outputfile == NULL) {
    printf("cannot open file");
    exit(1);
  }

  // Output Console and log file.
  // MM-DD
  fprintf(outputfile, "%s-%2d ", month[pnow->tm_mon], pnow->tm_mday);
  printf("%s-%2d ", month[pnow->tm_mon], pnow->tm_mday);
  // hh:
  if (pnow->tm_hour < 10) {
    fprintf(outputfile, "0");
    printf("0");
  }
  fprintf(outputfile, "%d:", pnow->tm_hour);
  printf("%d:", pnow->tm_hour);
  // mm:
  if (pnow->tm_min < 10) {
    fprintf(outputfile, "0");
    printf("0");
  }
  fprintf(outputfile, "%d:", pnow->tm_min);
  printf("%d:", pnow->tm_min);
  // ss
  if (pnow->tm_sec < 10) {
    fprintf(outputfile, "0");
    printf("0");
  }
  fprintf(outputfile, "%d ", pnow->tm_sec);
  printf("%d ", pnow->tm_sec);

  // File close
  fclose(outputfile);
  return 0;
}
