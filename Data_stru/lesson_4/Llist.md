# Bi-directional linked List

## 链表的分类

- 单向或者双向
- 带头或者不带头(哨兵位的头节点，不储存有效数据)
- 循环或者非循环(循环是特殊的环链表，最后一个指向第一个节点)

总共2^3 = 8种排列组合，但是并不是说我们需要全部学习，我们世纪中最常用的是两种结构：

- 无头单向非循环链表
- 带头双向循环链表

看上去带头双向循环比较难实现，但实际上比无头单向非循环更容易实现。

## 带头双向循环链表的编写

### 基础头文件的包含

```c
#pragma once
#include <stdio.h>

typedef int LTDataType;
typedef struct ListNode
{
    LTDataType data;
    struct ListNode *next;
    struct ListNode *prev;
}ListNode;

void ListInit(ListNode *phead);
void ListPushBack(ListNode *phead, LTDataType x);
```

### 初始化 ListInit

我们发现传递一级指针并不可行，因为我们是带头的链表，需要改变plist的值，类似下面

```c
void ListInit(ListNode **pphead)
{
    *pphead = (ListNode *)malloc(sizeof(ListNode));
		*pphead->prev = *pphead;
		*pphead->next = *pphead;
}
```

这是一种做法，当然我们也可以用返回值接收这个形参也可以。我们本次采用第二种方法去编写。

```c
ListNode *ListInit()
{
    ListNode *phead = (ListNode *)malloc(sizeof(ListNode));
    phead->prev = phead;
    phead->next = phead;

    return phead;
}
```

然后我们只需要在测试代码中编写这个即可完成初始化。

```c
void TestList1()
{
    ListNode *plist = ListInit();
}
```

### 尾插 ListPushBack

双向链表是非常简单的，这是因为我们有两个指向，即可以知道节点前面的节点，也可以知道节点后面的节点。

由于是尾插，需要找到尾，但是因为是循环链表，phead的前面的节点就是尾节点了，不需要再遍历寻找尾巴了。于是这样容易得出：

```c
void ListPushBack(ListNode *phead, LTDataType x)
{
    assert(phead);
    ListNode *tail = phead->prev;
    ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
    //赋值
    newnode->data = x;
    //修改指向
    tail->next = newnode;
    newnode->prev = tail;
    newnode->next = phead;
    phead->prev = newnode;
}
```

### 尾删 ListPopBack

尾删需要注意的一个问题是，要free还要在合适的位置释放。如果释放得早，会很容易出现野指针的情况，比如

```c
ListNode* tail = phead->prev;
free(phead->prev);
tail->prev->next = phead;
```

这上面free掉phead->prev后，是释放掉这部分的空间，而tail正是使用这部分的空间，所以会出现野指针的问题。解决的办法就是

- 可以先储存一下tail->prev
- 或者最后释放

```c
void ListPopBack(ListNode *phead, LTDataType x)
{
    assert(phead);
    assert(phead->prev != phead);
    ListNode *tail = phead->prev;
    ListNode *tailPrev = tail->prev;
    //修改指向
    tailPrev->next = phead;
    phead->prev = tailPrev;
    free(tail);
}
```

### 头插 ListPushFront

```c
void ListPushFront(ListNode *phead, LTDataType x)
{
    assert(phead);
    ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
    //赋值
    newnode->data = x;
    ListNode *next = phead->next;
    //修改指向
    phead->next = newnode;
    newnode->prev = phead;
    newnode->next = next;
    next->prev = newnode;
}
```

### 头删 ListPopFront

```c
void ListPopFront(ListNode *phead, LTDataType x)
{
    assert(phead->next != phead);
    assert(phead);
    ListNode *headNext = phead->next;
    //修改指向
    phead->next = headNext->next;
    headNext->next->prev = phead;
    free(headNext);
}
```

### 任意位置插入 ListInsert

我们当前写的是在pos位置之前插入，代码如下：

```c
void ListInsert(ListNode *pos, LTDataType x)
{
    assert(pos);
    ListNode *posPrev = pos->prev;
    ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
    newnode->data = x;
    //指向
    posPrev->next = newnode;
    newnode->prev = posPrev;
    newnode->next = pos;
    pos->prev = newnode;
}
```

写完之后，发现前面的头插和尾插都可以复用插入函数：

```c
void ListPushBack(ListNode *phead, LTDataType x)
{
    assert(phead);
		ListInsert(phead->next,x);
}

void ListPushFront(ListNode *phead, LTDataType x)
{
    assert(phead);
    //就是在phead之前插入而非phead的->prev插入！！
		ListInsert(phead,x);
}
```

### 任意列表删除 ListErase

```c
void ListErase(ListNode *pos)
{
    assert(pos);
    //检查pos是不是哨兵位
    if(pos->prev == pos)
    {
        return;
    }
    ListNode *posPrev = pos->prev;
    ListNode *posNext = pos->next;
    //指向
    posPrev->next = posNext;
    posNext->prev = posPrev;
    free(pos);
}
```

同样的，头删和尾删也是可以复用的。

```c
void ListPopBack(ListNode *phead, LTDataType x)
{
    assert(phead);
    assert(phead->prev != phead);
    ListErase(phead->prev);
}
void ListPopFront(ListNode *phead, LTDataType x)
{
    assert(phead->next != phead);
    assert(phead);
		ListErease(phead->next);
}
```

### 销毁 ListDestroy

写销毁，一般是传递二级指针进去，然后才可以把其头节点置空，否则但留一个头节点free掉而不置空，会有野指针的风险，但是我们其他接口函数都是写的是一级指针，为了保持接口的一致性，我们可以写一级指针。

区别于之前的单向链表，双向链表的销毁是可以在外面置空而且可以销毁得干干净净的。

```c
void ListDestroy(ListNode *phead)
{
    assert(phead);
    ListNode *cur = phead->next;
    while (cur!=phead)
    {
        ListNode *next = cur->next;
        free(cur);
        cur = next;
        next = next->next;
    }
    free(phead);
}
```

# 顺序表和链表的比较

这两个结构各有优势，很难说谁更优。严格说，顺序表和链表是相辅相成的两个结构。

## 顺序表

### 优点

1. 支持随机访问。需要随机访问结构支持算法可以很好地适用。
2. cpu高速缓存利用率更高。

### 缺点

1. 头部、中部插入删除时间效率低。O(N)

2. 连续的物理空间，空间不够了以后需要增容，增容有一定程度的消耗；为了避免频繁增容，一般我们都按照倍数去增，用不完可能存在一定的空间浪费。

## 链表

### 优点

1. 任意位置插入删除效率高。O(1)
2. 按需申请释放空间。

### 缺点

1. 不支持随机访问(用下标访问)。意味着有些算法，比如快排，二分查找等在这种结构并不适用。
2. 链表存储一个值，同时要存储链接指针，也有一定的消耗。
3. cpu高速缓存命中率更低。

> cpu处理并非直接处理主存中的数据，而是先看主存的数据的地址在不在缓存，在就直接访问，不在就先加载到缓存，再访问。
>
> 但是顺序表的加载并非直接加载一个位置，而是加载一片，比如20个字节(具体加载多少取决于硬件体系)，所以cpu高速缓存命中率高。
