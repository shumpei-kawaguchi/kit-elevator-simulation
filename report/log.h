//
//  log.h
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/27.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#ifndef LOG_H
#define LOG_H

#include "file.h"

int log_write(int log_type, const char *func, char *message);
int log_d(char *message, int value);
int log_lf(char *message, double value);

#endif
