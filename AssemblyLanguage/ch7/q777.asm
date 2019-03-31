assume cs:code, ds:data, ss:stack

stack segment
    dw 0, 0, 0, 0, 0, 0, 0, 0
stack ends

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
    mov ax, stack
    mov ss, ax
    mov sp, 10h
    mov bx, 0
    mov cx, 4
 s0:
    mov si, 0
    push cx
    mov cx, 3
    s:
      mov al, [bx+si]
      and al, 11011111b
      mov [bx+si], al
      inc si
      loop s
    pop cx
    add bx, 12
    loop s0

    mov ax, 4c00h
    int 21h
code ends

end start
