.DEFAULT_GOAL = all
.PHONY: all clean

CC := gcc
CFLAGS := -Wall -g -std=c99
AUX :=

#Ficheros a ejecutar
EXES = ejemplo1 ejemplo2
AUX_OBJ = generacion
EXES_ASM = f1 f2 f3 f4

#Targets
all : $(EXES)

$(EXES) : % : %.o $(AUX_OBJ).o
	$(CC) $(CFLAGS) -o $@ $@.o $(AUX_OBJ).o $(AUX)
	./$@ $@.asm
	nasm -g -o $@.o -f elf32 $@.asm
	gcc -m32 -o $@ $@.o lib/alfalib.o

$(AUX_OBJ) : % : %.c %.h
	$(CC) $(CFLAGS) -c $<

clean :
	rm -rfv *.o *.asm core $(EXES) $(EXES_ASM)
