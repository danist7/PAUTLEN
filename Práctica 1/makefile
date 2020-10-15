.DEFAULT_GOAL = all
.PHONY: all clean

CC := gcc
CFLAGS := -Wall -g -std=c99
AUX :=

#Ficheros a ejecutar
EXES = ejemplo1 ejemplo2
AUX_OBJ = generacion

#Targets
all : $(EXES)

$(EXES) : % : %.o $(AUX_OBJ).o
	$(CC) $(CFLAGS) -o $@ $@.o $(AUX_OBJ).o $(AUX)

$(AUX_OBJ) : % : %.c %.h
	$(CC) $(CFLAGS) -c $<

clean :
	rm -rfv *.o core $(EXES) \
	$(filter-out alfalib.o,$(wildcard *.o))
