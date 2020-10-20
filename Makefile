CC            = gcc
CFLAGS        = -g -Wall

CXX           = g++
TEST_TARGET   = test/test.cpp
TESTFLAGS     = -lgtest_main -lgtest

OBJS          = main.o combination.o
PROGRAM       = kit-elevator-simulation

all: $(PROGRAM)

clean:
	rm -f *.o *~ $(PROGRAM)


.PHONY: all test clean

test:
	$(CXX) -std=c++11 $(TEST_TARGET) -lgtest_main -lgtest
	./a.out

debug:
	./a.out

build: $(OBJS)
	$(CC) $(CFLAGS) -o build $(OBJS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

combination.o: calculations/combination.c
	$(CC) $(CFLAGS) -c calculations/combination.c
