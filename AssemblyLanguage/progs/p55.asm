assume cs:code

code segment
    
    mov ax, 0ffffh
    mov ds, ax

    mov dx, 0
    mov bx, 0
    mov ax, 0
    mov cx, 0bh

  s:mov al, [bx]
    mov ah, 0
    add dx, ax
    inc bx
    loop s

code ends

end
