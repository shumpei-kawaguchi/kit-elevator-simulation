//
//  log.h
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/27.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#ifndef LOG_H
#define LOG_H

#include "file.h"

// Write log header.
// MM-dd hh:mm:ss
static inline int log_header(void) {
  if (LOG == 0) return 0;
  time_t now = time(NULL);
  struct tm *pnow = localtime(&now);

  char path[32] = "";
  strcpy(path, file_path(0));
  // File open.
  file = fopen(path, "a");
  if (file == NULL) {
    printf("cannot open file");
    exit(1);
  }

  // Output Console and log file.
  // MMM-dd hh:mm:ss
  fprintf(file, "%s-%02d %02d:%02d:%02d ", month(pnow->tm_mon), pnow->tm_mday,
          pnow->tm_hour, pnow->tm_min, pnow->tm_sec);
  printf("%s-%02d %02d:%02d:%02d ", month(pnow->tm_mon), pnow->tm_mday,
         pnow->tm_hour, pnow->tm_min, pnow->tm_sec);

  // File close
  fclose(file);
  return 0;
}

// Write log to .log file.
// log_type 0 = "INFO", 1 = "ERROR", 2 = "DEBUG"
static inline int log_write(int log_type, const char *func, char *message) {
  static const char type_name[3][7] = {"INFO", "ERROR", "DEBUG"};
  if (LOG == 0) return 0;
  log_header();
  char path[32] = "";
  strcpy(path, file_path(0));
  // File open.
  file = fopen(path, "a");
  if (file == NULL) {
    printf("cannot open file\n");
    exit(1);
  }
  // File write.
  fprintf(file, "%s/[%s] %s", type_name[log_type], func, message);
  printf("%s/[%s] %s", type_name[log_type], func, message);
  // File close.
  fclose(file);
  return 0;
}

static inline int log_d(char *message, int value) {
  if (LOG == 0) return 0;
  char path[32] = "";
  strcpy(path, file_path(0));
  // File open.
  file = fopen(path, "a");
  if (file == NULL) {
    printf("cannot open file\n");
    exit(1);
  }
  // File write.
  fprintf(file, message, value);
  printf(message, value);
  // File
  fclose(file);
  return 0;
}

static inline int log_lf(char *message, double value) {
  if (LOG == 0) return 0;
  char path[32] = "";
  strcpy(path, file_path(0));
  // File open.
  file = fopen(path, "a");
  if (file == NULL) {
    printf("cannot open file\n");
    exit(1);
  }
  // File write.
  fprintf(file, message, value);
  printf(message, value);
  // File
  fclose(file);
  return 0;
}

#endif
