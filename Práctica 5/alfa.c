
#include <stdio.h>
#include "alfa.h"
#include "tabla_simbolos.h"
#include "generacion.h"


extern FILE* yyin;
extern FILE* yyout;
extern int yyparse();

int main(int argc, char const *argv[]) {


  if (argc != 3){
    printf("Se requiere fichero de entrada y de salida\n");
    printf("./alfa <fichero_entrada> <fichero_salida>\n");
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

  return 0;
}
