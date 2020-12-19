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
;D:	100
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
mov dword eax, 100
push dword eax
;D:	]
;R15:	<clase_vector> ::= array <tipo> [ <constante_entera> ]
