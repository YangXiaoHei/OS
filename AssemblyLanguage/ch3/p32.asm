assume cs:code

code segment
    mov ax, 1000h
    mov ds, ax
    mov al, 23h
    mov bx, 0
    mov [bx], al ;masm 和 debug 程序对 [] 的解释不一样

    mov ax, 4c00h
    int 21h
code ends
end
