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

int log_write()
{
  FILE *outputfile;
  outputfile = fopen("./output/test.log", "w");
  if (outputfile == NULL)
  {
    printf("cannot open file");
    exit(1);
  }

  fprintf(outputfile, "My name is Shumpei Kawaguchi.\n");
  fclose(outputfile);
  return 0;
}
