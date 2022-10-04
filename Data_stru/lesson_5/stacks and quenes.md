# 栈

## 栈的概念和结构

栈是一种特殊的线性表，其只允许在固定的一端进行插入和删除元素操作。进行数据插入和删除操作的一段成为栈顶，另一段称为栈底。栈中数据元素遵循先进后出(后进先出LIFO - last in first out)的原则。

- 压栈：栈的插入操作叫做进栈/压栈/入栈，入数据在栈顶。

- 出栈：栈的删除操作叫做出栈，出数据也在栈顶。

栈的选择，可以是顺序栈和链式栈。

***链式栈***

- 如果尾做栈顶，尾插尾删，要设计成双向链表，否则删除数据效率低。

- 如果头做栈顶，头插头删，就可以设计成单向链表。

但是二者中如果选一个，就选顺序栈，因为顺序栈具有很大的优势。

## 实现栈

### 头文件

```c
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int STDataType;
typedef struct Stack
{
    STDataType *a;
    int top;
    int capacity;
} ST;
//欲实现的功能
void StackInit(ST *ps);
void StackDestroy(ST *ps);
void StackPush(ST *ps,STDataType x);
void StackPop(ST *ps);
STDataType StackTop(ST *ps);
int StackSize(ST *ps);
bool StackEmpty(ST *ps);
```

### StackInit(ST *ps)

初始化需要对ps里的每个成员进行赋值。其中top需要注意的是：初始化时top给0，意味着top指向栈顶数据的下一个。

```c
StackInit(ST *ps)
{
    assert(ps);
    ps->a = NULL;
    ps->top = 0;
    ps->capacity = 0;
}
```

### StackDestroy(ST *ps)

```c
void StackDestroy(ST *ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->capacity = ps->top = 0;
}
```

### StackPush(ST *ps,STDataType x)

```c
void StackPush(ST *ps, STDataType x)
{
    assert(ps);
    //考虑增容
    if (ps->top == ps->capacity)
    {
        //给定大小
        int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
        //开辟空间
        STDataType *tmp = realloc(ps->a, sizeof(STDataType) * newCapacity);
        if (!tmp)
        {
            perror("realloc");
            return -1;
        }
        ps->a = tmp;
        ps->capacity = newCapacity;
    }
    ps->a[ps->top] = x;
    ps->top++;
}
```

### StackPop(ST *ps)

```c
void StackPop(ST *ps)
{
    assert(ps);
    assert(ps->top > 0);
    //或者用assert(!StackEmpty(ps));
    ps->top--;
}
```

### STDataType StackTop(ST *ps)

```c
STDataType StackTop(ST *ps)
{
    assert(ps);
    assert(ps->top > 0);
    //或者用assert(!StackEmpty(ps));
    return ps->a[ps->top - 1];
}
```

### int StackSize(ST *ps)

```c
int StackSize(ST *ps)
{
    assert(ps);
    return ps->top;
}
```

### bool StackEmpty(ST *ps)

```c
bool StackEmpty(ST *ps)
{
    assert(ps);
    return ps->top == 0;
}
```

### 取出数据

为遵循后进先出的原则，我们只能打印栈顶的元素后让其出栈

```c
    while(!StackEmpty(&st))
    {
        printf("%d ", StackTop(&st));
        StackPop(&st);
    }
```

# 栈的题目

## [有效的括号](https://leetcode.cn/problems/valid-parentheses/)

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/valid-parentheses

![CleanShot 2022-10-04 at 10.57.56@2x](/Users/amor/Library/Application Support/CleanShot/media/media_gfT3c1cOgm/CleanShot 2022-10-04 at 10.57.56@2x.png)

### 思路

左括号入栈，右括号出栈匹配。这样就可以一一对应了。

***我们仍旧使用我们先前创建的栈和接口函数。***(C的环境下题目中需要复制原来写好的代码)

- 创建栈

```c
	ST st;
	StackInit(&st);
```

- 左括号入栈

```c
 while(*s)
    {
        if(*s == '[' || *s == '{' || *s == '(')
        {
            StackPush(&st,*s);
            ++s;
        }
```

- 右括号，出栈，判断是否匹配

```c
  else
        {
            STDataType top = StackTop(&st);
            StackPop(&st);
            if((*s == ']' && top != '[')
             ||(*s == '}' && top != '{')
             ||(*s == ')' && top != '('))
             {
                StackDestroy(&st); 
                return false;
             }
             else
             {
                ++s;
             }
        }
```

- 如果栈不为空，说明栈中还有左括号未出栈，没有匹配

```c
    bool ret = StackEmpty(&st);
    StackDestroy(&st);
    return ret;
```

发现一个问题，如果只有一个右括号，程序会崩溃，这是因为我们在***StackPop***里面加了断言，断言栈不为空，但是只有一个右括号来判断时，栈为空，所以需要在前面加一个是否为空的判断，如果是则直接返回false。

```c
 //遇到右括号，但栈为空，说明不匹配
            if(StackEmpty(&st))
            {                
             		StackDestroy(&st);
								return false;
            }
```

### 代码

```c
bool isValid(char * s){
    ST st;
    StackInit(&st);
    while(*s)
    {
        if(*s == '[' || *s == '{' || *s == '(')
        {
            StackPush(&st,*s);
            ++s;
        }
        else
        {
            //遇到右括号，但栈为空，说明不匹配
            if(StackEmpty(&st))
            {
                StackDestroy(&st);
                return false;
            }
            STDataType top = StackTop(&st);
            StackPop(&st);
            if((*s == ']' && top != '[')
             ||(*s == '}' && top != '{')
             ||(*s == ')' && top != '('))
             {
                StackDestroy(&st); 
                return false;
             }
             else
             {
                ++s;
             }
        }
    }
    //如果栈不为空，说明栈中还有左括号未出栈
    //没有匹配
    bool ret = StackEmpty(&st);
    StackDestroy(&st);
    return ret;
}
```

注意：我们创建了栈，就必须要进行销毁。

# 队列

## 队列的概念和结构

队列：只允许在一段进行插入数据操作，在另外一段进行删除数据操作的特殊线性表，队列具有***先进先出FIFO***的特点。

- 入队列：进行插入操作的一段称为队尾。
- 出队列：进行删除操作的一段称为队头。