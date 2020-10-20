CC            = gcc
CFLAGS        = -g -Wall
DIR           = calculations

CXX           = g++
TEST_TARGET   = test
TESTFLAGS     = -lgtest_main -lgtest

OBJS          = main.o combination.o
PROGRAM       = kit-elevator-simulation

.PHONY: all test clean

all:$(PROGRAM)

clean:
	rm -f *.o *~ $(PROGRAM)

# Test =================================
test:
	$(CXX) -std=c++11 test/test.cpp $(TESTFLAGS)
	./a.out

test%:
	$(CXX) -std=c++11 test/$@.cpp $(TESTFLAGS)
	./a.out

# main build =================================
build: $(OBJS)
	$(CC) $(CFLAGS) $(OUTPUT_OPTION) $(OBJS)


# Compile functions =================================
%.o: %.c
	$(CC) $(CFLAGS) -c $^

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

combination.o: calculations/combination.c
	$(CC) $(CFLAGS) -c calculations/combination.c
