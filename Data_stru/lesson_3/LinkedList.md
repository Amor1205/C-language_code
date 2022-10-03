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

#### ![CleanShot 2022-10-02 at 12.31.47@2x](/Users/amor/Library/Application Support/CleanShot/media/media_2PUOjhv9bG/CleanShot 2022-10-02 at 12.31.47@2x.png)思路

一次比较链表中的节点，每次取小的节点尾插到新链表即可。

##### 逻辑分析

如果尾插到新链表的话，我们需要给定两个指针去指向list1和list2链表，并用head作为新链表的头，这样如果我们不给定多余的指针，我们必须每次遍历一遍新链表才能得到尾的所在，所以我们在最开始也定义一个尾，这样就省去了每次遍历的麻烦。

```c
    struct ListNode *cur1 = list1, *cur2 = list2;
    struct ListNode *head = NULL, *tail = NULL;
```

我们想要把比较过后的小的那个给到新的链表里面，所以进行判断，但是需要考虑初始情况，即head为空时，这时候head和tail都为空，我们需要判断，***如果cur1-val小的话***，需要

``` c
            if (head == NULL)
            {
                head = tail = cur1;
            }
```

反之亦然。

随后中间逻辑就是尾插，

```c
            else
            {
                tail->next = cur1;
                tail = cur1;
            }
```

通过使用cur->next给到cur1进行迭代。我们上面尾插是不改变cur1的下一个指向的，所以直接使用下列代码即可。

```c
            cur1 = cur1->next;
```

最后，我们判断结束条件，应该是两个链表先遍历完一个即可。

```c
		while (cur1 && cur2)
```

遍历完一个链表之后，只需要把另外一个链表追加到新链表的后面即可。

```c
    if (cur1)
    {
        tail->next = cur1;
    }
    else
    {
        tail->next = cur2;
    }
```

##### 代码

```c
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *cur1 = list1, *cur2 = list2;
    struct ListNode *head = NULL, *tail = NULL;
    if (cur1 == NULL)
        return cur2;
    if (cur2 == NULL)
        return cur1;
    while (cur1 && cur2)
    {
        //比较
        if (cur1->val < cur2->val)
        {
            if (head == NULL)
            {
                head = tail = cur1;
            }
            //尾插
            else
            {
                tail->next = cur1;
                tail = cur1;
            }
            //迭代
            cur1 = cur1->next;
        }
        else
        {
            if (head == NULL)
            {
                head = tail = cur2;
            }
            else
            {
                tail->next = cur2;
                tail = cur2;
            }
            cur2 = cur2->next;
        }
    }
    if (cur1)
    {
        tail->next = cur1;
    }
    else
    {
        tail->next = cur2;
    }
    return head;
}
```

##### 优化

1. 我们发现，每次进入循环都要判断head到底是否为空，不妨把这个拿到循环外面来，只要写一个判断语句即可，省去了后面每次都要判断的辛苦。

```c
        if (cur1->val < cur2->val)
        {
            head = tail = cur1;
            cur1 = cur1->next;
        }
        else
        {
            head = tail = cur2;
            cur2 = cur2->next;
        }
```

2. 带哨兵位的链表。

带哨兵位就是说的是plist指向的头节点是不含值的节点，它的作用就是指向下一个节点，我们如果定义链表定义出带哨兵位的节点的话，就不需要传递二级指针，因为我们无须改变plist的值，而只是改变plist之后的指向。

哨兵位一般都是malloc出来的。

``` c
head = tail = (ListNode*)malloc(sizeof(ListNode));
```

接下来我们需要做的就是往tail后面进行链接就可以了。

但是不能返回head了，因为head只是哨兵位，而且我们在最后的时候我们需要释放这个哨兵位的头。

我们应该先去储存哨兵位的下一位，也就是真正的头，随后free掉，然后返回新的头即可。

``` c
			struct ListNode* list = head->next;
			free(head);
			return list;
```

### 链表分割

现有一链表的头指针 ListNode* **pHead**，给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。

#### 思路

如果不要求保持原来的数据顺序，那我们就直接进行判断，小于x的头插，大于x的进行尾插就可以了。但是这个题目要求的是数据的顺序不变，那么我们需要转变策略，创建两个新链表，一个放大的，一个放小的，遍历一遍分好类之后，将二者合并即可。

但是贴到网站上进行提交时，发现超出内存了。一般内存超出了限制是因为程序编写不当，导致死循环从而引起的。仔细分析可以发现，bigger的最末节点仍旧指向着smaller的最末节点，导致整个链表在不断的死循环，这时候我们应该让bigger的末尾节点指向NULL。

#### 代码

```c
ListNode *partition(ListNode *pHead, int x)
{
    ListNode *smaller = NULL, *bigger = NULL;
    ListNode *tails = NULL, *tailb = NULL;
    smaller = tails = (ListNode *)malloc(sizeof(ListNode));
    bigger = tailb = (ListNode *)malloc(sizeof(ListNode));
    ListNode *cur = pHead;
    while(cur)
    {
        if(cur->val<x)
        {
            //尾插到smaller里面去
            tails->next = cur;
            tails = cur;
        }
        else
        {
            tailb->next = cur;
            tailb = cur;
        }
        cur = cur->next;
    }
    tails->next = bigger->next;
  	bigger->next = NULL;
    ListNode *lista = smaller->next;
    free(bigger);
    free(smaller);
    return lista;
}
```

### 链表的回文结构

![CleanShot 2022-10-02 at 16.43.41@2x](/Users/amor/Library/Application Support/CleanShot/media/media_OKYOkUWP9V/CleanShot 2022-10-02 at 16.43.41@2x.png)

#### 思路1

首先空间复杂度为1，我们就不能额外的创建新链表。初步考虑为，第一个和倒数第一个比较，第二个和倒数第二个比较，(找到第k个方法是知道的，我们只需要定义快慢指针，让快指针提前走k步即可，然后让快慢一起走到快指针为NULL即可)

但是经过编写之后发现太难实施。于是放弃这种思路。

#### 思路2

找到中间节点(引用之前的函数)，让之后的逆置(引用之前的函数)，随后进行一一比较。

其中一个比较关键的点在于，如果我们这样编写， 中间节点的前一个节点的最终指向是逆置之后的整个链表的最后一个节点，分奇偶情况，如果是奇数情况，无需比较，因为前面的节点都可以一一对应，走到最后一个节点处，必然相等，程序继续运行，直接指向NULL，程序中止；如果是偶数情况，由于找中间节点时如果是偶数情况，我们找到的是中间两个节点中后面的那个节点，所以相比于前半段链表，后半段链表更先结束，前后段链表一一比较之后，后面指向NULL时，前半段的最后节点指向链表的最终节点，此时程序就中止了，所以不必考虑让前面的节点去指向空。

思路比较关键，代码非常简单，注意引用之前的两组代码，将他们作为接口函数使用。	

### 输入两个链表，找出它们的第一个公共节点

![CleanShot 2022-10-02 at 17.46.54@2x](/Users/amor/Library/Application Support/CleanShot/media/media_qQx7VCUu9T/CleanShot 2022-10-02 at 17.46.54@2x.png)

链表相交只能是Y字形而非类似两根直线相交，这是因为一个节点只能有一个指向。（相交实际上就是指向同一个节点，需要比较的是地址）

实际上，题目分为两个部分

1. 判断两个链表是否相交
2. 如果相交，找出起始相交节点。

#### ***错误思路***

> 逆置两个链表，开始比较，找到第一个不同的节点，并返回这个节点的 前一个节点。

这是错误的，这是因为如果逆置，如图所示，我们不知道c1是到底指向a2还是指向b3，也就是说，我们先逆置A链表，后逆置B链表，则c1指向b3，反之亦然，无法判断。![CleanShot 2022-10-02 at 19.58.36@2x](/Users/amor/Library/Application Support/CleanShot/media/media_eFZKOY7pzV/CleanShot 2022-10-02 at 19.58.36@2x.png)

#### 思路1(暴力求解)

依次取A链表中的每个节点跟B链表中的所有节点比较，如果有地址相同的节点，就是相交，第一个相同的交点，就是相交节点。但是时间复杂度高O(N^2)，穷举。

#### 思路2，优化到O(N)

1. 尾节点相同就相交，不相同就不相交。
2. - 可以看如果两个链表长度相同，由于其相交之后的长度是相同的，那么可以知道相交节点之前的长度也是相同的。我们就只需要设定两个指针，同时开始比较即可；
   - 如果两个链表长度不同，设其中A的长度为a，B的长度为b，相交节点之后的长度为x，则A需要走过(a-x)步才能找到相交节点，B需要走过(b-x)步才能找到相交节点。只需要先让长度较长的链表走过|a-b|步即可，这样会同时找到节点。
   - 所以我们只需要先判断链表的长度再按上述方法找相交即可。

##### 逻辑分析

- 因为要找尾节点相同与否，所以至少都要从开头遍历一遍才可以。正好这样我们也可以顺便把两个链表的长度求出来。

```c
ListNode *tailA = headA, *tailB = headB;
    int lengthA = 1, lengthB = 1;
    //找尾巴，求长度
    while (tailA->next)
    {
        tailA = tailA->next;
        lengthA++;
    }
    while (tailB->next)
    {
        tailB = tailB->next;
        lengthB++;
    }
```

- 判断尾节点相同

```c
    //不相交
    if(tailA != tailB)
    {
        return NULL;
    }
```

- 因为我们后续的思路就是判断出A、B链表中较长的链表和较短的，所以我们可以先将其进行区分，如下、

```c
ListNode *longList = headA;
    ListNode *shortList = headB;
    if(lengthA < lengthB)
    {
        ListNode *longList = headB;
        ListNode *shortList = headA;
    }
```

- 长的多走他们之间长度的差值步即可。

```c
//长的走abs步
    int gap = abs(lengthA - lengthB);
    while (gap--)
    {
        longList = longList->next;
    }
```

- 判断是否相等，如果相等就是结束了。

```c
    while(longList!=shortList)
    {
        longList = longList->next;
        shortList = shortList->next;
    }
    return longList;
```

##### 代码

下面的代码其中有一些多余的部分，是思考的部分

```c
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    ListNode *tailA = headA, *tailB = headB;
    int lengthA = 1, lengthB = 1;
    //找尾巴，求长度
    while (tailA->next)
    {
        tailA = tailA->next;
        lengthA++;
    }
    while (tailB->next)
    {
        tailB = tailB->next;
        lengthB++;
    }
    //不相交
    if(tailA != tailB)
    {
        return NULL;
    }
    // ListNode* curA = headA;
    // ListNode* curB = headB;
    //可以使用绝对值函数
    //abs(lengthA - lengthB)

    //下面这段函数太冗余了，完全是重复的代码，只是区分headA和headB
    //可以设定一个长的和短的，如下
    ListNode *longList = headA;
    ListNode *shortList = headB;
    if(lengthA < lengthB)
    {
        ListNode *longList = headB;
        ListNode *shortList = headA;
    }
    //长的走abs步
    int gap = abs(lengthA - lengthB);
    while (gap--)
    {
        longList = longList->next;
    }
    while(longList!=shortList)
    {
        longList = longList->next;
        shortList = shortList->next;
    }
    return longList;
    // if (lengthA >= lengthB)
    // {
    //     int d = lengthA - lengthB;
    //     while (d--)
    //     {
    //         curA = curA->next;
    //     }
    //     while(curA)
    //     {
    //         if(curA->next == curB->next)
    //         {
    //             return curA->next;
    //         }
    //         curA = curA->next;
    //         curB = curB->next;
    //     }
    // }
    // else
    // {
    //     int d = lengthB - lengthA;
    //     while(d--)
    //     {
    //         curB = curB->next;
    //     }
    //     while(curB)
    //     {
    //         if (curA->next == curB->next)
    //         {
    //             return curA->next;
    //         }
    //         curA = curA->next;
    //         curB = curB->next;
    //     }
    // }
}
```

---

# Singly-Linked List Oj

## 条件

```c
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
```

## 环形链表

### 给定一个链表，判断链表中是否有环

![CleanShot 2022-10-03 at 00.37.13@2x](/Users/amor/Library/Application Support/CleanShot/media/media_VUj2Xr5SwQ/CleanShot 2022-10-03 at 00.37.13@2x.png)

#### 思路

*我们需要做的就是判断是否有环，所以可以定义一个fast 和 slow快慢指针，快指针每次走两步，慢指针每次走一步，如果快指针可以走到NULL，即无环，如果快指针一直走但是走不到头，就是有环，需要判断的是，快指针必定会比慢指针先多走一圈而追上慢指针，即相等。*

#### 代码

```c
bool hasCycle(struct ListNode *head)
{
    struct ListNode *fast = head, *slow = head;
    //fast->next和fast都应该不为空才行
    while (fast && fast->next)
    {

        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}
```

#### 延伸问题

> 为什么slow和fast一定在环中相遇，会不会在环里面错过，永远遇不上，证明一下。

- 带环则一定会相遇
- 分析证明：

slow和fast的距离差始终为n，n为slow走过的步数，n从1开始增加，为正整数。每追一次，距离减少1，他们之间的距离最后都会减到0，这个点就是相遇的点。

> 为什么slow走一步，fast走两步呢，能不能fast走n步呢，证明一下。

如果slow走一步，fast走三步，那么每次slow走一步，它们会相差2步，slow刚进环之后假设距离差为N，如果N为奇数，则距离会变为N-2，N-4，...，1，-1。-1就代表他们之间的距离为C-1(C为环长)。

- 如果C-1为奇数，那么就永远追不上了
- 如果C-1为偶数，那么可以追上。

假设slow一次走一步，fast一次走x步，以此类推

- 那么就是(x-1)步为每次的差值，假设slow刚进环的二者距离差为N，N-n(x-1)，如果N是(x-1)的倍数，就可以追上。如果不是，比如N = n(x-1)-1，就是代表他们两个此刻的距离为C-1，如果C-1是(x-1)的倍数，就可以追上，否则，无法追上。
- 总结一下：
- - 如果N是步数差的整数倍，可以追上。
  - 如果第一次追不上，那么会出现fast掠过slow但并不相遇。可能会出现从-1、-2、...、-(x-2)的情况。
  - 当环长C加上上面的负数为步数差的整数倍时，也可以追上。

### 给定一个链表，返回链表开始入环的第一个节点

![CleanShot 2022-10-03 at 00.44.58@2x](/Users/amor/Library/Application Support/CleanShot/media/media_uk3JXQYQNY/CleanShot 2022-10-03 at 00.44.58@2x.png)

#### 延伸问题

> slow一次走一步，fast一次走两步，一定会相遇，如何求环的入口点呢？

- 结论：

- - 一个指针从相遇点开始走，另一个指针从链表头开始走(都是每次走一步)，它们会在环的入口点相遇。
  - 两个指针同时从链表头开始走，第一次相遇时，走过的路程差就是环长C的整数倍。

#### 思路1

用上面的结论，即先找相遇点->再双指针求交点，找到的交点就是换的入口点。

#### 代码1

```c
struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode *slow = head, *fast = head;
    while(fast&&fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast)
        {
            struct ListNode *meetNode = slow;
            while(meetNode!=head)
            {
                meetNode = meetNode->next;
                head = head->next;
            }
            return meetNode;
        }
    }
    return NULL;
}
```

#### 思路2

我们把相遇点断开，让其指向空，会出现两个链表，一个是由原链表头指向相遇点，一个是由原来相遇点的后一个节点指向相遇点的链表。让两个链表求交点。交点即为环节点。（实践起来稍繁琐。）

## [复制带随机指针的链表](https://leetcode.cn/problems/copy-list-with-random-pointer/)

给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。

构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。复制链表中的指针都不应指向原链表中的节点 。

例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random --> y 。

返回复制链表的头节点。

用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：

val：一个表示 Node.val 的整数。
random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
你的代码 只 接受原链表的头节点 head 作为传入参数。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/copy-list-with-random-pointer

![CleanShot 2022-10-03 at 16.40.44@2x](/Users/amor/Library/Application Support/CleanShot/media/media_ItC1s4TGx8/CleanShot 2022-10-03 at 16.40.44@2x.png)

### 思路

1. 复制节点，插入到原节点和下一个节点之间。(为的是建立复制后的节点与原节点的链接关系)，如图所示![CleanShot 2022-10-03 at 16.35.24@2x](/Users/amor/Library/Application Support/CleanShot/media/media_XPWsaX3rv6/CleanShot 2022-10-03 at 16.35.24@2x.png)
2. 根据原节点random，处理复制节点的random。(比如13的random指向7，那么13后面的复制节点的random就会指向7的后面)
3. 将复制的节点解下来然后单独链接在一起就可以了。然后恢复原链表链接关系。

时间复杂度为O(N)，处理问题是优解。

```c
struct Node
{
    int val;
    struct Node *next;
    struct Node *random;
};
struct Node *copyRandomList(struct Node *head)
{
    //复制节点，然后插入
    struct Node *cur = head, *curCopy = head;
    //预先储存好cur的next
    struct Node *next = cur->next;
    // if(!cur)
    // {
    //     return NULL;
    // }
    while (cur)
    {
        //复制节点的值
        curCopy = (struct Node *)malloc(sizeof(struct Node));
        curCopy->val = cur->val;
        //指向
        cur->next = curCopy;
        curCopy->next = next;
        //迭代
        cur = next;
        next = next->next;
    }
    //将random的值写入curcopy
    //从头开始数，奇数为原始链表，偶数为复制的节点
    cur = head;
    while (cur)
    {
        curCopy = cur->next;
        //复制random
        if (!cur->random)
        {
            curCopy->random = NULL;
        }
        curCopy->random = cur->random->next;
        //迭代
        cur = curCopy->next;
        //什么时候中止呢？
    }
    //解开链接，然后重新形成新的链表
    //改变curcopy的next值即可。
    struct Node *copyHead = (struct Node *)malloc(sizeof(struct Node));
    copyHead = head->next;
    //为了尾插,定义tail
    struct Node *copyTail = copyHead;

    while (cur)
    {
        curCopy = cur->next;
        struct Node *next = curCopy->next;
        //尾插
        copyTail->next = curCopy;
        //恢复原节点
        cur->next = next;
        //迭代
        copyTail = curCopy;
        cur = next;
    }
    cur->next = NULL;
    return head->next;
}
```

