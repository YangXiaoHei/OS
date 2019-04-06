assume cs:code

code segment
    mov ax, 1000h
    mov ds, ax
    mov bx, 0
    mov cx, 10h
    mov ax, 0
  s:mov [bx], al
    inc bx 
    loop s
    mov ax, 4c00h
    int 21h
code ends
end
