assume cs:code, ds:data

data segment
    db 'I am king of the world!!!', 0
data ends

code segment
start:
    ; 安装中断程序
    mov ax, cs
    mov ds, ax 
    mov si, offset interrupt_prog
    mov ax, 0
    mov es, ax
    mov di, 200h

    mov cx, offset interrupt_end-offset interrupt_prog
    cld
    rep movsb

    ; 设置中断向量表地址
    mov ax, 0
    mov es, ax
    mov word ptr es:[7ch*4], 200h
    mov word ptr es:[7ch*4+2], 0

display:
    mov dh, 12
    mov dl, 32
    mov cl, 4
    mov ax, data
    mov ds, ax
    mov si, 0

    ; dh 行号
    ; dl 列号
    ; cl 颜色
    ; ds:si 指向字符串首地址
    int 7ch

    mov ax, 4c00h
    int 21h

interrupt_prog:
    push es
    push ax
    push bp
    push bx

    mov si, 0
    mov ax, 0b800h      
    mov es, ax          ; 显存段地址

    mov bh, 160
    mov bl, 2

    sub ax, ax
    mov al, dh
    mul bh              ; 行 * 160 

    mov bp, ax          ; 保存行 * 160, 因为需要用 ax 来做另一个乘法运算
    sub ax, ax
    
    mov al, dl
    mul bl
    add ax, bp          ; 行 * 160 + 列 * 2
    mov di, ax

interrupt_loop:
    cmp byte ptr [si], 0
    je interrupt_break
    mov al, [si]
    mov es:[di], al
    mov es:[di+1], cl
    inc si
    add di, 2
    jmp short interrupt_loop
interrupt_break:
    pop bx
    pop bp
    pop ax
    pop es
    iret
interrupt_end:
    nop

code ends

end start
