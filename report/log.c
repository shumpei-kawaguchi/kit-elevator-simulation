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
#include <time.h>

#include "../common/define.h"

static char type_name[3][7] = {"INFO", "ERROR", "DEBUG"};

// log_type 0 = "INFO", 1 = "ERROR", 2 = "DEBUG"
int log_write(int log_type, char *func, char *message) {
  log_header();
  FILE *outputfile;
  outputfile = fopen("./output/test.log", "a");
  if (outputfile == NULL) {
    printf("cannot open file");
    exit(1);
  }

  fprintf(outputfile, "%s/[%s] %s\n", type_name[log_type], func, message);
  fclose(outputfile);
  return 0;
}

int log_header() {
  time_t now = time(NULL);
  struct tm *pnow = localtime(&now);
  char month[][5] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                     "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

  FILE *outputfile;
  outputfile = fopen("./output/test.log", "a");
  if (outputfile == NULL) {
    printf("cannot open file");
    exit(1);
  }

  fprintf(outputfile, "%s-%2d ", month[pnow->tm_mon], pnow->tm_mday);

  if (pnow->tm_hour < 10) fprintf(outputfile, "0");
  fprintf(outputfile, "%d:", pnow->tm_hour);
  if (pnow->tm_min < 10) fprintf(outputfile, "0");
  fprintf(outputfile, "%d:", pnow->tm_min);
  if (pnow->tm_sec < 10) fprintf(outputfile, "0");
  fprintf(outputfile, "%d ", pnow->tm_sec);
  fclose(outputfile);
  return 0;
}
