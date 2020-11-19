%{
#include "y.tab.h"
%}

%option noyywrap
%option nodefault

%%

[ \t\n] {}
"//".*\n {}

main     {  fprintf(yyout, ";D:\t%s\n", yytext);
            return TOK_MAIN;}
int      {  fprintf(yyout, ";D:\t%s\n", yytext);
            return TOK_INT;}
boolean  {  fprintf(yyout, ";D:\t%s\n", yytext);
            return TOK_BOOLEAN;}
array    {  fprintf(yyout, ";D:\t%s\n", yytext);
            return TOK_ARRAY;}
function {  fprintf(yyout, ";D:\t%s\n", yytext);
            return TOK_FUNCTION;}
if       {  fprintf(yyout, ";D:\t%s\n", yytext);
            return TOK_IF;}
else     {  fprintf(yyout, ";D:\t%s\n", yytext);
            return TOK_ELSE;}
while    {  fprintf(yyout, ";D:\t%s\n", yytext);
            return TOK_WHILE;}
scanf    {  fprintf(yyout, ";D:\t%s\n", yytext);
            return TOK_SCANF;}
printf   {  fprintf(yyout, ";D:\t%s\n", yytext);
            return TOK_PRINTF;}
return   {  fprintf(yyout, ";D:\t%s\n", yytext);
            return TOK_RETURN;}

";"   {  fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_PUNTOYCOMA;}
","   {  fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_COMA;}
"("   {  fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_PARENTESISIZQUIERDO;}
")"   {  fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_PARENTESISDERECHO;}
"["   {  fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_CORCHETEIZQUIERDO;}
"]"   {  fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_CORCHETEDERECHO;}
"{"   {  fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_LLAVEIZQUIERDA;}
"}"   {  fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_LLAVEDERECHA;}
"="   {  fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_ASIGNACION;}
"+"   {  fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_MAS;}
"-"   {  fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_MENOS;}
"/"   {  fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_DIVISION;}
"*"   {  fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_ASTERISCO;}
"&&"  {  fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_AND;}
"||"  {  fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_OR;}
"!"   {  fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_NOT;}
"=="  {  fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_IGUAL;}
"!="  {  fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_DISTINTO;}
"<="  {  fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_MENORIGUAL;}
">="  {  fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_MAYORIGUAL;}
"<"   {  fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_MENOR;}
">"   {  fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_MAYOR;}

true  {  fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_TRUE;}
false {  fprintf(yyout, ";D:\t%s\n", yytext);
         return TOK_FALSE;}

[a-zA-Z]([a-zA-Z0-9]){0,99} {  fprintf(yyout, ";D:\t%s\n", yytext);
                               return TOK_IDENTIFICADOR;}
[0-9]+                      {  fprintf(yyout, ";D:\t%s\n", yytext);
                               return TOK_CONSTANTE_ENTERA;}

[a-zA-Z]([a-zA-Z0-9]){100,} {return TOK_ERROR;}
 . {return TOK_ERROR;}
%%
