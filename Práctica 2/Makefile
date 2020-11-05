.DEFAULT_GOAL = all
.PHONY: all clean

CC := gcc
CFLAGS := -Wall -g -std=c99

all: main

main: main.c lex.yy.o
	$(CC) $(CFLAGS) $^ -o $@

lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) -c $^

lex.yy.c: alfa.l
	flex $^

clean:
	rm -rf *.o pruebaMorfo lex.yy.*
