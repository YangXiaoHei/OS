assume cs:code, ds:data

data segment
    db 'ibm         '
    db 'dec         '
    db 'dos         '
    db 'vax         '
data ends

code segment
start:
    mov ax, data
    mov ds, ax
    mov bx, 0
    mov cx, 4
  s:
    mov al, [bx]
    and al, 11011111b
    mov [bx], al
    add bx, 12
    loop s

    mov ax, 4c00h
    int 21h
code ends

end start
