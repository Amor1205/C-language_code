#pragma once
#include <stdio.h>
#include <assert.h>

typedef int LTDataType;
typedef struct ListNode
{
    LTDataType data;
    struct ListNode *next;
    struct ListNode *prev;
}ListNode;

ListNode* ListInit();
void ListPushBack(ListNode *phead, LTDataType x);
void ListPrint(ListNode *phead);
void ListPushFront(ListNode *phead, LTDataType x);
void ListPopBack(ListNode *phead, LTDataType x);
void ListPopFront(ListNode *phead, LTDataType x);
