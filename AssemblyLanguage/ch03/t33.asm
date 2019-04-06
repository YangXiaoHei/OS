assume cs:code

code segment
    mov ax, 1000h
    mov ss, ax
    mov sp, 0

    mov ax, 2000h
    mov ds, ax

    mov cx, 8
    mov bx, 0eh
  s:
    pop [bx]
    sub bx, 2
    loop s

    mov ax, 4c00h
    int 21h
code ends
end
