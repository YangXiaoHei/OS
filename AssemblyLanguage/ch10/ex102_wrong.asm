assume cs:code

code segment
start:
    mov ax, 12345
    mov dx, 60000
    mov cx, 10
    call divdw

    mov ax, 4c00h
    int 21h
    
    ; ax dword 型数据的低 16 位
    ; dx dword 型数据的高 16 位
    ; cx 除数
    ; 返回  dx 结果的高 16 位，ax 结果的低 16 位
    ; cx 余数
divdw:
    jmp short div_code
    instk dw 8 dup (0)
div_code:
    cmp dx, cx
    jb divnflo

    push bx
    push ds

    mov bx, instk       ; 方便的访问内部栈空间
    mov ds, bx

    mov ds:[0], ax      ; [0] 保存 L
    mov ax, dx          ; ax 保存 H
    mov dx, 0           ; 清空 dx，因为除数为 16 位

    div cx              ; rem(H/N) ax 保存 H, cx 保存 N, [0] 保存 L 
    
    ; 上面这步得到了余数和商，分别保留下来
    mov ds:[2], ax      ; int(H/N)  商
    mov ds:[4], dx      ; rem(H/N)  余数
    mov ax, dx
    mov dx, 0

    mov bx, 512
    mul bx
    mov bx, 128
    mul bx              ; rem(H/N) * 65536  上述乘法可能已经填充了 dx

    add ax, ds:[0]      ; rem(H/N) * 65536 + L
    div cx              ; (rem(H/N) * 65536 + L) / N
    mov cx, dx

    ; 至此，公式的后半部分计算完毕
    ; 保留计算结果到内存
    mov ds:[6], ax
    mov ds:[8], dx
    
    ; 接下来计算公式的前半部分
    mov ax, ds:[2]
    mov dx, 0
    mul bx
    mov bx, 512
    mul bx

    ;加法会不会溢出啊？？？疑问...
    add ax, ds:[6]
    add dx, ds:[8]

    pop ds
    pop bx
    ret
divnflo:
    div cx
    mov cx, dx
    sub dx, dx 
    ret
code ends

end start


