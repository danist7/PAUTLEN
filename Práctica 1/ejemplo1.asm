segment .data
mensaje_error_div_0 dd "División por cero",0
segment .bss
__esp resd 1
_x resd 1
_y resd 1
_z resd 1
segment .text
global main
extern scan_int, scan_boolean
extern print_int, print_boolean, print_string, print_blank, print_endofline
main:
mov [__esp], esp
mov dword eax, 8
push dword eax
pop dword [_x]
push dword _y
call scan_int
add esp, 4
push dword _x
push dword _y
pop dword eax
mov dword ebx, [eax]
pop dword eax
mov dword ecx, [eax]
add ebx, ecx
push dword ebx
pop dword [_z]
push dword _z
pop dword eax
mov dword ebx, [eax]
push dword ebx
call print_int
add esp, 4
call print_endofline
mov dword eax, 7
push dword eax
push dword _y
pop dword eax
mov dword ebx, [eax]
pop dword ecx
add ebx, ecx
push dword ebx
pop dword [_z]
push dword _z
pop dword eax
mov dword ebx, [eax]
push dword ebx
call print_int
add esp, 4
call print_endofline
jmp near fin
error_div_0: push dword mensaje_error_div_0
call print_string
add esp, 4
jmp near fin
fin: mov esp, [__esp]
ret
