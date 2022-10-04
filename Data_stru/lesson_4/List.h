#pragma once
#include <stdio.h>
#include <assert.h>

typedef int LTDataType;
typedef struct ListNode
{
    LTDataType data;
    struct ListNode *next;
    struct ListNode *prev;
} ListNode;

ListNode *ListInit();
void ListPushBack(ListNode *phead, LTDataType x);
void ListPrint(ListNode *phead);
void ListPushFront(ListNode *phead, LTDataType x);
void ListPopBack(ListNode *phead, LTDataType x);
void ListPopFront(ListNode *phead, LTDataType x);
void ListFind(ListNode *phead, LTDataType x);
void ListInsert(ListNode *pos, LTDataType x); //在pos之前插入
void ListErase(ListNode *pos);
void ListDestroy(ListNode *phead); //不传二级是可以的，需要在外面置空。
