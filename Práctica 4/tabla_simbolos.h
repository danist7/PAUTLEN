#include <stdio.h>
#include <stdlib.h>

#include "tabla_simbolos.h"
#include "tabla_hash.h"

struct tabla_smb {
  tabla_hash *tabla_global;
  tabla_hash *tabla_local;
};

tabla_smb *crear_tabla_smb(void){
  tabla_smb *tb_smb;

  tb_smb = (tb_smb*)malloc(sizeof(tabla_smb));
  if(!tb_smb){
    printf("Error reservando memoria para la tabla de simbolos\n");
    return NULL;
  }

  tb_smb->tabla_global = crear_tabla_hash(); //TODO
  if(!tb_smb->tabla_global){
    printf("Error reservando memoria para la tabla global de la tabla de simbolos\n");
    return NULL;
  }

  tb_smb->tabla_local = crear_tabla_hash(); //TODO
  if(!tb_smb->tabla_local){
    printf("Error reservando memoria para la tabla local de la tabla de simbolos\n");
    return NULL;
  }

  return tb_smb;
}

void liberar_tabla_smb(tabla_smb* tb_smb){
  liberar_tabla_hash(tb_smb->tabla_global);
  liberar_tabla_hash(tb_smb->tabla_local);
  free(tb_smb);
}
