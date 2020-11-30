#include <stdio.h>
#include <stdlib.h>

#include "tabla_simbolos.h"
#include "tabla_hash.h"

#define ERROR -1;
#define OK 0;
#define FATAL_ERROR -2;


// En un futuro se usaran el resto de parámetros tambien, pero para el
// prueba_tabla y para esta práctica solo se necesita valor
struct simbolo {
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

struct tabla_smb {
  simbolo **tabla_global;
  simbolo **tabla_local;
  int hay_local;
} tabla_smb;

tabla_smb *crear_tabla_smb(void){
  tabla_smb *tb_smb;

  tb_smb = (tb_smb*)malloc(sizeof(tabla_smb));
  if(!tb_smb){
    printf("Error reservando memoria para la tabla de simbolos\n");
    return NULL;
  }

  tb_smb->tabla_global = (simbolo**)malloc(sizeof(simbolo)); //TODO
  if(!tb_smb->tabla_global){
    free(tb_smb);
    printf("Error reservando memoria para la tabla global de la tabla de simbolos\n");
    return NULL;
  }

  tb_smb->tabla_local = (simbolo**)malloc(sizeof(simbolo)); //TODO
  if(!tb_smb->tabla_local){
    free(tb_smb->tabla_global);
    free(tb_smb);
    printf("Error reservando memoria para la tabla local de la tabla de simbolos\n");
    return NULL;
  }

  *(tb_smb->tabla_local) = NULL;
  *(tb_smb->tabla_global) = NULL;
  tb_smb->hay_local = 0;
  return tb_smb;
}

void liberar_tablas(tabla_smb* tablas){
  eliminar_tabla(tablas->tabla_local);
  eliminar_tabla(tablas->tabla_global);
  free(tb_smb->tabla_local);
  free(tb_smb->tabla_global);
  free(tb_smb);
}

// En un futuro introducira el resto de parámetros tambien, pero para el
// prueba_tabla y para esta práctica se requiere que sea asi.
int insertar_simbolo(simbolo ** tabla, char* identificador, int valor){
  simbolo * nuevo_smb;
  if (buscar_simbolo(tabla, identificador) == 0) {
    return ERROR;
  }

  nuevo_smb = (simbolo *) malloc(sizeof(simbolo));
  if (nuevo_smb == NULL) {
    printf("Error reservando memoria para el simbolo %s\n", identificador);
    return FATAL_ERROR;
  }

  nuevo_smb->identificador = (char *) malloc(sizeof(char)*(strlen(identificador)+1));
  if (nuevo_smb->identificador == NULL) {
    free(nuevo_smb);
    printf("Error reservando memoria para el identificador del simbolo %s\n", identificador);
    return FATAL_ERROR;
  }
  strcpy(nuevo_smb->identificador, identificador);
  nuevo_smb->tipo = valor;

  HASH_ADD_STR(*tabla, identificador, nuevo_smb);

  return OK;
}

int eliminar_simbolo(simbolo ** tabla, simbolo* smb) {
  HASH_DEL(*tabla, smb);
  free(smb->identificador);
  free(smb);
}

int eliminar_tabla(simbolo ** tabla) {
  simbolo *item_ptr, *tmp_item_ptr;
  HASH_ITER(hh, *tabla, item_ptr, tmp_smb_ptr) {
    eliminar_simbolo(tabla, item_ptr);
  }

}

int buscar_simbolo(simbolo ** tabla, char* identificador) {
  simbolo *item_ptr;
  HASH_FIND_STR(*tabla, identificador, item_ptr);
  if(item_ptr == NULL) {
    return ERROR;
  }
  return OK;
}

int InserccionElemento(tabla_smb* tablas, char * identificador, int valor) {
  if (tablas->hay_local == 1) {
    return insertar_simbolo(tablas->tabla_local, identificador, valor);
  } else {
    return insertar_simbolo(tablas->tabla_global, identificador, valor);
  }
}

int BusquedaElemento(tabla_smb* tablas, char* identificador) {
  int encontrado;
  if (tablas->hay_local == 1) {
    encontrado = buscar_simbolo(tablas->tabla_local, identificador);
    if (encontrado == -1) {
      encontrado = buscar_simbolo(tablas->tabla_global, identificador);
    }
    return encontrado;
  } else {
    return buscar_simbolo(tablas->tabla_global, identificador);
  }
}

int AperturaAmbito(tabla_smb* tablas, char* identificador) {
  if (tablas->hay_local == 1) {
    return ERROR;
  }
  if (buscar_simbolo(tablas->tabla_global, identificador) == 0) {
    return ERROR;
  }
  insertar_simbolo(tablas->tabla_global, identificador);
  tablas->hay_local = 0;
  return OK;
}

int CierreAmbito(tabla_smb* tablas) {
  if (tablas->hay_local == 0) {
    return ERROR;
  }
  eliminar_tabla(tablas->tabla_local);
  tablas->hay_local = 1;
  return OK;
}
