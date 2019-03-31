assume cs:code, ds:data, ss:stack

data segment
    db '1. display      '
    db '2. brows        '
    db '3. replace      '
    db '4. modify       '
data ends

stack segment
    dw 0, 0, 0, 0, 0, 0, 0, 0
stack ends

code segment
start:
    mov ax, data
    mov ds, ax
    mov ax, stack
    mov ss, ax
    mov sp, 10h 

    mov cx, 4
    mov bx, 3
 s0:
    mov si, 0
    push cx
    mov cx, 4
    s:
        mov al, [bx+si] 
        and al, 11011111b
        mov [bx+si], al
        inc si
        loop s
    pop cx
    add bx, 16
    loop s0

    mov ax, 4c00h
    int 21h
code ends

end start
