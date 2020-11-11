CC            = gcc
CFLAGS        = -std=c11 -g -Wall
DIR           = calculations

CXX           = g++
TESTFLAGS     = -lgtest_main -lgtest

# Files
INIT          = init.o
CALCULATIONS  = ratio.o random.o
QUEUE         = customer.o
REPORT        = csv.o log.o file.o
ELEVATOR      = move.o
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

# calculations
ratio.o: calculations/ratio.c
	$(CC) $(CFLAGS) -c calculations/ratio.c

random.o: calculations/random.c
	$(CC) $(CFLAGS) -c calculations/random.c

# queue
customer.o: queue/customer.c
	$(CC) $(CFLAGS) -c queue/customer.c

#report
csv.o: report/csv.c
	$(CC) $(CFLAGS) -c report/csv.c

log.o: report/log.c
	$(CC) $(CFLAGS) -c report/log.c

file.o: report/file.c
	$(CC) $(CFLAGS) -c report/file.c

#elevator
move.o: elevator/move.c
	$(CC) $(CFLAGS) -c elevator/move.c
