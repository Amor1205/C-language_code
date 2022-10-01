[toc]

# Singly-Linked List

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

单链表的缺陷还是很多的，单纯单链表的增删查找的意义不大。

- 很多OJ题目考查的都是单链表
- 单链表更多的是做更复杂的数据结构的子结构，哈希桶、临接表

链表存储数据还是要看双向链表。

## 链表的实现

### 定义结构体

```c
typedef int SLTDataType;
typedef struct SListNode
{
    SLTDataType data;
    struct SListNode *next;
} SLTNode;
```

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

查找本身不会改变plist的值，所以无需传递二级指针。

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

```c
void SListInsert(SLTNode **pphead, SLTNode *pos, SLTDataType x)
{
    SLTNode *newnode = BuyListNode(x);
    //找到pos前一个位置
    if (pos == *pphead)
    {
        SListPushFront(pphead, x);
    }
    else
    {
        SLTNode *posPrev = *pphead;
        while (posPrev->next != pos)
        {
            posPrev = posPrev->next;
        }
        posPrev->next = newnode;
        newnode->next = pos;
    }
}
```

我们发现，在pos前面插入是非常麻烦的，这是因为我们需要确定pos之前的位置，也就是posPrev的值，但是posPrev的值又需要考虑区分为：pos就是*pphead时(posPrev没法取值)，posPrev可以取值，两种情况，非常麻烦，所以我们可以考虑在pos的后面插入。

```c
void SListInsertAfter(SLTNode *pos, SLTDataType x)
{
    SLTNode *newnode = BuyListNode(x);
    newnode->next = pos->next;
    pos->next = newnode;
}
```

### 删除 SListErase

删除相对于插入是非常类似的。我们需要判断pos的位置来确定是否头删，如果是头删直接复用头删函数，或者很简单的贴两行代码如下：

```c
if(*pphead == pos)
{
	*pphead = pos->next;
	free(pos);
}
```

随后需要进行的就是正常位置的删除，也就是中间删除。只需要用posPrev去找到pos的前一个位置，然后改变指向即可。

```c
        SLTNode *posPrev = *pphead;
        while (posPrev->next != pos)
        {
            posPrev = posPrev->next;
        }
        posPrev->next = pos->next;
        free(pos);
```

至此我们可以考虑一下如果是尾删的话会不会需要再单独列出来呢？

尾删时,pos->next  = NULL; 把空指针传过去给posPrev->next完全没有问题，所以不需要单独列出来。实际上，我们在写单链表的时候，只需要考虑头部情况即可。

一个问题：在free后不是紧接着要跟一个置空吗？

```c
free(pos);
pos = NULL;
```

但是在接口函数里，pos只是形参，是实参的一份临时拷贝，改变pos不会影响实参的值，所以可以不加。但是为了好的习惯，建议在free后都加置空。同样的，观看整体的函数，可以发现需要讨论情况，比较繁琐。

```c
void SListErase(SLTNode **pphead, SLTNode *pos)
{
    assert(pphead);
    //头删
    if (pos == *pphead)
    {
        *pphead = pos->next;
        free(pos);
    }
    else
    {
        SLTNode *posPrev = *pphead;
        while (posPrev->next != pos)
        {
            posPrev = posPrev->next;
        }
        posPrev->next = pos->next;
        free(pos);
    }
}
```

所以我们可以使用SListEraseAfter函数，删除pos位置的后一个接口即可。

### 销毁 SListDestroy

销毁实际上就是把每个内存块都进行free，所以有多种做法。

比如我们可以复用尾删函数进行销毁，如下：

```c
void SListDestroy(SLTNode **pphead)
{
    assert(pphead);
    while (pphead)
    {
        SLitstPopBack(pphead);
    }
}
```

同样的，我们也可以直接进行销毁，如下：

```c
void SListDestroy(SLTNode **pphead)
{
    assert(pphead);
    SLTNode *cur = pphead;
    while(cur)
    {
        SLTNode *next = cur->next;
        free(cur);
        cur = next;
    }
    *pphead = NULL;
}
```

## 总结

单向链表是比较简单的，不外乎主要的增删查改功能，而在对单向链表的考察中，也一般是增删查改的变形，我们需要做的就是记住链表的特点，并利用其特点和优点去实现简单链表和完成相应的题目。

---



# Singly-Linked List Oj

## 删除指定值的特定节点

### 条件

```c
//   struct ListNode
//  {
//      int val;
//      struct ListNode *next;
//  };
//       typedef struct ListNode ListNode;
```



### 思路

1. 定义cur指针去从头开始遍历整个链表。
2. 定义prev指针去指向cur的前一个地址。
3. 找到cur所指向的值等于指定值的时候，进行free和cur的再指向。
4. 注意区分考虑cur为第一个节点的情况(这时prev不能用)。

```c
 struct ListNode *removeElements(struct ListNode *head, int val)
 {
     struct ListNode *prev = NULL, *cur = head;
     while (cur)
     {
         if (cur->val == val)
         {
             //头删
             if (cur == head)
             {
                 head = cur->next;
                 free(cur);
                 cur = head;
             }
             //中间删除
             else
             {
                 prev->next = cur->next;
                 free(cur);
                 cur = prev->next;
             }
         }
         else
         {
             //迭代，往后走
             prev = cur;
             cur = cur->next;
         }
     }
     return head;
 }
```



## 反转一个单链表。

![CleanShot 2022-09-30 at 21.51.34@2x](/Users/amor/Library/Application Support/CleanShot/media/media_8wzmw1DSa6/CleanShot 2022-09-30 at 21.51.34@2x.png)

### 思路1

我们都知道链表是前一个里面存了后一个的地址，如果我们反转链表，实际上就是在后一个的节点里面去存前一个的地址。

所有的数据结构的解题都要涉及到画图，本题也要去画图解决。

首先我们需要判断如果反转，我们需要什么条件。

#### 逻辑分析

第一，我们需要让后一个节点指向前一个节点，而且指向之后，后一个节点就找不到原本它的下一个节点了，所以我们需要设计三个指针变量。

```c
    ListNode *n1, *n2, *n3;
    n1 = NULL;
    n2 = head;
    n3 = head->next;
```

核心逻辑是进行反转，也就是把前一个的地址给到下一个的节点里面去。

随后迭代条件是把整体的n1、n2、n3的指针向后推移，也就是把n2给到n1，n3给到n2，然后n3->next给到n3。做到这样就可以了。

``` c
   n1 = n2;
   n2 = n3;
   n3 = n3->next;
```

但是有一些问题，我们需要仔细考虑，如果n3为NULL，n3->next本身就是越界访问，会报错，所以我们需要单独设计条件判断。

```c
	if (n3)
  	 n3 = n3->next;
```

此外，还需要考虑，如果传过来的节点本身为空的话，我们反转是没有意义的，直接传递空指针回去即可。

```c
 if (head == NULL)
    {
        return;
    }
```

#### 代码

综合起来就是：

```c
struct ListNode *reverseList(struct ListNode *head)
{
    if (head == NULL)
    {
        return;
    }
    ListNode *n1, *n2, *n3;
    n1 = NULL;
    n2 = head;
    n3 = head->next;

    while (n2)
    {
        //反转
        n2->next = n1;
        //迭代走
        n1 = n2;
        n2 = n3;
        if (n3)
            n3 = n3->next;
    }
    return n1;
}
```

### 思路2

我们也可以去原链表中的节点，头插到newhead新链表中。

#### 逻辑分析

构建一个新链表，只需要把依次把原链表中的节点头插到新链表中，但是头插之后会发现这个节点的指向被抹去了，也就是我们无法通过这个节点再找到原来链表中的下一个节点。所以我们需要定义next去记忆下一个节点的地址。

我们需要学习每个题目都要去画图处理，画图的目的是分析清楚我们的

- 初始条件(定义什么变量)
- 中间逻辑(核心逻辑，也就是通过什么手段完成题目的要求)
- 迭代逻辑(如何去走一个循环，即完成一步之后如何进行下一步)
- 结束条件(什么时候中止循环)

对这个题目，我们同样的，如果想要头插的做法，初始条件分析在上面已经进行了：

 *头插之后会发现这个节点的指向被抹去了，也就是我们无法通过这个节点再找到原来链表中的下一个节点。所以我们需要定义next去记忆下一个节点的地址。* 即：

```c
		ListNode *cur = head;
    ListNode *newhead = NULL;
    ListNode *next = cur->next;
```

随后我们进行中间逻辑的编写，即头插，对于头插我们都已经轻车熟路了：

```c
        //头插
        cur->next = newhead;
        newhead = cur;
```

迭代条件：

```c
		cur = next;	
```

中止条件：

当cur为空的时候，我们不能在继续执行头插操作，即是循环中止。

```c
while(cur)
```

#### 代码

```c 
struct ListNode *reverseList(struct ListNode *head)
{
    ListNode *cur = head;
    ListNode *newhead = NULL;
    while(cur)
    {
        ListNode *next = cur->next;
        //头插
        cur->next = newhead;
        newhead = cur;
        //迭代
        cur = next;
    }
    return newhead;
}
```

### 返回中间节点

给定一个头结点为 `head` 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点。

![CleanShot 2022-10-01 at 22.17.12@2x](/Users/amor/Library/Application Support/CleanShot/media/media_54nzqYdqWF/CleanShot 2022-10-01 at 22.17.12@2x.png)

#### 思路1

遍历一次，算出长度，分析奇偶情况并找到中间值

#### 思路2

使用“快慢指针”，定义slow和fast，slow每次走一步，fast每次走两步。

通过画图可以知道，中止条件应该是fast或者fast->next为空，这时候的slow就是需要返回的值。

#### 代码

```c
struct ListNode* middleNode(struct ListNode* head){
 struct ListNode *slow = head, *fast = head;
    while(fast&&fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
```

### **链表中倒数第k个结点**

输入一个链表，输出该链表中倒数第k个结点。![CleanShot 2022-10-01 at 22.28.36@2x](/Users/amor/Library/Application Support/CleanShot/media/media_bdGv5q4ELE/CleanShot 2022-10-01 at 22.28.36@2x.png)

#### 思路1

遍历链表求得节点个数，然后遍历第二遍找到倒数第k个。

#### 思路2

快慢指针，slow和fast定义好之后，fast先走k步，slow和fast再一起走，fast == NULL时，slow就是倒数第k个。

```c
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k ) {
    struct ListNode* fast = pListHead, *slow = pListHead;
    while (k--) { //k--是走k步，--k是走k-1步，搞不清楚就带值
        //k大于链表长度
        if (!fast) {
            return NULL;
        }
        fast = fast->next;
    }
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
```

### 归并(合并两个有序链表)

#### 思路

一次比较链表中的节点，每次取小的节点尾插到新链表即可。

