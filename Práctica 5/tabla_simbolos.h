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
  char * identificador;      /* key */
  int categoria;
  int tipo;
  int categoria_estructura;
  int tamanio;
  int n_parametros;
  int posicion;
  int n_varloc;
  int posicion_varloc;
  UT_hash_handle hh;         /* makes this structure hashable */
} simbolo;

typedef struct _tablas_smb tablas_smb;

tablas_smb * CrearTablas(void);

void LiberarTablas(tablas_smb* tablas);

int InserccionElemento(tablas_smb* tablas, char * identificador, int valor);

simbolo *BusquedaElemento(tablas_smb* tablas, char* identificador);

int AperturaAmbito(tablas_smb* tablas, char* identificador, int valor);

int CierreAmbito(tablas_smb* tablas);




#endif
