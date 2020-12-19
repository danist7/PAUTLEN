%{
#include "alfa.h"
#include "alfa.tab.h"


size_t ncols = 1;
size_t nlines = 1;
int err_morf;

extern YYSTYPE yylval;
%}

%option noyywrap
%option nodefault

%%

"//".* {ncols += yyleng;}
" "+ {ncols += yyleng;}
"\t"+ {ncols += yyleng;}
"\n" {ncols = 1; nlines ++;}



main     {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
            return TOK_MAIN;}
int      {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
            return TOK_INT;}
boolean  {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
            return TOK_BOOLEAN;}
array    {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
            return TOK_ARRAY;}
function {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
            return TOK_FUNCTION;}
if       {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
            return TOK_IF;}
else     {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
            return TOK_ELSE;}
while    {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
            return TOK_WHILE;}
scanf    {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
            return TOK_SCANF;}
printf   {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
            return TOK_PRINTF;}
return   {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
            return TOK_RETURN;}

";"   {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_PUNTOYCOMA;}
","   {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_COMA;}
"("   {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_PARENTESISIZQUIERDO;}
")"   {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_PARENTESISDERECHO;}
"["   {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_CORCHETEIZQUIERDO;}
"]"   {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_CORCHETEDERECHO;}
"{"   {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_LLAVEIZQUIERDA;}
"}"   {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_LLAVEDERECHA;}
"="   {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_ASIGNACION;}
"+"   {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_MAS;}
"-"   {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_MENOS;}
"/"   {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_DIVISION;}
"*"   {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_ASTERISCO;}
"&&"  {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_AND;}
"||"  {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_OR;}
"!"   {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_NOT;}
"=="  {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_IGUAL;}
"!="  {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_DISTINTO;}
"<="  {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_MENORIGUAL;}
">="  {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_MAYORIGUAL;}
"<"   {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_MENOR;}
">"   {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_MAYOR;}

true  {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_TRUE;}
false {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_FALSE;}

[a-zA-Z]([a-zA-Z0-9]){0,99} {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
                               strcpy(yylval.atributos.lexema, yytext);
                               return TOK_IDENTIFICADOR;}
[0-9]+                      {  ncols += yyleng; fprintf(yyout, ";D:\t%s\n", yytext);
                                yylval.atributos.valor_entero = atoi(yytext);
                               return TOK_CONSTANTE_ENTERA;}

[a-zA-Z]([a-zA-Z0-9]){100,} {printf("****Error morfologico en [lin %lu col %lu]. Cadena demasiado larga\n",nlines, ncols); err_morf = 1; return TOK_ERROR;}
 . { printf("****Error morfologico en [lin %lu col %lu]: simbolo no permitido (%s)\n",nlines, ncols,yytext); err_morf = 1; return TOK_ERROR;}
%%
