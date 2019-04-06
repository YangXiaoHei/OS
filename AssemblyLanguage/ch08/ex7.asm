assume cs:code, ds:data, es:table

data segment    
    db '1975', '1976', '1977', '1978', '1979', '1980', '1981', '1982', '1983'
    db '1984', '1985', '1986', '1987', '1988', '1989', '1990', '1991', '1992'
    db '1993', '1994', '1995'

    dd 16, 22, 382, 1356, 2390, 8000, 16000, 24486, 50065, 97479, 140417, 197514
    dd 345980, 590827, 803530, 1183000, 1843000, 2759000, 3753000, 4649000, 5937000

    dw 3, 7, 9, 13, 28, 38, 130, 220, 476, 778, 1001, 1442, 2258, 2793, 4037, 5635, 8226
    dw 11542, 14430, 15257, 17800
data ends

table segment
    db 21 dup ('year summ ne ?? ')
table ends

code segment
start:
    mov ax, data
    mov ds, ax
    mov ax, table
    mov es, ax

    sub di, di
    sub si, si
    sub bx, bx

    mov cx, 21
  s:
    mov ax, [si]
    mov es:[di], ax
    mov ax, [si+2]
    mov es:[di+2], ax               ; 年份
    mov byte ptr es:[di+4], ' '     ; 空格

    mov ax, [si+84]
    mov es:[di+5], ax
    mov ax, [si+86]
    mov es:[di+7], ax               ; 总收入
    mov byte ptr es:[di+9], ' '     ; 空格

    mov ax, [bx+168]
    mov es:[di+10], ax              ; 雇员
    mov byte ptr es:[di+12], ' '    ; 空格

    mov ax, [si+84]
    mov dx, [si+86]
    div word ptr [bx+168]
    mov es:[di+13], ax              ; 人均收入
    mov byte ptr es:[di+15], ' '    ; 空格 

    add si, 4
    add di, 10h
    add bx, 2
    loop s

    mov ax, 4c00h
    int 21h
code ends

end start
