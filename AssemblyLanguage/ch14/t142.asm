assume cs:code

code segment
    mov ax, 8
    mov bx, ax

    mov cx, 5
    shl ax, cl

    shl bx, 1
    add ax, bx

    mov ax, 4c00h
    int 21h
code ends

end
