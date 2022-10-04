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

虽然顺序表和链表都适用于队列，但是我们可以发现链表明显更优，这是因为顺序表如果一端为队头，一端为队尾，我们需要进行挪动数组的操作，非常麻烦。接下来我们就用链表来实现一下队列。

## 实现队列

### 头文件

由于队列的概念要求我们记录队头和队尾，所以我们要在建立QueueNode结构体的基础上再编写一个Queue结构体，QueueNode结构体里放的是next和data，Queue结构体里放的是头节点和尾节点的地址。

```c
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int QDataType;
typedef struct QueueNode
{
    struct QueueNode *next;
    QDataType data;
}QueueNode;

typedef struct Queue
{
    QueueNode *head;
    QueueNode *tail;
}Queue;

void QueueInit(Queue *pq);
void QueueDestroy(Queue *pq);
void QueuePush(Queue *pq, QDataType x);
void QueuePop(Queue *pq);
QDataType QueueFront(Queue *pq);
QDataType QueueBack(Queue *pq);
int QueueSize(Queue *pq);
bool QueueEmpty(Queue *pq);
```

### void QueueInit(Queue *pq)

初始化，初始化只需要让头和尾都指向NULL即可。

```c
void QueueInit(Queue *pq)
{
    assert(pq);
    pq->head = NULL;
    pq->tail = NULL;
}
```

### void QueueDestroy(Queue *pq)

销毁，只需要从头开始，定义cur，cur往后走，一个接一个的销毁，直到全部销毁完毕，随后让头和尾指向空即可。因为free(cur) 后我们无法找到下一个节点，需要提前定义变量储存好。

```c
void QueueDestroy(Queue *pq)
{
    assert(pq);
    QueueNode *cur = pq->head;
    while (cur)
    {
        QueueNode *next = cur->next;
        free(cur);
        cur = next;
    }
    pq->head = pq->tail = NULL;
}
```

### void QueuePush(Queue *pq, QDataType x)

添加节点，由于队列是先进先出，也就是队尾进，队头出，所以我们需要尾插。这时候，我们先前定义的tail就有了用场。

在这里我们先写了一个函数是获取新的节点，并直接把x赋给新节点的data位置。随后，需要注意的是如果pq->head = pq->tail = NULL，这个时候不能按照常理处理，因为pq->tail->next是对空指针的解引用，是错误的。所以需要另外添加条件判断。

```c
QueueNode *Buynewnode(Queue *pq, QDataType x)
{
    assert(pq);
    QueueNode *newnode = (QueueNode *)malloc(sizeof(QueueNode));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}
void QueuePush(Queue *pq, QDataType x)
{
    assert(pq);
    if (pq->tail == NULL)
    {
        pq->tail = pq->head = Buynewnode(pq, x);
    }
    else
    {
        QueueNode *newnode = Buynewnode(pq, x);
        pq->tail->next = newnode;
        pq->tail = newnode;
    }
}
```

### void QueuePop(Queue *pq)

头删，很多伙伴会把头删的函数写成如下

---

错误：

```c
void QueuePop(Queue *pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));

    QueueNode *next = pq->head->next;
    free(pq->head);
    pq->head = next;
}
```

---

可以发现，我们的确把所有的节点都free删除完了，但是并未解除pq->tail的指向，所以需要这么写：

```c
void QueuePop(Queue *pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));

    QueueNode *next = pq->head->next;
    free(pq->head);
    pq->head = next;
    if(pq->head == NULL)
    {
        pq->tail = NULL;
    }
}
```

### QDataType QueueFront(Queue *pq);

```c
QDataType QueueFront(Queue *pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    //队尾
    return pq->head->data;
}
```

### QDataType QueueBack(Queue *pq)

```c
QDataType QueueBack(Queue *pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    //队尾
    return pq->tail->data;
}
```

### int QueueSize(Queue *pq)

```c
int QueueSize(Queue *pq)
{
    assert(pq);
    int n = 0;
    QueueNode *cur = pq->head;
    while(cur)
    {
        ++ n;
        cur = cur->next;
    }
    return n;
}
```

### bool QueueEmpty(Queue *pq)

```c
bool QueueEmpty(Queue *pq)
{
    assert(pq);
    return pq->head == NULL;
}
```

# 队列的题目

## [用队列实现栈](https://leetcode.cn/problems/implement-stack-using-queues/)

请你***仅使用两个队列实现一个后入先出（LIFO）的栈***，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

实现 MyStack 类：

void push(int x) 将元素 x 压入栈顶。
int pop() 移除并返回栈顶元素。
int top() 返回栈顶元素。
boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。


注意：

你只能使用队列的基本操作 —— 也就是 push to back、peek/pop from front、size 和 is empty 这些操作。
你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/implement-stack-using-queues
![CleanShot 2022-10-04 at 15.50.06@2x](/Users/amor/Library/Application Support/CleanShot/media/media_ZNYJVpmzVG/CleanShot 2022-10-04 at 15.50.06@2x.png)

### 思路

1. 入数据，往不为空的队列入。保证一个为空。
2. 出数据，一次出队头的数据，转移另一个队列保存，只剩最后一个时Pop掉。

### 实现

首先我们都建立在刚刚写的队列的基础之上，所以第一步就是把刚刚编写的队列的代码都复制过来。

题目要求我们自己编写结构体，题目中写明两个队列，我们需要如下编写结构体：

```c
typedef struct {
    Queue q1;
    Queue q2;
} MyStack;
```

结构体的创建和初始化。

```c
MyStack* myStackCreate() {
//我们不能直接定义变量然后返回他的地址，因为本身这个局部变量出函数就销毁了。
//只能malloc
    MyStack* st = (MyStack*)malloc(sizeof(MyStack));//st是malloc出来的节点的地址
    QueueInit(&st->q1);
    QueueInit(&st->q2);
    return st;//返回的是地址用一级指针接收
}
```

需要如此接收：

```c
MyStack* st = myStackCreate();
```

Push函数：我们往队列中Push，是添加到队尾中，我们只需要在队列中按顺序添加即可。注意我们的中心思想就是保证一个队列为空，从而可以按栈的规则删除节点。

```c
void myStackPush(MyStack* obj, int x) {
    //传的是一级指针obj，是st的地址，obj->q1就是q1这个队列
    //QueueEmpty需要传递的是Queue的地址，所以需要取地址
    if(!QueueEmpty(&obj->q1))
    {
        QueuePush(&obj->q1,x);
    }
    else
    {
        QueuePush(&obj->q2,x);
    }
}
```

Pop函数：我们如果区分q1和q2哪个为空而哪个不为空，就会出现两套极其类似而重复冗余的代码，所以我们设定qEmpty和qNonEmpty两个新队列，前者接收空的队列，后者接收不空的队列。

```c
int myStackPop(MyStack* obj) {
    Queue* qEmpty = &obj->q1;
    Queue* qNonEmpty = &obj->q2;
    if(!QueueEmpty(&obj->q1))
    {
        qEmpty = &obj->q2;
        qNonEmpty = &obj->q1;
    }
    while(QueueSize(qNonEmpty)>1)
    {
        QueuePush(qEmpty,QueueFront(qNonEmpty));
        QueuePop(qNonEmpty);
    }
    int top = QueueFront(qNonEmpty);
    QueuePop(qNonEmpty);
    return top;
}
```

Top函数：因为我们本来队列就是有找尾的接口的，所以可以直接用。

```c
int myStackTop(MyStack* obj) {
    if(!QueueEmpty(&obj->q1))
    {
        return QueueBack(&obj->q1);
    }
    else
        return QueueBack(&obj->q2);
}
```

```c
bool myStackEmpty(MyStack* obj) {
    return QueueEmpty(&obj->q1)&&QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
    QueueDestroy(&obj->q1);
    QueueDestroy(&obj->q2);
    free(obj);
}
```

### 代码

```c
typedef int QDataType;
typedef struct QueueNode
{
    struct QueueNode *next;
    QDataType data;
}QueueNode;

typedef struct Queue
{
    QueueNode *head;
    QueueNode *tail;
}Queue;

void QueueInit(Queue *pq)
{
    assert(pq);
    pq->head = NULL;
    pq->tail = NULL;
}
void QueueDestroy(Queue *pq)
{
    assert(pq);
    QueueNode *cur = pq->head;
    while (cur)
    {
        QueueNode *next = cur->next;
        free(cur);
        cur = next;
    }
    pq->head = pq->tail = NULL;
}
QueueNode *Buynewnode(Queue *pq, QDataType x)
{
    assert(pq);
    QueueNode *newnode = (QueueNode *)malloc(sizeof(QueueNode));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}
void QueuePush(Queue *pq, QDataType x)
{
    assert(pq);
    if (pq->tail == NULL)
    {
        pq->tail = pq->head = Buynewnode(pq, x);
    }
    else
    {
        QueueNode *newnode = Buynewnode(pq, x);
        pq->tail->next = newnode;
        pq->tail = newnode;
    }
}
int QueueEmpty(Queue *pq)
{
    assert(pq);
    return pq->head == NULL;//空则返回1
}
void QueuePop(Queue *pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));

    QueueNode *next = pq->head->next;
    free(pq->head);
    pq->head = next;
    if(pq->head == NULL)
    {
        pq->tail = NULL;
    }
}
QDataType QueueFront(Queue *pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    //队尾
    return pq->head->data;
}
QDataType QueueBack(Queue *pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    //队尾
    return pq->tail->data;
}
int QueueSize(Queue *pq)
{
    assert(pq);
    int n = 0;
    QueueNode *cur = pq->head;
    while(cur)
    {
        ++ n;
        cur = cur->next;
    }
    return n;
}


typedef struct {
    Queue q1;
    Queue q2;
} MyStack;


MyStack* myStackCreate() {
//我们不能直接定义变量然后返回他的地址，因为本身这个局部变量出函数就销毁了。
//只能malloc
    MyStack* st = (MyStack*)malloc(sizeof(MyStack));//st是malloc出来的节点的地址
    QueueInit(&st->q1);
    QueueInit(&st->q2);
    return st;//返回的是地址用一级指针接收
}

void myStackPush(MyStack* obj, int x) {
    //传的是一级指针obj，是st的地址，obj->q1就是q1这个队列
    //QueueEmpty需要传递的是Queue的地址，所以需要取地址
    if(!QueueEmpty(&obj->q1))
    {
        QueuePush(&obj->q1,x);
    }
    else
    {
        QueuePush(&obj->q2,x);
    }
}

int myStackPop(MyStack* obj) {
    Queue* qEmpty = &obj->q1;
    Queue* qNonEmpty = &obj->q2;
    if(!QueueEmpty(&obj->q1))
    {
        qEmpty = &obj->q2;
        qNonEmpty = &obj->q1;
    }
    while(QueueSize(qNonEmpty)>1)
    {
        QueuePush(qEmpty,QueueFront(qNonEmpty));
        QueuePop(qNonEmpty);
    }
    int top = QueueFront(qNonEmpty);
    QueuePop(qNonEmpty);
    return top;
}

int myStackTop(MyStack* obj) {
    if(!QueueEmpty(&obj->q1))
    {
        return QueueBack(&obj->q1);
    }
    else
        return QueueBack(&obj->q2);
}

bool myStackEmpty(MyStack* obj) {
    return QueueEmpty(&obj->q1)&&QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
    QueueDestroy(&obj->q1);
    QueueDestroy(&obj->q2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
```

## [用栈实现队列](https://leetcode.cn/problems/implement-queue-using-stacks/)

请你***仅使用两个栈实现先入先出队列***。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

实现 MyQueue 类：

- void push(int x) 将元素 x 推到队列的末尾

- int pop() 从队列的开头移除并返回元素

- int peek() 返回队列开头的元素

- boolean empty() 如果队列为空，返回 true ；否则，返回 false

  说明：

你 ***只能 使用标准的栈操作*** —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/implement-queue-using-stacks
![CleanShot 2022-10-04 at 17.16.45@2x](/Users/amor/Library/Application Support/CleanShot/media/media_1McsHjdUNn/CleanShot 2022-10-04 at 17.16.45@2x.png)

### 思路

栈如果从一个栈倒到另外一个栈，顺序会恰好相反，所以我们应该考虑是否要把其再倒回来从而让顺序和原来一致。

但是并不需要如此，因为，我们将一个栈s1的数据倒到另外一个栈s2之后，s2可以用作是出栈口，如果要输入值到栈内，可以直接输入到s1中，我们直接定义PushST和PopST入栈和出栈两个栈。

### 代码

类似上面用队列实现栈的题目，所以不再赘述。

```c

typedef int STDataType;
typedef struct Stack
{
    STDataType *a;
    int top;
    int capacity;
} ST;

void StackInit(ST *ps)
{
    assert(ps);
    ps->a = NULL;
    ps->top = 0; //初始化时top给0，意味着top指向栈顶数据的下一个
    ps->capacity = 0;
}
void StackDestroy(ST *ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->capacity = ps->top = 0;
}
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
            exit(-1);
        }
        ps->a = tmp;
        ps->capacity = newCapacity;
    }
    ps->a[ps->top] = x;
    ps->top++;
}
void StackPop(ST *ps)
{
    assert(ps);
    assert(ps->top > 0);
    //或者用assert(!StackEmpty(ps));
    ps->top--;
}
STDataType StackTop(ST *ps)
{
    assert(ps);
    assert(ps->top > 0);
    //或者用assert(!StackEmpty(ps));
    return ps->a[ps->top - 1];
}
int StackSize(ST *ps)
{
    assert(ps);
    return ps->top;
}
bool StackEmpty(ST *ps)
{
    assert(ps);
    return ps->top == 0;
    //空则返回1，真
}

typedef struct {
    ST pushST;
    ST popST;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&q->pushST);
    StackInit(&q->popST);
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    StackPush(&obj->pushST,x);
}

int myQueuePop(MyQueue* obj) {
    //如果popST里没有数据就把pushST数据倒过去。
    if(StackEmpty(&obj->popST))
    {
       while(!StackEmpty(&obj->pushST))
       {
           StackPush(&obj->popST,StackTop(&obj->pushST));
           StackPop(&obj->pushST);
       } 
    }
    int front = StackTop(&obj->popST);
    StackPop(&obj->popST);
    return front;
}

int myQueuePeek(MyQueue* obj) {
    //如果popST里没有数据就把pushST数据倒过去。
    if(StackEmpty(&obj->popST))
    {
       while(!StackEmpty(&obj->pushST))
       {
           StackPush(&obj->popST,StackTop(&obj->pushST));
           StackPop(&obj->pushST);
       } 
    }
    return StackTop(&obj->popST);
}

bool myQueueEmpty(MyQueue* obj) {
    return StackEmpty(&obj->popST) && StackEmpty(&obj->pushST);
}


void myQueueFree(MyQueue* obj) {
    StackDestroy(&obj->popST);
    StackDestroy(&obj->pushST);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
```

## [设计循环队列](https://leetcode.cn/problems/design-circular-queue/)

设计你的循环队列实现。 ***循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。***

循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。

你的实现应该支持如下操作：

- MyCircularQueue(k): 构造器，设置队列长度为 k 。
- Front: 从队首获取元素。如果队列为空，返回 -1 。
- Rear: 获取队尾元素。如果队列为空，返回 -1 。
- enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
- deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
- isEmpty(): 检查循环队列是否为空。
- isFull(): 检查循环队列是否已满。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/design-circular-queue

![CleanShot 2022-10-04 at 18.12.06@2x](/Users/amor/Library/Application Support/CleanShot/media/media_ZixL9KbqZY/CleanShot 2022-10-04 at 18.12.06@2x.png)

### 思路

循环队列的特点是：

1. 可以用数组实现，也可以使用循环链表实现。
2. 固定空间，只能存储k个值
3. 无论使用什么方法实现，都要多开一个空间。所以要存k个数据的循环队列，要开k+1个空间，否则无法实现判空和判满。

分析链表：front = tail  就是循环队列空。判满：front = tail也是满，这就出现了一个问题：***要存k个数据的循环队列，要开k+1个空间***。数组的话亦然。

最终

- 链表的判满是 tail->next = front，判空条件是相等。
- 顺序表的判满是 (tail+1)%(k+1) == front则为满，相等为空，tail和front是下标。

### 实现

#### 首先用顺序表实现

```c
typedef struct {
    int* a;
    int front;
    int tail;
    int k;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->tail; 
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->tail+1)%(obj->k+1) == (obj->front);
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
    free(obj);
}
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    q->front = 0;
    q->tail = 0;
    q->a = malloc(sizeof(int)*(k+1));
    q->k = k;
    
    return q;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj))
        return false;
    else
    {
        obj->a[obj->tail] = value;
        ++obj->tail;
        obj->tail %= obj->k+1;
        return true;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return false;
    else
    {
        ++obj->front;
        obj->front %= (obj->k+1);
        return true;
    }
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return -1;
    return obj->a[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return -1;
    if(obj->tail)
        return obj->a[obj->tail-1];
    else{
        return obj->a[obj->k];
        }
}



/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
```

