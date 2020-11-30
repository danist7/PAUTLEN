#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H


#define MAX_LOCAL_TB 1024

typedef struct tabla_smb tabla_smb;

tabla_smb *crear_tabla_smb(void);

void liberar_tabla_smb(tabla_smb* tb_smb);

int symb_tb_insert(symbol_tb *symb_tb, char *key, int value);

int symb_tb_isKey(symbol_tb *symb_tb, char *key);

int symb_tb_search(symbol_tb *symb_tb, char *key, int *value);


#endif
