#### PC 和 CS:IP 的区别是什么？
* PC 和 CS:IP 的含义是一致的，都是存放 CPU 将要执行的下一条指令地址的寄存器。据我猜测，之所以这里只用到一个寄存器，是因为 `x86_64` 位的 CPU 地址总线宽度和字长一致，不像 8086 CPU，地址总线是 20 位，而字长是 16 位。因此需要 CS 存段地址，IP 存偏移地址，再把它们合为一个 20 位的地址。

#### C 语言程序翻译成可执行目标文件经历哪几个过程？

* 1、预处理器处理。`gcc -E`
	* 预处理器将 #include 指明导入的头文件中的内容拷贝过来，当然，忽略了条件编译语句中被忽略的代码。
	* 展开 #define 宏。
* 2、C 语言编译器 `gcc -S`
	* 将 C 语言编译为汇编代码
* 3、汇编编译器
	* 将汇编代码编译为机器码
* 4、连接（还不是很懂）
	* 将程序中用到的函数定义的 .o 文件和该文件合并成最终的可执行文件。

#### hello 程序的运行经历了哪些复制阶段？

* 从磁盘被复制到主存
* 从主存被复制到指令缓冲期

#### 描述 Amdahl 定律

* 提升系统某一部分性能所带来的效果的观察就是 Amdahl 定律描述的内容。
* 提升系统某一部分性能给整体带来的改善取决于该部分的重要性，以及改善的程度。
* `S(Told/Tnew) = 1 / ((1-a) + a/k)`

#### 操作系统的两个基本功能

* 防止失控的软件对硬件的滥用
* 对应用层提供简单统一的机制来管理下层复杂并且各不相同的低级硬件设备，比如 read, write 的使用的描述符，即可能是套接字描述符，也可能是目录文件描述符，也可能是管道或者其他，这些文件的读写统一用 read 和 write 就可以完成，但它们里面的实现机制是不尽相同的。

#### 操作系统实现上述两个基本功能提供的抽象有

* 文件、进程、虚拟内存
* 文件是对 IO 设备的抽象，进程是对 IO 设备、主存和处理器的抽象，虚拟内存是对主存和 IO 设备的抽象。

#### 一个 CPU 看上去像是在并发执行多个进程，这是怎么实现的

* 一个 CPU 看上去像是在并发执行多个进程，这是处理器在不同进程间切换执行模拟出的并发效果，因为 CPU 切换很快，所以看上去好像都在同时被执行。

#### CPU 在不同进程间切换时都做了什么？

* CPU 从进程 A 切换时，首先将当时使用的上下文信息保存起来。比如 8086 CPU，将标志寄存器入栈，TF、IF 设置为 0，TF 设置为 0 是防止执行一条指令后进入继续执行单步中断程序的死循环，IF 置为 0 是防止执行中断程序时被可屏蔽中断打断。然后 CS 入栈，IP 入栈（下一条要执行的指令地址入栈， CPU 切换回来时从栈中拿出接下来要执行的指令地址）。最后将 CS, IP 设置为当前所要执行的指令的地址。虽然不是 8086 CPU，但本质思想肯定是一样的。

















