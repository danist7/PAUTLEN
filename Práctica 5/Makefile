CC = gcc
CFLAGS = -g -Wall
LIBS = tokens.h lex.yy.c alfa.tab.c tabla_simbolos.c generacion.c
OUTS = error_se1 error_se2 error_se3 error_se4 error_se5  error_se6 error_se7 error_se8 error_se9 error_se10

all: alfa nasm

alfa:
	flex alfa.l
	bison -d alfa.y
	$(CC) $(CFLAGS) alfa.c $(LIBS) -o alfa

#nasm:
#	./alfa ejemplos/$(OUTS).alf salidas/$(OUTS).asm

nasm: $(OUTS)

$(OUTS):
	./alfa ejemplos/$@.alf salidas/$@.asm


#$(OUTS):
#	nasm -g -o $@.o -f elf32 salidas/$@.asm
#	gcc -m32 -o $@ $@.o lib/alfalib.o

clean:
	rm -rf lex.yy.c alfa $(OUTS) $(OUTS).o salidas/$(OUTS).asm
