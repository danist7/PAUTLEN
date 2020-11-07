#include <stdio.h>
#include "tokens.h"


extern FILE* yyin;
extern FILE* yyout;
extern char* yytext;
extern int yyleng;

int main(int argc, char const *argv[]) {
  int token;
  FILE* fout;

  if (argc != 3){
    printf("Se requiere fichero de entrada y de salida\n");
    printf("$prueba <fichero_entrada> <fichero_salida>\n");
    return 0;
  }

  if ((yyin = fopen(argv[1], "r")) == NULL) {
    printf("Error al abrir fichero de entrada\n");
    return 0;
  }

  if ((fout = fopen(argv[2], "w")) == NULL) {
    printf("Error al abrir fichero de salida\n");
    return 0;
  }

  /*if ((yyout = fopen("aux.txt", "wr")) == NULL) {
    printf("Error al abrir fichero auxiliar\n");
    return 0;
  }*/

  while((token = yylex()) != 0){

    switch (token) {
      case TOK_MAIN:
        fprintf(fout, "TOK_MAIN\t%d\t%.*s\n", TOK_MAIN , yyleng, yytext);
        break;
      case TOK_INT:
        fprintf(fout, "TOK_INT\t%d\t%.*s\n", TOK_INT , yyleng, yytext);
        break;
      case TOK_BOOLEAN:
        fprintf(fout, "TOK_BOOLEAN\t%d\t%.*s\n", TOK_BOOLEAN , yyleng, yytext);
        break;
      case TOK_ARRAY:
        fprintf(fout, "TOK_ARRAY\t%d\t%.*s\n", TOK_ARRAY , yyleng, yytext);
        break;
      case TOK_FUNCTION:
        fprintf(fout, "TOK_FUNCTION\t%d\t%.*s\n", TOK_FUNCTION , yyleng, yytext);
        break;
      case TOK_IF:
        fprintf(fout, "TOK_IF\t%d\t%.*s\n", TOK_IF , yyleng, yytext);
        break;
      case TOK_ELSE:
        fprintf(fout, "TOK_ELSE\t%d\t%.*s\n", TOK_ELSE , yyleng, yytext);
        break;
      case TOK_WHILE:
        fprintf(fout, "TOK_WHILE\t%d\t%.*s\n", TOK_WHILE , yyleng, yytext);
        break;
      case TOK_SCANF:
        fprintf(fout, "TOK_SCANF\t%d\t%.*s\n", TOK_SCANF , yyleng, yytext);
        break;
      case TOK_PRINTF:
        fprintf(fout, "TOK_PRINTF\t%d\t%.*s\n", TOK_PRINTF , yyleng, yytext);
        break;
      case TOK_RETURN:
        fprintf(fout, "TOK_RETURN\t%d\t%.*s\n", TOK_RETURN , yyleng, yytext);
        break;
      case TOK_PUNTOYCOMA:
        fprintf(fout, "TOK_PUNTOYCOMA\t%d\t%.*s\n", TOK_PUNTOYCOMA , yyleng, yytext);
        break;
      case TOK_COMA:
        fprintf(fout, "TOK_COMA\t%d\t%.*s\n", TOK_COMA , yyleng, yytext);
        break;
      case TOK_PARENTESISIZQUIERDO:
        fprintf(fout, "TOK_PARENTESISIZQUIERDO\t%d\t%.*s\n", TOK_PARENTESISIZQUIERDO , yyleng, yytext);
        break;
      case TOK_PARENTESISDERECHO:
        fprintf(fout, "TOK_PARENTESISDERECHO\t%d\t%.*s\n", TOK_PARENTESISDERECHO , yyleng, yytext);
        break;
      case TOK_CORCHETEIZQUIERDO:
        fprintf(fout, "TOK_CORCHETEIZQUIERDO\t%d\t%.*s\n", TOK_CORCHETEIZQUIERDO , yyleng, yytext);
        break;
      case TOK_CORCHETEDERECHO:
        fprintf(fout, "TOK_CORCHETEDERECHO\t%d\t%.*s\n", TOK_CORCHETEDERECHO , yyleng, yytext);
        break;
      case TOK_LLAVEIZQUIERDA:
        fprintf(fout, "TOK_LLAVEIZQUIERDA\t%d\t%.*s\n", TOK_LLAVEIZQUIERDA , yyleng, yytext);
        break;
      case TOK_LLAVEDERECHA:
        fprintf(fout, "TOK_LLAVEDERECHA\t%d\t%.*s\n", TOK_LLAVEDERECHA , yyleng, yytext);
        break;
      case TOK_ASIGNACION:
        fprintf(fout, "TOK_ASIGNACION\t%d\t%.*s\n", TOK_ASIGNACION , yyleng, yytext);
        break;
      case TOK_MAS:
        fprintf(fout, "TOK_MAS\t%d\t%.*s\n", TOK_MAS , yyleng, yytext);
        break;
      case TOK_MENOS:
        fprintf(fout, "TOK_MENOS\t%d\t%.*s\n", TOK_MENOS , yyleng, yytext);
        break;
      case TOK_DIVISION:
        fprintf(fout, "TOK_DIVISION\t%d\t%.*s\n", TOK_DIVISION , yyleng, yytext);
        break;
      case TOK_ASTERISCO:
        fprintf(fout, "TOK_ASTERISCO\t%d\t%.*s\n", TOK_ASTERISCO , yyleng, yytext);
        break;
      case TOK_AND:
        fprintf(fout, "TOK_AND\t%d\t%.*s\n", TOK_AND , yyleng, yytext);
        break;
      case TOK_OR:
        fprintf(fout, "TOK_OR\t%d\t%.*s\n", TOK_OR , yyleng, yytext);
        break;
      case TOK_NOT:
        fprintf(fout, "TOK_NOT\t%d\t%.*s\n", TOK_NOT , yyleng, yytext);
        break;
      case TOK_IGUAL:
        fprintf(fout, "TOK_IGUAL\t%d\t%.*s\n", TOK_IGUAL , yyleng, yytext);
        break;
      case TOK_DISTINTO:
        fprintf(fout, "TOK_DISTINTO\t%d\t%.*s\n", TOK_DISTINTO , yyleng, yytext);
        break;
      case TOK_MENORIGUAL:
        fprintf(fout, "TOK_MENORIGUAL\t%d\t%.*s\n", TOK_MENORIGUAL , yyleng, yytext);
        break;
      case TOK_MAYORIGUAL:
        fprintf(fout, "TOK_MAYORIGUAL\t%d\t%.*s\n", TOK_MAYORIGUAL , yyleng, yytext);
        break;
      case TOK_MENOR:
        fprintf(fout, "TOK_MENOR\t%d\t%.*s\n", TOK_MENOR , yyleng, yytext);
        break;
      case TOK_MAYOR:
        fprintf(fout, "TOK_MAYOR\t%d\t%.*s\n", TOK_MAYOR , yyleng, yytext);
        break;
      case TOK_IDENTIFICADOR:
        fprintf(fout, "TOK_IDENTIFICADOR\t%d\t%.*s\n", TOK_IDENTIFICADOR , yyleng, yytext);
        break;
      case TOK_CONSTANTE_ENTERA:
        fprintf(fout, "TOK_CONSTANTE_ENTERA\t%d\t%.*s\n", TOK_CONSTANTE_ENTERA , yyleng, yytext);
        break;
      case TOK_TRUE:
        fprintf(fout, "TOK_TRUE\t%d\t%.*s\n", TOK_TRUE , yyleng, yytext);
        break;
      case TOK_FALSE:
        fprintf(fout, "TOK_FALSE\t%d\t%.*s\n", TOK_FALSE , yyleng, yytext);
        break;
      case TOK_ERROR:
        //fprintf(fout, "TOK_ERROR\t%d\t%.*s\n", TOK_ERROR , yyleng, yytext);
        // Lo he puesto asi para que coincida la salida 2
        return;
      default:
        fprintf(fout, "ERROR");
        break;
    }
  }

  fclose(yyin);
  fclose(fout);
  fclose(yyout);
}
