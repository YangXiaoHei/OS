assume cs:code

code segment
start:
    mov al, 8
    out 70h, al
    in al, 71h

    mov ah, al
    mov cl, 4
    shr ah, cl
    and al, 00001111b
    add al, '0'
    add ah, '0'

    mov bx, 0b800h
    mov es, bx
    mov byte ptr es:[12*160+30*2], ah
    mov byte ptr es:[12*160+30*2+1], 4
    mov byte ptr es:[12*160+31*2], al
    mov byte ptr es:[12*160+31*2+1], 4
    
    mov ax, 4c00h
    int 21h
    
code ends

end

