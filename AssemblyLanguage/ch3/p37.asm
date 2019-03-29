assume cs:code

code segment
    mov ax, 1000h
    mov ss, ax
    mov sp, 0010h

    mov ax, 1234h
    mov bx, 5678h
    mov dx, 9abch

    push ax
    push bx
    push dx
code ends
end
