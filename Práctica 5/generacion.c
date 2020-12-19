#include <stdio.h>
#include "generacion.h"


void escribir_cabecera_bss(FILE* fpasm){
  fprintf(fpasm, "segment .bss\n");
  fprintf(fpasm, "__esp resd 1\n");
}

void escribir_subseccion_data(FILE* fpasm){
  fprintf(fpasm, "segment .data\n");
  //TODO: escribir cada mensaje de error segun vayamos creandolos
  fprintf(fpasm, "mensaje_error_div_0 dd \"****Error de ejecucion: División por cero\",0\n");
  fprintf(fpasm, "mensaje_error_fuera_rango dd \"****Error de ejecucion: Indice fuera de rango\",0\n");
}

void declarar_variable(FILE* fpasm, char * nombre, int tipo, int tamano){
  fprintf(fpasm, "_%s resd %d\n", nombre, tamano);
}

void escribir_segmento_codigo(FILE* fpasm){
  fprintf(fpasm, "segment .text\n");
  fprintf(fpasm, "global main\n");
  fprintf(fpasm, "extern scan_int, scan_boolean\n");
  fprintf(fpasm, "extern print_int, print_boolean, print_string, print_blank, print_endofline\n");
}

void escribir_inicio_main(FILE* fpasm){
  fprintf(fpasm, "main:\n");
  fprintf(fpasm, "mov [__esp], esp\n");
}

void escribir_fin(FILE* fpasm){
  fprintf(fpasm, "jmp near fin\n");

  fprintf(fpasm, "error_div_0: push dword mensaje_error_div_0\n");
  fprintf(fpasm, "call print_string\n");
  fprintf(fpasm, "add esp, 4\n");
  fprintf(fpasm, "jmp near fin\n");

  fprintf(fpasm, "fin_indice_fuera_rango: push dword mensaje_error_fuera_rango\n");
  fprintf(fpasm, "call print_string\n");
  fprintf(fpasm, "add esp, 4\n");
  fprintf(fpasm, "jmp near fin\n");

  fprintf(fpasm, "fin: mov esp, [__esp]\n");
  fprintf(fpasm, "ret\n");
}

void escribir_operando(FILE* fpasm, char* nombre, int es_variable){
  if (es_variable==1)
    fprintf(fpasm, "push dword _%s\n", nombre);
  else if (es_variable==0){
    fprintf(fpasm, "mov dword eax, %s\n", nombre);
    fprintf(fpasm, "push dword eax\n");
  }
}

void asignar(FILE* fpasm, char* nombre, int es_variable){
  if (es_variable==1){
     /* Se guarda la referencia en eax*/
    fprintf(fpasm, "pop dword eax\n");
    /*Se accede a la referencia con [] */
    fprintf(fpasm, "mov dword [_%s], [eax]\n", nombre);
  }
  else if (es_variable==0)
    fprintf(fpasm, "pop dword [_%s]\n", nombre);
}

void sumar(FILE* fpasm, int es_variable_1, int es_variable_2){
  /* Guarda variable 1 en ebx*/
  if(es_variable_2 == 1){
    /* Se guarda la referencia en eax*/
   fprintf(fpasm, "pop dword eax\n");
   /*Se accede a la referencia con [] */
   fprintf(fpasm, "mov dword ecx, [eax]\n");
  }
  else if(es_variable_2 == 0){
     fprintf(fpasm, "pop dword ecx\n");
  }
  /* Guarda variable 2 en ecx*/
  if(es_variable_1 == 1){
    /* Se guarda la referencia en eax*/
   fprintf(fpasm, "pop dword eax\n");
   /*Se accede a la referencia con [] */
   fprintf(fpasm, "mov dword ebx, [eax]\n");
  }
  else if(es_variable_1 == 0){
     fprintf(fpasm, "pop dword ebx\n");
  }


  fprintf(fpasm, "add ebx, ecx\n");
  fprintf(fpasm, "push dword ebx\n");
}

void restar(FILE* fpasm, int es_variable_1, int es_variable_2){
  /* Guarda variable 1 en ebx*/
  if(es_variable_2 == 1){
    /* Se guarda la referencia en eax*/
   fprintf(fpasm, "pop dword eax\n");
   /*Se accede a la referencia con [] */
   fprintf(fpasm, "mov dword ecx, [eax]\n");
  }
  else if(es_variable_2 == 0){
     fprintf(fpasm, "pop dword ecx\n");
  }
  /* Guarda variable 2 en ecx*/
  if(es_variable_1 == 1){
    /* Se guarda la referencia en eax*/
   fprintf(fpasm, "pop dword eax\n");
   /*Se accede a la referencia con [] */
   fprintf(fpasm, "mov dword ebx, [eax]\n");
  }
  else if(es_variable_1 == 0){
     fprintf(fpasm, "pop dword ebx\n");
  }

  fprintf(fpasm, "sub ebx, ecx\n");
  fprintf(fpasm, "push dword ebx\n");

}

void multiplicar(FILE* fpasm, int es_variable_1, int es_variable_2){

  /* Guarda variable 1 en eax*/
  if(es_variable_2 == 1){
    /* Se guarda la referencia en eax*/
   fprintf(fpasm, "pop dword ebx\n");
   /*Se accede a la referencia con [] */
   fprintf(fpasm, "mov dword ecx, [ebx]\n");
  }
  else if(es_variable_2 == 0){
     fprintf(fpasm, "pop dword ecx\n");
  }
  /* Guarda variable 2 en ecx*/
  if(es_variable_1 == 1){
    /* Se guarda la referencia en eax*/
   fprintf(fpasm, "pop dword ebx\n");
   /*Se accede a la referencia con [] */
   fprintf(fpasm, "mov dword eax, [ebx]\n");
  }
  else if(es_variable_1 == 0)
     fprintf(fpasm, "pop dword eax\n");

  /* Multiplica el contenido de eax por el de ecx*/
  fprintf(fpasm, "imul ecx\n");
  /*El resultado se guarda en eax*/
  fprintf(fpasm, "push dword eax\n");
}

void dividir(FILE* fpasm, int es_variable_1, int es_variable_2){
  /* Guarda variable 1 en eax*/
  if(es_variable_2 == 1){
    /* Se guarda la referencia en eax*/
   fprintf(fpasm, "pop dword ebx\n");
   /*Se accede a la referencia con [] */
   fprintf(fpasm, "mov dword ecx, [ebx]\n");
  }
  else if(es_variable_2 == 0){
     fprintf(fpasm, "pop dword ecx\n");
  }
  /* Guarda variable 2 en ecx*/
  if(es_variable_1 == 1){
    /* Se guarda la referencia en eax*/
   fprintf(fpasm, "pop dword ebx\n");
   /*Se accede a la referencia con [] */
   fprintf(fpasm, "mov dword eax, [ebx]\n");
  }
  else if(es_variable_1 == 0){
     fprintf(fpasm, "pop dword eax\n");
  }

  /* Comprueba si el dividor es 0*/
  fprintf(fpasm, "cmp ecx, 0\n");
  fprintf(fpasm, "je error_div_0\n");

  /* Extiende eax*/
  fprintf(fpasm, "cdq\n");
  /* Divide el contenido de eax entre el de ecx*/
  fprintf(fpasm, "idiv ecx\n");
  /*El resultado se guarda en eax*/
  fprintf(fpasm, "push dword eax\n");

}

void o(FILE* fpasm, int es_variable_1, int es_variable_2){
  /* Guarda variable 1 en ebx*/
  if(es_variable_2 == 1){
    /* Se guarda la referencia en eax*/
   fprintf(fpasm, "pop dword eax\n");
   /*Se accede a la referencia con [] */
   fprintf(fpasm, "mov dword ecx, [eax]\n");
  }
  else if(es_variable_2 == 0){
     fprintf(fpasm, "pop dword ecx\n");
  }
  /* Guarda variable 2 en ecx*/
  if(es_variable_1 == 1){
    /* Se guarda la referencia en eax*/
   fprintf(fpasm, "pop dword eax\n");
   /*Se accede a la referencia con [] */
   fprintf(fpasm, "mov dword ebx, [eax]\n");
  }
  else if(es_variable_1 == 0){
     fprintf(fpasm, "pop dword ebx\n");
  }


  fprintf(fpasm, "or ebx, ecx\n");
  fprintf(fpasm, "push dword ebx\n");

}

void y(FILE* fpasm, int es_variable_1, int es_variable_2){
  /* Si es un registro guarda v1 en ebx*/
  if(es_variable_2 == 1){
    /* Se guarda la referencia en eax*/
   fprintf(fpasm, "pop dword eax\n");
   /*Se accede a la referencia con [] */
   fprintf(fpasm, "mov dword ecx, [eax]\n");
  }
  /* Si es un valor solo se extrae en ebx */
  else if(es_variable_2 == 0){
     fprintf(fpasm, "pop dword ecx\n");
  }
  /* Si es un registro guarda v2 en ecx*/
  if(es_variable_1 == 1){
    /* Se guarda la referencia en eax*/
   fprintf(fpasm, "pop dword eax\n");
   /*Se accede a la referencia con [] */
   fprintf(fpasm, "mov dword ebx, [eax]\n");
  }
  /* Si es un valor solo se extrae en ecx */
  else if(es_variable_1 == 0){
     fprintf(fpasm, "pop dword ebx\n");
  }
  fprintf(fpasm, "and ebx, ecx\n");
  fprintf(fpasm, "push dword ebx\n");
}

void cambiar_signo(FILE* fpasm, int es_variable){
  /* Si es un registro guarda v en ebx*/
  if(es_variable == 1){
    /* Se guarda la referencia en eax*/
   fprintf(fpasm, "pop dword eax\n");
   /*Se accede a la referencia con [] */
   fprintf(fpasm, "mov dword ebx, [eax]\n");
  }
  /* Si es un valor solo se extrae en ebx */
  else if(es_variable == 0){
     fprintf(fpasm, "pop dword ebx\n");
  }

  fprintf(fpasm, "neg ebx\n");
  fprintf(fpasm, "push dword ebx\n");
}

void no(FILE* fpasm, int es_variable, int cuantos_no){
  /* Si es un registro guarda v en ebx*/
  if(es_variable == 1){
   fprintf(fpasm, "pop dword eax\n");
   fprintf(fpasm, "mov dword ebx, [eax]\n");
  }
  /* Si es un valor solo se extrae en ebx */
  else if(es_variable == 0){
     fprintf(fpasm, "pop dword ebx\n");
  }

  fprintf(fpasm, "cmp ebx, 0\n");
  /* Si son iguales escribe un 1 en la pila */
  fprintf(fpasm, "je no_uno_%d\n", cuantos_no);
  /* Sino escribe un 0 */
  fprintf(fpasm, "push dword 0\n");
  fprintf(fpasm, "jmp no_%d\n", cuantos_no);
  fprintf(fpasm, "no_uno_%d:\n", cuantos_no);
  fprintf(fpasm, "push dword 1\n");
  fprintf(fpasm, "no_%d:\n", cuantos_no);
}

void igual(FILE* fpasm, int es_variable_1, int es_variable_2, int etiqueta){
  /* Si es un registro guarda v en ebx*/
  if(es_variable_2 == 1){
   fprintf(fpasm, "pop dword eax\n");
   fprintf(fpasm, "mov dword ecx, [eax]\n");
  }
  /* Si es un valor solo se extrae en ebx */
  else if(es_variable_2 == 0){
     fprintf(fpasm, "pop dword ecx\n");
  }
  /* Si es un registro guarda v2 en ecx*/
  if(es_variable_1 == 1){
   fprintf(fpasm, "pop dword eax\n");
   fprintf(fpasm, "mov dword ebx, [eax]\n");
  }
  /* Si es un valor solo se extrae en ecx */
  else if(es_variable_1 == 0){
     fprintf(fpasm, "pop dword ebx\n");
  }
  fprintf(fpasm, "cmp ebx, ecx\n");
  /* USANDO SET
  fprintf(fpasm, "sete eax\n");
  fprintf(fpasm, "push eax 0\n"); */
  /* USANDO JUMPS */
  fprintf(fpasm, "je igual_escribe_%d\n", etiqueta);
  fprintf(fpasm, "push dword 0\n");
  fprintf(fpasm, "jmp igual_%d\n", etiqueta);
  fprintf(fpasm, "igual_escribe_%d:\n", etiqueta);
  fprintf(fpasm, "push dword 1\n");
  fprintf(fpasm, "igual_%d:\n", etiqueta);
}


void distinto(FILE* fpasm, int es_variable_1, int es_variable_2, int etiqueta){
  /* Si es un registro guarda v en ebx*/
  if(es_variable_2 == 1){
   fprintf(fpasm, "pop dword eax\n");
   fprintf(fpasm, "mov dword ecx, [eax]\n");
  }
  /* Si es un valor solo se extrae en ebx */
  else if(es_variable_2 == 0){
     fprintf(fpasm, "pop dword ecx\n");
  }
  /* Si es un registro guarda v2 en ecx*/
  if(es_variable_1 == 1){
   fprintf(fpasm, "pop dword eax\n");
   fprintf(fpasm, "mov dword ebx, [eax]\n");
  }
  /* Si es un valor solo se extrae en ecx */
  else if(es_variable_1 == 0){
     fprintf(fpasm, "pop dword ebx\n");
  }
  fprintf(fpasm, "cmp ebx, ecx\n");
  /* USANDO SET
  fprintf(fpasm, "setne eax\n");
  fprintf(fpasm, "push eax 0\n");*/
  /* USANDO JUMPS */
  fprintf(fpasm, "jne distinto_escribe_%d\n", etiqueta);
  fprintf(fpasm, "push dword 0\n");
  fprintf(fpasm, "jmp distinto_%d\n", etiqueta);
  fprintf(fpasm, "distinto_escribe_%d:\n", etiqueta);
  fprintf(fpasm, "push dword 1\n");
  fprintf(fpasm, "distinto_%d:\n", etiqueta);
}


void menor_igual(FILE* fpasm, int es_variable_1, int es_variable_2, int etiqueta){
  /* Si es un registro guarda v en ebx*/
  if(es_variable_2 == 1){
   fprintf(fpasm, "pop dword eax\n");
   fprintf(fpasm, "mov dword ecx, [eax]\n");
  }
  /* Si es un valor solo se extrae en ebx */
  else if(es_variable_2 == 0){
     fprintf(fpasm, "pop dword ecx\n");
  }
  /* Si es un registro guarda v2 en ecx*/
  if(es_variable_1 == 1){
   fprintf(fpasm, "pop dword eax\n");
   fprintf(fpasm, "mov dword ebx, [eax]\n");
  }
  /* Si es un valor solo se extrae en ecx */
  else if(es_variable_1 == 0){
     fprintf(fpasm, "pop dword ebx\n");
  }
  fprintf(fpasm, "cmp ebx, ecx\n");
  /* USANDO SET
  fprintf(fpasm, "setle eax\n");
  fprintf(fpasm, "push eax 0\n");*/
  /* USANDO JUMPS */
  fprintf(fpasm, "jle menorigual_escribe_%d\n", etiqueta);
  fprintf(fpasm, "push dword 0\n");
  fprintf(fpasm, "jmp menorigual_%d\n", etiqueta);
  fprintf(fpasm, "menorigual_escribe_%d:\n", etiqueta);
  fprintf(fpasm, "push dword 1\n");
  fprintf(fpasm, "menorigual_%d:\n", etiqueta);
}


void mayor_igual(FILE* fpasm, int es_variable_1, int es_variable_2, int etiqueta){
  /* Si es un registro guarda v en ebx*/
  if(es_variable_2 == 1){
   fprintf(fpasm, "pop dword eax\n");
   fprintf(fpasm, "mov dword ecx, [eax]\n");
  }
  /* Si es un valor solo se extrae en ebx */
  else if(es_variable_2 == 0){
     fprintf(fpasm, "pop dword ecx\n");
  }
  /* Si es un registro guarda v2 en ecx*/
  if(es_variable_1 == 1){
   fprintf(fpasm, "pop dword eax\n");
   fprintf(fpasm, "mov dword ebx, [eax]\n");
  }
  /* Si es un valor solo se extrae en ecx */
  else if(es_variable_1 == 0){
     fprintf(fpasm, "pop dword ebx\n");
  }
  fprintf(fpasm, "cmp ebx, ecx\n");
  /* USANDO SET
  fprintf(fpasm, "setge eax\n");
  fprintf(fpasm, "push eax 0\n"); */
  /* USANDO JUMPS */
  fprintf(fpasm, "jge mayorigual_escribe_%d\n", etiqueta);
  fprintf(fpasm, "push dword 0\n");
  fprintf(fpasm, "jmp mayorigual_%d\n", etiqueta);
  fprintf(fpasm, "mayorigual_escribe_%d:\n", etiqueta);
  fprintf(fpasm, "push dword 1\n");
  fprintf(fpasm, "mayorigual_%d:\n", etiqueta);
}
void menor(FILE* fpasm, int es_variable_1, int es_variable_2, int etiqueta){
  /* Si es un registro guarda v en ebx*/
  if(es_variable_2 == 1){
   fprintf(fpasm, "pop dword eax\n");
   fprintf(fpasm, "mov dword ecx, [eax]\n");
  }
  /* Si es un valor solo se extrae en ebx */
  else if(es_variable_2 == 0){
     fprintf(fpasm, "pop dword ecx\n");
  }
  /* Si es un registro guarda v2 en ecx*/
  if(es_variable_1 == 1){
   fprintf(fpasm, "pop dword eax\n");
   fprintf(fpasm, "mov dword ebx, [eax]\n");
  }
  /* Si es un valor solo se extrae en ecx */
  else if(es_variable_1 == 0){
     fprintf(fpasm, "pop dword ebx\n");
  }
  fprintf(fpasm, "cmp ebx, ecx\n");
  /* USANDO SET
  fprintf(fpasm, "setl eax\n");
  fprintf(fpasm, "push eax 0\n");*/
  /* USANDO JUMPS */
  fprintf(fpasm, "jl menor_escribe_%d\n", etiqueta);
  fprintf(fpasm, "push dword 0\n");
  fprintf(fpasm, "jmp menor_%d\n", etiqueta);
  fprintf(fpasm, "menor_escribe_%d:\n", etiqueta);
  fprintf(fpasm, "push dword 1\n");
  fprintf(fpasm, "menor_%d:\n", etiqueta);
}

void mayor(FILE* fpasm, int es_variable_1, int es_variable_2, int etiqueta){
  /* Si es un registro guarda v en ebx*/
  if(es_variable_2 == 1){
   fprintf(fpasm, "pop dword eax\n");
   fprintf(fpasm, "mov dword ecx, [eax]\n");
  }
  /* Si es un valor solo se extrae en ebx */
  else if(es_variable_2 == 0){
     fprintf(fpasm, "pop dword ecx\n");
  }
  /* Si es un registro guarda v2 en ecx*/
  if(es_variable_1 == 1){
   fprintf(fpasm, "pop dword eax\n");
   fprintf(fpasm, "mov dword ebx, [eax]\n");
  }
  /* Si es un valor solo se extrae en ecx */
  else if(es_variable_1 == 0){
     fprintf(fpasm, "pop dword ebx\n");
  }
  fprintf(fpasm, "cmp ebx, ecx\n");
  /* USANDO SET
  fprintf(fpasm, "setg eax\n");
  fprintf(fpasm, "push eax 0\n");*/
  /* USANDO JUMPS */
  fprintf(fpasm, "jg mayor_escribe_%d\n", etiqueta);
  fprintf(fpasm, "push dword 0\n");
  fprintf(fpasm, "jmp mayor_%d\n", etiqueta);
  fprintf(fpasm, "mayor_escribe_%d:\n", etiqueta);
  fprintf(fpasm, "push dword 1\n");
  fprintf(fpasm, "mayor_%d:\n", etiqueta);
}

void leer(FILE* fpasm, char* nombre, int tipo){
  /* Se prepara la pila */
  fprintf(fpasm, "push dword _%s\n", nombre);
  /* Llamada a alfalib.o (distinta para enteros y booleanos) */
  if (tipo == ENTERO) {
    fprintf(fpasm, "call scan_int\n");
  } else if (tipo == BOOLEANO) {
    fprintf(fpasm, "call scan_boolean\n");
  }
  /* Restaurar la pila */
  fprintf(fpasm, "add esp, 4\n");
}

void escribir(FILE* fpasm, int es_variable, int tipo){
  /* Si es un registro guarda v en ebx*/
  if(es_variable == 1){
   fprintf(fpasm, "pop dword eax\n");
   fprintf(fpasm, "mov dword ebx, [eax]\n");
   fprintf(fpasm, "push dword ebx\n");
  }
  /* Se prepara la pila */
  /* Llamada a alfalib.o (distinta para enteros y booleanos) */
  if (tipo == ENTERO) {
    fprintf(fpasm, "call print_int\n");
  } else if (tipo == BOOLEANO) {
    fprintf(fpasm, "call print_boolean\n");
  }
  /* Restaurar la pila */
  fprintf(fpasm, "add esp, 4\n");
  /* Imprimir un salto de linea */
  fprintf(fpasm, "call print_endofline\n");
}


void ifthenelse_inicio(FILE * fpasm, int exp_es_variable, int etiqueta){//
  fprintf(fpasm, "pop eax\n");
  if(exp_es_variable == 1)
    fprintf(fpasm, "mov eax,[eax]\n");

  fprintf(fpasm, "cmp eax, 0\n");
  fprintf(fpasm, "je near fin_then_%d\n",etiqueta);
}

void ifthen_inicio(FILE * fpasm, int exp_es_variable, int etiqueta){//
  fprintf(fpasm, "pop eax\n");
  if(exp_es_variable == 1)
    fprintf(fpasm, "mov eax,[eax]\n");

  fprintf(fpasm, "cmp eax, 0\n");
  fprintf(fpasm, "je near fin_then_%d\n",etiqueta);

}

void ifthen_fin(FILE * fpasm, int etiqueta){//
  fprintf(fpasm, "fin_then_%d:\n",etiqueta);
}

void ifthenelse_fin_then( FILE * fpasm, int etiqueta){//
  fprintf(fpasm, "jmp near fin_ifelse_%d\n",etiqueta);
  fprintf(fpasm, "fin_then_%d:\n",etiqueta);
}

void ifthenelse_fin( FILE * fpasm, int etiqueta){//
  fprintf(fpasm, "fin_ifelse_%d:\n",etiqueta);
}

void while_inicio(FILE * fpasm, int etiqueta){//
  fprintf(fpasm, "while_inicio_%d:\n",etiqueta);
}

void while_exp_pila (FILE * fpasm, int exp_es_variable, int etiqueta){

  /* Si es un registro guarda v en ebx*/
  if(exp_es_variable == 1){
   fprintf(fpasm, "pop dword eax\n");
   fprintf(fpasm, "mov dword ebx, [eax]\n");
  }
  /* Si es un valor solo se extrae en ebx */
  else if(exp_es_variable == 0){
     fprintf(fpasm, "pop dword ebx\n");
  }
  /* Si son iguales saltamos al final del while */
  fprintf(fpasm, "cmp ebx, 0\n");
  fprintf(fpasm, "je while_fin_%d\n", etiqueta);
}

void while_fin( FILE * fpasm, int etiqueta){
  fprintf(fpasm, "jmp while_inicio_%d\n", etiqueta);
  fprintf(fpasm, "while_fin_%d:\n", etiqueta);
}

void escribir_elemento_vector(FILE * fpasm,char * nombre_vector, int tam_max, int exp_es_direccion){
  fprintf(fpasm, "pop dword eax\n");
  /* Si es < 0 el programa continua */
  if(exp_es_direccion == 1){
    fprintf(fpasm, "mov dword eax, [eax]\n");
  }
  /* Si son iguales saltamos al error */
  fprintf(fpasm, "cmp eax, 0\n");
  fprintf(fpasm, "jl fin_indice_fuera_rango\n");
  /* Si el indice es mayor se termina el programa */
  fprintf(fpasm, "cmp eax, %d-1\n", tam_max);
  fprintf(fpasm, "jg fin_indice_fuera_rango\n");

  fprintf(fpasm, "mov edx, _%s\n", nombre_vector);
  fprintf(fpasm, "lea eax, [edx + eax*4]\n");
  fprintf(fpasm, "push dword eax\n");
}

void declararFuncion(FILE * fd_asm, char * nombre_funcion, int num_var_loc){
  /* etiqueta de la funcion */
  fprintf(fd_asm, "_%s:\n", nombre_funcion);
  fprintf(fd_asm, "push ebp\n");
  fprintf(fd_asm, "mov ebp, esp\n");
  /* Reservar espacio para las variables locales en pila */
  fprintf(fd_asm, "sub esp, 4*%d\n", num_var_loc);
}

void retornarFuncion(FILE * fd_asm, int es_variable){
  fprintf(fd_asm, "pop dword eax\n");
  if (es_variable)
      fprintf(fd_asm, "mov eax, [eax]\n");
  fprintf(fd_asm, "mov esp, ebp\n");
  fprintf(fd_asm, "pop dword ebp\n");
  fprintf(fd_asm, "ret\n");
}

void escribirParametro(FILE* fpasm, int pos_parametro, int num_total_parametros){
  int d_ebp;

  d_ebp = 4*(1 + num_total_parametros - pos_parametro);
  fprintf(fpasm, "lea eax, [ebp + %d]\n", d_ebp);
  fprintf(fpasm, "push dword eax\n");
}

void escribirVariableLocal(FILE* fpasm, int posicion_variable_local){
  int d_ebp;

  d_ebp = 4*posicion_variable_local;
  fprintf(fpasm, "lea eax, [ebp - %d]\n", d_ebp);
  fprintf(fpasm, "push dword eax\n");
}

void asignarDestinoEnPila(FILE* fpasm, int es_variable){
  fprintf(fpasm, "pop dword eax\n");
  fprintf(fpasm, "pop dword ebx\n");
  if(es_variable == 1){
    fprintf(fpasm, "mov ebx, [ebx]\n");
  }
  fprintf(fpasm, "mov [eax], ebx\n");
}

void operandoEnPilaAArgumento(FILE * fd_asm, int es_variable){
  if (es_variable == 1) {
    fprintf(fd_asm, "pop eax\n");
    fprintf(fd_asm, "mov eax, [eax]\n");
    fprintf(fd_asm, "push eax\n");
  }
}

void llamarFuncion(FILE * fd_asm, char * nombre_funcion, int num_argumentos){
  fprintf(fd_asm, "call _%s\n", nombre_funcion);
  limpiarPila(fd_asm, num_argumentos);
  fprintf(fd_asm, "push dword eax\n");
}

void limpiarPila(FILE * fd_asm, int num_argumentos){
  fprintf(fd_asm, "add esp, %d\n", num_argumentos*4);
}
