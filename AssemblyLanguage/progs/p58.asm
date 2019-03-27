assume cs:code

code segment

    mov cx, 0bh
    mov bx, 0

  s:mov ax, 0ffffh
    mov ds, ax
    mov dl, [bx]

    mov ax, 0
    mov ds, ax
    add bx, 200h
    mov [bx], dl  
    sub bx, 200h
    inc bx
    loop s

    mov ax, 4c00h
    int 21h
code ends

end
