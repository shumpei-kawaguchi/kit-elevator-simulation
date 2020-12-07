//
//  main.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/20.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "main.h"

char id[9] = "test";
int LOG = 1;

int main(void) {
  const char *TAG = __func__;
  SETTINGS setting = setup();
  log_write(0, TAG, START);

  for (int i = 0; i < setting.iterations; i++) {
    int id = init();
    // MARK: Search
    //////////////
    p = malloc(sizeof(PATTERN));
    if (p == NULL) exit(-1);
    p->next = root;
    root = p;
    p->id = id;
    //////////////
    p->model = up_peak_traffic();
    p->result = convergence();

    process_print(setting.iterations, i);
  }

  int i = 0;
  char path[32] = "";
  strcpy(path, file_path(1));
  file = fopen(path, "a");
  if (file == NULL) exit(1);
  for (p = root; p; p = p->next) {
    double r = p->model.A / (SERVER * p->model.B);
    double L = average(p->queueing.total, p->queueing.time + 1);
    fprintf(file,
            "%d,"
            "%d,"
            "%lf,"
            "%lf,"
            "%lf,"
            "%lf,"
            "%d,"
            "%lf,"
            "%lf,"
            "%lf\n",
            i, p->id, p->average, p->model.A, p->model.B, r, p->queueing.time,
            L, p->result, (p->result - p->average));
    i++;
  }
  fclose(file);
  log_write(0, TAG, END);
  printf(" Completed🔥\n");
  return 0;
}
