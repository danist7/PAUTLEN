%{
#include <stdio.h>
%}
%option noyywrap
%%
TOK_MAIN {return 100;}
TOK_INT {return 101;}
TOK_BOOLEAN {return 102;}
TOK_ARRAY {return 103;}
TOK_FUNCTION {return 104;}
TOK_IF {return 105;}
TOK_ELSE {return 106;}
TOK_WHILE {return 107;}
TOK_SCANF {return 108;}
TOK_PRINTF {return 109;}
TOK_RETURN {return 110;}
TOK_PUNTOYCOMA {return 200;}
TOK_COMA {return 201;}
TOK_PARENTESISIZQUIERDO {return 202;}
TOK_PARENTESISDERECHO {return 203;}
TOK_CORCHETEIZQUIERDO {return 204;}
TOK_CORCHETEDERECHO {return 205;}
TOK_LLAVEIZQUIERDA {return 206;}
TOK_LLAVEDERECHA {return 207;}
TOK_ASIGNACION {return 208;}
TOK_MAS {return 209;}
TOK_MENOS {return 210;}
TOK_DIVISION {return 211;}
TOK_ASTERISCO {return 212;}
TOK_AND {return 213;}
TOK_OR {return 214;}
TOK_NOT {return 215;}
TOK_IGUAL {return 216;}
TOK_DISTINTO {return 217;}
TOK_MENORIGUAL {return 218;}
TOK_MAYORIGUAL {return 219;}
TOK_MENOR {return 220;}
TOK_MAYOR {return 221;}
TOK_IDENTIFICADOR {return 300;}
TOK_CONSTANTE_ENTERA {return 400;}
TOK_TRUE {return 401;}
TOK_FALSE {return 402;}
TOK_ERROR {return -1;}
%%
int main()
{
return yylex();
}
