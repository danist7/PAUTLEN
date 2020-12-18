#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

#include "uthash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ERROR -1
#define OK 0
#define FATAL_ERROR -2
#define MAX_LOCAL_TB 1024

typedef struct _simbolo {
  char * identificador;      /* String que guarda el nombre del identificador */
  int categoria;             /* Puede ser VARIABLE, PARAMETRO o FUNCION */
  int tipo;                  /* Puede ser ENTERO o BOOLEANO */
  int categoria_estructura;  /* Puede ser ESCALAR o VECTOR */
  int tamanio;               /* Tamaño de la variable (1 para escalar, más para vectores)*/
  int n_parametros;          /* Número de parámetros que tiene una funcion */
  int posicion;              /* Solo para elementos de tipo parametro, posicion en orden, empieza por 0 */
  int n_varloc;              /* Numero de variables locales, solo para elementos FUNCION */
  int posicion_varloc;       /* Posicion de la variable local, solo para elementos FUNCION */
  UT_hash_handle hh;         /* makes this structure hashable */
} simbolo;

typedef struct _tablas_smb tablas_smb;

tablas_smb * CrearTablas(void);

void LiberarTablas(tablas_smb* tablas);

int InsercionElemento(tablas_smb* tablas, char * identificador,
                       int categoria,
                       int tipo,
                       int categoria_estructura,
                       int tamanio,
                       int n_parametros,
                       int posicion,
                       int n_varloc,
                       int posicion_varloc);

/* Si hay abierto ámbito local, busca un elemento primero en el ámbito local.
Y luego en el ámbito global.
En caso contrario, busca solo en el ambito global.
Devuelve NULL en caso de no encontrarlo */
simbolo *BusquedaElemento(tablas_smb* tablas, char* identificador);

/* Si hay abierto ámbito local, busca un elemento solo en el ámbito local.
En caso contrario, busca solo en el ambito global
Devuelve NULL en caso de no encontrarlo */
simbolo *BusquedaEnAmbitoActual(tablas_smb* tablas, char* identificador);

int AperturaAmbito(tablas_smb* tablas, char* identificador, int valor);

int CierreAmbito(tablas_smb* tablas);

int Ambito(tablas_smb* tablas);




#endif
