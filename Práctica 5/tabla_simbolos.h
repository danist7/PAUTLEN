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
  int posicion_varloc;       /* Posicion de la variable local, solo para elementos variable local de funcion */
  UT_hash_handle hh;         /* makes this structure hashable */
} simbolo;

typedef struct _tablas_smb {
  simbolo **tabla_global;    /* Simbolo de la tabla global */
  simbolo **tabla_local;     /* Simbolo de la tabla local */
  int hay_local;             /* Es 1 si hay ambito local y 0 si es el global */
} tablas_smb;

/**
 * Funcion: CrearTablas
 * Parametros: void
 * Return: una nueva tabla estructura con las tablas global y local
 *
 * Reserva memoria para las tablas global y local de la estructura tablas_smb
 */
tablas_smb * CrearTablas(void);

/**
 * Funcion: LiberarTablas
 * Parametros: estructura tablas_smb
 * Return: void
 *
 * Hace un free de cada simbolo de las tablas y de ambas tablas
 */
void LiberarTablas(tablas_smb* tablas);

/**
 * Funcion: InsercionElemento
 * Parametros: la estructura de tablas y todos los atributos de un simbolo
 * Return: ERROR si insertamos un elemento que ya existia
 *         FATAL_ERROR si no se reserva bien la memoria
 *         OK si todo fue bien
 *
 * Inserta un nuevo elemento en la tabla de simbolos local si hay_local es 1
 * y sino lo inserta en la tabla de simbolos global
 */
int InsercionElemento(tablas_smb* tablas, char * identificador,
                       int categoria,
                       int tipo,
                       int categoria_estructura,
                       int tamanio,
                       int n_parametros,
                       int posicion,
                       int n_varloc,
                       int posicion_varloc);


/**
 * Funcion: BusquedaElemento
 * Parametros: la estructura con ambas tablas y el identificador a buscar
 * Return: simbolo del elemento que buscamos con identificador o NULL
 *
 * Si hay abierto ámbito local, busca un elemento primero en el ámbito local.
 * Y luego en el ámbito global.
 * En caso contrario, busca solo en el ambito global.
 * Devuelve NULL en caso de no encontrarlo
 */
simbolo *BusquedaElemento(tablas_smb* tablas, char* identificador);


/**
 * Funcion: BusquedaEnAmbitoActual
 * Parametros: la estructura con ambas tablas y el identificador a buscar
 * Return: simbolo del elemento que buscamos con identificador o NULL
 *
 * Si hay abierto ámbito local, busca un elemento solo en el ámbito local.
 * En caso contrario, busca solo en el ambito global
 * Devuelve NULL en caso de no encontrarlo
 */
simbolo *BusquedaEnAmbitoActual(tablas_smb* tablas, char* identificador);

/**
 * Funcion: AperturaAmbito
 * Parametros: la estructura con ambas tablas y los atributos del ambito local a crear
 * Return: ERROR si intentamos abrir un ambito local cuando ya hay uno
 *         OK si se abre el ambito local con exito
 *
 * Inicializa un ambito local
 */
int AperturaAmbito(tablas_smb* tablas, char* identificador,
                      int categoria,
                      int tipo,
                      int categoria_estructura,
                      int tamanio,
                      int n_parametros,
                      int posicion,
                      int n_varloc,
                      int posicion_varloc);

/**
 * Funcion: CierreAmbito
 * Parametros: la estructura con ambas tablas
 * Return: ERROR si intentamos cerrar el ambito local sin que haya
 *         OK si cerramos el ambito local con exito
 *
 * Cierra y elimina los simbolos del ambito local, volviendo al ambito local
 */
int CierreAmbito(tablas_smb* tablas);

/**
 * Funcion: Ambito
 * Parametros: la estructura con ambas tablas
 * Return: 1 si el ambito es local
 *         0 si el ambito es global
 *
 * Devuelve el valor de la variable hay_local
 */
int Ambito(tablas_smb* tablas);




#endif
