//
//  log.h
//  kit-elevator-simulation
//
//  Created by Shumpei Kawaguchi on 2020/10/27.
//  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
//

#ifndef LOG_H
#define LOG_H

int log_write(log_type t, char *func, char *message);
int log_header();

#endif
