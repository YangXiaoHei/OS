assume cs:code

code segment
    mov ax, 0
    mov ds, ax
    mov ax, 99h
    add ds, ax

    mov ax, 4c00h
    int 21h
code ends
end
