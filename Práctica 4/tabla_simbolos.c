#include <stdio.h>
#include <stdlib.h>

#include "tabla_simbolos.h"
#include "tabla_hash.h"

struct simbolo {
  char * identificador;      /* key */
  int value;
  UT_hash_handle hh;         /* makes this structure hashable */
}simbolo;

struct tabla_smb {
  simbolo **tabla_global;
  simbolo **tabla_local;
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
    printf("Error reservando memoria para la tabla global de la tabla de simbolos\n");
    return NULL;
  }

  tb_smb->tabla_local = (simbolo**)malloc(sizeof(simbolo)); //TODO
  if(!tb_smb->tabla_local){
    printf("Error reservando memoria para la tabla local de la tabla de simbolos\n");
    return NULL;
  }

  *(tb_smb->tabla_local) = NULL;
  *(tb_smb->tabla_global) = NULL;
  return tb_smb;
}

void liberar_tabla(simbolo** tabla){
  liberar_tabla_hash(tb_smb->tabla_global);
  liberar_tabla_hash(tb_smb->tabla_local);
  free(tb_smb);
}
