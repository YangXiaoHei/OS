assume cs:code 

data segment 
    db 8, 11, 8, 1, 8, 5, 63, 38
data ends

code segment
start:
    mov ax, data
    mov ds, ax
    mov cx, 8
    mov bh, 8
    mov si, 0
    sub ax, ax
lo:
    mov bl, ds:[si]
    cmp bh, bl
    je equal
    jmp short go_on
equal:
    inc ax
go_on:
    inc si
    dec cx
    jcxz ok
    jmp short lo
ok:
    mov ax, 4c00h
    int 21h
code ends

end start
