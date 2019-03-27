assume cs:code

code segment
    
start:
    mov ax, cs
    mov ds, ax
    mov bx, 0

    mov ax, 20h
    mov es, ax
    mov cx, offset cpend-offset start
  s:
    mov al, [bx]
    mov es:[bx], al
    inc bx
    loop s
cpend:

    mov ax, 4c00h
    int 21h

code ends

end
