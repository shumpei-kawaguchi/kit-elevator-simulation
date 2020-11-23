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
  settings setting = setup();
  log_write(0, TAG, START);

  for (int i = 0; i < setting.iterations; i++) {
    csv_d("%d,", i);
    init();
    double final_result = 0.0;

    model up_peak = up_peak_traffic();

    if (setting.is_convergence == true) {
      variances variances = {0.0, 0.0, 1};

      double va = 0;
      double b_va = 0;
      double n = 0;

      while (n < 10) {
        double result = MMn_queueing_simulation(up_peak);
        variances.result_total += result;
        variances.squared_total += pow(result, 2.0);
        if (variances.i > 0) {
          b_va = va;
          va = variance(variances);
        }
        if (fabs(b_va - va) < 0.01) {
          n++;
        }
        variances.i++;
      }

      final_result = average(variances.result_total, (double)variances.i);
    } else {
      final_result = MMn_queueing_simulation(up_peak);
    }

    // ========= Log =========
    log_write(0, TAG, "");
    log_lf("Final result = %lf\n", final_result);

    csv_lf(",%lf\n", final_result);
    printf("\r%3.2f％ %.2fsec",
           ((double)i + 1) * 100 / (double)setting.iterations,
           (double)clock() / CLOCKS_PER_SEC);
    fflush(stdout);
  }
  printf(" Completed🔥\n");
  log_write(0, TAG, END);
  exit(0);
}
