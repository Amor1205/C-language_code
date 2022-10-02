#include "SList.h"

//删除是先指再删

void SListPrint(SLTNode *phead)
{
    SLTNode *cur = phead;
    while (cur != NULL)
    {
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
SLTNode *BuyListNode(SLTDataType x) //帮助创建节点，并赋值
{
    SLTNode *newnode = (SLTNode *)malloc(sizeof(SLTNode));
    if (newnode == NULL)
    {
        perror("malloc");
        exit(-1);
    }
    newnode->next = NULL;
    newnode->data = x;
}
void SListPushBack(SLTNode **pphead, SLTDataType x)
{
    SLTNode *newnode = BuyListNode(x);

    if (*pphead == NULL)
    {
        *pphead = newnode;
    }
    SLTNode *tail = *pphead;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = newnode;
}

void SListPushFront(SLTNode **pphead, SLTDataType x)
{
    SLTNode *newnode = BuyListNode(x);

    newnode->next = *pphead;
    *pphead = newnode;
}
void SLitstPopBack(SLTNode **pphead)
{
    // if (*pphead == NULL)
    // {
    //     return;
    // }
    assert(*pphead); //比较粗暴
    if (((*pphead)->next) == NULL)
    {
        free((*pphead)->next);
        *pphead = NULL;
    }
    SLTNode *prev = NULL;
    SLTNode *tail = *pphead;
    while (tail->next)
    {
        prev = tail;
        tail = tail->next;
    }
    free(tail);
    tail = NULL;
    prev->next = NULL;
}
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
SLTNode *SListFind(SLTNode *phead, SLTDataType x)
{
    SLTNode *pos = phead;
    while (pos)
    {
        if (pos->data == x)
        {
            return pos;
        }
        pos = pos->next;
    }
    return NULL;
}
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
void SListInsertAfter(SLTNode *pos, SLTDataType x)
{
    SLTNode *newnode = BuyListNode(x);
    newnode->next = pos->next;
    pos->next = newnode;
}

void SListErase(SLTNode **pphead, SLTNode *pos)
{
    assert(pphead);
    assert(pos);

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
void SListEraseAfter(SLTNode *pos)
{
    assert(pos->next);
    SLTNode *next = pos->next;
    pos->next = next->next;
    free(next);
    next = NULL;
}
void SListDestroy(SLTNode **pphead)
{
    assert(pphead);
    while (pphead)
    {
        SLitstPopBack(pphead);
    }
}
void SListDestroy1(SLTNode **pphead)
{
    assert(pphead);
    SLTNode *cur = pphead;
    while (cur)
    {
        SLTNode *next = cur->next;
        free(cur);
        cur = next;
    }
    *pphead = NULL;
}