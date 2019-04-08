assume cs:code 

code segment
    mov ax, 1000h
    mov bx, 1
    div bx 

    mov ax, 4c00h
    int 21h
code ends

end
