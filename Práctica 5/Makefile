CC = gcc
CFLAGS = -g -Wall
LIBS = tokens.h lex.yy.c alfa.tab.c tablasimbolos.c generacion.c
EJS = alfa

all: $(EJS)

alfa:
	flex alfa.l
	bison -d alfa.y
	$(CC) $(CFLAGS) alfa.c $(LIBS) -o alfa

clean:
	rm -rf lex.yy.c $(EJS)
