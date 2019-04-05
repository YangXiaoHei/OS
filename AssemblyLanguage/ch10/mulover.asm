assume cs:code

code segment
    mov ax, 65533
    mov bx, 65534
    div bx
    mov ax, dx
    mov bx, 512
    mul bx
    mov bx,128
    mul bx

    mov ax, 4c00h
    int 21h
code ends

end
