assume cs:code

code segment
start:
    mov ax, 60
    call showsin

    mov ax, 4c00h
    int 21h

showsin:
    jmp short show
    table   dw ag0, ag30, ag60, ag90, ag120, ag180
    ag0     db  '0',0
    ag30    db  '0.5',0
    ag60    db  '0.866',0
    ag90    db  '1',0
    ag120   db  '0.866',0
    ag150   db  '0.5',0
    ag180   db  '0',0
show:
    push ax
    push dx
    push es
    push si
    push bx

    mov ah, 0

    mov dl, 30      ; 计算偏移地址
    mov dh, 0
    div dl

    mov bl, al
    mov bh, 0
    add bx, bx      ; bx *= 2
    mov bx, table[bx]

    mov ax, 0b800h
    mov es, ax
    mov si, 160*12+40*2
    
showstr:
    mov ah, cs:[bx]
    cmp ah, 0
    je showstr_end
    mov es:[si], ah
    inc bx
    add si, 2
    jmp short showstr
showstr_end:
    pop bx
    pop si    
    pop es
    pop dx
    pop ax
    ret
code ends

end start
