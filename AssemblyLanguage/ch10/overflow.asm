assume cs:code

code segment
    mov bh, 1
    mov ax, 1000
    div bh

    mov ax, 4c00h
    int 21h
code ends
end
