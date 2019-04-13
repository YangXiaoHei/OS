assume cs:code

code segment
start:
    mov ax, cs
    mov ds, ax
    mov si, offset int7ch       ; 源地址

    mov ax, 0
    mov es, ax
    mov di, 200h                ; 目的地址

    cld
    mov cx, offset int7ch_end-offset int7ch
    rep movsb

    mov ax, 0
    mov es, ax
    mov word ptr es:[7ch*4], 200h
    mov word ptr es:[7ch*4+2], 0

    mov ax, 4c00h
    int 21h

    ; 参数：
    ;   用 ah 寄存器传递功能号: 0 清屏, 1 设置前景色, 2 设置背景色, 3 表示向上滚动一行
    ;   用 al 传递颜色值
int7ch:
    cmp ah, 0
    je do1

    cmp ah, 1
    je do2

    cmp ah, 2
    je do3

    cmp ah, 3
    je do4
    jmp short sret

do1:
    call sub1
    jmp short sret

do2:
    call sub2
    jmp short sret

do3:
    call sub3
    jmp short sret

do4:
    call sub4
    jmp short sret

sret:
    iret
sub1:
    push ax
    push es
    push si
    push cx 

    mov ax, 0b800h
    mov es, ax
    mov si, 0
    mov cx, 2000
sub1s:
    mov byte ptr es:[si], ' '
    add si, 2
    loop sub1s

    pop cx
    pop si
    pop es
    pop ax
    ret

sub2:
    push bx
    push es
    push cx
    push si

    mov bx, 0b800h
    mov es, bx
    mov si, 1
    mov cx, 2000
sub2s:
    and byte ptr es:[si], 11111000b
    or es:[si], al 
    add si, 2
    loop sub2s

    pop si
    pop cx
    pop es
    pop bx
    ret
 
sub3:
    push bx
    push es
    push si
    push cx

    mov bx, 0b800h
    mov es, bx
    mov si, 1
    mov cl, 4
    shl al, cl
    mov cx, 2000
sub3s:
    and byte ptr es:[si], 10001111b
    or es:[si], al
    add si, 2
    loop sub3s

    pop cx
    pop si
    pop es
    pop bx
    ret

sub4:
    push bx
    push ds
    push si
    push di
    push cx

    mov bx, 0b800h
    mov ds, bx
    mov es, bx
    mov si, 160
    mov di, 0
    cld
    mov cx, 24
sub4s:
    push cx
    mov cx, 160
    rep movsb
    pop cx
    loop sub4s

    mov cx, 80
    mov si, 0
sub4s1:
    mov byte ptr [si+160*24], ' '
    add si, 2
    loop sub4s1

    pop cx
    pop di
    pop si
    pop ds
    pop bx
    ret
int7ch_end:
    nop
code ends

end start
