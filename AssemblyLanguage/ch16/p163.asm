assume cs:code, ds:data

data segment
    table db '0123456789ABCDEF'
data ends

code segment
start:
    mov ax, data
    mov ds, ax
    
    mov ax, 0bfh
    call showbyte

    mov ax, 4c00h
    int 21h

showbyte:
    push cx
    push bx
    push es

    mov ah, al
    mov cl, 4
    shr ah, cl
    and al, 00001111b

    mov bx, 0b800h
    mov es, bx

    mov bl, ah
    mov bh, 0 
    mov ah, table[bx]
    mov es:[160*12+30*2], ah

    mov bl, al
    mov bh, 0
    mov ah, table[bx]
    mov es:[160*12+30*2+2], ah

    pop es
    pop bx
    pop cx
    ret
code ends

end
