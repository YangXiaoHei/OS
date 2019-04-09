assume cs:code, ds:data

data segment
    dw 8*160+70
    dw 9*160+70
    dw 10*160+70
    dw 11*160+70
    dw 12*160+70
    dw 13*160+70
    dw 14*160+70
    dw 15*160+70
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

    ; 设置中断向量表
    mov ax, 0
    mov es, ax
    mov word ptr es:[7ch*4], 200h
    mov word ptr es:[7ch*4+2], 0

    ; --------- 在屏幕中间显示 80 个 ! -----------------

    mov ax, 0b800h
    mov es, ax              ; 设置显存写入段地址
    mov ax, data
    mov ds, ax              ; 设置读取显存偏移地址的数据段段地址
    mov di, 0               ; 初始偏移为 0
    mov cx, 8               ; 外层循环次数为 8

out_loop:
    mov si, [di]
    push cx             ;保存外层循环次数变量
    push di             ;内存循环会修改该寄存器，先保存一份
    mov cx, 10          ;内层循环次数为 10 

    inter_loop:
        mov byte ptr es:[si], '!'           ;低位字节写入 ascii
        mov byte ptr es:[si+1], 4           ;高位字节写入属性
        add si, 2                           ;移动到下一个写入位置
        mov bx, offset inter_loop-offset inter_loop_end     ;中断程序中据此修改 ip 寄存器
        int 7ch
    inter_loop_end:
        nop

    pop di              ;恢复 di
    pop cx              ;恢复外层循环变量
    add di, 2           ;下一个取内存写入偏移地址的数据段偏移地址
    mov bx, offset out_loop-offset out_loop_end         ;中断程序中据此修改 ip 寄存器
    int 7ch
out_loop_end:
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
