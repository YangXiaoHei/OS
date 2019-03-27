assume cs:code

code segment

    mov bx, 20h
    mov ds, bx
    mov bx, 0

    mov cx, 3fh
  s:mov [bx], bx
    inc bx
    loop s 

    mov ax, 4c00h
    int 21h

code ends

end
