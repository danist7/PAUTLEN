;D:	main
segment .data
mensaje_error_div_0 dd "División por cero",0
mensaje_error_fuera_rango dd "Indice fuera de rango",0
segment .bss
__esp resd 1
;D:	{
;D:	boolean
;R11:	<tipo> ::= boolean
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	resultado
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_resultado resd 1
;D:	;
;R18:	<identificadores> ::= <identificador>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	array
;D:	boolean
;R11:	<tipo> ::= boolean
;D:	[
;D:	3
;D:	]
;R15:	<clase_vector> ::= array <tipo> [ <constante_entera> ]
;R7:	<clase> ::= <clase_vector>
;D:	vector
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_vector resd 1
;D:	;
;R18:	<identificadores> ::= <identificador>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	function
;R2:	<declaraciones> ::= <declaracion>
;R3:	<declaraciones> ::= <declaracion> <declaraciones>
segment .text
global main
extern scan_int, scan_boolean
extern print_int, print_boolean, print_string, print_blank, print_endofline
;D:	boolean
;R11:	<tipo> ::= boolean
;D:	or
;D:	(
;D:	boolean
;R11:	<tipo> ::= boolean
;D:	b1
;R27:	<parametro_funcion> ::= <tipo> <identificador>
;D:	;
;D:	boolean
;R11:	<tipo> ::= boolean
;D:	b2
;R27:	<parametro_funcion> ::= <tipo> <identificador>
;D:	;
;D:	boolean
;R11:	<tipo> ::= boolean
;D:	b3
;R27:	<parametro_funcion> ::= <tipo> <identificador>
;D:	)
;R26:	<resto_parametros_funcion> ::= 
;R25:	<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>
;R25:	<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>
;R23:	<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>
;D:	{
;D:	boolean
;R11:	<tipo> ::= boolean
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	a
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	a
;R2:	<declaraciones> ::= <declaracion>
;R28:	<declaraciones_funcion> ::= <declaraciones>
_or:
push ebp
mov ebp, esp
sub esp, 4*1
;D:	=
;D:	b1
;D:	||
;R80:	<exp> ::= <identificador>
lea eax, [ebp + 16]
push dword eax
;D:	b2
;D:	||
;R80:	<exp> ::= <identificador>
lea eax, [ebp + 12]
push dword eax
;R78:	<exp> ::= <exp> || <exp>
pop dword eax
mov dword ecx, [eax]
pop dword eax
mov dword ebx, [eax]
or ebx, ecx
push dword ebx
;D:	b3
;D:	;
;R80:	<exp> ::= <identificador>
lea eax, [ebp + 8]
push dword eax
;R78:	<exp> ::= <exp> || <exp>
pop dword eax
mov dword ecx, [eax]
pop dword ebx
or ebx, ecx
push dword ebx
;R43:	<asignacion> ::= <identificador> = <exp>
lea eax, [ebp - 4]
push dword eax
pop dword eax
pop dword ebx
mov [eax], ebx
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	return
;D:	a
;D:	;
;R80:	<exp> ::= <identificador>
lea eax, [ebp - 4]
push dword eax
;R61:	<retorno_funcion> ::= return <exp>
pop dword eax
mov eax, [eax]
mov esp, ebp
pop dword ebp
ret
;R38:	<sentencia_simple> ::= <retorno_funcion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R22:	<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }
;D:	vector
;R21:	<funciones> ::= 
;R20:	<funciones> ::= <funcion> <funciones>
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
;D:	false
;R103:	<constante_logica> ::= false
mov dword eax, 0
push dword eax
;R99:	<constante> ::= <constante_logica>
;R81:	<exp> ::= <constante>
;D:	;
;R44:	<asignacion> ::= <elemento_vector> = <exp>
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	vector
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
;D:	true
;R102:	<constante_logica> ::= true
mov dword eax, 1
push dword eax
;R99:	<constante> ::= <constante_logica>
;R81:	<exp> ::= <constante>
;D:	;
;R44:	<asignacion> ::= <elemento_vector> = <exp>
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	vector
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
;D:	false
;R103:	<constante_logica> ::= false
mov dword eax, 0
push dword eax
;R99:	<constante> ::= <constante_logica>
;R81:	<exp> ::= <constante>
;D:	;
;R44:	<asignacion> ::= <elemento_vector> = <exp>
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	resultado
;D:	=
;D:	or
;D:	(
;D:	vector
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
;D:	,
;D:	vector
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
;D:	,
;D:	vector
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
;D:	)
;R92:	<resto_lista_expresiones> ::= 
;R91:	<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>
;R91:	<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
;R88:	<exp> ::= <identificador> ( <lista_expresiones> )
call _or
add esp, 12
push dword eax
add esp, 12
;D:	;
;R43:	<asignacion> ::= <identificador> = <exp>
