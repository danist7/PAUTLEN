.DEFAULT_GOAL = all
.PHONY: all clean

CC := gcc
CFLAGS := -Wall -g -std=c99

#Ficheros a ejecutar
EXES = pruebaTabla
AUX_OBJ = #aqui van la tabla hash y la de simbolos

#Targets
all : $(EXES)

$(EXES) : % : %.o $(AUX_OBJ).o
	$(CC) $(CFLAGS) -o $@ $@.o $(AUX_OBJ).o

$(AUX_OBJ) : % : %.c %.h
	$(CC) $(CFLAGS) -c $<

clean :
	rm -rfv *.o core $(EXES)
