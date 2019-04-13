assume cs:code, ss:stack

stack segment
    db 128 dup (0)
stack ends

code segment
start:
    mov ax, stack
    mov ss, ax
    mov sp, 128             ; 设置栈的段地址和栈顶地址

    ; --------- 下面的代码将 int9 中断程序拷贝到 0:204 地址
    push cs                  
    pop ds
    mov si, offset int9         ; movsb 使用 ds:si 作为拷贝源地址, 因此这里设置 ds 和 si 指向要拷贝的代码源地址

    mov ax, 0
    mov es, ax
    mov di, 204h                ; movsb 使用 es:di 作为拷贝的目的地址，因此这里设置 es 和 di 指向要把代码拷贝到的目的地址

    mov cx, offset int9end-offset int9      ; movsb 使用 cx 作为要拷贝的字节长度，因此将 cx 设置为代码长度，使用标号相减让编译器计算代码长度
    cld                         ; 设置正向传输，即每拷贝一个字节，si 和 di 就递增 1
    rep movsb                   ; 该句指令执行真正的拷贝，该指令完成后，ds:si 后的 cx 字节长度数据被拷贝到 es:di 指向的目的地址
    ;------------------------------------------------------------

    ;----------- 下面的代码将原来的 int9 中断处理程序入口地址保存到 0:200 ~ 0:204
    push es:[9*4+2] 
    pop es:[202h]           ; 原来的 int9 中断处理程序入口地址的段地址保存到了 0:202
    push es:[9*4]
    pop es:[200h]           ; 原来的 int9 中断处理程序入口地址的偏移地址保存到了 0:200
    ;------------------------------------------------------------
    
    ; --------- 下面的代码将中断向量表 9 号状态码的处理程序的地址改为我自己的 int9    
    cli                             ; 设置 IF 为 0，因为下面两句代码执行过程中不可被可屏蔽中断中断
    mov word ptr es:[9*4+2], 0      ; 设置段地址
    mov word ptr es:[9*4], 204h     ; 设置偏移地址
    sti                             ; 设置 IF 为 1

    mov ax, 4c00h                   ; 安装程序在此退出
    int 21h

    ; ----------- 下面是我写的新的 int9 中断处理程序
    ; 只要在键盘上按了某个键，就会调用该中断程序，那么也就是说 cs:ip 被设置成了 0:204
    ; 所以下面的 cs 肯定为 0
    ; (然而如果我使用 call dword ptr 0:[200h]，那么就无法正确执行....why?)
int9:
    push ax
    push es
    push bx
    push cx 

    in al, 60h                  ; 从端口 60 读出键盘按键的扫描码

    ; ; ------------ 下面两句代码模拟 int9 的中断过程
    ; pushf                       ; 标志寄存器入栈
    ; call dword ptr cs:[200h]    ; 调用原来的 int9 中断处理程序
    
    cmp al, 09eh                ; 判断键盘上是否按了 'A'
    jne int9ret                 ; 如果按的不是 'A'

    ;----------- 如果键盘上按了 'A'，那么显示满屏的 'A'
    mov bx, 0
    mov ax, 0b800h
    mov es, ax
    mov cx, 2000
int9loop:
    mov byte ptr es:[bx], 'A'
    add bx, 2  
    loop int9loop
    ;--------------------------------------------------

int9ret:
    pop cx
    pop bx
    pop es
    pop ax
    iret
int9end:
    nop
code ends

end start
