
%{
#include <stdio.h>
extern FILE* yyout
%}

%union {
   char* cadena;
   int numero;
}

%token TOK_MAIN
%token TOK_INT
%token TOK_BOOLEAN
%token TOK_ARRAY
%token TOK_FUNCTION
%token TOK_IF
%token TOK_ELSE
%token TOK_WHILE
%token TOK_SCANF
%token TOK_PRINTF
%token TOK_RETURN

%token TOK_PUNTOYCOMA
%token TOK_COMA
%token TOK_PARENTESISIZQUIERDO
%token TOK_PARENTESISDERECHO
%token TOK_CORCHETEIZQUIERDO
%token TOK_CORCHETEDERECHO
%token TOK_LLAVEIZQUIERDA
%token TOK_LLAVEDERECHA
%token TOK_ASIGNACION
%token TOK_MAS
%token TOK_MENOS
%token TOK_DIVISION
%token TOK_ASTERISCO
%token TOK_AND
%token TOK_OR
%token TOK_NOT
%token TOK_IGUAL
%token TOK_DISTINTO
%token TOK_MENORIGUAL
%token TOK_MAYORIGUAL
%token TOK_MENOR
%token TOK_MAYOR

%token <cadena> TOK_IDENTIFICADOR

%token <entero> TOK_CONSTANTE_ENTERA
%token TOK_TRUE
%token TOK_FALSE

%token TOK_ERROR

%left TOK_IGUAL TOK_MENORIGUAL  TOK_MENOR TOK_MAYORIGUAL TOK_MAYOR TOK_DISTINTO
%left TOK_AND TOK_OR
%left TOK_MAS TOK_MENOS
%left TOK_ASTERISCO TOK_DIVISION
%right TOK_NOT
%%

programa                  :   TOK_MAIN TOK_LLAVEIZQUIERDA declaraciones funciones sentencias TOK_LLAVEDERECHA
                              {fprintf(yyout,";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }")}
                          ;
declaraciones             :   declaracion
                          |   declaracion declaraciones
                          ;
declaracion               :   clase identificadores TOK_PUNTOYCOMA
                          ;
clase                     :   clase_escalar
                          |   clase_vector
                          ;
clase_escalar             :   tipo
                          ;
tipo                      :   TOK_INT
                          |   TOK_BOOLEAN
                          ;
clase_vector              :   TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO constante_entera TOK_CORCHETEDERECHO
                          ;
identificadores           :   identificador
                          |   identificador TOK_COMA identificadores
                          ;
funciones                 :   funcion funciones
                          |   %empty
                          ;
funcion                   :   TOK_FUNCTION tipo identificador TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion sentencias TOK_LLAVEDERECHA
                          ;
parametros_funcion        :   parametro_funcion resto_parametros_funcion
                          |   %empty
                          ;
resto_parametros_funcion  :   TOK_PUNTOYCOMA parametro_funcion resto_parametros_funcion
                          |   %empty
                          ;
parametro_funcion         :   tipo identificador
                          ;
declaraciones_funcion     :   declaraciones
                          |   %empty
                          ;
sentencias                :   sentencia
                          |   sentencia sentencias
                          ;
sentencia                 :   sentencia_simple
                          |   bloque
                          ;
sentencia_simple          :   asignacion
                          |   lectura
                          |   escritura
                          |   retorno_funcion
                          ;
bloque                    :   condicional
                          |   bucle
                          ;
asignacion                :   identificador TOK_ASIGNACION exp
                          |   elemento_vector TOK_ASIGNACION exp
                          ;
elemento_vector           :   identificador TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO
                          ;
condicional               :   TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA
                          |   TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA
                          ;
bucle                     :   TOK_WHILE TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA
                          ;
lectura                   :   TOK_SCANF identificador
                          ;
escritura                 :   TOK_PRINTF exp
                          ;
retorno_funcion           :   TOK_RETURN exp
                          ;
exp                       :   exp TOK_MAS exp
                          |   exp TOK_MENOS exp
                          |   exp TOK_DIVISION exp
                          |   exp TOK_ASTERISCO exp
                          |   TOK_MENOS exp
                          |   exp TOK_AND exp
                          |   exp TOK_OR exp
                          |   TOK_NOT exp
                          |   identificador
                          |   constante
                          |   TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO
                          |   TOK_PARENTESISIZQUIERDO comparacion TOK_PARENTESISDERECHO
                          |   elemento_vector
                          |   identificador TOK_PARENTESISIZQUIERDO lista_expresiones TOK_PARENTESISDERECHO
                          ;
lista_expresiones         :   exp resto_lista_expresiones
                          |   %empty
                          ;
resto_lista_expresiones   :   TOK_COMA exp resto_lista_expresiones
                          |   %empty
                          ;
comparacion               :   exp TOK_IGUAL exp
                          |   exp TOK_DISTINTO exp
                          |   exp TOK_MENORIGUAL exp
                          |   exp TOK_MAYORIGUAL exp
                          |   exp TOK_MENOR exp
                          |   exp TOK_MAYOR exp
                          ;
constante                 :   constante_logica
                          |   constante_entera
                          ;
constante_logica          :   TOK_TRUE
                          |   TOK_FALSE
                          ;
constante_entera          :   TOK_CONSTANTE_ENTERA
                          ;
identificador             :   TOK_IDENTIFICADOR
%%

int main() {
    return yyparse();
}
