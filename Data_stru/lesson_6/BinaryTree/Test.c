typedef int BTDataType;
typedef struct BinaryTreeNode
{
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
    BTDataType data;
} BTNode;
BTNode *BuyNode(BTDataType x)
{
    BTNode *node = (BTNode *)malloc(sizeof(BTNode));
    node->data = x;
    node->left = node->right = NULL;
    return node;
}
BTNode *createBinaryTree()
{
    BTNode *nodeA = BuyNode('A');
    BTNode *nodeB = BuyNode('B');
    BTNode *nodeC = BuyNode('C');
    BTNode *nodeD = BuyNode('D');
    BTNode *nodeE = BuyNode('E');
    BTNode *nodeF = BuyNode('F');

    nodeA->left = nodeB;
    nodeA->right = nodeD;
    nodeB->left = nodeC;
    nodeC->right = nodeE;
    nodeC->right = nodeF;

    return nodeA;
}
//二叉树前序遍历
void PreOrder(BTNode *root)
{
    if (!root)
    {
        printf("NULL ");
        return;
    }
    printf("%c ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}
//二叉树中序遍历
void InOrder(BTNode *root)
{
    if (!root)
    {
        printf("NULL ");
        return;
    }
    PreOrder(root->left);
    printf("%c ", root->data);
    PreOrder(root->right);
}
//二叉树后序遍历
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
// int BinaryTreeSize(BTNode *root)
// {
//     int num = 0;
//     if (!root)
//     {
//         printf("NULL ");
//         return;
//     }
//     num++;//这样是不对的。结合栈帧的知识，每次递归都是建立栈帧，出函数后会销毁
//     //用静态的和用全局的都会出现多次调用存在问题。（不会销毁）
//     PreOrder(root->left);
//     PreOrder(root->right);
// }
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
int BinaryTreeSize(BTNode *root)
{
    return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
//求叶子节点的个数
int BinaryTreeLeafSize(BTNode *root)
{
    if (!root)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;

    return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

//求第k层的节点个数
int BinaryTreeLevelKSize(BTNode *root, int k)
{
    assert(k > 0);
    if (!root)
        return 0;
    if (k == 1)
        return 1;
    //若root不为空，k也不等于1，那么说明第k层还在root的子树里面
    //转换成求左右子树的第k-1层的节点数量
    return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
int BinaryTreeDepth(BTNode *root)
{
    //空树给0
    if (!root)
        return 0;
    int leftDepth = BinaryTreeDepth(root->left);
    int rightDepth = BinaryTreeDepth(root->right);
    //求较大值加1
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}
BTNode *BinaryTreeFind(BTNode *root, BTDataType x)
{
    if (!root)
        return NULL;
    if (root->data == x)
        return root;
    BTNode *leftNode = BinaryTreeFind(root->left, x);
    if (leftNode)
        return leftNode;
    BTNode *rightNode = BinaryTreeFind(root->right, x);
    if (rightNode)
        return rightNode;
    return NULL;
}
bool isUnivalTree(BTNode *root)
{
    if (!root)
        return true;
    if (root->left && root->left->data != root->data)
        return false;
    if (root->rigth && root->right->data != root->data)
        return false;
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}

int TreeSize(BTNode *root)
{
    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
int *_preorderTraversal(BTNode *root, int *a, int *pi)
{
    if (!root)
    {
        return;
    }
    a[(*pi)++] = root->data;
    _preorderTraversal(root->left, a, pi);
    _preorderTraversal(root->right, a, pi);
}
int *preorderTraversal(BTNode *root, int *returnSize)
{
    int size = TreeSize(root);
    int *a = (int *)malloc(sizeof(int) * size);
    //应该检查，oj题目可以不用。
    int i = 0;
    _preorderTraversal(root, a, &i);
    *returnSize = size;
    return a;
}
int main()
{
    BTNode *root = createBinaryTree();
    PreOrder(root);

    return 0;
}

bool isSameTree(BTNode *p, BTNode *q)
{
    if (!p && !q)
        return true;
    if (!p || !q)
        return false;
    if (p->data != q->data)
        return false;
    //&&是走完左边如果相等再走右边，如果左边值为0，则右边根本就不需要判断了。
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
bool _isSymmertric(BTNode *root1, BTNode *root2)
{
    if (!root1 && !root2)
        return true;
    if (!root1 || !root2)
        return false;
    if (root1->data != root2->data)
        return false;
    return _isSymmertric(root1->left, root2->right) && _isSymmertric(root1->right, root2->left);
}
bool isSymmertric(BTNode *root)
{
    if (!root)
        return true;
    return _isSymmertric(root->left, root->right);
}
bool isSubTree(BTNode *root, BTNode *subRoot)
{
    if (!root)
        return false;
    if (isSameTree(root, subRoot))
    {
        return ture;
    }
    return isSubTree(root->left, subRoot) || isSubTree(root->right, subRoot);
}
//层序遍历
void BinaryTreeLevelOrder(BTNode *root)
{
    if (!root)
        return;
    Queue q;
    QueueInit(&q);
    //队列得放结构体指针才可以。否则找不到左右孩子
    while (QueueEmpty(&q))
    {
        BTNode *front = QueueFront(&q);
        QueuePop(&q);
        printf("%d ", front->data);
        if (front->left)
        {
            QueuePush(&q, front->left);
        }
        if (front->right)
        {
            QueuePush(&q, front->right);
        }
    }
    printf("\n");
    QueueDestroy(&q);
}
int BinaryTreeComplete(BTNode* root)
{
        if (!root)
            return;
        Queue q;
        QueueInit(&q);
        //队列得放结构体指针才可以。否则找不到左右孩子
        while (QueueEmpty(&q))
        {
            BTNode *front = QueueFront(&q);
            QueuePop(&q);
            if(!front)
            {
                break;
            }
            else
            {
                QueuePush(&q, front->left);
                QueuePush(&q, front->right);
            }
        }
        BTNode* front = QueueFront(&q);
        // while (!front)
        // {
        //     //
        //     QueuePop(&q);
        //     front = QueueFront(&q);
        // }
        // if (front)
        //     {QueueDestroy(&q);
        //     return 0;}
        // return 1;

        while(!QueueEmpty(&q))
        {
            BTNode *front = QueueFront(&q);
            QueuePop(&q);

            if(front)
            {
                QueueDestroy(&q);
                return 0;
            }
        }
        QueueDestroy(&q);
        return 1;
}
void BinaryTreeDestroy(BTNode* root)
{
    if(!root)
        return;
    BinaryTreeDestroy(root->left);
    BinaryTreeDestroy(root->left);
    free(root);
}

