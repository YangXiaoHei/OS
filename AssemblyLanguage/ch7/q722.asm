assume cs:code, ds:data

code segment
    mov ax, data
    mov ds, ax
    mov si, 0
    mov di, 16

    mov cx, 8
  s:
    mov ax, [si]
    mov [di], ax
    add si, 2
    add di, 2
    loop s

    mov ax, 4c00h
    int 21h
code ends

data segment
    db 'welcome to masm!'
    db '................'
data ends

end
