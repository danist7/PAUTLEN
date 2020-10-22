segment .data
mensaje_error_div_0 dd "División por cero",0
segment .bss
__esp resd 1
_b1 resd 1
_x resd 1
segment .text
global main
extern scan_int, scan_boolean
extern print_int, print_boolean, print_string, print_blank, print_endofline
main:
mov [__esp], esp
push dword _b1
call scan_boolean
add esp, 4
push dword _x
call scan_int
add esp, 4
push dword _x
mov dword eax, 3
push dword eax
pop dword ecx
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
jg mayor_escribe_0
push dword 0
jmp mayor_0
mayor_escribe_0:
push dword 1
mayor_0:
call print_boolean
add esp, 4
call print_endofline
push dword _x
mov dword eax, 3
push dword eax
pop dword ecx
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
jge mayorigual_escribe_1
push dword 0
jmp mayorigual_1
mayorigual_escribe_1:
push dword 1
mayorigual_1:
call print_boolean
add esp, 4
call print_endofline
push dword _x
mov dword eax, 3
push dword eax
pop dword ecx
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
jl menor_escribe_2
push dword 0
jmp menor_2
menor_escribe_2:
push dword 1
menor_2:
call print_boolean
add esp, 4
call print_endofline
push dword _x
mov dword eax, 3
push dword eax
pop dword ecx
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
jle menorigual_escribe_3
push dword 0
jmp menorigual_3
menorigual_escribe_3:
push dword 1
menorigual_3:
call print_boolean
add esp, 4
call print_endofline
push dword _x
mov dword eax, 3
push dword eax
pop dword ecx
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
je igual_escribe_4
push dword 0
jmp igual_4
igual_escribe_4:
push dword 1
igual_4:
call print_boolean
add esp, 4
call print_endofline
push dword _x
mov dword eax, 3
push dword eax
pop dword ecx
pop dword eax
mov dword ebx, [eax]
cmp ebx, ecx
jne distinto_escribe_5
push dword 0
jmp distinto_5
distinto_escribe_5:
push dword 1
distinto_5:
call print_boolean
add esp, 4
call print_endofline
push dword _b1
mov dword eax, 0
push dword eax
pop dword ecx
pop dword eax
mov dword ebx, [eax]
and ebx, ecx
push dword ebx
call print_boolean
add esp, 4
call print_endofline
push dword _b1
mov dword eax, 1
push dword eax
pop dword ecx
pop dword eax
mov dword ebx, [eax]
or ebx, ecx
push dword ebx
call print_boolean
add esp, 4
call print_endofline
jmp near fin
error_div_0: push dword mensaje_error_div_0
call print_string
add esp, 4
jmp near fin
fin: mov esp, [__esp]
ret
