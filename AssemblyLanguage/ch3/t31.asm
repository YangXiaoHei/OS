assume cs:code

code segment
    mov ax, 1
    mov ds, ax
    mov si, 0
    mov ax, [si]    ;mov ax, [0000]

    inc si
    mov bx, [si]    ;mov bx, [0001] 

    mov ax, bx

    sub si, si
    mov ax, [si]    ;mov ax, [0000]

    add si, 2
    mov bx, [si]    ;mov bx, [0002]

    add ax, bx
    
    add si, 2
    add ax, [si]    ;mov ax, [0004]
    mov ax, 0
    
    sub si, 2
    mov al, [si]    ;mov al, [0002]

    mov bx, 0
    
    add si, 0ah
    
    mov bl, [si]    ;mov bl, [000c]
    add al, bl

    mov ax, 4c00h
    int 21h
code ends
end
