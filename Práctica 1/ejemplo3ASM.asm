segment .data
mensaje_error_div_0 dd "División por cero",0
segment .bss
__esp resd 1
_x resd 1
_y resd 1
_z resd 1
_j resd 1
segment .text
global main
extern scan_int, scan_boolean
extern print_int, print_boolean, print_string, print_blank, print_endofline
main:
mov [__esp], esp
push dword _x
call scan_int
add esp, 4
push dword _z
call scan_int
add esp, 4
push dword _x
pop dword eax
mov dword ebx, [eax]
neg ebx
push dword ebx
pop dword [_j]
push dword _j
pop dword eax
mov dword ebx, [eax]
push dword ebx
call print_int
add esp, 4
call print_endofline
push dword _x
push dword _z
pop dword eax
mov dword ecx, [eax]
pop dword eax
mov dword ebx, [eax]
sub ebx, ecx
push dword ebx
call print_int
add esp, 4
call print_endofline
push dword _x
mov dword eax, 2
push dword eax
pop dword ecx
pop dword ebx
mov dword eax, [ebx]
cmp ecx, 0
je error_div_0
cdq
idiv ecx
push dword eax
pop dword [_y]
push dword _y
pop dword eax
mov dword ebx, [eax]
push dword ebx
call print_int
add esp, 4
call print_endofline
push dword _x
push dword _y
pop dword ebx
mov dword ecx, [ebx]
pop dword ebx
mov dword eax, [ebx]
imul ecx
push dword eax
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
