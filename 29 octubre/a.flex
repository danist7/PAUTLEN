%{
#include <stdio.h>
%}
%option noyywrap
%%
principal { return 1;}
main { return 1;}
function { return 2;}
[a-zA-Z][a-zA-Z0-9]* {return 3;}
. ; // { printf("Error bad character");}
%%
main() {
  int a;
  for(;a=yylex();) {
  if(a==1)
    printf("TOK_MAIN %s\n", yytext);
  if(a==2)
    printf("TOK_FUNCTION %s\n", yytext);
  if(a==3)
    printf("TOK_ID %s\n", yytext);
  }
}
