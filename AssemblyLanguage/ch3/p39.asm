assume cs:code

code segment
    mov ax, 1000h
    mov ss, ax
    mov sp, 10h

    mov ax, 001ah
    mov bx, 001bh

    push ax
    push bx
    pop ax
    pop bx

    mov ax, 4c00h
    int 21h
code ends
end
