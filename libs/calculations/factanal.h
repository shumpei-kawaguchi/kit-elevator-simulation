//
//  factanal.h
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/11/19.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#ifndef FACTANAL_H
#define FACTANAL_H

inline int factanal(int x) {
  int f = x;
  while (1) {
    x--;
    if (x < 2) break;
    f = f * x;
  }
  return f;
}

#endif
