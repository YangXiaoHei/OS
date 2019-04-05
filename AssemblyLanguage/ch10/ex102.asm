assume cs:code

code segment
    
    ; ax dword 型数据的低 16 位
    ; dx dword 型数据的高 16 位
    ; cx 除数
    ; 返回  dx 结果的高 16 位，ax 结果的低 16 位
    ; cx 余数
divdw:
    jmp short div_code
    instk dw 8 dup (0)
div_code:
    mov bx, instk       ; 方便的访问内部栈空间
    mov ds, bx

    mov ds:[0], ax,     ; [0] 保存 L
    mov ax, dx          ; ax 保存 H

    div cx              ; rem(H/N) ax 保存 H, cx 保存 N, [0] 保存 L 
    
    ; 上面这步得到了余数和商，分别保留下来
    mov ds:[2], ax      ; int(H/N)  商
    mov ds:[4], dx      ; rem(H/N)  余数
    mov ax, dx

    mov bx, 512
    mul bx
    mov bx, 128
    mul bx              ; rem(H/N) * 65536

    add ax, ds:[0]      ; rem(H/N) * 65536 + L
    div cx

    

code ends

end


