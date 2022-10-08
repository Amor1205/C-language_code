typedef int BTDataType;
typedef(void *) 0 NULL;
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

int main()
{
    BTNode *root = createBinaryTree();
    PreOrder(root);

    return 0;
}