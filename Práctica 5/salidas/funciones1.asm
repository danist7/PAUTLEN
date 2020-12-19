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
;D:	resultado
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_resultado resd 1
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
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
;D:	suma
;D:	(
;D:	int
;R10:	<tipo> ::= int
;D:	num1
;R27:	<parametro_funcion> ::= <tipo> <identificador>
;D:	;
;D:	int
;R10:	<tipo> ::= int
;D:	num2
;R27:	<parametro_funcion> ::= <tipo> <identificador>
;D:	)
;R26:	<resto_parametros_funcion> ::= 
;R25:	<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>
;R23:	<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>
;D:	{
;D:	return
;R29:	<declaraciones_funcion> ::= 
_suma:
push ebp
mov ebp, esp
sub esp, 4*0
;D:	num1
;D:	+
;R80:	<exp> ::= <identificador>
lea eax, [ebp + 12]
push dword eax
;D:	num2
;D:	;
;R80:	<exp> ::= <identificador>
lea eax, [ebp + 8]
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
;R22:	<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }
;D:	x
;R21:	<funciones> ::= 
;R20:	<funciones> ::= <funcion> <funciones>
main:
mov [__esp], esp
;D:	=
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 1
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
;D:	3
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 3
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R43:	<asignacion> ::= <identificador> = <exp>
pop dword [_y]
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	resultado
;D:	=
;D:	suma
;D:	(
;D:	x
;D:	,
;R80:	<exp> ::= <identificador>
push dword _x
pop eax
mov eax, [eax]
push eax
;D:	y
;D:	)
;R80:	<exp> ::= <identificador>
push dword _y
pop eax
mov eax, [eax]
push eax
;R92:	<resto_lista_expresiones> ::= 
;R91:	<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
;R88:	<exp> ::= <identificador> ( <lista_expresiones> )
call _suma
add esp, 8
push dword eax
add esp, 8
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
;D:	resultado
;D:	=
;D:	suma
;D:	(
;D:	x
;D:	,
;R80:	<exp> ::= <identificador>
push dword _x
pop eax
mov eax, [eax]
push eax
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 1
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R92:	<resto_lista_expresiones> ::= 
;R91:	<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
;R88:	<exp> ::= <identificador> ( <lista_expresiones> )
call _suma
add esp, 8
push dword eax
add esp, 8
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
;D:	resultado
;D:	=
;D:	suma
;D:	(
;D:	10
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 10
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	,
;D:	y
;D:	)
;R80:	<exp> ::= <identificador>
push dword _y
pop eax
mov eax, [eax]
push eax
;R92:	<resto_lista_expresiones> ::= 
;R91:	<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
;R88:	<exp> ::= <identificador> ( <lista_expresiones> )
call _suma
add esp, 8
push dword eax
add esp, 8
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
;D:	resultado
;D:	=
;D:	suma
;D:	(
;D:	3
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 3
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	,
;D:	5
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 5
push dword eax
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R92:	<resto_lista_expresiones> ::= 
;R91:	<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
;R88:	<exp> ::= <identificador> ( <lista_expresiones> )
call _suma
add esp, 8
push dword eax
add esp, 8
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
