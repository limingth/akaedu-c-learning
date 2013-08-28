
#CC = arm-linux-gcc
CC=gcc
TEST = abc
CC=cc
TEST ?= 123 
#TEST:=$(TEST)    $(CC)

all: main
	echo ok, finished!
	echo $(TEST)

main: head.h head2.h
main: add.o sub.o main.o 
#  adkjfalsjdf
	$(CC) -O2 $^ -o $@

%.o: %.c
	$(CC) -g -c $< -o $@

main.o: main.c 
	$(CC) -O0 -c main.c

add.o: add.c 
	$(CC) -c add.c

sub.o: sub.c
	$(CC) -c sub.c


test:
	echo target : $@
	echo leftmost: $<
	echo total: $^
	echo newest: $?
	$(CC) main.o add.o sub.o -o main

%:
	echo only for $@

#main.o: main.c head.h
.PHONY: clean
c clean:
	-rm a.out
	-rm *.o
	-rm main
	@echo clean ok




tmp:
#compile run
	make compile
	-make run
	echo finish

run:
	./a.out

compile:
	gcc NULL.c

