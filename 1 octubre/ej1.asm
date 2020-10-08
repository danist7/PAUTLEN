segment .bss
_a resd 1
segment .data
_b dd 22
segment .text
global main
extern scan_int
main:
mov eax, [_b]
add eax,3
ret
; call scan_int
