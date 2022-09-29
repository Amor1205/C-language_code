# Linked List

## 顺序表的缺陷
1. realloc是有空间损耗的，在realloc运行的时候，首先进行判断，空间不够就会异地扩容，如果空间足够就会原地扩容。增容是要付出代价的。
2. 为避免频繁扩容，空间满了一般会扩二倍，可能就会导致一定的空间浪费。
3. 顺序表要求顺序从开始位置连续存储，我们在头部或者中间位置插入删除数据，就需要挪动数据，效率不高

但顺序表支持随机访问，有些算法，需要结构支持随机访问。比如，二分查找，比如优化的快排。

针对顺序表的缺陷我们就设计出来链表

## 链表的优缺点

### 优点

1. 按需申请空间，不用了就释放空间，会合理的利用空间。
2. 头部中间插入删除数据，不需要挪动数据，从而不存在空间浪费。

### 缺点

1. 每存放一个数据，都要存一个指针去链接后面的数据节点。
2. 不支持数据的随机访问(如同顺序表里直接用a[i] 去访问第i个数据)
3. 

## 链表的实现

### 链表的打印 SListPrint

关键就是

```c
 cur = cur->next
```

因为这个链表里面的两个数据分别是

```c
typedef struct SListNode
{
    SLTDataType data;
    struct SListNode *next;
}SLTNode;
```

cur被赋给了cur的next，实际上这个next里存放的就是下一个结构体的地址。

```c
void SListPrint(SLTNode *phead)
{
    SLTNode *cur = phead;
    while(cur!=NULL)
    {
        printf("%d->", cur->data);
        cur = cur->next;
    }
}
```

我们一般学习链表分为逻辑图和物理图，在我们的想象里，一般是phead去指向链表的第一个结构体，然后第一个结构体指向第二个结构体，以此类推，但是物理图并非如此，每个都是单独存放。

### 链表的尾插 SListPushBack

要尾插，首先就要找到这个尾巴。需要找到最后一个节点。我们需要找到这个原来的尾，去指向新的NewNode。

如何找到呢？

尾的标志就是下一个节点为空

```c
    SLTNode *tail = phead;
    while(tail->next !=NULL)
    {
        tail = tail->next;
    }
```

直到找到了尾节点，再找到新节点

```c
    SLTNode *newnode = (SLTNode *)malloc(sizeof(SLTNode));
    newnode->next = NULL;
    newnode-> data = x;
    tail->next = newnode;
```

最后一步是通过修改尾的指向，指向新的结构体newnode内存块。

但是发现运行不起来，程序会崩掉，这是因为如果我们直接去判断

```` c
    while (tail->next!= NULL)
````

会造成对NULL的解引用，从而导致了程序崩溃。

有一个问题，形参phead的改变没有影响实参plist。

我们是把plist的值拷贝了一份给phead，因为二者都是一级指针，如果想要改变plist实参的数值，你需要传递plist的地址，然后用二级指针接收。类似下面：

```c
&plist = pphead
//改变*pphead 就改变了plist的值	
```

所以我们可以把新空间块放在前面扩建，然后再去判断传过来的地址是不是空，如果是空的话，证明我们的链表整个为空。

### 头插 SListPushFront

我们知道pphead形参是plist实参的地址，如果我们头插，就是把*pphead(plist的地址) 放到新组建的newnode组块的next里，然后在把newnode的地址传给 解引用后的pphead。

这样就可以做到plist指向newnode，而newnode->又指向原来plist指向的值。这个时候即便去验证*pphead为空的情况，可以发现并没有影响，所以不用单独列出考虑。

```c
void SListPushFront(SLTNode **pphead, SLTDataType x)
{
    SLTNode *newnode = BuyListNode(x);

    newnode->next = *pphead;
    *pphead = newnode;
}							
```

### 尾删 SListPopback

尾删首先要做到的就是找到尾巴，这个很简单，我们只需要使用

```c
    SLTNode *tail = *pphead;
    while(tail->next)
    {
        prev = tail;
        tail = tail->next;
    }	
```

就可以找到尾，随后很多同学就直接用

``` c
    free(tail);
    tail = NULL;
```

free掉tail就结束函数了，这是不正确的。因为tail之前的一个块是没有置空的，这样就会导致野指针。从而程序出错。正确做法应该是记录一个指针变量prev，每次记录tail之前的块，然后最后找到尾后置空prev->next即可。

```c
void SLitstPopBack(SLTNode **pphead)
{
    if(*pphead ==NULL)
    {
        return;
    }
    //assert(*pphead!=NULL)//比较粗暴
    if(((*pphead)->next)==NULL)
    {
        free((*pphead)->next);
        *pphead = NULL;
    }
    SLTNode *prev = NULL;
    SLTNode *tail = *pphead;
    while(tail->next)
    {
        prev = tail;
        tail = tail->next;
    }
    free(tail);
    tail = NULL;
    prev->next = NULL;
}
```

### 头删 SListPopFront

头删相对于尾删来说简单一些，只需要一个tmp变量存储中间值，然后free掉*pphead即可，不过要注意plist传过来为空指针的情况

````
void SLitstPopFront(SLTNode **pphead)
{
    if (*pphead == NULL)
    {
        return;
    }

    SLTNode *tmp = (*pphead)->next;
    free(*pphead);
    *pphead = tmp;
}
````

### 查找 SListFind

```c
SLTNode* SListFind(SLTNode *phead, SLTDataType x)
{
    SLTNode *pos = phead;
    while(pos)
    {
        if(pos->data == x)
        {
            return pos;
        }
        pos = pos->next;
    }
    return NULL;
}
```

查找本身很简单，如何实现多次查找呢( 也就是如果想查找的值在链表内多次出现的话)

```c
    SLTNode* pos = SListFind(plist,2);
    int i = 1;
    while(pos)
    {
        printf("第%d个pos节点: %p->%d\n", i++, pos, pos->data);
        pos = SListFind(pos->next, 2);
    }
```

查找的同时也可以进行修改，很简单，此处就不贴代码了。

### 插入 SListInsert

插入接口函数需要先设计好Find函数，先查找到具体的值的位置pos，然后插入到pos位置之前。

但是由于单向链表是无法直接找到pos前一个位置的，所以我们需要再定义一个posPrev，然后找到posPrev，随后让posPrev指向newnode，newnode再指向pos。

但是我们需要注意posPrev在pos之前，如果pos就是plist指向的结构体的地址的话，程序会崩溃。在这个条件的时候，变成头插了，所以直接复用头插即可。
