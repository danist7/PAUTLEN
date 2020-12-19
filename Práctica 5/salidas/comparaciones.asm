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
;D:	boolean
;R11:	<tipo> ::= boolean
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	a
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_a resd 1
;D:	;
;R18:	<identificadores> ::= <identificador>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	x
;R2:	<declaraciones> ::= <declaracion>
;R3:	<declaraciones> ::= <declaracion> <declaraciones>
segment .text
global main
extern scan_int, scan_boolean
extern print_int, print_boolean, print_string, print_blank, print_endofline
;R21:	<funciones> ::= 
main:
mov [__esp], esp
;D:	=
;D:	13
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 13
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R43:	<asignacion> ::= <identificador> = <exp>
pop dword [_x]
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	y
;D:	=
;D:	54
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 54
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R43:	<asignacion> ::= <identificador> = <exp>
pop dword [_y]
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	a
;D:	=
;D:	(
;D:	x
;D:	<
;R80:	<exp> ::= <identificador>
push dword _x
;D:	y
;D:	)
;R80:	<exp> ::= <identificador>
push dword _y
;R97:	<comparacion> ::= <exp> < <exp>
pop dword eax
mov dword ecx, [eax]
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
jl menor_escribe_0
push dword 0
jmp menor_0
menor_escribe_0:
push dword 1
menor_0:
;R83:	<exp> ::= ( <comparacion> )
;D:	;
;R43:	<asignacion> ::= <identificador> = <exp>
pop dword [_a]
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	a
;D:	;
;R80:	<exp> ::= <identificador>
push dword _a
;R56:	<escritura> ::= printf <exp>
pop eax
mov eax, [eax]
push eax
call print_boolean
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	a
;D:	=
;D:	(
;D:	x
;D:	<=
;R80:	<exp> ::= <identificador>
push dword _x
;D:	y
;D:	)
;R80:	<exp> ::= <identificador>
push dword _y
;R95:	<comparacion> ::= <exp> <= <exp>
pop dword eax
mov dword ecx, [eax]
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
jle menorigual_escribe_1
push dword 0
jmp menorigual_1
menorigual_escribe_1:
push dword 1
menorigual_1:
;R83:	<exp> ::= ( <comparacion> )
;D:	;
;R43:	<asignacion> ::= <identificador> = <exp>
pop dword [_a]
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	a
;D:	;
;R80:	<exp> ::= <identificador>
push dword _a
;R56:	<escritura> ::= printf <exp>
pop eax
mov eax, [eax]
push eax
call print_boolean
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	a
;D:	=
;D:	(
;D:	x
;D:	!=
;R80:	<exp> ::= <identificador>
push dword _x
;D:	y
;D:	)
;R80:	<exp> ::= <identificador>
push dword _y
;R94:	<comparacion> ::= <exp> != <exp>
pop dword eax
mov dword ecx, [eax]
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
jne distinto_escribe_2
push dword 0
jmp distinto_2
distinto_escribe_2:
push dword 1
distinto_2:
;R83:	<exp> ::= ( <comparacion> )
;D:	;
;R43:	<asignacion> ::= <identificador> = <exp>
pop dword [_a]
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	a
;D:	;
;R80:	<exp> ::= <identificador>
push dword _a
;R56:	<escritura> ::= printf <exp>
pop eax
mov eax, [eax]
push eax
call print_boolean
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	a
;D:	=
;D:	(
;D:	x
;D:	>
;R80:	<exp> ::= <identificador>
push dword _x
;D:	y
;D:	)
;R80:	<exp> ::= <identificador>
push dword _y
;R98:	<comparacion> ::= <exp> > <exp>
pop dword eax
mov dword ecx, [eax]
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
jg mayor_escribe_3
push dword 0
jmp mayor_3
mayor_escribe_3:
push dword 1
mayor_3:
;R83:	<exp> ::= ( <comparacion> )
;D:	;
;R43:	<asignacion> ::= <identificador> = <exp>
pop dword [_a]
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	a
;D:	;
;R80:	<exp> ::= <identificador>
push dword _a
;R56:	<escritura> ::= printf <exp>
pop eax
mov eax, [eax]
push eax
call print_boolean
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	a
;D:	=
;D:	(
;D:	x
;D:	>=
;R80:	<exp> ::= <identificador>
push dword _x
;D:	y
;D:	)
;R80:	<exp> ::= <identificador>
push dword _y
;R96:	<comparacion> ::= <exp> >= <exp>
pop dword eax
mov dword ecx, [eax]
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
jge mayorigual_escribe_4
push dword 0
jmp mayorigual_4
mayorigual_escribe_4:
push dword 1
mayorigual_4:
;R83:	<exp> ::= ( <comparacion> )
;D:	;
;R43:	<asignacion> ::= <identificador> = <exp>
pop dword [_a]
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	a
;D:	;
;R80:	<exp> ::= <identificador>
push dword _a
;R56:	<escritura> ::= printf <exp>
pop eax
mov eax, [eax]
push eax
call print_boolean
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	a
;D:	=
;D:	(
;D:	x
;D:	==
;R80:	<exp> ::= <identificador>
push dword _x
;D:	y
;D:	)
;R80:	<exp> ::= <identificador>
push dword _y
;R93:	<comparacion> ::= <exp> == <exp>
pop dword eax
mov dword ecx, [eax]
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
je igual_escribe_5
push dword 0
jmp igual_5
igual_escribe_5:
push dword 1
igual_5:
;R83:	<exp> ::= ( <comparacion> )
;D:	;
;R43:	<asignacion> ::= <identificador> = <exp>
pop dword [_a]
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	a
;D:	;
;R80:	<exp> ::= <identificador>
push dword _a
;R56:	<escritura> ::= printf <exp>
pop eax
mov eax, [eax]
push eax
call print_boolean
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
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
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
