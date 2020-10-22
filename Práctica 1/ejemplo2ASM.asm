segment .data
mensaje_error_div_0 dd "División por cero",0
segment .bss
__esp resd 1
_b1 resd 1
segment .text
global main
extern scan_int, scan_boolean
extern print_int, print_boolean, print_string, print_blank, print_endofline
main:
mov [__esp], esp
push dword _b1
call scan_boolean
add esp, 4
push dword _b1
pop dword eax
mov dword ebx, [eax]
cmp ebx, 0
je no_uno_0
push dword 0
jmp no_0
no_uno_0:
push dword 1
no_0:
call print_boolean
add esp, 4
call print_endofline
push dword _b1
pop dword eax
mov dword ebx, [eax]
cmp ebx, 0
je no_uno_1
push dword 0
jmp no_1
no_uno_1:
push dword 1
no_1:
pop dword ebx
cmp ebx, 0
je no_uno_2
push dword 0
jmp no_2
no_uno_2:
push dword 1
no_2:
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
