assume cs:code, ds:data
data segment
    db 'welcome to masm!'
    db '................'
data ends

code segment
start:
        mov ax, data
        mov ds, ax
        mov si, 0
        mov di, 16

        mov cx, 16
      s:
        mov al, ds:[si]
        mov ds:[di], al  
        inc si
        inc di
        loop s

        mov ax, 4c00h
        int 21h
code ends

end start
