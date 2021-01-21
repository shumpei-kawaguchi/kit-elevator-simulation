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
  int optimisation;
} SETTINGS;

int pattern(void) {
  int pt[] = {0,   7,   26,  68,  138, 228, 315, 369,
              369, 315, 228, 138, 68,  26,  7,   1};
  printf("pt = %d\n", pt[CLASS]);
  return pt[CLASS];
}

SETTINGS setup(void) {
  SETTINGS st = {0, 0};
  new_csv();
  printf("\n[Setup] type iterations number.\n-> ");
  scanf("%d", &st.iterations);
  printf("\n[Setup] Optimisation box? type 0[yes] or 1[no]\n-> ");
  while (1) {
    scanf("%d", &st.optimisation);
    if (st.optimisation == 0 || st.optimisation == 1)
      break;
    else
      printf("fatal\n->");
  }
  return st;
}

int main(void) {
  SETTINGS setting = setup();

  int pt = pattern();
  int p_array[pt];
  int count = pt;

  while (count > 0) {
    int id = init();
    int i = 0;
    for (i = 0; i < pt - count; i++) {
      if ((p_array[i] - id) == 0) {
        // printf("cof %d\n", id);
        id = 0;
        break;
      }
    }
    // printf("%d, %d, ", i, pt - count);

    if (id != 0) {
      p_array[pt - count] = id;
      // printf("%d\n", p_array[pt - count]);
      count--;
    }
  }

  for (int i = 0; i < pt - 1; i++) {
    int maxi = p_array[i];
    int k = i;

    for (int j = i + 1; j < pt; j++) {
      if (maxi < p_array[j]) {
        maxi = p_array[j];
        k = j;
      }
    }

    int temp = p_array[i];
    p_array[i] = p_array[k];
    p_array[k] = temp;
    printf("%d,", p_array[i]);
  }
  printf("%d\n", p_array[pt - 1]);

  // main
  for (int j = 0; j < pt; j++) {
    for (int i = 0; i < setting.iterations; i++) {
      p = malloc(sizeof(PATTERN));
      if (p == NULL) exit(-1);
      int id = p_array[j];
      while (id != p->id) {
        p->id = init();
      }

      //実測値に基づくタイムドリブン型確率シミュレーション
      p->average = result_average(setting.optimisation);

      //モデルの作成
      p->model = mmn_model();

      //モデルに基づくタイムドリブン型理論シミュレーション
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
      printf(
          "\r%3.2f％ %.2fsec",
          ((double)((pt * j) + ((double)(pt / setting.iterations) * (i + 1)))) /
              ((double)(pt * pt)) * 100,
          (double)clock() / CLOCKS_PER_SEC);
      fflush(stdout);
    }
  }

  printf(" Completed🔥\n");
  return 0;
}
