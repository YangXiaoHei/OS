assume cs:code, ds:data

data segment
    db 16 dup (0)
data ends

code segment
    index: db 0, 2, 4, 7, 8, 9
    free: db 16 dup (0)

start:
    mov ax, cs
    mov ds, ax

    mov si, offset free
    mov di, offset index
    mov cx, 6
fetch_loop:
    mov al, [di]
    out 70h, al
    in al, 71h
    mov [si], al 
    inc di
    inc si
    loop fetch_loop

    mov ax, 0b800h
    mov es, ax

    mov di, 12*160+30*2
    mov si, offset free+5
    call convert            ; 年

    add di, 4
    mov byte ptr es:[di], '/'

    add di, 2
    dec si
    call convert            ; 月

    add di, 4
    mov byte ptr es:[di], '/'

    add di, 2
    dec si
    call convert            ; 日

    add di, 4
    mov byte ptr es:[di], ' '

    add di, 2
    dec si
    call convert            ; 时

    add di, 4
    mov byte ptr es:[di], ':'

    add di, 2
    dec si
    call convert

    add di, 4
    mov byte ptr es:[di], ':'

    add di, 2
    dec si
    call convert            ; 秒

    mov ax, 4c00h
    int 21h 

    ; 功能：将 bcd 转成 ascii 并写到显存
    ; ds:si 指向源内存
    ; es:di 指向显存地址
convert:
    push ax
    push cx

    mov al, ds:[si]
    mov ah, al
    mov cl, 4
    shr ah, cl
    and al, 00001111b
    add ah, '0'
    add al, '0'

    mov es:[di], ah
    mov es:[di+2], al

    pop cx
    pop ax
    ret

code ends

end start
