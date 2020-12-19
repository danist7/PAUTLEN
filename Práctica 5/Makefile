CC = gcc
CFLAGS = -g -Wall
LIBS = tokens.h lex.yy.c alfa.tab.c tabla_simbolos.c generacion.c
EXES = funciones1 funciones2 funciones3 funciones4

all: alfa nasm

alfa:
	flex alfa.l
	bison -d alfa.y
	$(CC) $(CFLAGS) alfa.c $(LIBS) -o alfa

nasm: $(EXES)

$(EXES):
	./alfa ejemplos/$@.alf salidas/$@.asm
	nasm -g -o $@.o -f elf32 salidas/$@.asm
	gcc -m32 -o $@ $@.o lib/alfalib.o

clean:
	rm -rf lex.yy.c alfa $(EXES) *.o salidas/*.asm
