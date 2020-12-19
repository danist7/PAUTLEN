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
;D:	b
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_b resd 1
;D:	;
;R18:	<identificadores> ::= <identificador>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	function
;R2:	<declaraciones> ::= <declaracion>
segment .text
global main
extern scan_int, scan_boolean
extern print_int, print_boolean, print_string, print_blank, print_endofline
;D:	boolean
;R11:	<tipo> ::= boolean
;D:	imprimir
;D:	(
;D:	)
;R24:	<parametros_funcion> ::= 
;D:	{
;D:	printf
;R29:	<declaraciones_funcion> ::= 
_imprimir:
push ebp
mov ebp, esp
sub esp, 4*0
;D:	1000
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 1000
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
;D:	return
;D:	true
;R102:	<constante_logica> ::= true
mov dword eax, 1
push dword eax
;R99:	<constante> ::= <constante_logica>
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
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R22:	<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }
;D:	b
;R21:	<funciones> ::= 
;R20:	<funciones> ::= <funcion> <funciones>
main:
mov [__esp], esp
;D:	=
;D:	imprimir
;D:	(
;D:	)
;R90:	<lista_expresiones> ::= 
;R88:	<exp> ::= <identificador> ( <lista_expresiones> )
call _imprimir
add esp, 0
push dword eax
add esp, 0
;D:	;
;R43:	<asignacion> ::= <identificador> = <exp>
