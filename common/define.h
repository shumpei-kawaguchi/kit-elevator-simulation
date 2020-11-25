//
//  define.h
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/20.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#ifndef DEFINE_H
#define DEFINE_H

#include <stdio.h>

#define START "--START--\n"
#define END "--END--\n"
#define LEVEL 7
#define CLASS 8
#define NUMBER_OF_PEOPLE 50
#define BOX 10
#define END_TIME 1000
#define SERVER 3

extern FILE *file;
extern const int classroom_of_level[LEVEL];
extern int ratio_of_class[CLASS];
extern char id[9];
extern int LOG;

#endif
