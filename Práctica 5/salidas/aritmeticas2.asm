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
;D:	,
;D:	z
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_z resd 1
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
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
;D:	scanf
;D:	y
;R54:	<lectura> ::= scanf <identificador>
push dword _y
call scan_int
add esp, 4
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	scanf
;D:	z
;R54:	<lectura> ::= scanf <identificador>
push dword _z
call scan_int
add esp, 4
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	x
;D:	+
;R80:	<exp> ::= <identificador>
push dword _x
;D:	y
;D:	*
;R80:	<exp> ::= <identificador>
push dword _y
;D:	z
;D:	;
;R80:	<exp> ::= <identificador>
push dword _z
;R75:	<exp> ::= <exp> * <exp>
pop dword ebx
mov dword ecx, [ebx]
pop dword ebx
mov dword eax, [ebx]
imul ecx
push dword eax
;R72:	<exp> ::= <exp> + <exp>
pop dword ecx
pop dword eax
mov dword ebx, [eax]
add ebx, ecx
push dword ebx
;R56:	<escritura> ::= printf <exp>
call print_int
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	(
;D:	x
;D:	+
;R80:	<exp> ::= <identificador>
push dword _x
;D:	y
;D:	)
;R80:	<exp> ::= <identificador>
push dword _y
;R72:	<exp> ::= <exp> + <exp>
pop dword eax
mov dword ecx, [eax]
pop dword eax
mov dword ebx, [eax]
add ebx, ecx
push dword ebx
;R82:	<exp> ::= ( <exp> )
;D:	*
;D:	z
;D:	;
;R80:	<exp> ::= <identificador>
push dword _z
;R75:	<exp> ::= <exp> * <exp>
pop dword ebx
mov dword ecx, [ebx]
pop dword eax
imul ecx
push dword eax
;R56:	<escritura> ::= printf <exp>
call print_int
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	-
;D:	x
;D:	*
;R80:	<exp> ::= <identificador>
push dword _x
;D:	y
;D:	*
;R80:	<exp> ::= <identificador>
push dword _y
;R75:	<exp> ::= <exp> * <exp>
pop dword ebx
mov dword ecx, [ebx]
pop dword ebx
mov dword eax, [ebx]
imul ecx
push dword eax
;D:	-
;D:	z
;D:	;
;R80:	<exp> ::= <identificador>
push dword _z
;R76:	<exp> ::= - <exp>
pop dword eax
mov dword ebx, [eax]
neg ebx
push dword ebx
;R75:	<exp> ::= <exp> * <exp>
pop dword ecx
pop dword eax
imul ecx
push dword eax
;R76:	<exp> ::= - <exp>
pop dword ebx
neg ebx
push dword ebx
;R56:	<escritura> ::= printf <exp>
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
