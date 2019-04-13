assume cs:code, ds:data, ss:stack

stack segment
    db 128 dup (0)
stack ends

data segment
    db 0,0
data ends

code segment
start:
    mov ax, stack
    mov ss, ax
    mov sp, 128

    mov ax, data
    mov ds, ax

    mov ax, 0
    mov es, ax

    ; 保存原来的中断向量表
    push es:[9*4+2]         ; 段地址
    pop ds:[2] 
    push es:[9*4]           ; 偏移地址
    pop ds:[0]

    ; 设置中断向量表, 设置中断向量表时如果被键盘中断，那么此时中断程序地址是错误的
    ; 因此将 IF 设置为 0，表示不响应可屏蔽中断
    cli                     ; 设置下面的指令都不会被可屏蔽中断中断
    mov ax, offset int9
    mov es:[9*4+2], cs
    mov es:[9*4], ax
    sti

    mov ax, 0b800h
    mov es, ax
    mov al, 'a'
display_loop:
    mov es:[160*12+30*2], al
    call delay
    inc al
    add si, 2
    cmp al, 'z'
    jna display_loop

    cli
    mov ax, 0
    mov es, ax
    push ds:[0]
    pop es:[9*4]
    push ds:[2]
    pop es:[9*4+2]
    sti

    mov ax, 4c00h
    int 21h

    ; ----------- int9 处理键盘中断程序 -------------------

int9:
    push ax
    push es
    in al, 60h
    pushf
    call dword ptr ds:[0]

    cmp al, 1
    jne int9ret

    mov ax, 0b800h
    mov es, ax
    mov byte ptr es:[160*12+2*30+1], 4
int9ret:
    pop es
    pop ax
    iret

    ; ---------------- 延时 -------------------　
delay:
    push ax
    push dx
    mov ax, 0
    mov dx, 10
delay_loop:
    sub ax, 1
    sbb dx, 0
    cmp ax, 0
    jne delay_loop
    cmp dx, 0
    jne delay_loop
    pop dx
    pop ax
    ret
code ends

end start
