assume cs:code

code segment
    mov ax, 2000h
    mov ss, ax
    mov sp, 10h

    mov ax, 1000h
    mov ds, ax

    mov cx, 8h
    mov bx, 0h
  s:
    push [bx]
    add bx, 2
    loop s

    mov ax, 4c00h
    int 21h
code ends
end
