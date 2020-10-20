CC            = gcc
CFLAGS        = -g -Wall

TEST_TARGET   = test/test.cpp
TESTFLAGS     = -lgtest_main -lgtest

OBJS          = main.o sub.o
PROGRAM       = kit-elevator-simulation

all: $(PROGRAM)

clean:
	rm -f *.o *~ $(PROGRAM)

test:
	g++ -std=c++11 $(TEST_TARGET) $(TESTFLAGS)

debug:
	./a.out

build: main.o combination.o
	$(CC) $(CFLAGS) -o build $(OBJS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

combination.o: calculations/combination.c
	$(CC) $(CFLAGS) -c calculations/combination.c
