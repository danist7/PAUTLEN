;D:	main
segment .data
mensaje_error_div_0 dd "División por cero",0
mensaje_error_fuera_rango dd "Indice fuera de rango",0
segment .bss
__esp resd 1
;D:	{
;D:	int
;R10:	<tipo> ::= int
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	x
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_x resd 1
;D:	,
;D:	y
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_y resd 1
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	scanf
;R2:	<declaraciones> ::= <declaracion>
segment .text
global main
extern scan_int, scan_boolean
extern print_int, print_boolean, print_string, print_blank, print_endofline
;R21:	<funciones> ::= 
main:
mov [__esp], esp
;D:	x
;R54:	<lectura> ::= scanf <identificador>
push dword _x
call scan_int
add esp, 4
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	y
;D:	=
;D:	x
;D:	+
;R80:	<exp> ::= <identificador>
lea eax, [ebp - 0]
push dword eax
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 1
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R72:	<exp> ::= <exp> + <exp>
pop dword ecx
pop dword eax
mov dword ebx, [eax]
add ebx, ecx
push dword ebx
;R43:	<asignacion> ::= <identificador> = <exp>
pop dword [_y]
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	y
;D:	;
;R80:	<exp> ::= <identificador>
lea eax, [ebp - 0]
push dword eax
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
