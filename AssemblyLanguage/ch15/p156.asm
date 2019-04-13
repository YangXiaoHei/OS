assume cs:code, ss:stack

stack segment
    db 128 dup (0)
stack ends

code segment
start:
    mov ax, stack
    mov ss, ax
    mov sp, 128             ; 设置栈地址

    push cs
    pop ds                  ; 将 ds 设置为 cs

    mov ax, 0
    mov es, ax              ; 将 es 设置为 0

    mov si, offset int9                     ; 源代码起始地址
    mov di, 204h                            ; 源代码复制目的的起始地址
    mov cx, offset int9end-offset int9      ; 源代码长度
    cld                                     ; 设置正向传输
    rep movsb                               ; 复制源代码

    push es:[9*4+2]                         
    pop es:[202h]                           ; 将原始 int9 中断程序的入口段地址保存在 0:202
    push es:[9*4]
    pop es:[200h]                           ; 将原始 int9 中断程序的入口偏移地址保存在 0:200

    cli 
    mov word ptr es:[9*4], 204h
    mov word ptr es:[9*4+2], 0
    sti

    mov ax, 4c00h
    int 21h

    ; ---------- int9 中断程序 -------------
int9:
    push ax
    push cx
    push es
    push si

    in al, 60h

    pushf                       ; 标志寄存器入栈
    call dword ptr cs:[200h]       ; 在原始 int9 中断程序的末尾会调用 iret，所以需要让标志寄存器先入栈

    cmp al, 3bh
    jne int9ret

    mov cx, 2000
    mov ax, 0b800h
    mov es, ax
    mov si, 1
int9loop:
    mov byte ptr es:[si], 4 
    add si, 2
    loop int9loop

int9ret:
    pop si
    pop es
    pop cx
    pop ax 
    iret
int9end:        ; 用来计算 offset
    nop

code ends

end start
