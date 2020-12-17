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




typedef struct
{
 char lexema[MAX_LONG_ID+1];
 int tipo;
 int valor_entero;
 int es_direccion;
 int etiqueta;
} tipo_atributos;


#endif
