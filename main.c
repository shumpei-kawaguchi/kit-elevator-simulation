//
//  main.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/20.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "main.h"

// char id[9] = "test";

int ratio_of_class[CLASS] = {};

typedef struct settings {
  int iterations;
} SETTINGS;

SETTINGS setup(void) {
  const char *TAG = __func__;
  SETTINGS st = {0};
  new_csv();
  printf("\n[Setup] type iterations number.\n-> ");
  scanf("%d", &st.iterations);
  return st;
}

int main(void) {
  const char *TAG = __func__;
  SETTINGS setting = setup();
  for (int i = 0; i < setting.iterations; i++) {
    int id = init();
    // MARK: Surch
    //////////////
    p = malloc(sizeof(PATTERN));
    if (p == NULL) exit(-1);
    p->next = root;
    root = p;
    p->id = id;
    //////////////
    p->average = service_average();
    p->model = up_peak_traffic();
    p->result = convergence();
    // ========= Log =========
    printf("\r%3.2f％ %.2fsec",
           ((double)i + 1) * 100 / (double)setting.iterations,
           (double)clock() / CLOCKS_PER_SEC);
    fflush(stdout);
  }

  FILE *file;
  int i = 0;
  char path[32] = "./output/data.csv";
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
  printf(" Completed🔥\n");
  return 0;
}
