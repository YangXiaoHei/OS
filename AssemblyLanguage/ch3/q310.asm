assume cs:code

code segment
    mov ax, 1000h
    mov ss, ax
    mov sp, 2h

    mov ax, 2266h
    push ax

    mov ax, 4c00h
    int 21h
code ends
end
