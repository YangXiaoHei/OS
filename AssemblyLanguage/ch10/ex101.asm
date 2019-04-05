assume cs:code, ds:data

data segment
    db 'Welcome to masm!', 0
data ends

code segment
start:
        mov ax, data
        mov ds, ax

        mov dh, 13
        mov dl, 32
        mov cl, 4
        mov si, 0
        call show_str
        mov ax, 4c00h
        int 21h

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

      s:
        mov cl, es:[si]
        mov ch, 0
        jcxz ok
        mov [bx], cl
        mov [bx+1], al
        add bx, 2
        inc si
        jmp short s
     ok:
        pop es
        pop si
        pop cx
        pop ds
        pop ax
        ret

code ends

end start
