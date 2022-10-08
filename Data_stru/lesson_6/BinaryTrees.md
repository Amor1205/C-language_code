# 二叉树

## 树的概念及结构

### 树的概念

树是一种**非线性**的数据结构，它是由n （n>=0）个有限结点组成一个具有层次关系的集合。***把它叫做树是因为它看起来像一棵倒挂的树，也就是说它是根朝上，而叶朝下的。***

- 有一个特殊的结点，称为**根结点**，根节点**没有前驱结点**
- 任何树都会被分成根和子树。子树可能为多个子树或者空树。
- 除根节点外，其余结点被分成M(M>0)个**互不相交**的集合T1、T2、.、Tm，其中每一个集合Ti(1<= i <= m)又是一棵结构与树类似的子树。每棵子树的根结点有且只有一个前驱，可以有0个或多个后继。（子树不相交）
- 除了根节点外，每个节点有且仅有一个交节点。
- 一颗N个节点的树有N-1条边。
- 因此，***树是递归定义的***。![CleanShot 2022-10-04 at 22.16.58@2x](/Users/amor/Library/Application Support/CleanShot/media/media_K28ZyYC5uX/CleanShot 2022-10-04 at 22.16.58@2x.png)

### 树的相关概念

> - 节点的度：一个节点包含的子树的个数
> - 叶节点或终端节点：度为0的节点称为叶节点，又叫终端节点。
> - 非终端节点或分枝节点：度不为0的。
> - 双亲节点或父节点：若一个节点含有子节点，则这个节点称为子节点的父节点。
> - 孩子节点或子节点
> - 兄弟节点：相同父节点的节点互为兄弟节点
> - 树的度：一棵树中最大的节点的度称为树的度
> - 节点的层次：从根开始定义，根为第一层，根的子节点为第二层，以此类推
> - 树的高度或深度：节点的最大层次
> - 堂兄弟节点：双亲在同一层的节点互为堂兄弟
> - 节点的祖先：从根到该节点所经分支上的所有节点
> - 子孙：以某节点为根的子树中任意节点都称为该节点的子树。
> - 森林：由m（m>0）颗互不相交的树的集合为森林。并查集就是多棵树构成的森林。

### 树的表示

树的表示其实就是用代码实现定义树的结构。其难点就在于结构体的编写。于是我们提出以下猜想

- 方式1：（假设树的度为N）

```c
struct TreeNode
{
	int data;
	struct TreeNode* subs[N];
}
```

这种方式就会造成空间的浪费。而且如果并未给出树的度，则无法编写。

- 方式2：如果不给度，我们用一个顺序表存，不够了再扩容

```c
typedef struct TreeNode* SLDataType;//SeqList
struct TreeNode
{
	int data;
	SeqList s;
}
```

结构相对复杂了。

- 方式3：结构数组存储

```c
struct TreeNode
{
	int parent;
	int data;
}
struct TreeNode arr[10]
```

只存自己的值和父亲的下标。

上述方式各有优缺点，但是都不常用，最常用的且最优的表示方法就是：***左孩子右兄弟表示法***。

```c
typedef int DataType;
struct Node
{
	struct Node* firstChild;//第一个孩子节点
	struct Node* pNextBrother;//指向其下一个兄弟节点
	Datatype data;//节点中的数据域
}
```

![CleanShot 2022-10-04 at 22.57.31@2x](/Users/amor/Library/Application Support/CleanShot/media/media_Lm9tK4eMAC/CleanShot 2022-10-04 at 22.57.31@2x.png)

树的经典应用是，***目录树***

![CleanShot 2022-10-04 at 23.01.44@2x](/Users/amor/Library/Application Support/CleanShot/media/media_RhACjkmfay/CleanShot 2022-10-04 at 23.01.44@2x.png)

树在实际情况并不常用，常用的是二叉树。（度为2的树）

## 二叉树的概念及结构

### 二叉树的概念

> 一棵二叉树是结点的一个有限集合，该集合或者为空，或者是由一个根节点加上两棵别称为左子树和右子树的二叉树组成。

> 二叉树的特点：
>
> 1. 每个结点最多有两棵子树，即二叉树不存在度大于2的结点。
>
> 2. 二叉树的子树有左右之分，其子树的次序不能颠倒。

### 特殊的二叉树：

1. 满二叉树：

   - 所有的叶节点都在最后一层
   - 所有分枝节点都有两个孩子
   - 第k层有2^(k-1)^个节点，到k层总共有2^k^-1个节点

2. 完全二叉树：

   - 前N-1层都是满的
   
   - 最后一层不满，但是最后一层从左到右是连续的

   - 最多只有一个度为1的节点
   
   - 高度为h的完全二叉树的节点个数范围是：2^h-1^ ~ 2^h^-1
   
   - 具有n个节点的完全二叉树，叶子节点的个数为：
   
     > n~0~ + n~1~ +n~2~ = n
     >
     > n~0~ = n~2~ +1
     >
     > -->2n~0~ + n~1~ = n+1
     >
     > 又知道完全二叉树最多只有一个度为1的节点
     >
     > - n如果为偶数，n+1奇数，n~1~必须为1；
     >
     > - n如果为奇数，n+1偶数，n~1~必须为0；
   
     
   
   ![CleanShot 2022-10-04 at 23.11.02@2x](/Users/amor/Library/Application Support/CleanShot/media/media_s9UTOo4kgY/CleanShot 2022-10-04 at 23.11.02@2x.png)

### 二叉树的存储结构

二叉树一般可以使用两种结构存储，一种是顺序结构，一种是链式结构。

### 二叉树的性质

- 若规定根节点的层数为i，则一棵非空二叉树的第i层上最多有2^(i-1)^ 个结点。
- 若规定根节点的层数为1，则深度为h的二叉树的最大结点数是2^h^-1。
- 对任何一棵二叉树，如果度为0其叶结点个数为 n~0~,度为2的分支结点个数为 n~2~,则有n~0~=n~2~ +1。***换言之，我们叶子节点的个数永远比度为2的节点个数多1个。***
- 若规定根节点的层数为1，具有n个结点的满二叉树的深度，***h=Log~2~(n+1)。***
- 对于具有n个结点的完全二叉树，如果按照从上至下从左至右的数组顺序对所有节点从0开始编号，则对于序号为的结点有：
  1. 若i>0，i位置节点的双亲序号：(i-1)/2；若i=0，为根节点编号，无双亲节点
  2. 若2i+1>n，左孩子序号：2i+1，2i+1>=n否则无左孩子
  3. 若2i+2<n，右孩子序号：2i+2，2i+2>=n否则无右孩子

二叉树不学习增删查改，普通二叉树的增删查改没有意义，主要学习控制它的结构。以后完成搜索二叉树，在此基础上实现AVL树和红黑树，这些才会研究他的增删查改。

#### 顺序储存

顺序结构存储就是用数组来存储，一般使用数组只适合表示完全二叉树，因为不是完全二叉树会有空间的浪费，而现实中使用中只有堆才会用数组来存储。二叉树顺序存储在物理上是一个数组，在逻辑上是一棵二叉树。

- 假设parent是父亲节点在数组中的下标，
  - 那么子节点：左孩子leftchild = parent*2+1
  - 子节点右孩子rightchild = parent*2+2
- 假设子节点下标识child，不管是左孩子还是右孩子，都用
  - Parent = (child - 1)/2

#### 链式储存

二叉链和三叉链，后面再进行讲解。

## 堆

操作系统堆程序内存区域的划分：从下到上依次为，常量区，静态区，堆，....，栈。***操作系统里面的堆***主要是用来创建栈帧。

数据结构里的栈和堆是与操作系统里的栈和堆***没有任何关系***。

### 堆的概念及结构

- 大堆：树中一个树及子树中，任何一个父亲都大于等于孩子。
- 小堆：树中一个树及子树中，任何一个父亲都小于等于孩子。

所有的数组都可以表示成完全二叉树，但是他不一定是堆。

堆的应用：

1. 堆排序
2. topK问题。在N个树中，找出最大的前K个/找出最小的前K个

### 堆的实现

- 堆的逻辑结构：完全二叉树
- 堆的物理结构：数组

所以我们需要在顺序表的基础上实现堆：（***在这里我们模拟实现大堆）***

#### 头文件

```c
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
    HPDataType *a;
    int size;
    int capacity;
} HP;
void HeapInit(HP *hp);
void HeapDestroy(HP *hp);
void HeapPush(HP *hp,HPDataType x);
void HeapPop(HP *hp);
```

#### 初始化和销毁

```c
void HeapInit(HP *hp)
{
    assert(hp);
    hp->a = NULL;
    hp->size = hp->capacity = 0;
}
void HeapDestroy(HP *hp)
{
    assert(hp);
    free(hp->a);
    hp->capacity = hp->size = 0;
}
```

#### 插入 HeapPush

我们模拟实现大堆，也就是父节点大于子节点

堆插入数据对其他节点没有影响，只是可能会影响从他到跟节点路径上的节点关系

我们采用***向上调整***策略，新插入的子节点找到父节点，比较后大的值成为父节点，小的值称为子节点，然后比较直到比较到根节点或者父节点大于插入的数据节点。

```c
void AdjustUp(int *a, int size, int child) // child = hp->size
{
    assert(a);
    int parent = (child - 1) / 2;
    while (child > 0)
    {
        if (a[child] > a[parent])
        {
            HPDataType tmp = a[child];
            a[child] = a[parent];
            a[parent] = tmp;

            child = parent;
            parent = (child - 1) / 2;
        }
        else
            break;
    }
}
```

```c
void HeapPush(HP *hp, HPDataType x)
{
    assert(hp);
    //实现增容
    if (hp->size == hp->capacity)
    {
        size_t newCapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
        HPDataType *tmp = (HP *)realloc(hp->a, sizeof(HP) * newCapacity);
        if (!tmp)
        {
            perror("malloc");
            exit(-1);
        }
        hp->a = tmp;
        hp->capacity = newCapacity;
    }
    //假设实现大堆
    AdjustUp(hp->a, hp->size, hp->size - 1);
}
```

#### 删除堆顶数据

删除堆顶数据的意义是删除最值，如果暴力删除然后错位会导致

- 堆结构完全改变，全部乱套。
- 时间复杂度O(N)，不简便。

我们的思路是：

1. 我们把堆顶数据和堆底数据位置置换。
2. 堆顶元素向下调整。
3. 跟左右孩子中小的那个交换（假设的是小堆）。
4. 中止条件
   - 父亲<=小的孩子则停止。
   - 或者到了叶节点(叶子的特征没有左孩子，左孩子下标超出数组范围)。

由于置换我们经常用，所以单独写了置换函数

```c
void HeapSwap(HPDataType *px, HPDataType *py)
{
    HPDataType tmp = *px;
    *px = *py;
    *py = tmp;
}
```

向下调整，很多小伙伴会比较纠结父节点到底是和左孩子还是和右孩子比较大小，这里我们不妨只定义孩子child节点，由于数组在内存中连续存放，可以轻易定义到child右边的节点就是右孩子(需要判断右孩子存在与否)，然后寻找这两个里面大的那个孩子和父亲做比较，如果孩子大，则孩子与父亲交换。（以大堆为例）

比较官方的写法是：

```c
void AdjustDown(int *a, int size, int parent)
{
    assert(a);
    int child = parent * 2 + 1;
    while (child < size)
    {
        //选出左右孩子中大的那个
        if (child + 1 < size && a[child + 1] > a[child])
        {
            child++;
        }
        //如果大的孩子 大于 父亲，交换
        if (a[child] > a[parent])
        {
            HeapSwap(&a[child], &a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}
```

***时间复杂度为：O(log~2~N)，（高度）***

此外再提供一种思路，比较清晰，也是找到大孩子，不过采用了把找大孩子作为一个函数来编写。

```c
int SearchForBigChild(int parent,int size)
{
    int smallChild = parent * 2 + 1;
    int bigChild = parent * 2 + 2;
    //有右孩子
    if (bigChild < size)
    {
        bigChild = smallChild > bigChild ? smallChild : bigChild;
    }
    //只有一个孩子
    else
        bigChild = smallChild;

    return bigChild;
}
//默认大堆
void AdjustDown(int *a, int size, int parent)
{
    assert(a);
    HeapSwap(&a[parent], &a[size - 1]);
    int bigChild = SearchForBigChild(parent, size);
    while (bigChild < size)
    {
        if (a[parent] < a[bigChild])
        {
            HeapSwap(&a[parent], &a[bigChild]);

            parent = bigChild;
            bigChild = SearchForBigChild(parent, size);
        }
        else
            break;
    }
}

```

随后编写删除函数

```c
void HeapPop(HP *hp)
{
    //只能删除堆顶的数据
    assert(hp);
    assert(!HeapEmpty(hp));
    //对换
    HeapSwap(&hp->a[0], &hp->a[hp->size - 1]); //最后一个数据是size-1
    hp->size--;
    AdjustDown(hp->a, hp->size, 0);
}
```

### 经典的topK问题

在N个数中找出最大的前K个

| 方式 |                             思路                             |
| ---- | :----------------------------------------------------------: |
| 1    |     先排降序，前K个就是最大的。时间复杂度为O(N*log~2~N)      |
| 2    | N个数依次插入大堆(建立N个数的堆时间复杂度为O(N) )，PopK次(时间复杂度为O(K*log~2~N))，每次取堆顶的数据就是前K个。时间复杂度为O(N+Klog~2~N) |
| 3    | 假设N非常大，内存中存不下这些数，它们存在文件中，方式1、2都不能用了。（1G约为10亿字节)我们这么做：1.用前K个数建立K个数的小堆，2.用剩下的N-K个数依次跟堆顶的数据进行比较，如果比堆顶的数据大，就替换堆顶的数据，在向下调整，3.最后堆里面的K个数就是最大的K个数。时间复杂度为：O(K+(N-K)*logK) ~ O(N logK) ~ O(N) |

```c
void PrintTopK(int *a, int n, int k)
{
    HP hp;
    HeapInit(&hp);
    //创建K个数的小堆
    for (int i = 0; i < k; ++i)
    {
        HeapPush(&hp, a[i]);
    }
    //剩下N-K个数与堆顶数据比较，比他大就替换他进堆
    for (int i = k; i < n; i++)
    {
        if (a[i] > HeapTop(&hp))
        {
            HeapPop(&hp);
            HeapPush(&hp, a[i]);
        }
    }
    HeapPrint(&hp);
    HeapDestroy(&hp);
}
```

注意：TopK找前K个最大数，需要建立小堆；等到堆排序的时候，排升序，需要建立大堆。

### 堆排序

给一个数组，让数组中的n个数在堆中排序（比如升序）

#### 思路

正常思路一般都是，创建一个数组来接收数(构建堆)，插入后形成n个数的堆，不断选数再传回原来的数组。这样会浪费空间。具体思路为：

- 建立一个n个数的堆
- PopN次

换个思路：数组是可以被看作完全二叉树的。更进一步，我们可以

把它构建成堆（排升序，建小堆）。有两种方法：

- 把数组从a[0]开始，视作一个一个加入进来的，只不过需要向上调整，所以我们写一个循环让每个数加进来的同时向上调整。

```c
    for (int i = 1; i < n;i++)
    {
        AdjustUp(a, i);
    }
```

- 向下调整的方法。向下调整算法的前提是左右子树都是小堆。而叶子所在的子树不需要调，所以倒着走第一个非叶子节点的子树可以找到(用parent = child-1/2)，我找到了最后一个非叶子节点的子树父节点，只需要减一就可以得到所有的父亲节点。

```c
    for (int i = (n - 1 - 1) / 2; i >= 0; --i) // n为数组中元素个数而非最后一位的下标
      //要>=0因为根节点也要向上调整。
    {
        AdjustDown(a, n, i);
    }
```

> 我们建立小堆之后可以选出最小的数，放在堆顶了。如何挑选出次小的数呢？
>
> > 如果删掉堆顶数据，从堆顶的下一个位置视作堆顶。那么之前建立好的堆的关系就全部乱了，必须重新排列重新建堆，那么时间复杂度会飙升->O(N*N)。(这个时间复杂度还不如遍历选数呢)
>
> 我们换一种思路，排升序我们建大堆。

思路转变为：

1. 建***大堆*** (只需要让AdjustDown函数改变一下大小关系即可)，选出最大的数。
2. 最大的数跟最后一个数***交换。***得到最小的数
3. *如何选出次小的数呢？* 把最后一个数不看做堆里面的数，进行向下调整，就可以选出次小的数，以此类推重复上面的过程。

只需要调整高度次，也就是时间复杂度为N*logN(N为堆中元素个数)

```c
    //标记最后一位的位置，方便后面的删除
    //依次选数，调堆
    int pos = n - 1;
    while(pos--)
    {
        HeapSwap(a+0, a + pos);
        //选出次小的数
        AdjustDown(a, pos, 0);
    }
```

如果想要排降序，只需要把向下排序调整大小关系即可。最后的代码如下：

```c
//进行堆排序
void HeapSort(int *a, int n)
{
    //方法一
    // for (int i = 1; i < n;i++)
    // {
    //     AdjustUp(a, i);
    // }
    //方法二
    for (int i = (n - 1 - 1) / 2; i >= 0; --i) // n为数组中元素个数而非最后一位的下标
    {
        AdjustDown(a, n, i);
    }

    //标记最后一位的位置，方便后面的删除
    //依次选数，调堆
    int pos = n - 1;
    while(pos--)
    {
        HeapSwap(a+0, a + pos);
        //选出次小的数
        AdjustDown(a, pos, 0);
    }
}
```

堆排序是迄今为止比较优的排序，因为其时间复杂度是O(N*logN).

### 建堆的时间复杂度

因为堆是完全二叉树，而满二叉树也是完全二叉树。此处为了简化使用满二叉树来证明(时间复杂度本来看的就是近似值，多几个节点并不影响最终结果)

假设树高为h，则第k层有2^k-1^个节点，第k层又是倒数第h-k+1层，需要的最坏情况下(最多)的向下调整次数为：(h-k+1)-1 = h-k次，节点数乘以向下调整次数就是这一层总共需要调整的次数。把每层的依次相加，就得到了总共需要向下调整的次数。

等比乘以等差，用错位相减。最终算出来总共需要移动节点的总的移动步数值为：

T(n) = n - log~2~(n+1) 约为n。

## 二叉树的链式结构及实现

普通二叉树的增删查改没有什么价值，因为用来存放数据太复杂了。它的价值在于

- 在他的基础之上增加一些性质，才有意义，比如
  - 搜索二叉树，左子树的值都比父节点小，右子树的值逗比父节点大。最多可以查找高度次。->平衡搜索二叉树、AVLTree、红黑树 -> B树
  - huffman tree

不关注增删查改，关注递归遍历结构。

学习这个是为了后面学习更有用的树打基础，同时很多oj题目结构普通二叉树。

### 前序、中序以及后序遍历

学习二叉树的结构，最简单的方式就是遍历。二叉树遍历 (Traversal)时按照某种待定的规则，依次堆二叉树中的节点进行相应的操作，并且每个节点只操作一次。

二叉树可以分为根、左子树和右子树。走到空就中止。

二叉树的遍历分为：前序/中序/后序的递归结构遍历。![CleanShot 2022-10-08 at 23.22.32@2x](/Users/amor/Library/Application Support/CleanShot/media/media_sQfEi8qCFO/CleanShot 2022-10-08 at 23.22.32@2x.png)

1. 前序遍历（preorder Traversal） -- 访问跟节点的操作发生在遍历左右子树之前。

   根 -> 左子树 -> 右子树 

   也就是说，遍历顺序为： A->B->D ->NULL(left) -> NULL(right) -> NULL(B下面) -> C -> E -> NULL(left) ->NULL(right)->F->NULL(left)->NULL(right) 

   前期学习应该把空写出来，表示清楚的遍历顺序，但是在打印的时候由于是空，所以不会打印出来。

2. 中序遍历（Inorder Traversal） -- 访问根节点的操作发生在遍历其左右子树中间。

   左子树 -> 根 -> 右子树

   也就是访问A先访问A的左子树B，访问B先访问B的左子树D，访问D先访问D的左子树NULL，所以是：

   NULL(left) -> D ->NULL(right) -> B -> NULL(right) -> A -> NULL(left) -> E -> NULL(right) -> C -> NULL(left) -> F -> NULL(right) 

3. 后序遍历（postorder Traversal）

   左子树 -> 右子树 -> 根

   NULL(left) -> NULL(right) -> D -> NULL(right) -> B ->NULL(left) -> NULL( right) -> E -> NULL(left) -> NULL(right) -> F -> C -> A

## 实现遍历

分置思想，大事化小小事化了

### 前序遍历

```c
void PreOrder(BTNode *root)
{
    if(root == NULL)
    {
        printf("NULL ");
        return;
    }
    printf("%c ",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}
```

本质就是遇到空或者调用完成后就会回到调用的地方，然后继续进行递归。

### 中序遍历

```c
void InOrder(BTNode *root)
{
    if(!root)
    {
        printf("NULL ");
        return;
    }
    PreOrder(root->left);
    printf("%c ", root->data);
    PreOrder(root->right);
}
```

遇到了不为空的节点，先走这个节点的左子树，左子树不为空，再找左子树，直到为空，打印，然后往回走。只是因为顺序不同，打印的时机不同。

### 后序遍历

```c
void PostOrder(BTNode *root)
{
    if (!root)
    {
        printf("NULL ");
        return;
    }
    PreOrder(root->left);
    PreOrder(root->right);
    printf("%c ", root->data);
}
```

### 求二叉树节点的个数

如果我们用一遍遍历。在此我们用前序遍历写一下。

---

错误：

```c
int BinaryTreeSize(BTNode *root)
{
    int num = 0;
    if (!root)
    {
        printf("NULL ");
        return;
    }
    num++;//这样是不对的。结合栈帧的知识，每次递归都是建立栈帧，出函数后会销毁
    //用静态的和用全局的都会出现多次调用存在问题。（不会销毁）
    BinaryTreeSize(root->left);
    BinaryTreeSize(root->right);
}
```

---

我们可以在main函数里创建一个变量，然后传变量的地址进去就可以了。

```c
void BinaryTreeSize(BTNode *root, int *pn)
{
    if (!root)
    {
        return;
    }
    ++(*pn);
    BinaryTreeSize(root->left, pn);
    BinaryTreeSize(root->right, pn);
}
```

调用多次也不会出现问题。还有一种方式，返回值可以帮助我们解决：





## 二叉树的顺序结构及实现

## 
