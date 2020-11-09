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
  // MMM-dd hh:mm:ss
  fprintf(outputfile, "%s-%02d %02d:%02d:%02d ", month(pnow->tm_mon),
          pnow->tm_mday, pnow->tm_hour, pnow->tm_min, pnow->tm_sec);
  printf("%s-%02d %02d:%02d:%02d ", month(pnow->tm_mon), pnow->tm_mday,
         pnow->tm_hour, pnow->tm_min, pnow->tm_sec);

  // File close
  fclose(outputfile);
  return 0;
}
