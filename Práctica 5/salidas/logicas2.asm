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
;D:	a
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_a resd 1
;D:	,
;D:	b
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_b resd 1
;D:	,
;D:	c
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_c resd 1
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
;D:	a
;R54:	<lectura> ::= scanf <identificador>
push dword _a
call scan_boolean
add esp, 4
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	scanf
;D:	b
;R54:	<lectura> ::= scanf <identificador>
push dword _b
call scan_boolean
add esp, 4
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	scanf
;D:	c
;R54:	<lectura> ::= scanf <identificador>
push dword _c
call scan_boolean
add esp, 4
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	a
;D:	||
;R80:	<exp> ::= <identificador>
push dword _a
;D:	b
;D:	&&
;R80:	<exp> ::= <identificador>
push dword _b
;R78:	<exp> ::= <exp> || <exp>
pop dword eax
mov dword ecx, [eax]
pop dword eax
mov dword ebx, [eax]
or ebx, ecx
push dword ebx
;D:	c
;D:	;
;R80:	<exp> ::= <identificador>
push dword _c
;R77:	<exp> ::= exp> && <exp>
pop dword eax
mov dword ecx, [eax]
pop dword ebx
and ebx, ecx
push dword ebx
;R56:	<escritura> ::= printf <exp>
call print_boolean
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	(
;D:	a
;D:	||
;R80:	<exp> ::= <identificador>
push dword _a
;D:	b
;D:	)
;R80:	<exp> ::= <identificador>
push dword _b
;R78:	<exp> ::= <exp> || <exp>
pop dword eax
mov dword ecx, [eax]
pop dword eax
mov dword ebx, [eax]
or ebx, ecx
push dword ebx
;R82:	<exp> ::= ( <exp> )
;D:	&&
;D:	c
;D:	;
;R80:	<exp> ::= <identificador>
push dword _c
;R77:	<exp> ::= exp> && <exp>
pop dword eax
mov dword ecx, [eax]
pop dword ebx
and ebx, ecx
push dword ebx
;R56:	<escritura> ::= printf <exp>
call print_boolean
add esp, 4
call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	!
;D:	a
;D:	&&
;R80:	<exp> ::= <identificador>
push dword _a
;R79:	<exp> ::= ! <exp>
pop dword eax
mov dword ebx, [eax]
cmp ebx, 0
je no_uno_0
push dword 0
jmp no_0
no_uno_0:
push dword 1
no_0:
;D:	b
;D:	&&
;R80:	<exp> ::= <identificador>
push dword _b
;R77:	<exp> ::= exp> && <exp>
pop dword eax
mov dword ecx, [eax]
pop dword ebx
and ebx, ecx
push dword ebx
;D:	!
;D:	c
;D:	;
;R80:	<exp> ::= <identificador>
push dword _c
;R79:	<exp> ::= ! <exp>
pop dword eax
mov dword ebx, [eax]
cmp ebx, 0
je no_uno_1
push dword 0
jmp no_1
no_uno_1:
push dword 1
no_1:
;R77:	<exp> ::= exp> && <exp>
pop dword ecx
pop dword ebx
and ebx, ecx
push dword ebx
;R56:	<escritura> ::= printf <exp>
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
