# 函数栈帧的创建和销毁

本文浅述函数栈帧的创建和销毁。

在我们前期的学习过程中，可能会遇到很多困惑比如，

- 局部变量是怎么创建的？
- 为什么局部变量是随机值？
- 函数是怎么传参的？传惨的顺序是怎样的？
- 形参和实参是什么关系？
- 函数调用是怎么做的？
- 函数调用结束后是怎么返回的？

如果知道函数栈帧的创建和销毁后就都清楚了。在不同的编译器下，函数栈帧的创建和销毁稍有差异，但大体相同。

寄存器分为：

- eax
- ebx
- ecx
- edx
- ebp
- esp

要理解函数栈帧就必须要理解ebp，esp这两个寄存器，这两个存放的是地址。这两个地址是用来维护函数栈帧的。

每一个函数调用，都要在栈区开辟一个空间，然后这块空间是由ebp和esp来维护的。我们默认栈是从高地址走向低地址。其中ebp(栈底指针)存放的是函数栈帧中的高地址，esp(栈顶指针)存放的是低地址，他们中间的这块空间就是函数的栈帧。

在vs2013中，main函数被其他函数调用。简言之，被别的函数调用其实就是别的函数的栈帧会在main函数的栈底的下面。因为main是由别的函数调用的，就势必先调用其他的函数，这个函数先被调用，就是它的栈帧创建得更早，就在main栈帧的下面。

## 栈帧创建的具体过程：

1. push(ebp)，压栈。就是把上个函数栈帧的ebp储存的地址压入栈顶。push完后，esp会向低地址处走，地址会-4。因为函数栈帧从高地址流向低地址。
2. mov(esp, ebp)，传递地址。就是把esp的地址给到ebp。意思就是ebp不再指向原来的函数栈底，而是指向原来函数的栈顶，（也是新函数的栈底）。
3. sub(esp)，给esp减去一个八进制的数字，让其指向更低地址处。改变新函数的栈顶。

这样，就为新函数预开辟好了空间。

随后push：ebx, esi, edi.

4. lea (edi, [ebp-0E4h])  -- (load effective )：把[ebp-0E4h]这个地址传给edi

5. mov (ecx,39h) ： 

6. mov (eax,0CCCCCCCCh)

7. rep stos (dword ptr es: [edi])  

   4，5，6，7的作用是：从edi开始，39h次 个double word （4字节）全部初始化成0CCCCCCCCh，就是全部变成ccccccccc

   刚刚开辟的那一块为函数开辟的栈帧全部变成了cccccccc，就是初始化main函数好了。

8. 假设下一个操作时int a = 10; ， mov (dword, ptr [ebp-8], 0Ah), 把0Ah的值给到[ebp-8]的位置处。如果不初始化，而只是给到变量，int a;，那么内存中存放的就是 0cccccccch就是烫烫烫烫烫烫

9. 假设下一个操作时int b = 20; ， mov (dword, ptr [ebp-14], 14h), 把014h的值给到[ebp-14]位置处。

10. 假设下一个操作是简单的Add函数，其进行的操作为 

    最一开始就进行传参）

    - mov (eax, dword ptr [ebp-14h]) ，把ebp-14h的地址给到eax，就是把20这个值给到eax

    - push (eax)，eax压栈，把20压进去了。传参b

    - mov (ecx, dword ptr [ebp-8h])，把ebp-8h的地址给到ecx，就是把10这个值给到ecx

    - push (ecx)，ecx压栈，把10压进去了。传参a

    - call (一个地址px)，调用函数，也就是call指令的下一个地址变成了px

    - 随后真正来到了px地址，也就是***调用Add函数***。

      - push (ebp)，把ebp的值压栈

      - mov (ebp,esp) 把esp给到ebp，ebp现在指向了esp的地址

      - sub (esp, 0CCh), esp减去0cch的值，指向更低的地址

        以上三个步骤，开辟add函数栈帧

      - push -ebp, -esi, -edi, 将三个寄存器地址push进栈帧

      - lea (edi, [ebp+FFFFFF34h] )

      - mov (ecx, 33h)

      - mov (eax, 0CCCCCCCCh) 

      - rep stos (dword ptr es:[edi])，把add栈帧全部初始化为cccccccc 

      - mov (dword ptr [ebp-8], 0) -- int z = 0

      - Z = x + y; 

        - mov (eax, dword ptr [ebp+8] ), 找到原来push过来的a的值，挪到eax处
        - add (eax,dword ptr [ebp+0Ch])，把ebp+12的值加到eax里面，就是得到了30
        - mov (dword ptr [ebp-8] eax)，把eax的值放到ebp-8里面去。放到z里面去了。

      - return z; 

        - mov (eax, dword ptr [ebp-8])，把ebp-8的值放到eax寄存器里，(相当于用全局的寄存器储存了一个变量，否则一会就销毁了)

        

        - pop -edi, -esi, -ebx;
        - mov (esp,ebp)，把ebp赋给esp，esp指向ebp指向的位置
        - pop (ebp)，把栈顶元素删除，就是把ebp里面存的main函数地址删除，这样ebp不在指向栈顶，而是回到原来的指向，即栈底，main函数的栈底，而esp也不在指向原来ebp的指向位置，而是向下一个位置，因为栈顶元素pop掉了，需要下移一个。
        - ret ，是返回call指令的下一条指令的地址

    - add (esp, 8), 把esp的地址+8，也就是把a和b两个形参释放

    - mov (dword ptr [ebp-20h], eax) , 把eax的值给到ebp-20，eax原本是我们存的add返回值，这样我们就把返回值带回到ebp-20了。
