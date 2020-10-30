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

int log_write(log_type t, char *func, char *message)
{
  log_header();
  FILE *outputfile;
  outputfile = fopen("./output/test.log", "a");
  if (outputfile == NULL)
  {
    printf("cannot open file");
    exit(1);
  }

  fprintf(outputfile, "%s/[%s] %s\n", type_name[t], func, message);
  fclose(outputfile);
  return 0;
}

int log_header()
{
  time_t now = time(NULL);
  struct tm *pnow = localtime(&now);
  char month[][5] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

  FILE *outputfile;
  outputfile = fopen("./output/test.log", "a");
  if (outputfile == NULL)
  {
    printf("cannot open file");
    exit(1);
  }

  fprintf(outputfile, "%s-%2d %d:%d:%d ",
          month[pnow->tm_mon],
          pnow->tm_mday,
          pnow->tm_hour,
          pnow->tm_min,
          pnow->tm_sec);
  fclose(outputfile);
  return 0;
}
