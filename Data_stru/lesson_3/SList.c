#include "SList.h"
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
    if (*pphead == NULL)
    {
        return;
    }
    // assert(*pphead!=NULL)//比较粗暴
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
}

void SListErase(SLTNode **pphead, SLTNode *pos);
void SListDestroy(SLTNode **phead);
