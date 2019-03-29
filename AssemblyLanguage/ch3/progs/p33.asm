assume cs:code

code segment
    mov ax, 1000h
    mov ds, ax
    mov si, 0
    mov ax, [si]
    add si, 2
    mov bx, [si]
    sub si, 1
    mov cx, [si]
    add bx, [si]
    inc si
    add cx, [si]

    mov ax, 4c00h
    int 21h

code ends
end
