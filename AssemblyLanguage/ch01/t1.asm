assume cs:code

code segment
    mov sp, 200h
    mov ax, sp
    push sp
    pop dx
    sub ax, dx

    mov ax, 4c00h
    int 21h
code ends

end
