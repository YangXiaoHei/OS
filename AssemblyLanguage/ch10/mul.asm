assume cs:code, ds:data

data segment
    db  15
data ends

code segment
start:
    mov ax, data
    mov ds, ax
    mov al, 2
    mov bx, 0
    mul byte ptr [bx]

    mov ax, 4c00h
    int 21h
code ends

end start

