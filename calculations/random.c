//
//  random.c
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/31.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#include "random.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int genRand(int min, int max) {
  static int flag;
  if (flag == 0) {
    srand((unsigned int)time(NULL));
    rand();
    flag = 1;
  }
  int ret = min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
  return ret;
}

char* getRandomCharsLower(int length) {
  char chars[length + 2];
  for (int i = 0; i < length; i++) {
    chars[i] = getRandomCharLower();
  }
  return chars;
}

static char getRandomCharLower(void) {
  //　英小文字の例
  const char CHARS[] =
      "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int index = genRand(0, (strlen(CHARS) - 1));
  char c = CHARS[index];
  return c;
}
