assume cs:code

code segment
    
    dw 0123h, 4567h, 89abh, 0cdefh
    
    start :
            mov ax, 0
            mov bx, 0
            mov cx, 10h
          s:add ax, cs:[bx]
            add bx, 2
            loop s

            mov ax, 4c00h
            int 21h

code ends

end start
