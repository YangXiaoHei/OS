assume cs:code

code segment
    mov ax, 1000h
    mov ss, ax
    mov sp, 10h

    mov ax, 1ah
    mov bx, 1bh

    push ax
    push bx

    sub ax, ax
    sub bx, bx

    pop bx
    pop ax

    mov ax, 4c00h
    int 21h
code ends
end
