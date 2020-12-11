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
LIBS          = libs/init.o libs/calculations.o
ELEVATOR      = libs/elevator.o libs/move.o libs/service.o
OPTIMISATION  = libs/optimisation.o libs/sort.o
#
OBJS          = main.o $(LIBS) $(QUEUE) $(ELEVATOR) $(OPTIMISATION)
OBJS_PATH     = compile/objs/
PROGRAM       = kit-elevator-simulation

.PHONY: all test clean

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) $(OUTPUT_OPTION) $(OBJS)

ca:
	make clean logrm csvrm

clean:
	rm -f *.o libs/*.o *.out *~ $(PROGRAM)

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

# main
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

#libs
libs/%.o: libs/$@.c
	$(CC) $(CFLAGS) -c libs/$@.c
