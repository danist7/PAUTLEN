;D:	main
segment .data
mensaje_error_div_0 dd "División por cero",0
mensaje_error_fuera_rango dd "Indice fuera de rango",0
segment .bss
__esp resd 1
;D:	{
;D:	array
;D:	int
;R10:	<tipo> ::= int
;D:	[
;D:	3
;D:	]
;R15:	<clase_vector> ::= array <tipo> [ <constante_entera> ]
;R7:	<clase> ::= <clase_vector>
;D:	vector1
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_vector1 resd 3
;D:	;
;R18:	<identificadores> ::= <identificador>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	vector1
;R2:	<declaraciones> ::= <declaracion>
segment .text
global main
extern scan_int, scan_boolean
extern print_int, print_boolean, print_string, print_blank, print_endofline
;R21:	<funciones> ::= 
main:
mov [__esp], esp
;D:	[
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 0
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	]
;R48:	<elemento_vector> ::= <identificador> [ <exp> ]
;D:	=
;D:	10
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 10
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R44:	<asignacion> ::= <elemento_vector> = <exp>
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	vector1
;D:	[
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 1
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	]
;R48:	<elemento_vector> ::= <identificador> [ <exp> ]
;D:	=
;D:	20
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 20
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R44:	<asignacion> ::= <elemento_vector> = <exp>
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	vector1
;D:	[
;D:	2
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 2
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	]
;R48:	<elemento_vector> ::= <identificador> [ <exp> ]
;D:	=
;D:	30
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 30
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R44:	<asignacion> ::= <elemento_vector> = <exp>
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	vector1
;D:	[
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 0
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	]
;R48:	<elemento_vector> ::= <identificador> [ <exp> ]
;R85:	<exp> ::= <elemento_vector>
;D:	;
;R56:	<escritura> ::= printf <exp>
pop eax
mov eax, [eax]
push eax
call print_int
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	vector1
;D:	[
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 1
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	]
;R48:	<elemento_vector> ::= <identificador> [ <exp> ]
;R85:	<exp> ::= <elemento_vector>
;D:	;
;R56:	<escritura> ::= printf <exp>
pop eax
mov eax, [eax]
push eax
call print_int
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	vector1
;D:	[
;D:	2
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 2
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	]
;R48:	<elemento_vector> ::= <identificador> [ <exp> ]
;R85:	<exp> ::= <elemento_vector>
;D:	;
;R56:	<escritura> ::= printf <exp>
pop eax
mov eax, [eax]
push eax
call print_int
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R1:	<programa> ::= main { <declaraciones> <funciones> <sentencias> }
jmp near fin
error_div_0: push dword mensaje_error_div_0
call print_string
add esp, 4
jmp near fin
fin_indice_fuera_rango: push dword mensaje_error_fuera_rango
call print_string
add esp, 4
jmp near fin
fin: mov esp, [__esp]
ret
