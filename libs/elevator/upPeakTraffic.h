//
//  upPeakTraffic.h
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/12/7.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#ifndef UPPEAKTRAFFIC_H
#define UPPEAKTRAFFIC_H

#include "../common/define.h"

static inline MODEL up_peak_traffic(double average) {
  // １秒当たりの、到着率
  double rambda = (double)(CLASS * NUMBER_OF_PEOPLE) / (10 * 60);
  // 一人当たりの、サービス率
  double mu = 1 / (average / BOX);

  MODEL model = {rambda, mu, SERVER};

  return model;
}

#endif
