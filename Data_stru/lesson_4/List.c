#include "List.h"
ListNode *ListInit()
{
    ListNode *phead = (ListNode *)malloc(sizeof(ListNode));
    phead->prev = phead;
    phead->next = phead;

    return phead;
}

void ListPushBack(ListNode *phead, LTDataType x)
{
    assert(phead);
    ListNode *tail = phead->prev;
    ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
    //赋值
    newnode->data = x;
    //修改指向
    tail->next = newnode;
    newnode->prev = tail;
    newnode->next = phead;
    phead->prev = newnode;
}

void ListPrint(ListNode *phead)
{
    assert(phead);
    ListNode *cur = phead->next;
    while (cur != phead)
    {
        printf("%d  ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
void ListPushFront(ListNode *phead, LTDataType x)
{
    assert(phead);
    ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
    //赋值
    newnode->data = x;
    ListNode *next = phead->next;
    //修改指向
    phead->next = newnode;
    newnode->prev = phead;
    newnode->next = next;
    next->prev = newnode;
}
void ListPopBack(ListNode *phead, LTDataType x)
{
    assert(phead);
    assert(phead->prev != phead);
    ListNode *tail = phead->prev;
    ListNode *tailPrev = tail->prev;
    //修改指向
    tailPrev->next = phead;
    phead->prev = tailPrev;
    free(tail);
}
void ListPopFront(ListNode *phead, LTDataType x)
{
    assert(phead->next != phead);
    assert(phead);
    ListNode *headNext = phead->next;
    //修改指向
    phead->next = headNext->next;
    headNext->next->prev = phead;
    free(headNext);
}