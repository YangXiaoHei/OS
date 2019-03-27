assume cs:code

code segment

    mov ax, 20h
    mov ds, ax

    mov al, 0
    mov bx, 0

    mov cx, 0ffh
  s:
    mov [bx], al 
    inc bx
    loop s

    mov ax, 4c00h
    int 21h

code ends

end
