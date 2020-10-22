.DEFAULT_GOAL = all
.PHONY: all clean

CC := gcc
CFLAGS := -Wall -g -std=c99
AUX :=

#Ficheros a ejecutar
EXES = ejemplo1 ejemplo2 ejemplo3 ejemplo4 ejemplo6
AUX_OBJ = generacion
EXES_ASM = ejemplo1ASM ejemplo2ASM ejemplo3ASM ejemplo4ASM ejemplo6ASM

#Targets
all : $(EXES)

$(EXES) : % : %.o $(AUX_OBJ).o
	$(CC) $(CFLAGS) -o $@ $@.o $(AUX_OBJ).o $(AUX)
	./$@ $@ASM.asm
	nasm -g -o $@ASM.o -f elf32 $@ASM.asm
	gcc -m32 -o $@ASM $@ASM.o lib/alfalib.o

$(AUX_OBJ) : % : %.c %.h
	$(CC) $(CFLAGS) -c $<

clean :
	rm -rfv *.o *.asm core $(EXES) $(EXES_ASM)
