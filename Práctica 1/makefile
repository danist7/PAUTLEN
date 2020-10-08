
CC=gcc
CFLAGS=-g
COMPILAR=generacion.o

all: $(COMPILAR)

generacion.o: generacion.c
	$(CC) $(CFLAGS) -c $?

.PHONY: clean
clean:
	rm -rf *.o
