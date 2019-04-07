assume cs:code, ds:data

data segment
    db 8, 11, 8, 1, 8, 5, 63, 38
data ends

code segment 
start:
    mov ax, data
    mov ds, ax
    mov cx, 8
    sub ax, ax
    mov bx, 0
lo:
    cmp byte ptr [bx], 8
    jna ignore
    inc ax
ignore:
    inc bx
    loop lo

    mov ax, 4c00h
    int 21h
code ends

end start
