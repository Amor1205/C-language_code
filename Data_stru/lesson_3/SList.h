#pragma once
#include <stdio.h>

typedef int SLTDataType;
typedef struct SListNode
{
    SLTDataType data;
    struct SListNode *next;
} SLTNode;

void SListPrint(SLTNode *phead);
void SListPushFront(SLTNode **pphead, SLTDataType x);
void SListPushBack(SLTNode **pphead, SLTDataType x);
void SLitstPopFront(SLTNode **pphead);
void SLitstPopBack(SLTNode **pphead); //尾一般不用，只有当为空的时候，才需要二级指针
SLTNode *SListFind(SLTNode *phead, SLTDataType x);
void SListInsert(SLTNode **pphead, SLTNode *pos, SLTDataType x); //在pos前面插入
void SListInsertAfter(SLTNode *pos, SLTDataType x);              //在后面插入
void SListErase(SLTNode **pphead, SLTNode *pos);
void SListDestroy(SLTNode **phead);
