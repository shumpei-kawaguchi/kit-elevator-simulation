//
//  main.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/12/8.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "main.h"

char id[9] = "test";
int LOG = 1;

int setup(void) {
  const char *TAG = __func__;
  // SETTINGS st = {0};
  new_id(7);
  new_csv();
  // printf("\n[Setup] type iterations number.\n-> ");
  // scanf("%d", &st.iterations);
  printf("\n[Setup] Total class is %d\n", CLASS);
  for (int i = 0; i < LEVEL; i++) {
    int value = 0;
    printf("\n[Setup] Classroom of level %d.-> ", i + 3);
    scanf("%d", &value);
    classroom_of_level[i] = value;
  }

  log_write(0, TAG, "Finithed setup.\n");
  return 0;
}

int main(void) {
  setup();
  int id = init();
  printf("id is %d\n", id);
  p = malloc(sizeof(PATTERN));
  if (p == NULL) exit(-1);
  p->id = id;
  p->average = opt_service_average();
  p->model = up_peak_traffic(p->average);
  p->result = convergence();
  // printf("service = %lf\n", service);

  int i = 0;
  char path[32] = "";
  strcpy(path, file_path(1));
  file = fopen(path, "a");
  if (file == NULL) exit(1);
  double r = p->model.rambda / (SERVER * p->model.mu);
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
          i, p->id, p->average, p->model.rambda, p->model.mu, r,
          p->queueing.time, L, p->result, (p->result - p->average));

  fclose(file);
  printf(" Completed🔥\n");
  return 0;
}
