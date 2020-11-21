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
  settings st = setup();
  log_write(0, TAG, START);

  for (int interval = 0; interval < st.iterations; interval++) {
    csv_d("%d,", interval);
    init();
    double average = service_average();
    double final_result = 0.0;
    // １秒当たりの、到着率
    double p1 = (double)(CLASS * NUMBER_OF_PEOPLE) / (10 * 60);
    // 一人当たりの、サービス率
    double p2 = 1 / (average / BOX);

    if (st.is_convergence == true) {
      histgram hist = {0.0, 0.0, 0.0, 0.0, 0, 0};

      while (hist.n < 10 || hist.n_variance == 0.0) {
        double result = elevator_system(p1, p2);
        hist.total += result;

        // convergence
        if (hist.i > 0) {
          hist.deviation += pow(result, 2.0);
          hist.b_variance = hist.n_variance;
          hist.n_variance =
              (hist.deviation / hist.i + 1) - pow((hist.total / hist.i + 1), 2);
          if (fabs(hist.b_variance - hist.n_variance) < 0.01) hist.n++;
        }
        hist.i++;
      }

      final_result = hist.total / hist.i;
    } else {
      final_result = elevator_system(p1, p2);
    }

    // ========= Log =========
    log_write(0, TAG, "");
    log_lf("Result = %lf, ", average);
    log_lf("p1 = %lf, ", p1);
    log_lf("p2 = %lf\n", p2);
    log_write(0, TAG, "");
    log_lf("Final result = %lf\n", final_result);

    csv_lf(",%lf", average);
    csv_lf(",%lf", p1);
    csv_lf(",%lf", p2);
    csv_lf(",%lf\n", final_result);
    printf("\r%3.2f％ %.2fsec",
           ((double)interval + 1) * 100 / (double)st.iterations,
           (double)clock() / CLOCKS_PER_SEC);
    fflush(stdout);
  }
  printf(" Completed🔥\n");
  log_write(0, TAG, END);
  exit(0);
}
