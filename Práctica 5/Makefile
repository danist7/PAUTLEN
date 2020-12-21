CC = gcc
CFLAGS = -g -Wall
LIBS = tokens.h lex.yy.c alfa.tab.c tabla_simbolos.c generacion.c
EXES = aritmeticas1 aritmeticas2 casobasico comparaciones if1 if2 if3 logicas1 logicas2 vectores1 vectores2 vectores3 vectores4 while funciones1 funciones2 funciones3 funciones4 error_ej1 error_ej2
ERR = error_se1 error_se2 error_se3 error_se4 error_se5 error_se6 error_se7 error_se8 error_se9 error_se10 error_se11 error_se12 error_se13 error_se14 error_se15

all: alfa

alfa:
	flex alfa.l
	bison -d alfa.y
	$(CC) $(CFLAGS) alfa.c $(LIBS) -o alfa

exes: $(EXES)

$(EXES):
	./alfa ejemplos/$@.alf salidas/$@.asm
	nasm -g -o $@.o -f elf32 salidas/$@.asm
	gcc -m32 -o $@ $@.o lib/alfalib.o

err: $(ERR)

$(ERR):
	./alfa ejemplos/$@.alf salidas/$@.asm

clean:
	rm -rf lex.yy.c alfa $(EXES) *.o salidas/*.asm alfa.tab.h alfa.tab.c
