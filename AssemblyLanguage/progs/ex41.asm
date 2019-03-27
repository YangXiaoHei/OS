assume cs:code

code segment
    
    mov cx, 3fh
    mov ax, 20h
    mov ds, ax
    mov bx, 0
    mov ax, 0

  s:mov [bx], al
    inc bx
    inc ax
    loop s 

    mov ax, 4c00h
    int 21h

code ends

end
