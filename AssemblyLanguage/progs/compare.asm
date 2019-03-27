assume cs:code

code segment
    mov ax, 2000h
    mov ds, ax

    mov al, [0]
    mov ah, [1]
    mov bl, [2]
    mov bh, [3]

code ends

end
