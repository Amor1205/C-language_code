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

### 头删 ListPopFront

