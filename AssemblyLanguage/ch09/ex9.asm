assume cs:code, ds:data

data segment
    db 77h, 02h  ; 绿色
    db 65h, 02h
    db 6ch, 02h
    db 63h, 02h
    db 6fh, 02h
    db 6dh, 02h
    db 65h, 02h
    db 20h, 02h
    db 74h, 02h
    db 6fh, 02h
    db 20h, 02h
    db 6dh, 02h
    db 61h, 02h
    db 73h, 02h
    db 6dh, 02h
    db 21h, 02h

    db 77h, 24h  ; 绿底红色
    db 65h, 24h
    db 6ch, 24h
    db 63h, 24h
    db 6fh, 24h
    db 6dh, 24h
    db 65h, 24h
    db 20h, 24h
    db 74h, 24h
    db 6fh, 24h
    db 20h, 24h
    db 6dh, 24h
    db 61h, 24h
    db 73h, 24h
    db 6dh, 24h
    db 21h, 24h

    db 77h, 71h  ; 白底蓝色
    db 65h, 71h
    db 6ch, 71h
    db 63h, 71h
    db 6fh, 71h
    db 6dh, 71h
    db 65h, 71h
    db 20h, 71h
    db 74h, 71h
    db 6fh, 71h
    db 20h, 71h
    db 6dh, 71h
    db 61h, 71h
    db 73h, 71h
    db 6dh, 71h
    db 21h, 71h
data ends

code segment
start:
    mov ax, data
    mov ds, ax 
    mov ax, 0b800h
    mov es, ax

    mov bx, 0
    mov si, 0680h; 第一行 绿色
    mov cx, 16
  s:
    mov ax, [bx]
    mov es:[si], ax 
    add bx, 2
    add si, 2
    loop s

    mov bx, 32
    mov si, 0720h; 第二行 绿底红色
    mov cx, 16
 s0:
    mov ax, [bx]
    mov es:[si], ax 
    add bx, 2
    add si, 2
    loop s0

    mov bx, 64
    mov si, 07c0h; 第三行 白底蓝字
    mov cx, 16
 s1:
    mov ax, [bx]
    mov es:[si], ax 
    add bx, 2
    add si, 2
    loop s1
    mov ax, 4c00h

    int 21h
code ends

end start
