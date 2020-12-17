#include "tabla_simbolos.h"


typedef struct _tablas_smb {
  simbolo **tabla_global;
  simbolo **tabla_local;
  int hay_local;
} tablas_smb;

tablas_smb * CrearTablas(void){
  tablas_smb *tb_smb;

  tb_smb = (tablas_smb*)malloc(sizeof(tablas_smb));
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


int eliminar_simbolo(simbolo ** tabla, simbolo* smb) {
  HASH_DEL(*tabla, smb);
  free(smb->identificador);
  free(smb);
  return OK;
}

int eliminar_tabla(simbolo ** tabla) {
  simbolo *item_ptr, *tmp_item_ptr;
  HASH_ITER(hh, *tabla, item_ptr, tmp_item_ptr) {
    eliminar_simbolo(tabla, item_ptr);
  }
  return OK;
}

void LiberarTablas(tablas_smb* tablas){
  eliminar_tabla(tablas->tabla_local);
  eliminar_tabla(tablas->tabla_global);
  free(tablas->tabla_local);
  free(tablas->tabla_global);
  free(tablas);
}


simbolo *buscar_simbolo(simbolo ** tabla, char* identificador) {
  simbolo *item_ptr;
  HASH_FIND_STR(*tabla, identificador, item_ptr);
  if(item_ptr == NULL) {
    return NULL;
  }
  return item_ptr;
}

// En un futuro introducira el resto de parámetros tambien, pero para el
// prueba_tabla y para esta práctica se requiere que sea asi.
int insertar_simbolo(simbolo ** tabla, char* identificador,
                                       int categoria,
                                       int tipo,
                                       int categoria_estructura,
                                       int tamanio,
                                       int n_parametros,
                                       int posicion,
                                       int n_varloc,
                                       int posicion_varloc){
  simbolo * nuevo_smb;
  if (buscar_simbolo(tabla, identificador) != ERROR) {
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
  nuevo_smb->categoria = categoria;
  nuevo_smb->tipo = tipo;
  nuevo_smb->categoria_estructura = categoria_estructura;
  nuevo_smb->tamanio = tamanio;
  nuevo_smb->n_parametros = n_parametros;
  nuevo_smb->posicion = posicion;
  nuevo_smb->n_varloc = n_varloc;
  nuevo_smb->posicion_varloc = posicion_varloc;

  HASH_ADD_STR(*tabla, identificador, nuevo_smb);
  return OK;
}

int InsercionElemento(tablas_smb* tablas, char * identificador,
                       int categoria,
                       int tipo,
                       int categoria_estructura,
                       int tamanio,
                       int n_parametros,
                       int posicion,
                       int n_varloc,
                       int posicion_varloc); {
  if (tablas->hay_local == 1) {
    return insertar_simbolo(tablas->tabla_local, identificador,
                            categoria,
                            tipo,
                            categoria_estructura,
                            tamanio,
                            n_parametros,
                            posicion,
                            n_varloc,
                            posicion_varloc);
  } else {
    return insertar_simbolo(tablas->tabla_global, identificador,
                            categoria,
                            tipo,
                            categoria_estructura,
                            tamanio,
                            n_parametros,
                            posicion,
                            n_varloc,
                            posicion_varloc);
  }
}

simbolo *BusquedaElemento(tablas_smb* tablas, char* identificador) {
  simbolo *simbolo = NULL;
  if (tablas->hay_local == 1) {
    simbolo = buscar_simbolo(tablas->tabla_local, identificador);
    if (simbolo == NULL) {
      simbolo = buscar_simbolo(tablas->tabla_global, identificador);
    }
    return simbolo;
  } else {
    return buscar_simbolo(tablas->tabla_global, identificador);
  }
}

int AperturaAmbito(tablas_smb* tablas, char* identificador, int valor) {
  if (tablas->hay_local == 1) {
    return ERROR;
  }
  if (buscar_simbolo(tablas->tabla_global, identificador) != ERROR) {
    return ERROR;
  }
  insertar_simbolo(tablas->tabla_global, identificador, valor);
  insertar_simbolo(tablas->tabla_local, identificador, valor);
  tablas->hay_local = 1;
  return OK;
}

int CierreAmbito(tablas_smb* tablas) {
  if (tablas->hay_local == 0) {
    return ERROR;
  }
  eliminar_tabla(tablas->tabla_local);
  tablas->hay_local = 1;
  return OK;
}

int Ambito(tablas_smb* tablas){
  return tablas->hay_local;
}
