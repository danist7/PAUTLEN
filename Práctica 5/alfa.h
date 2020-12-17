#ifndef _ALFA_H
#define _ALFA_H
#define MAX_LONG_ID 100
#define MAX_TAMANIO_VECTOR 64
#define GLOBAL = 0
#define LOCAL = 1

//DEFINICIONES DE CATEGORIAS
#define VARIABLE = 1
#define PARAMETRO = 2
#define FUNCION = 3


//DEFINICIONES DE CATEGORIAS DE ESTRUCTURA
#define ESCALAR = 1
#define VECTOR = 2


#define MAX_TAM_ENTERO 50



typedef struct
{
 char lexema[MAX_LONG_ID+1]; /* Nombre del identificador */
 int tipo;                   /* Tipo del identificador ENTERO o BOOLEANO*/
 int valor_entero;           /* El valor de un identificador entero */
 int es_direccion;           /* Para decir que es una direccion de memoria */
 int etiqueta;               /* Etiqueta para hacer en ensamblador una sentencia condicional o iterativa */
} tipo_atributos;


#endif
