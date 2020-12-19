CC = gcc
CFLAGS = -g -Wall
LIBS = tokens.h lex.yy.c alfa.tab.c tabla_simbolos.c generacion.c
OUTS = logicas2

all: alfa nasm ejec

alfa:
	flex alfa.l
	bison -d alfa.y
	$(CC) $(CFLAGS) alfa.c $(LIBS) -o alfa

nasm:
	./alfa ejemplos/$(OUTS).alf salidas/$(OUTS).asm

ejec: $(OUTS)

$(OUTS):
	nasm -g -o $@.o -f elf32 salidas/$@.asm
	gcc -m32 -o $@ $@.o lib/alfalib.o

clean:
	rm -rf lex.yy.c alfa $(OUTS) $(OUTS).o salidas/$(OUTS).asm
