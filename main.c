//
//  main.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/20.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "main.h"

int ratio_of_class[CLASS] = {};
PATTERN *p;

typedef struct settings {
  int iterations;
} SETTINGS;

SETTINGS setup(void) {
  SETTINGS st = {0};
  new_csv();
  printf("\n[Setup] type iterations number.\n-> ");
  scanf("%d", &st.iterations);
  return st;
}

int main(void) {
  SETTINGS setting = setup();
  for (int i = 0; i < setting.iterations; i++) {
    p = malloc(sizeof(PATTERN));
    if (p == NULL) exit(-1);
    p->id = init();
    p->average = opt_service_average();
    p->model = mmn_model();
    p->result = convergence();
    // ========= CSV =========
    FILE *file;
    file = fopen("./output/data.csv", "a");
    if (file == NULL) exit(1);
    double r = p->model.A / (SERVER * p->model.B);
    double L = average(p->queueing.total, p->queueing.time + 1);
    fprintf(file,
            "%d,"
            "%d,"
            "%lf,"
            "%lf,"
            "%lf,"
            "%lf,"
            "%lf,"
            "%d,"
            "%lf,"
            "%lf,"
            "%lf\n",
            i, p->id, p->average.service, p->average.back, p->model.A,
            p->model.B, r, p->queueing.time, L, p->result,
            (p->result - p->average.service));
    fclose(file);
    free(p);
    // ========= Log progress =========
    printf("\r%3.2f％ %.2fsec",
           ((double)i + 1) * 100 / (double)setting.iterations,
           (double)clock() / CLOCKS_PER_SEC);
    fflush(stdout);
  }

  printf(" Completed🔥\n");
  return 0;
}
