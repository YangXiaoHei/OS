assume cs:code

code segment
    dw 0123h, 0456h, 0789h, 0abch, 0defh, 0fedh, 0cbah, 0987h
    start:
            mov ax, 0
            mov ss, ax
            mov sp, 300h

            mov cx, 8
            mov bx, 0
          s:push cs:[bx]
            add bx, 2
            loop s

            mov bx, 0
            mov cx, 8
         s0:pop cs:[bx]
            add bx, 2
            loop s0

            mov ax, 4c00h
            int 21h
code ends
end start
