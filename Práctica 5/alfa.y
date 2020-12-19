
%{
#include <stdio.h>
#include <string.h>
#include "alfa.h"
#include "generacion.h"
#include "tabla_simbolos.h"

extern FILE* yyout;
extern int yylex();
extern size_t nlines;
void yyerror(const char *s);
tablas_smb *tabla;

int num_total_parametros = 0;   /* Numero de parametros para DECLARAR una funcion */
int num_total_varlocs = 0;      /* Numero de variables locales, por ej, dentro de una funcion */
int tamanio = 1;                /* Para controlar el tamaño del identificador */
int tipo;                       /* Para darle un tipo entero o booleano a un identificador */
int funcion_retorno = 0;        /* Comprueba que hay un return en la funcion */
int funcion_tipo;               /* Tipo de una funcion (entero o booleano) */
int etiqueta = 0;

int dentro_llamada_fun = 0;         /* Esta a 1 si estamos si estamos dentro de los parentesis de una funcion y a 0 si estamos fuera */
int categoria_estructura;       /* Es ESCALAR o VECTOR */
int posicion_parametro = 0;     /* Solo para elementos de tipo parametro, posicion en orden, empieza por 0 */
int posicion = 0;               /* Solo para variables locales, su posición */
int num_arg_funcion = 0;        /* Numero de parametros al LLAMAR a una funcion */
%}

%union {
  tipo_atributos atributos;
}

%token <atributos> TOK_IDENTIFICADOR
%token <atributos> TOK_CONSTANTE_ENTERA

%token TOK_MAIN
%token TOK_INT
%token TOK_BOOLEAN
%token <atributos> TOK_ARRAY
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

%token TOK_TRUE
%token TOK_FALSE

%token TOK_ERROR

%type <atributos> constante
%type <atributos> constante_logica
%type <atributos> constante_entera
%type <atributos> identificador
%type <atributos> comparacion
%type <atributos> exp
%type <atributos> idf_llamada_funcion
%type <atributos> condicional
%type <atributos> if_exp
%type <atributos> if_else_exp
%type <atributos> bucle
%type <atributos> while_exp
%type <atributos> while
%type <atributos> elemento_vector
%type <atributos> funcion
%type <atributos> fn_declaration
%type <atributos> fn_name



%left TOK_IGUAL TOK_MENORIGUAL  TOK_MENOR TOK_MAYORIGUAL TOK_MAYOR TOK_DISTINTO
%left TOK_MAS TOK_MENOS TOK_OR
%left TOK_ASTERISCO TOK_DIVISION TOK_AND
%right TOK_NOT
%%

programa                  :   TOK_MAIN inicio TOK_LLAVEIZQUIERDA declaraciones escribir_TS funciones escribir_MAIN sentencias TOK_LLAVEDERECHA
                              {fprintf(yyout,";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");
                               escribir_fin(yyout);
                               LiberarTablas(tabla);}
                          ;
inicio                    :   %empty
                              {  tabla = CrearTablas();
                                if(tabla == NULL){
                                  printf("No existe la tabla de símbolos\n");
                                  return -1;
                                }
                                escribir_subseccion_data(yyout);
                                escribir_cabecera_bss(yyout);
                              }
                          ;
escribir_TS               :   %empty
                              {
                               escribir_segmento_codigo(yyout);
                              }
                          ;
escribir_MAIN             :   %empty
                              {
                               escribir_inicio_main(yyout);
                              }
                          ;
declaraciones             :   declaracion
                              {fprintf(yyout,";R2:\t<declaraciones> ::= <declaracion>\n");}
                          |   declaracion declaraciones
                              {fprintf(yyout,";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");}
                          ;
declaracion               :   clase identificadores TOK_PUNTOYCOMA
                              {fprintf(yyout,";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");}
                          ;
clase                     :   clase_escalar
                              {fprintf(yyout,";R5:\t<clase> ::= <clase_escalar>\n");
                               categoria_estructura = ESCALAR;}
                          |   clase_vector
                              {fprintf(yyout,";R7:\t<clase> ::= <clase_vector>\n");
                               categoria_estructura = VECTOR;}
                          ;
clase_escalar             :   tipo
                              {fprintf(yyout,";R9:\t<clase_escalar> ::= <tipo>\n");
                               tamanio = 1;}
                          ;
tipo                      :   TOK_INT
                              {fprintf(yyout,";R10:\t<tipo> ::= int\n");
                               tipo = ENTERO;}
                          |   TOK_BOOLEAN
                              {fprintf(yyout,";R11:\t<tipo> ::= boolean\n");
                               tipo = BOOLEANO;}
                          ;
clase_vector              :   TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO TOK_CONSTANTE_ENTERA TOK_CORCHETEDERECHO
                              {fprintf(yyout,";R15:\t<clase_vector> ::= array <tipo> [ <constante_entera> ]\n");
                              if($4.valor_entero <= 0 || $4.valor_entero > MAX_TAMANIO_VECTOR){
                                printf("****Error semantico en lin %lu: El tamanyo del vector excede los limites permitidos (1,64).\n", nlines); //TODO en el enunciado nos piden aqui dar el nombre del vector pero no se puede
                                LiberarTablas(tabla);
                                return -1;
                              }
                              if (Ambito(tabla) == LOCAL) {
                                printf("****Error semantico en lin %lu: Declaracion de vector en ambito local.\n", nlines, $1.lexema); //DUDA: He puesto esto para el error 15 pero no estoy seguro
                                LiberarTablas(tabla);
                                return -1;
                              }
                              }
                          ;
identificadores           :   identificador
                              {fprintf(yyout,";R18:\t<identificadores> ::= <identificador>\n");}
                          |   identificador TOK_COMA identificadores
                              {fprintf(yyout,";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");}
                          ;
funciones                 :   funcion funciones
                              {fprintf(yyout,";R20:\t<funciones> ::= <funcion> <funciones>\n");}
                          |   %empty
                              {fprintf(yyout,";R21:\t<funciones> ::= \n");}
                          ;
funcion                   :   fn_declaration sentencias TOK_LLAVEDERECHA
                              {
                              fprintf(yyout,";R22:\t<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }\n");
                              if (funcion_retorno < 1){
                                printf("****Error semantico en lin %lu : Funcion %s sin sentencia de retorno\n", nlines, $1.lexema);
                                LiberarTablas(tabla);
                                return -1;
                              }
                              CierreAmbito(tabla);
                              // Tras cerrar el simbolo guardamos la informacion pertinente en el simbolo de la tabla global
                              simbolo *simbolo;
                              simbolo = BusquedaElemento(tabla, $1.lexema);
                              if (simbolo == NULL){
                                printf("****Error en la tabla de simbolos\n");
                                LiberarTablas(tabla);
                                return -1;
                              }
                              simbolo->n_parametros = num_total_parametros;
                              num_total_parametros = 0;
                              num_total_varlocs = 0;
                              posicion_parametro = 0;
                              }
                          ;
fn_declaration            :   fn_name TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion
                              {
                               simbolo *simbolo;
                               simbolo = BusquedaElemento(tabla, $1.lexema);
                               if (simbolo == NULL){
                                 printf("****Error en la tabla de simbolos\n");
                                 LiberarTablas(tabla);
                                 return -1;
                               }
                               simbolo->n_parametros = num_total_parametros;
                               simbolo->n_varloc = num_total_varlocs;
                               strcpy($$.lexema, $1.lexema);
                               declararFuncion(yyout, $1.lexema, num_total_varlocs);
                              }
                          ;
fn_name                   :   TOK_FUNCTION tipo TOK_IDENTIFICADOR
                              {
                                /* La funcion no existia y la metemos en tabla simbolos */
                                if (BusquedaElemento(tabla, $3.lexema) == NULL){
                                  strcpy($$.lexema, $3.lexema);
                                  /* Abrimos ambito local de tipo funcion en la tabla */
                                  AperturaAmbito(tabla, $3.lexema, 0, 0);
                                  /* Reseteamos los valores */
                                  tamanio = 1;
                                  num_total_varlocs = 0;
                                  posicion_parametro = 0;
                                  num_total_parametros = 0;
                                  funcion_retorno = 0;
                                  funcion_tipo = tipo;
                                }
                                /* La funcion ya existe */
                                else{
                                  printf("****Error semantico en lin %lu: Declaracion duplicada\n", nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                              }
                          ;
parametros_funcion        :   parametro_funcion resto_parametros_funcion
                              {fprintf(yyout,";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");}
                          |   %empty
                              {fprintf(yyout,";R24:\t<parametros_funcion> ::= \n");}
                          ;
resto_parametros_funcion  :   TOK_PUNTOYCOMA parametro_funcion resto_parametros_funcion
                              {fprintf(yyout,";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");}
                          |   %empty
                              {fprintf(yyout,";R26:\t<resto_parametros_funcion> ::= \n");}
                          ;
parametro_funcion         :   tipo idpf
                              {fprintf(yyout,";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
                               num_total_parametros++;
                               posicion_parametro++;
                              }
                          ;
idpf                      :   TOK_IDENTIFICADOR
                              {
                               if(BusquedaEnAmbitoActual(tabla, $1.lexema) == NULL){
                                if(InsercionElemento(tabla, $1.lexema, PARAMETRO, tipo, ESCALAR, 1, 0, posicion_parametro, 0, 0) == FATAL_ERROR){
                                  printf("****Error en la tabla de simbolos\n");
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                               }else{
                                 printf("****Error semantico en lin %lu: Declaracion duplicada.\n", nlines);
                                 LiberarTablas(tabla);
                                 return -1;
                               }
                              }
declaraciones_funcion     :   declaraciones
                              {fprintf(yyout,";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");}
                          |   %empty
                              {fprintf(yyout,";R29:\t<declaraciones_funcion> ::= \n");}
                          ;
sentencias                :   sentencia
                              {fprintf(yyout,";R30:\t<sentencias> ::= <sentencia>\n");}
                          |   sentencia sentencias
                              {fprintf(yyout,";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");}
                          ;
sentencia                 :   sentencia_simple TOK_PUNTOYCOMA
                              {fprintf(yyout,";R32:\t<sentencia> ::= <sentencia_simple> ;\n");}
                          |   bloque
                              {fprintf(yyout,";R33:\t<sentencia> ::= <bloque>\n");}
                          ;
sentencia_simple          :   asignacion
                              {fprintf(yyout,";R34:\t<sentencia_simple> ::= <asignacion>\n");}
                          |   lectura
                              {fprintf(yyout,";R35:\t<sentencia_simple> ::= <lectura>\n");}
                          |   escritura
                              {fprintf(yyout,";R36:\t<sentencia_simple> ::= <escritura>\n");}
                          |   retorno_funcion
                              {fprintf(yyout,";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");}
                          ;
bloque                    :   condicional
                              {fprintf(yyout,";R40:\t<bloque> ::= <condicional>\n");}
                          |   bucle
                              {fprintf(yyout,";R41:\t<bloque> ::= <bucle>\n");}
                          ;
asignacion                :   TOK_IDENTIFICADOR TOK_ASIGNACION exp
                              {
                                fprintf(yyout,";R43:\t<asignacion> ::= <identificador> = <exp>\n");
                                simbolo *simbolo;
                                if((simbolo = BusquedaElemento(tabla, $1.lexema)) == NULL){
                                  printf("****Error semantico en lin %lu: Acceso a variable no declarada (%s)\n", nlines, $1.lexema);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                if (simbolo->categoria_estructura == VECTOR) {
                                  printf("****Error semantico en lin %lu: Asignacion incompatible. \n", nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                if (simbolo->categoria == FUNCION) {
                                  printf("****Error semantico en lin %lu: Asignacion incompatible. \n", nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }

                                if (simbolo->tipo != $3.tipo) {
                                  printf("****Error semantico en lin %lu: Asignacion incompatible. \n", nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                if(Ambito(tabla) == GLOBAL){
                                  asignar(yyout, $1.lexema, $3.es_direccion);
                                }else{
                                  escribirVariableLocal(yyout,simbolo->posicion);
                                  asignarDestinoEnPila(yyout,$3.es_direccion);
                                }
                              }
                          |   elemento_vector TOK_ASIGNACION exp
                              {fprintf(yyout,";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");}
                          ;
elemento_vector           :   TOK_IDENTIFICADOR TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO
                              {fprintf(yyout,";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");
                              simbolo *simbolo;
                              if ((simbolo = BusquedaElemento(tabla, $1.lexema)) == NULL){
                                printf("****Error semantico en lin %lu: Acceso a variable no declarada (%s).\n", nlines, $1.lexema);
                                LiberarTablas(tabla);
                                return -1;
                              }
                              if (Ambito(tabla) == LOCAL) {
                                printf("****Error semantico en lin %lu: Acceso vector en ambito local.\n", nlines, $1.lexema); //DUDA: Error extra
                                LiberarTablas(tabla);
                                return -1;
                              }
                              if (simbolo->categoria_estructura != VECTOR) {
                                printf("****Error semantico en lin %lu: Intento de indexacion de una variable que no es de tipo vector.\n", nlines);
                                LiberarTablas(tabla);
                                return -1;
                              }
                              if ($3.tipo != ENTERO) {
                                printf("****Error semantico en lin %lu: El indice en una operacion de indexacion tiene que ser de tipo entero.\n", nlines);
                                LiberarTablas(tabla);
                                return -1;
                              }
                              $$.tipo = simbolo->tipo;
                              $$.es_direccion = 1;
                              $$.valor_entero = $3.valor_entero;
                              escribir_elemento_vector(yyout, simbolo->identificador, tamanio, $3.es_direccion);
                              }
                          ;
condicional               :   if_exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA
                              {fprintf(yyout,";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
                              ifthen_fin(yyout, $1.etiqueta);
                              }
                          |   if_else_exp TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA
                              {fprintf(yyout,";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
                              ifthenelse_fin(yyout, $1.etiqueta);
                              }
                          ;
if_exp                    :   TOK_IF TOK_PARENTESISIZQUIERDO exp
                              {
                              if ($3.tipo != BOOLEANO) {
                                printf("****Error semantico en lin %lu: Condicional con condicion de tipo int.\n", nlines);
                                LiberarTablas(tabla);
                                return -1;
                              }
                              $$.etiqueta = etiqueta++;
                              ifthen_inicio(yyout, $3.es_direccion, $$.etiqueta);
                              }
                          ;
if_else_exp               :   if_exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA
                              {
                              $$.etiqueta = $1.etiqueta;
                              ifthenelse_fin_then(yyout, $$.etiqueta);
                              }
                          ;
bucle                     :   while_exp TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA
                              {fprintf(yyout,";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");
                              while_fin(yyout, $1.etiqueta);
                              }
                          ;
while_exp                 :   while TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO
                              {
                              if ($3.tipo != BOOLEANO) {
                                printf("****Error semantico en lin %lu: Bucle con condicion de tipo int.\n", nlines);
                                LiberarTablas(tabla);
                                return -1;
                              }

                              $$.etiqueta =$1.etiqueta;
                              while_exp_pila(yyout, $3.es_direccion, $$.etiqueta);
                              }
                          ;
while                     :   TOK_WHILE
                              {
                              $$.etiqueta = etiqueta++;
                              while_inicio(yyout, $$.etiqueta);
                              }
                          ;
lectura                   :   TOK_SCANF TOK_IDENTIFICADOR
                              {fprintf(yyout,";R54:\t<lectura> ::= scanf <identificador>\n");
                               simbolo *simbolo;
                               simbolo = BusquedaElemento(tabla, $2.lexema);

                               /* Si el simbolo no estaba declarado */
                               if (simbolo == NULL){
                                printf("****Error semantico en lin %lu: Acceso a variable no declarada (%s).\n", nlines, $2.lexema);
                                LiberarTablas(tabla);
                                return -1;
                               }
                               /* Solo leemos ESCALAR y VARIABLE o PARAMETRO */
                               if (simbolo->categoria_estructura == VECTOR || simbolo->categoria == FUNCION){
                                printf("****Error semantico en lin %lu: Variable local de tipo no escalar.\n", nlines);
                                LiberarTablas(tabla);
                                return -1;
                               }
                              leer(yyout, $2.lexema, simbolo->tipo);}
                          ;
escritura                 :   TOK_PRINTF exp
                              {fprintf(yyout,";R56:\t<escritura> ::= printf <exp>\n");
                               operandoEnPilaAArgumento(yyout, $2.es_direccion);
                               escribir(yyout, 0, $2.tipo);}
                          ;
retorno_funcion           :   TOK_RETURN exp
                              {if (dentro_llamada_fun == 1){
                                printf("****Error semantico en lin %lu: Sentencia de retorno fuera del cuerpo de una funcion.\n", nlines);
                                LiberarTablas(tabla);
                                return -1;
                              }
                              fprintf(yyout,";R61:\t<retorno_funcion> ::= return <exp>\n");
                              if (funcion_tipo != $2.tipo){
                                printf("****Error semantico en lin %lu: Tipo incorrecto en retorno.\n", nlines);
                                LiberarTablas(tabla);
                                return -1;
                              }
                              funcion_retorno++;
                              retornarFuncion(yyout, $2.es_direccion);}
                          ;
exp                       :   exp TOK_MAS exp
                              {
                                fprintf(yyout,";R72:\t<exp> ::= <exp> + <exp>\n");
                                if(($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)){
                                  printf("****Error semantico en lin %lu: Operacion aritmetica con operandos boolean.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                sumar(yyout, $1.es_direccion, $3.es_direccion);
                                $$.tipo = ENTERO;
                                $$.es_direccion = 0;
                              }
                          |   exp TOK_MENOS exp
                              {
                                fprintf(yyout,";R73:\t<exp> ::= <exp> - <exp>\n");
                                if(($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)){
                                  printf("****Error semantico en lin %lu: Operacion aritmetica con operandos boolean.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                restar(yyout, $1.es_direccion, $3.es_direccion);
                                $$.tipo = ENTERO;
                                $$.es_direccion = 0;
                              }
                          |   exp TOK_DIVISION exp
                              {
                                fprintf(yyout,";R74:\t<exp> ::= <exp> / <exp>\n");
                                if(($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)){
                                  printf("****Error semantico en lin %lu: Operacion aritmetica con operandos boolean.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                dividir(yyout, $1.es_direccion, $3.es_direccion);
                                $$.tipo = ENTERO;
                                $$.es_direccion = 0;
                              }
                          |   exp TOK_ASTERISCO exp
                              {
                                fprintf(yyout,";R75:\t<exp> ::= <exp> * <exp>\n");
                                if(($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)){
                                  printf("****Error semantico en lin %lu: Operacion aritmetica con operandos boolean.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                multiplicar(yyout, $1.es_direccion, $3.es_direccion);
                                $$.tipo = ENTERO;
                                $$.es_direccion = 0;
                              }
                          |   TOK_MENOS exp
                              {
                                fprintf(yyout,";R76:\t<exp> ::= - <exp>\n");
                                if($2.tipo == BOOLEANO){
                                  printf("****Error semantico en lin %lu: Operacion aritmetica con operandos boolean.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                cambiar_signo(yyout, $2.es_direccion);
                                $$.tipo = ENTERO;
                                $$.es_direccion = 0;
                              }
                          |   exp TOK_AND exp
                              {
                                fprintf(yyout,";R77:\t<exp> ::= exp> && <exp>\n");
                                if(($1.tipo == ENTERO) || ($3.tipo == ENTERO)){
                                  printf("****Error semantico en lin %lu: Operacion logica con operandos int.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                y(yyout, $1.es_direccion, $3.es_direccion);
                                $$.tipo = BOOLEANO;
                                $$.es_direccion = 0;
                              }
                          |   exp TOK_OR exp
                              {
                                fprintf(yyout,";R78:\t<exp> ::= <exp> || <exp>\n");
                                if(($1.tipo == ENTERO) || ($3.tipo == ENTERO)){
                                  printf("****Error semantico en lin %lu: Operacion logica con operandos int.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                o(yyout, $1.es_direccion, $3.es_direccion);
                                $$.tipo = BOOLEANO;
                                $$.es_direccion = 0;
                              }
                          |   TOK_NOT exp
                              {
                                fprintf(yyout,";R79:\t<exp> ::= ! <exp>\n");
                                if($2.tipo == ENTERO){
                                  printf("****Error semantico en lin %lu: Operacion logica con operandos int.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                no(yyout, $2.es_direccion, etiqueta);
                                etiqueta++;
                                $$.tipo = BOOLEANO;
                                $$.es_direccion = 0;
                              }
                          |   TOK_IDENTIFICADOR
                              {fprintf(yyout,";R80:\t<exp> ::= <identificador>\n");
                              simbolo *simbolo;
                              if ((simbolo = BusquedaElemento(tabla, $1.lexema)) == NULL){
                                printf("****Error semantico en lin %lu: Acceso a variable no declarada (%s).\n", nlines, $1.lexema);
                                LiberarTablas(tabla);
                                return -1;
                              }
                              if (simbolo->categoria == FUNCION || simbolo->categoria_estructura == VECTOR) {
                                printf("****Error semantico en lin %lu: Asignacion incompatible.\n", nlines); //DUDA: No se si es este error
                                LiberarTablas(tabla);
                                return -1;
                              }
                              $$.tipo = simbolo->tipo;
                              $$.es_direccion = 1;
                              if (simbolo->categoria == PARAMETRO) {
                                escribirParametro(yyout, simbolo->posicion, posicion_parametro);
                              } else if (simbolo->categoria == VARIABLE) {
                                  if (Ambito(tabla) == LOCAL) {
                                    escribirVariableLocal(yyout, simbolo->posicion_varloc);
                                  }
                                  else {
                                    escribir_operando(yyout, $1.lexema, 1);
                                    if ( dentro_llamada_fun == 1){
                                      operandoEnPilaAArgumento(yyout, 1);
                                    }
                                  }
                              }}
                          |   constante
                              {fprintf(yyout,";R81:\t<exp> ::= <constante>\n");
                                $$.tipo = $1.tipo;
                                $$.es_direccion = $1.es_direccion;
                              }
                          |   TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO
                              {fprintf(yyout,";R82:\t<exp> ::= ( <exp> )\n");
                                $$.tipo = $2.tipo;
                                $$.es_direccion = $2.es_direccion;
                              }
                          |   TOK_PARENTESISIZQUIERDO comparacion TOK_PARENTESISDERECHO
                              {fprintf(yyout,";R83:\t<exp> ::= ( <comparacion> )\n");
                                $$.tipo = $2.tipo;
                                $$.es_direccion = $2.es_direccion;
                              }
                          |   elemento_vector
                              {fprintf(yyout,";R85:\t<exp> ::= <elemento_vector>\n");
                                $$.tipo = $1.tipo;
                                $$.es_direccion = $1.es_direccion;
                              }
                          |   idf_llamada_funcion TOK_PARENTESISIZQUIERDO lista_expresiones TOK_PARENTESISDERECHO
                              {fprintf(yyout,";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");
                              simbolo *simbolo;
                              if ((simbolo = BusquedaElemento(tabla, $1.lexema)) == NULL) {
                                printf("****Error semantico en lin %lu: Acceso a variable no declarada (%s).\n", nlines, $1.lexema);
                                LiberarTablas(tabla);
                                return -1;
                              }
                              if (num_arg_funcion != simbolo->n_parametros) {
                                printf("****Error semantico en lin %lu: Numero incorrecto de parametros en llamada a función.\n", nlines);
                                LiberarTablas(tabla);
                                return -1;
                              }
                              $$.tipo = simbolo->tipo;
                              llamarFuncion(yyout, $1.lexema, simbolo->n_parametros);
                              limpiarPila(yyout, simbolo->n_parametros);
                              dentro_llamada_fun = 0;
                              }
                          ;
idf_llamada_funcion       :   TOK_IDENTIFICADOR
                              {
                                simbolo *simbolo;
                                if (dentro_llamada_fun == 1){
                                  printf("****Error semantico en lin %lu: No esta permitido el uso de llamadas a funciones como parametros de otras funciones.\n", nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                if ((simbolo = BusquedaElemento(tabla, $1.lexema)) == NULL){
                                  printf("****Error semantico en lin %lu: Acceso a variable no declarada (%s).\n", nlines, $1.lexema);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                if (simbolo->categoria != FUNCION) {
                                  printf("****Error semantico en lin %lu: Intento de llamar a una variable en vez de funcion.\n", nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                num_arg_funcion = 0;
                                dentro_llamada_fun = 1;
                                strcpy($$.lexema, $1.lexema);
                              }
                          ;
lista_expresiones         :   exp resto_lista_expresiones
                              {
                                fprintf(yyout,";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");
                                if(dentro_llamada_fun == 1){
                                  num_arg_funcion++;
                                }
                              }
                          |   %empty
                              {fprintf(yyout,";R90:\t<lista_expresiones> ::= \n");}
                          ;
resto_lista_expresiones   :   TOK_COMA exp resto_lista_expresiones
                              {
                                fprintf(yyout,";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");
                                if(dentro_llamada_fun == 1){
                                  num_arg_funcion++;
                                }
                              }
                          |   %empty
                              {fprintf(yyout,";R92:\t<resto_lista_expresiones> ::= \n");}
                          ;
comparacion               :   exp TOK_IGUAL exp
                              {
                                fprintf(yyout,";R93:\t<comparacion> ::= <exp> == <exp>\n");
                                if(($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)){
                                  printf("****Error semantico en lin %lu: Comparacion con operandos boolean.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                igual(yyout, $1.es_direccion, $3.es_direccion, etiqueta);
                                etiqueta++;
                                $$.tipo = BOOLEANO;
                                $$.es_direccion = 0;
                              }
                          |   exp TOK_DISTINTO exp
                              {
                                fprintf(yyout,";R94:\t<comparacion> ::= <exp> != <exp>\n");
                                if(($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)){
                                  printf("****Error semantico en lin %lu: Comparacion con operandos boolean.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                distinto(yyout, $1.es_direccion, $3.es_direccion, etiqueta);
                                etiqueta++;
                                $$.tipo = BOOLEANO;
                                $$.es_direccion = 0;
                              }
                          |   exp TOK_MENORIGUAL exp
                              {
                                fprintf(yyout,";R95:\t<comparacion> ::= <exp> <= <exp>\n");
                                if(($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)){
                                  printf("****Error semantico en lin %lu: Comparacion con operandos boolean.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                menor_igual(yyout, $1.es_direccion, $3.es_direccion, etiqueta);
                                etiqueta++;
                                $$.tipo = BOOLEANO;
                                $$.es_direccion = 0;
                              }
                          |   exp TOK_MAYORIGUAL exp
                              {
                                fprintf(yyout,";R96:\t<comparacion> ::= <exp> >= <exp>\n");
                                if(($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)){
                                  printf("****Error semantico en lin %lu: Comparacion con operandos boolean.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                mayor_igual(yyout, $1.es_direccion, $3.es_direccion, etiqueta);
                                etiqueta++;
                                $$.tipo = BOOLEANO;
                                $$.es_direccion = 0;
                              }
                          |   exp TOK_MENOR exp
                              {
                                fprintf(yyout,";R97:\t<comparacion> ::= <exp> < <exp>\n");
                                if(($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)){
                                  printf("****Error semantico en lin %lu: Comparacion con operandos boolean.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                menor(yyout, $1.es_direccion, $3.es_direccion, etiqueta);
                                etiqueta++;
                                $$.tipo = BOOLEANO;
                                $$.es_direccion = 0;
                              }
                          |   exp TOK_MAYOR exp
                              {
                                fprintf(yyout,";R98:\t<comparacion> ::= <exp> > <exp>\n");
                                if(($1.tipo == BOOLEANO) || ($3.tipo == BOOLEANO)){
                                  printf("****Error semantico en lin %lu: Comparacion con operandos boolean.\n",nlines);
                                  LiberarTablas(tabla);
                                  return -1;
                                }
                                mayor(yyout, $1.es_direccion, $3.es_direccion, etiqueta);
                                etiqueta++;
                                $$.tipo = BOOLEANO;
                                $$.es_direccion = 0;
                              }
                          ;
constante                 :   constante_logica
                              {
                                fprintf(yyout,";R99:\t<constante> ::= <constante_logica>\n");
                                $$.tipo = $1.tipo;
                                $$.es_direccion = $1.es_direccion;
                              }
                          |   constante_entera
                              {
                                fprintf(yyout,";R100:\t<constante> ::= <constante_entera>\n");
                                $$.tipo = $1.tipo;
                                $$.es_direccion = $1.es_direccion;
                              }
                          ;
constante_logica          :   TOK_TRUE
                              {
                                fprintf(yyout,";R102:\t<constante_logica> ::= true\n");
                                $$.tipo = BOOLEANO;
                                $$.es_direccion = 0;
                                char v[1];
                                sprintf(v,"1");
                                escribir_operando(yyout,v,0);
                              }
                          |   TOK_FALSE
                              {
                                fprintf(yyout,";R103:\t<constante_logica> ::= false\n");
                                $$.tipo = BOOLEANO;
                                $$.es_direccion = 0;
                                char v[1];
                                sprintf(v,"0");
                                escribir_operando(yyout,v,0);
                              }
                          ;
constante_entera          :   TOK_CONSTANTE_ENTERA
                              {
                                fprintf(yyout,";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n");
                                $$.tipo = ENTERO;
                                $$.es_direccion = 0;
                                $$.valor_entero = $1.valor_entero;
                                char v[MAX_TAM_ENTERO];
                                sprintf(v,"%d",$$.valor_entero);
                                escribir_operando(yyout,v,0);
                              }
                          ;
identificador             :   TOK_IDENTIFICADOR
                              {fprintf(yyout,";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
                               /* Si la variable no estaba declarada antes, la declaramos */
                               if (BusquedaEnAmbitoActual(tabla, $1.lexema) == NULL){
                                if (Ambito(tabla) == LOCAL){
                                  num_total_varlocs++;
                                  posicion++;
                                  InsercionElemento(tabla, $1.lexema, VARIABLE, tipo, categoria_estructura, tamanio, num_total_parametros, posicion, 0, num_total_varlocs);
                                }
                                if (Ambito(tabla) == GLOBAL){
                                  InsercionElemento(tabla, $1.lexema, VARIABLE, tipo, categoria_estructura, tamanio, num_total_parametros, posicion, 0, num_total_varlocs);
                                  declarar_variable(yyout, $1.lexema, tipo, tamanio);
                                }
                               }
                               /* Ya existia la variable luego error por duplicado*/
                               else{
                                printf("****Error semantico en lin %lu: Declaracion duplicada.\n", nlines);
                                LiberarTablas(tabla);
                                return -1;
                               }}
%%

void yyerror(const char *s){
  extern size_t nlines;
  extern size_t ncols;
  extern int err_morf;
  extern int yyleng;
  if(!err_morf){
    printf("****Error sintáctico en [lin %lu col %lu]\n",nlines, ncols-yyleng);
    return;
  }
  err_morf = 0;
  return;
}
