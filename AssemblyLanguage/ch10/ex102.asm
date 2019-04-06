assume cs:code

code segment
start:
    
    ; ax 存放低 16 位, dx 存放高 16 位
    ; cx 存放除数
    ; 返回值
    ; dx 存放商的高 16 位，ax 存放商的低 16 位
    ; cx 存放余数
divdw:
    push ax
    mov ax, dx
    mov dx, 0
    div cx
    mov bx, ax
    pop ax
    div cx
    mov cx, dx
    mov dx, bx
    ret

code ends

end
