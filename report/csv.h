//
//  csv.h
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/27.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#ifndef CSV_H
#define CSV_H

#include "file.h"

int new_csv(void);
int csv_s(char *string, char *value);
int csv_d(char *string, int value);
int csv_lf(char *string, double value);

#endif
