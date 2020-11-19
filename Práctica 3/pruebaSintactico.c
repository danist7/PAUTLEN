#include <stdio.h>
#include <stdlib.h>


extern FILE* yyin;
extern FILE* yyout;

void main(int argc, char const *argv[]) {
  int token;
  FILE* fout;

  if (argc != 3){
    printf("Se requiere fichero de entrada y de salida\n");
    printf("./pruebaSintactico <fichero_entrada> <fichero_salida>\n");
    return 1;
  }

  if ((yyin = fopen(argv[1], "r")) == NULL) {
    printf("Error al abrir fichero de entrada\n");
    return 1;
  }

  if ((yyout = fopen(argv[2], "w")) == NULL) {
    printf("Error al abrir fichero de salida\n");
    return 1;
  }

  yyparse();

  fclose(yyin);
  fclose(yyout);
}
