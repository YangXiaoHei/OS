assume cs:code, ss:stack

stack segment
    db 128 dup (0)
stack ends

code segment
start:
    mov ax, stack
    mov ss, ax
    mov sp, 128

    push cs
    pop ds

    mov ax, 0
    mov es, ax

    mov si, offset int9
    mov di, 204h
    mov cx, offset int9end-offset int9
    cld
    rep movsb

    push es:[9*4+2]
    pop es:[202h]
    push es:[9*4]
    pop es:[200h]

    cli
    mov word ptr es:[9*4+2], 0
    mov word ptr es:[9*4], 204h    
    sti

    mov ax, 4c00h
    int 21h

int9:
    push ax
    push es
    push bx
    push cx 

    in al, 60h

    ; TODO 这个地方的 cs 不是 0，比如当调用
    ; mov ax, 0
    ; mov es, ax
    ; 然后调用 call dword ptr es:[200h] 时，键盘中断程序无法正常使用
    ; 但是这里无法 debug，因为中断程序安装后，键盘输入失效。。。
    ; 实在无法理解这里发生了什么
    pushf
    call dword ptr cs:[200h]

    cmp al, 09eh
    jne int9ret

    mov bx, 0
    mov ax, 0b800h
    mov es, ax
    mov cx, 2000
int9loop:
    mov byte ptr es:[bx], 'A'
    add bx, 2  
    loop int9loop

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
