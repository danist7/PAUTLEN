#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabla_simbolos.h"

#define BUFFER_SIZE 256


int main(int argc, char const *argv[]) {
  FILE *filein, *fileout;
  tablas_smb* tablas;
  char buffer[BUFFER_SIZE];
  char *keytoken, *valtoken;
  int val, result;



  if (argc != 3){
    printf("Se requiere fichero de entrada y de salida\n");
    printf("./pruebaTabla <fichero_entrada> <fichero_salida>\n");
    return 1;
  }

  if ((filein = fopen(argv[1], "r")) == NULL) {
    printf("Error al abrir fichero de entrada\n");
    return 1;
  }

  if ((fileout = fopen(argv[2], "w")) == NULL) {
    fclose(filein);
    printf("Error al abrir fichero de salida\n");
    return 1;
  }

  if ((tablas = CrearTablas()) == NULL){
    fclose(filein);
    fclose(fileout);
    printf("Error al crear las tablas\n");
    return 1;
  }

  while (fgets(buffer, BUFFER_SIZE, filein)) {
    keytoken = strtok(buffer, " \n");
    if(keytoken == NULL) {
      fprintf(fileout, "ERROR: Linea vacia\n");
    }
    valtoken = strtok(NULL, " \n");
    if(valtoken == NULL) {
      result = BusquedaElemento(tablas, keytoken);
      fprintf(fileout, "%s %d\n", keytoken, result);
    } else {
      val = atoi(valtoken);
      if((strcmp(keytoken, "cierre") == 0) && (val == -999)) {
        result = CierreAmbito(tablas);
        if (result == OK) {
          fprintf(fileout, "cierre\n");
        } else {
          fprintf(fileout, "-1 cierre\n"); //ERROR: Cierre sin haber tabla local
        }
      } else if (val < -1) {
        result = AperturaAmbito(tablas, keytoken, val);
        if (result == OK) {
          fprintf(fileout, "%s\n", keytoken);
        } else {
          fprintf(fileout, "-1 %s\n", keytoken); //ERROR: Apertura fallida
        }
      } else if (val >= 0) {
        result = InserccionElemento(tablas, keytoken, val);
        if (result == OK) {
          fprintf(fileout, "%s\n", keytoken);
        } else {
          fprintf(fileout, "-1 %s\n", keytoken);
        }
      }
    }
  }

  LiberarTablas(tablas);

  fclose(filein);
  fclose(fileout);

  return 0;
}
