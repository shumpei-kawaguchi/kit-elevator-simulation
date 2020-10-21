CC            = gcc
CFLAGS        = -g -Wall
DIR           = calculations

CXX           = g++
TEST_TARGET   = test
TESTFLAGS     = -lgtest_main -lgtest

OBJS          = main.o combination.o
OBJS_PATH     = compile/objs/
PROGRAM       = kit-elevator-simulation

.PHONY: all test clean

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) $(OUTPUT_OPTION) $(OBJS)

clean:
	rm -f *.o *.out *~ $(PROGRAM)

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

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

combination.o: calculations/combination.c
	$(CC) $(CFLAGS) -c calculations/combination.c
