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
;D:	if
;D:	(
;D:	(
;D:	x
;D:	==
;R80:	<exp> ::= <identificador>
push dword _x
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 0
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R93:	<comparacion> ::= <exp> == <exp>
pop dword ecx
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
je igual_escribe_0
push dword 0
jmp igual_0
igual_escribe_0:
push dword 1
igual_0:
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;D:	(
;D:	y
;D:	==
;R80:	<exp> ::= <identificador>
push dword _y
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 0
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R93:	<comparacion> ::= <exp> == <exp>
pop dword ecx
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
je igual_escribe_1
push dword 0
jmp igual_1
igual_escribe_1:
push dword 1
igual_1:
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;R77:	<exp> ::= exp> && <exp>
pop dword ecx
pop dword ebx
and ebx, ecx
push dword ebx
;D:	(
;D:	z
;D:	==
;R80:	<exp> ::= <identificador>
push dword _z
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 0
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R93:	<comparacion> ::= <exp> == <exp>
pop dword ecx
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
je igual_escribe_2
push dword 0
jmp igual_2
igual_escribe_2:
push dword 1
igual_2:
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;R77:	<exp> ::= exp> && <exp>
pop dword ecx
pop dword ebx
and ebx, ecx
push dword ebx
pop eax
cmp eax, 0
je near fin_then_3
;D:	{
;D:	printf
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 0
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
call print_int
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	else
jmp near fin_ifelse_3
fin_then_3:
;D:	{
;D:	if
;D:	(
;D:	(
;D:	x
;D:	>
;R80:	<exp> ::= <identificador>
push dword _x
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 0
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R98:	<comparacion> ::= <exp> > <exp>
pop dword ecx
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
jg mayor_escribe_4
push dword 0
jmp mayor_4
mayor_escribe_4:
push dword 1
mayor_4:
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;D:	(
;D:	y
;D:	>
;R80:	<exp> ::= <identificador>
push dword _y
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 0
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R98:	<comparacion> ::= <exp> > <exp>
pop dword ecx
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
jg mayor_escribe_5
push dword 0
jmp mayor_5
mayor_escribe_5:
push dword 1
mayor_5:
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;R77:	<exp> ::= exp> && <exp>
pop dword ecx
pop dword ebx
and ebx, ecx
push dword ebx
pop eax
cmp eax, 0
je near fin_then_6
;D:	{
;D:	if
;D:	(
;D:	(
;D:	z
;D:	>
;R80:	<exp> ::= <identificador>
push dword _z
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 0
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R98:	<comparacion> ::= <exp> > <exp>
pop dword ecx
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
jg mayor_escribe_7
push dword 0
jmp mayor_7
mayor_escribe_7:
push dword 1
mayor_7:
;R83:	<exp> ::= ( <comparacion> )
;D:	)
pop eax
cmp eax, 0
je near fin_then_8
;D:	{
;D:	printf
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 1
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
call print_int
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	else
jmp near fin_ifelse_8
fin_then_8:
;D:	{
;D:	printf
;D:	5
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 5
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
call print_int
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
fin_ifelse_8:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	if
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
fin_then_6:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	(
;D:	(
;D:	x
;D:	<
;R80:	<exp> ::= <identificador>
push dword _x
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 0
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R97:	<comparacion> ::= <exp> < <exp>
pop dword ecx
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
jl menor_escribe_9
push dword 0
jmp menor_9
menor_escribe_9:
push dword 1
menor_9:
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;D:	(
;D:	y
;D:	>
;R80:	<exp> ::= <identificador>
push dword _y
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 0
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R98:	<comparacion> ::= <exp> > <exp>
pop dword ecx
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
jg mayor_escribe_10
push dword 0
jmp mayor_10
mayor_escribe_10:
push dword 1
mayor_10:
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;R77:	<exp> ::= exp> && <exp>
pop dword ecx
pop dword ebx
and ebx, ecx
push dword ebx
pop eax
cmp eax, 0
je near fin_then_11
;D:	{
;D:	if
;D:	(
;D:	(
;D:	z
;D:	>
;R80:	<exp> ::= <identificador>
push dword _z
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 0
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R98:	<comparacion> ::= <exp> > <exp>
pop dword ecx
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
jg mayor_escribe_12
push dword 0
jmp mayor_12
mayor_escribe_12:
push dword 1
mayor_12:
;R83:	<exp> ::= ( <comparacion> )
;D:	)
pop eax
cmp eax, 0
je near fin_then_13
;D:	{
;D:	printf
;D:	2
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 2
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
call print_int
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	else
jmp near fin_ifelse_13
fin_then_13:
;D:	{
;D:	printf
;D:	6
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 6
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
call print_int
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
fin_ifelse_13:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	if
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
fin_then_11:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	(
;D:	(
;D:	x
;D:	<
;R80:	<exp> ::= <identificador>
push dword _x
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 0
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R97:	<comparacion> ::= <exp> < <exp>
pop dword ecx
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
jl menor_escribe_14
push dword 0
jmp menor_14
menor_escribe_14:
push dword 1
menor_14:
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;D:	(
;D:	y
;D:	<
;R80:	<exp> ::= <identificador>
push dword _y
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 0
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R97:	<comparacion> ::= <exp> < <exp>
pop dword ecx
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
jl menor_escribe_15
push dword 0
jmp menor_15
menor_escribe_15:
push dword 1
menor_15:
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;R77:	<exp> ::= exp> && <exp>
pop dword ecx
pop dword ebx
and ebx, ecx
push dword ebx
pop eax
cmp eax, 0
je near fin_then_16
;D:	{
;D:	if
;D:	(
;D:	(
;D:	z
;D:	>
;R80:	<exp> ::= <identificador>
push dword _z
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 0
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R98:	<comparacion> ::= <exp> > <exp>
pop dword ecx
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
jg mayor_escribe_17
push dword 0
jmp mayor_17
mayor_escribe_17:
push dword 1
mayor_17:
;R83:	<exp> ::= ( <comparacion> )
;D:	)
pop eax
cmp eax, 0
je near fin_then_18
;D:	{
;D:	printf
;D:	3
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 3
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
call print_int
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	else
jmp near fin_ifelse_18
fin_then_18:
;D:	{
;D:	printf
;D:	7
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 7
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
call print_int
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
fin_ifelse_18:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	if
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
fin_then_16:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	(
;D:	(
;D:	x
;D:	>
;R80:	<exp> ::= <identificador>
push dword _x
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 0
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R98:	<comparacion> ::= <exp> > <exp>
pop dword ecx
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
jg mayor_escribe_19
push dword 0
jmp mayor_19
mayor_escribe_19:
push dword 1
mayor_19:
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;D:	(
;D:	y
;D:	<
;R80:	<exp> ::= <identificador>
push dword _y
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 0
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R97:	<comparacion> ::= <exp> < <exp>
pop dword ecx
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
jl menor_escribe_20
push dword 0
jmp menor_20
menor_escribe_20:
push dword 1
menor_20:
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;R77:	<exp> ::= exp> && <exp>
pop dword ecx
pop dword ebx
and ebx, ecx
push dword ebx
pop eax
cmp eax, 0
je near fin_then_21
;D:	{
;D:	if
;D:	(
;D:	(
;D:	z
;D:	>
;R80:	<exp> ::= <identificador>
push dword _z
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 0
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R98:	<comparacion> ::= <exp> > <exp>
pop dword ecx
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
jg mayor_escribe_22
push dword 0
jmp mayor_22
mayor_escribe_22:
push dword 1
mayor_22:
;R83:	<exp> ::= ( <comparacion> )
;D:	)
pop eax
cmp eax, 0
je near fin_then_23
;D:	{
;D:	printf
;D:	4
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 4
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
call print_int
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	else
jmp near fin_ifelse_23
fin_then_23:
;D:	{
;D:	printf
;D:	8
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 8
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
call print_int
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
fin_ifelse_23:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	}
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
fin_then_21:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;R30:	<sentencias> ::= <sentencia>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
fin_ifelse_3:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia>
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
