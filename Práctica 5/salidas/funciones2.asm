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
;D:	resultado
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_resultado resd 1
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	function
;R2:	<declaraciones> ::= <declaracion>
segment .text
global main
extern scan_int, scan_boolean
extern print_int, print_boolean, print_string, print_blank, print_endofline
;D:	int
;R10:	<tipo> ::= int
;D:	fibonacci
;D:	(
;D:	int
;R10:	<tipo> ::= int
;D:	num1
;R27:	<parametro_funcion> ::= <tipo> <identificador>
;D:	)
;R26:	<resto_parametros_funcion> ::= 
;R23:	<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>
;D:	{
;D:	int
;R10:	<tipo> ::= int
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	res1
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	,
;D:	res2
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	if
;R2:	<declaraciones> ::= <declaracion>
;R28:	<declaraciones_funcion> ::= <declaraciones>
_fibonacci:
push ebp
mov ebp, esp
sub esp, 4*2
;D:	(
;D:	(
;D:	num1
;D:	==
;R80:	<exp> ::= <identificador>
lea eax, [ebp + 8]
push dword eax
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
;D:	)
pop eax
cmp eax, 0
je near fin_then_1
;D:	{
;D:	return
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 0
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R61:	<retorno_funcion> ::= return <exp>
pop dword eax
mov esp, ebp
pop dword ebp
ret
;R38:	<sentencia_simple> ::= <retorno_funcion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	if
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
fin_then_1:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	(
;D:	(
;D:	num1
;D:	==
;R80:	<exp> ::= <identificador>
lea eax, [ebp + 8]
push dword eax
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 1
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
pop eax
cmp eax, 0
je near fin_then_3
;D:	{
;D:	return
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 1
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R61:	<retorno_funcion> ::= return <exp>
pop dword eax
mov esp, ebp
pop dword ebp
ret
;R38:	<sentencia_simple> ::= <retorno_funcion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	res1
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
fin_then_3:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	=
;D:	fibonacci
;D:	(
;D:	num1
;D:	-
;R80:	<exp> ::= <identificador>
lea eax, [ebp + 8]
push dword eax
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 1
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R73:	<exp> ::= <exp> - <exp>
pop dword ecx
pop dword eax
mov dword ebx, [eax]
sub ebx, ecx
push dword ebx
;R92:	<resto_lista_expresiones> ::= 
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
;R88:	<exp> ::= <identificador> ( <lista_expresiones> )
call _fibonacci
add esp, 4
push dword eax
add esp, 4
;D:	;
;R43:	<asignacion> ::= <identificador> = <exp>
lea eax, [ebp - 4]
push dword eax
pop dword eax
pop dword ebx
mov [eax], ebx
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	res2
;D:	=
;D:	fibonacci
;D:	(
;D:	num1
;D:	-
;R80:	<exp> ::= <identificador>
lea eax, [ebp + 8]
push dword eax
;D:	2
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 2
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R73:	<exp> ::= <exp> - <exp>
pop dword ecx
pop dword eax
mov dword ebx, [eax]
sub ebx, ecx
push dword ebx
;R92:	<resto_lista_expresiones> ::= 
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
;R88:	<exp> ::= <identificador> ( <lista_expresiones> )
call _fibonacci
add esp, 4
push dword eax
add esp, 4
;D:	;
;R43:	<asignacion> ::= <identificador> = <exp>
lea eax, [ebp - 8]
push dword eax
pop dword eax
pop dword ebx
mov [eax], ebx
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	return
;D:	res1
;D:	+
;R80:	<exp> ::= <identificador>
lea eax, [ebp - 4]
push dword eax
;D:	res2
;D:	;
;R80:	<exp> ::= <identificador>
lea eax, [ebp - 8]
push dword eax
;R72:	<exp> ::= <exp> + <exp>
pop dword eax
mov dword ecx, [eax]
pop dword eax
mov dword ebx, [eax]
add ebx, ecx
push dword ebx
;R61:	<retorno_funcion> ::= return <exp>
pop dword eax
mov esp, ebp
pop dword ebp
ret
;R38:	<sentencia_simple> ::= <retorno_funcion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R22:	<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }
;D:	scanf
;R21:	<funciones> ::= 
;R20:	<funciones> ::= <funcion> <funciones>
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
;D:	resultado
;D:	=
;D:	fibonacci
;D:	(
;D:	x
;D:	)
;R80:	<exp> ::= <identificador>
push dword _x
pop eax
mov eax, [eax]
push eax
;R92:	<resto_lista_expresiones> ::= 
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
;R88:	<exp> ::= <identificador> ( <lista_expresiones> )
call _fibonacci
add esp, 4
push dword eax
add esp, 4
;D:	;
;R43:	<asignacion> ::= <identificador> = <exp>
pop dword [_resultado]
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	resultado
;D:	;
;R80:	<exp> ::= <identificador>
push dword _resultado
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
