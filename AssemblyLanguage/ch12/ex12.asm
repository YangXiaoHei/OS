assume cs:code

code segment
start:
    mov ax, cs
    mov ds, ax
    mov si, offset do0              ; ds:si 指向复制源
    mov ax, 0
    mov es, ax
    mov di, 200h                    ; es:di 指向复制目的

    mov cx, offset do0_end-offset do0
    cld
    rep movsb                       ; 把中断处理程序复制到一段不被使用的内存

    mov ax, 0
    mov es, ax
    mov word ptr es:[0*4], 200h
    mov word ptr es:[0*4+2], 0      ; 设置中断程序入口地址

    mov ax, 4c00h
    int 21h

do0:
    jmp short do0_start
    db 'divide overflow!!!'       ;18 个字符
do0_start:
    push ax
    push ds
    push di
    push si

    mov ax, 0b800h
    mov es, ax

    mov ax, cs
    mov ds, ax
    mov di, 202h
    mov si, 12*160+34*2             ; 要写入显存中的起始内存地址

    mov cx, 18
do0_loop:
    mov al, [di]
    mov es:[si], al
    add di, 1
    add si, 2
    loop do0_loop

    pop si
    pop di
    pop ds
    pop ax

    mov ax, 4c00h
    int 21h

do0_end:
    nop

code ends

end start
