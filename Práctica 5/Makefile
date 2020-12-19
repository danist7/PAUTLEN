CC = gcc
CFLAGS = -g -Wall
LIBS = tokens.h lex.yy.c alfa.tab.c tabla_simbolos.c generacion.c
EJS = alfa
OUTS = salida_casobasico

all: $(EJS)

alfa:
	flex alfa.l
	bison -d alfa.y
	$(CC) $(CFLAGS) alfa.c $(LIBS) -o alfa

nasm: $(OUTS)

$(OUTS):
	nasm -g -o $@.o -f elf32 salidas/$@.asm
	gcc -m32 -o $@ $@.o lib/alfalib.o

clean:
	rm -rf lex.yy.c $(EJS) $(OUTS) $(OUTS).o
