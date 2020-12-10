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
#define END_TIME 10000
#define SERVER 3

typedef struct mdoel {
  double A;
  double B;
  double C;
} MODEL;

typedef struct st_result {
  double service;
  double back;
} RESULT;

typedef struct Queueing {
  int time;
  int queue;
  int total;
} QUEUEING;

typedef struct pattern {
  int id;
  MODEL model;
  QUEUEING queueing;
  // double average;
  RESULT average;
  double result;
  struct pattern *next;
} PATTERN;

extern int ratio_of_class[CLASS];
extern PATTERN *p;

#endif
