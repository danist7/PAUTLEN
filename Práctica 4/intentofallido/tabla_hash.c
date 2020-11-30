#include <stdlib.h>


typedef struct tabla_hash{
  size_t tamanio;
  item_hash** items;
} tabla_hash;

typedef struct item_hash{

} item_hash;

int hash(char* key) {
  int hash_id=0;
  int i, len;

  len = strlen(key);

  for (i=0; i<len; i++){
    hash_id += ()(int) key[i]) * (HASH_P^i);
  }

  return hash_id%HASH_M
}

item_hash* crear_item( ) {
  item_hash* item = (item_hash*) malloc (sizeof(item_hash));

  return item;
}

tabla_hash* crear_tabla_hash( ) {
  tabla_hash* tabla = (tabla_hash*) malloc (sizeof(tabla_hash));
  tabla->items =  (item_hash**) calloc (tabla->tamanio, sizeof(item_hash))
  for (int i=0; i<tabla->tamanio; i++){
    tabla->items[i] = NULL;
  }

  return tabla;
}

void liberar_item(item_hash* item) {
  free(item);
}

void liberar_tabla(tabla_hash* tabla) {
  for (int i=0; i<tabla->tamanio; i++){
    item_hash* item = tabla->items[i]
    if (item != NULL)
      liberar_item(item);
  }
  free(tabla->items);
  free(tabla);
}

int th_insertar(tabla_hash* th, char* key, char* value) {
  int hash_id;

  if (!th)
    return ERROR;

  hash_id = hash(key);
  if(hash_id < 0){
    printf("Error en el id del hash\n");
    return ERROR;
  }

  
}
