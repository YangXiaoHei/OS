assume cs:code

code segment
start:
    mov ax, 0b800h;
    mov es, ax
    mov di, 0
    mov si, 160*12+30*2
    mov al, 'a'

  s:
    mov es:[si], al
    inc al
    add si, 2
    cmp al, 'z'
    jna s

    mov ax, 4c00h
    int 21h
code ends

end
