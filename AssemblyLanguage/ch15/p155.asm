assume cs:code

code segment
start:
    mov ax, 0b800h
    mov es, ax
    mov si, 0
    mov di, 160*12+20*2
    mov al, 'a'

  s:
    mov es:[di], al
    inc al
    add di, 2
    cmp al, 'z'
    call delay
    jna s

    mov ax, 4c00h
    int 21h

; 执行迭代次数很大的循环来模拟延时
delay:
    pushf
    push dx
    push ax
    mov dx, 10
    mov ax, 0
delay_loop:
    sub ax, 1
    sbb dx, 0
    cmp ax, 0
    jne delay_loop
    cmp dx, 0
    jne delay_loop
    pop ax
    pop dx
    popf
    ret
code ends

end start
