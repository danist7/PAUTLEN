segment .bss
_a resd 1
segment .data
_b dd 22
segment .text
global main
main:

mov [_a], 5+2
mov eax, [-a]
add eax, [_b]
ret
