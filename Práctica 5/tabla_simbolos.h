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

typedef struct _simbolo simbolo;
typedef struct _tablas_smb tablas_smb;

tablas_smb * CrearTablas(void);

void LiberarTablas(tablas_smb* tablas);

int InserccionElemento(tablas_smb* tablas, char * identificador, int valor);

int BusquedaElemento(tablas_smb* tablas, char* identificador);

int AperturaAmbito(tablas_smb* tablas, char* identificador, int valor);

int CierreAmbito(tablas_smb* tablas);




#endif
