assume cs:code, ds:data

data segment 
    db 'conversation',0
data ends

code segment
start:

    ; 安装 int 程序

    mov ax, cs
    mov ds, ax
    mov si, offset interrupt_prog

    mov ax, 0
    mov es, ax
    mov di, 200h

    mov cx, offset interrupt_end-offset interrupt_prog

    cld
    rep movsb

    ; 设置中断向量表

    mov ax, 0
    mov ds, ax
    mov word ptr ds:[7ch*4], 200h
    mov word ptr ds:[7ch*4+2], 0

    ; 执行显示字符串程序
    
display:
    mov ax, data
    mov ds, ax
    mov ax, 0b800h
    mov es, ax
    mov di, 12*160+30*2
    mov si, 0

    mov cx, 12
display_loop:
    mov al, [si]
    mov es:[di], al
    mov byte ptr es:[di+1], 4
    inc si
    add di, 2

    mov bx, offset display_loop-offset display_end 
    int 7ch

display_end:
    nop
    
    mov ax, 4c00h
    int 21h

interrupt_prog:
    push bp
    mov bp, sp
    dec cx
    jcxz interrupt_ok
    add [bp+2], bx
interrupt_ok:
    pop bp
    iret
interrupt_end:
    nop

code ends
end start
