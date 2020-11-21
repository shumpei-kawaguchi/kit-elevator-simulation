#
#  Makefile
#  kit-elevator-simulation
#
#  Created by Shumpei Kawaguchi on 2020/10/20.
#  Copyright (c) 2020 Shumpei Kawaguchi. All rights reserved.
#

CC            = gcc
CFLAGS        = -std=c11 -g -Wall -O2
DIR           = calculations

CXX           = g++
TESTFLAGS     = -lgtest_main -lgtest

# Files
INIT          = init.o global.o
CALCULATIONS  =
REPORT        = csv.o log.o
ELEVATOR      = elevator.o
#
OBJS          = main.o $(INIT) $(CALCULATIONS) $(QUEUE) $(REPORT) $(ELEVATOR)
OBJS_PATH     = compile/objs/
PROGRAM       = kit-elevator-simulation

.PHONY: all test clean

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) $(OUTPUT_OPTION) $(OBJS)

ca:
	make clean logrm csvrm

clean:
	rm -f *.o *.out *~ $(PROGRAM)

logrm:
	rm -f output/*.log

csvrm:
	rm -f output/*.csv

build: $(OBJS)
	$(CC) $(CFLAGS) -o $(PROGRAM) $(OBJS)

run:
	./$(PROGRAM)

# Test =================================
test:
	$(CXX) -std=c++11 test/test.cpp $(TESTFLAGS)
	./a.out

test%:
	$(CXX) -std=c++11 test/$@.cpp $(TESTFLAGS)
	./a.out

# Compile functions =================================
%.o: %.c
	$(CC) $(CFLAGS) -c $^

# main
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

# common
init.o: common/init.c
	$(CC) $(CFLAGS) -c common/init.c

global.o: common/global.c
	$(CC) $(CFLAGS) -c common/global.c

# calculations


#report
csv.o: report/csv.c
	$(CC) $(CFLAGS) -c report/csv.c

log.o: report/log.c
	$(CC) $(CFLAGS) -c report/log.c

#elevator
elevator.o: elevator/elevator.c
	$(CC) $(CFLAGS) -c elevator/elevator.c
