assume cs:code

code segment
    mov ax, 1000h
    mov ds, ax
    mov ax, 11316
    mov si, 0
    mov [si], ax
    mov bx, [si]
    add si, 2
    sub bx, [si]
    mov [si], bx

    mov ax, 4c00h
    int 21h
code ends
end
