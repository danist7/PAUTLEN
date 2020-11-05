#include <stdio.h>

extern FILE* yyin;
extern FILE* yyout;
extern char* yytext;
extern int yytext;

int int main(int argc, char const *argv[]) {
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

  if ((yyin = fopen("aux.txt", "r")) == NULL) {
    printf("Error al abrir fichero auxiliar\n");
    return 0;
  }

  while((token = yylex()) != ){

    switch (token) {
      case TOK_MAIN:
        fprintf(fout, "TOK_MAIN\t½d\t%.*s\n", TOK_MAIN , yylen, yytext);
        break;
      case TOK_INT:
        fprintf(fout, "TOK_INT\t½d\t%.*s\n", TOK_INT , yylen, yytext);
        break;
      case TOK_BOOLEAN:
        fprintf(fout, "TOK_BOOLEAN\t½d\t%.*s\n", TOK_BOOLEAN , yylen, yytext);
        break;
      case TOK_ARRAY:
        fprintf(fout, "TOK_ARRAY\t½d\t%.*s\n", TOK_ARRAY , yylen, yytext);
        break;
      case TOK_FUNCTION:
        fprintf(fout, "TOK_FUNCTION\t½d\t%.*s\n", TOK_FUNCTION , yylen, yytext);
        break;
      case TOK_IF:
        fprintf(fout, "TOK_IF\t½d\t%.*s\n", TOK_IF , yylen, yytext);
        break;
      case TOK_ELSE:
        fprintf(fout, "TOK_ELSE\t½d\t%.*s\n", TOK_ELSE , yylen, yytext);
        break;
      case TOK_WHILE:
        fprintf(fout, "TOK_WHILE\t½d\t%.*s\n", TOK_WHILE , yylen, yytext);
        break;
      case TOK_SCANF:
        fprintf(fout, "TOK_SCANF\t½d\t%.*s\n", TOK_SCANF , yylen, yytext);
        break;
      case TOK_PRINTF:
        fprintf(fout, "TOK_PRINTF\t½d\t%.*s\n", TOK_PRINTF , yylen, yytext);
        break;
      case TOK_RETURN:
        fprintf(fout, "TOK_RETURN\t½d\t%.*s\n", TOK_RETURN , yylen, yytext);
        break;
      case TOK_PUNTOYCOMA:
        fprintf(fout, "TOK_PUNTOYCOMA\t½d\t%.*s\n", TOK_PUNTOYCOMA , yylen, yytext);
        break;
      case TOK_COMA:
        fprintf(fout, "TOK_COMA\t½d\t%.*s\n", TOK_COMA , yylen, yytext);
        break;
      case TOK_PARENTESISIZQUIERDO:
        fprintf(fout, "TOK_PARENTESISIZQUIERDO\t½d\t%.*s\n", TOK_PARENTESISIZQUIERDO , yylen, yytext);
        break;
      case TOK_PARENTESISDERECHO:
        fprintf(fout, "TOK_PARENTESISDERECHO\t½d\t%.*s\n", TOK_PARENTESISDERECHO , yylen, yytext);
        break;
      case TOK_CORCHETEIZQUIERDO:
        fprintf(fout, "TOK_CORCHETEIZQUIERDO\t½d\t%.*s\n", TOK_CORCHETEIZQUIERDO , yylen, yytext);
        break;
      case TOK_CORCHETEDERECHO:
        fprintf(fout, "TOK_CORCHETEDERECHO\t½d\t%.*s\n", TOK_CORCHETEDERECHO , yylen, yytext);
        break;
      case TOK_LLAVEIZQUIERDA:
        fprintf(fout, "TOK_LLAVEIZQUIERDA\t½d\t%.*s\n", TOK_LLAVEIZQUIERDA , yylen, yytext);
        break;
      case TOK_LLAVEDERECHA:
        fprintf(fout, "TOK_LLAVEDERECHA\t½d\t%.*s\n", TOK_LLAVEDERECHA , yylen, yytext);
        break;
      case TOK_ASIGNACION:
        fprintf(fout, "TOK_ASIGNACION\t½d\t%.*s\n", TOK_ASIGNACION , yylen, yytext);
        break;
      case TOK_MAS:
        fprintf(fout, "TOK_MAS\t½d\t%.*s\n", TOK_MAS , yylen, yytext);
        break;
      case TOK_MENOS:
        fprintf(fout, "TOK_MENOS\t½d\t%.*s\n", TOK_MENOS , yylen, yytext);
        break;
      case TOK_DIVISION:
        fprintf(fout, "TOK_DIVISION\t½d\t%.*s\n", TOK_DIVISION , yylen, yytext);
        break;
      case TOK_ASTERISCO:
        fprintf(fout, "TOK_ASTERISCO\t½d\t%.*s\n", TOK_ASTERISCO , yylen, yytext);
        break;
      case TOK_AND:
        fprintf(fout, "TOK_AND\t½d\t%.*s\n", TOK_AND , yylen, yytext);
        break;
      case TOK_OR:
        fprintf(fout, "TOK_OR\t½d\t%.*s\n", TOK_OR , yylen, yytext);
        break;
      case TOK_NOT:
        fprintf(fout, "TOK_NOT\t½d\t%.*s\n", TOK_NOT , yylen, yytext);
        break;
      case TOK_IGUAL:
        fprintf(fout, "TOK_IGUAL\t½d\t%.*s\n", TOK_IGUAL , yylen, yytext);
        break;
      case TOK_DISTINTO:
        fprintf(fout, "TOK_DISTINTO\t½d\t%.*s\n", TOK_DISTINTO , yylen, yytext);
        break;
      case TOK_MENORIGUAL:
        fprintf(fout, "TOK_MENORIGUAL\t½d\t%.*s\n", TOK_MENORIGUAL , yylen, yytext);
        break;
      case TOK_MAYORIGUAL:
        fprintf(fout, "TOK_MAYORIGUAL\t½d\t%.*s\n", TOK_MAYORIGUAL , yylen, yytext);
        break;
      case TOK_MENOR:
        fprintf(fout, "TOK_MENOR\t½d\t%.*s\n", TOK_MENOR , yylen, yytext);
        break;
      case TOK_MAYOR:
        fprintf(fout, "TOK_MAYOR\t½d\t%.*s\n", TOK_MAYOR , yylen, yytext);
        break;
      case TOK_IDENTIFICADOR:
        fprintf(fout, "TOK_IDENTIFICADOR\t½d\t%.*s\n", TOK_IDENTIFICADOR , yylen, yytext);
        break;
      case TOK_CONSTANTE_ENTERA:
        fprintf(fout, "TOK_CONSTANTE_ENTERA\t½d\t%.*s\n", TOK_CONSTANTE_ENTERA , yylen, yytext);
        break;
      case TOK_TRUE:
        fprintf(fout, "TOK_TRUE\t½d\t%.*s\n", TOK_TRUE , yylen, yytext);
        break;
      case TOK_FALSE:
        fprintf(fout, "TOK_FALSE\t½d\t%.*s\n", TOK_FALSE , yylen, yytext);
        break;
      case TOK_ERROR:
        fprintf(fout, "TOK_ERROR\t½d\t%.*s\n", TOK_ERROR , yylen, yytext);
        break;
      default:
        fprintf(fout, "ERROR");
        break;
    }
  }

  fclose(yyin);
  fclose(fout);
  fclose(yyout);
}
