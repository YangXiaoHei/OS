assume cs:code, ds:data

data segment
    dw 11 dup (0)
data ends

code segment
start:

    mov ax, data
    mov ds, ax
    mov ax, 12345
    mov dx, 0
    call dtoc

    mov dh, 12
    mov dl, 34
    mov cl, 4   
    call show_str
    mov ax, 4c00h
    int 21h

    ;参数 : 要转换的十进制数码的高16位和低16位：dx，ax
    ;       ds:si指向字符串的首地址
dtoc:
    push cx
    push dx
    push ax

    mov si, 10
    mov byte ptr [si], 0        ; \0
    dec si

  dtoc_loop:
    mov cx, 10
    call divdw
    add cx, '0'
    mov [si], cl
    dec si
    cmp dx, 0
    jne dtoc_loop
    cmp ax, 0
    jne dtoc_loop
    inc si

    pop ax
    pop dx
    pop cx
    ret

    ; 参数 : ax dword 型数据的低 16 位
    ;        dx dword 型数据的高 16 位
    ;        cx 除数
    ; 
    ; return : 返回 dx 结果的高 16 位，ax 结果的低 16 位
    ;          cx 余数
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
    
    ; dh 行号，取值范围 0 ~ 24
    ; dl 列号，取值范围 0 ~ 79
    ; cl 颜色，ds:si 指向字符串的首地址
    ; 返回: 无
show_str:
    push ax
    push ds
    push cx
    push si
    push es

    mov ax, ds
    mov es, ax
    mov ax, 0b800h
    mov ds, ax

    mov ah, 0
    mov bh, 0

    mov al, 0a0h
    mul dh          ; 有可能得到 16 位的结果
    mov bx, ax      ; 行

    mov al, 2
    mul dl
    add bx, ax      ; bx 中保留要写入显存的首地址

    mov al, cl      ;al 中保留颜色

show_loop:
    mov cl, es:[si]
    mov ch, 0
    jcxz ok
    mov [bx], cl
    mov [bx+1], al
    add bx, 2
    inc si
    jmp short show_loop
 ok:
    pop es
    pop si
    pop cx
    pop ds
    pop ax
    ret
code ends

end start
