.DEFAULT_GOAL = all
.PHONY: all clean

CC := gcc
CFLAGS := -Wall -g -std=c99

all: pruebaMorfo

pruebaMorfo: pruebaMorfo.c lex.yy.o
	$(CC) $(CFLAGS) $^ -o $@

## make test realiza nuestra salida para cada uno de los fichero de entrada
## propuestos y los compara con las salidas dadas.
test: diff1 diff2 diff3

misalida2.txt: pruebaMorfo entrada2.txt
	./pruebaMorfo entrada2.txt misalida2.txt

misalida3.txt: pruebaMorfo entrada3.txt
	./pruebaMorfo entrada3.txt misalida3.txt

misalida1.txt: pruebaMorfo entrada1.txt
	./pruebaMorfo entrada1.txt misalida1.txt

diff1: salida1.txt misalida1.txt
	diff -Bb salida1.txt misalida1.txt

diff2: salida2.txt misalida2.txt
	diff -Bb salida2.txt misalida2.txt

diff3: salida3.txt misalida3.txt
	diff -Bb salida3.txt misalida3.txt

lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) -c $^

lex.yy.c: alfa.l
	flex $^

clean:
	rm -rf *.o pruebaMorfo lex.yy.* misalida*.txt aux.txt
