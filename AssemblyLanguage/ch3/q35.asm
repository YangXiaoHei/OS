assume cs:code 

code segment
    mov ax, 0
    mov ds, ax

    mov si, 0
    mov bx, 1
    mov [si], bx
    inc bx
    inc si
    mov [si], bx
    inc bx
    inc si
    mov [si], bx

    mov cx, 3
    mov si, 0
  s:
    add al, [si]
    inc si
    loop s

    mov ax, 4c00h
    int 21h
code ends
end
