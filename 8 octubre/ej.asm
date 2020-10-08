segment .bss
segment .data
_a dd 496
segment .text
global main
extern print_int
main:
push dword [_a]
call print_int
add esp, 4
ret
