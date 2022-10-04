#include "queue.h"
void QueueInit(Queue *pq)
{
    assert(pq);
    pq->head = NULL;
    pq->tail = NULL;
}
void QueueDestroy(Queue *pq)
{
    assert(pq);
    QueueNode *cur = pq->head;
    while (cur)
    {
        QueueNode *next = cur->next;
        free(cur);
        cur = next;
    }
    pq->head = pq->tail = NULL;
}
QueueNode *Buynewnode(Queue *pq, QDataType x)
{
    assert(pq);
    QueueNode *newnode = (QueueNode *)malloc(sizeof(QueueNode));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}
void QueuePush(Queue *pq, QDataType x)
{
    assert(pq);
    if (pq->tail == NULL)
    {
        pq->tail = pq->head = Buynewnode(pq, x);
    }
    else
    {
        QueueNode *newnode = Buynewnode(pq, x);
        pq->tail->next = newnode;
        pq->tail = newnode;
    }
}
void QueuePop(Queue *pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));

    QueueNode *next = pq->head->next;
    free(pq->head);
    pq->head = next;
    if(pq->head == NULL)
    {
        pq->tail = NULL;
    }
}
QDataType QueueFront(Queue *pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    //队尾
    return pq->head->data;
}
QDataType QueueBack(Queue *pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    //队尾
    return pq->tail->data;
}
int QueueSize(Queue *pq)
{
    assert(pq);
    int n = 0;
    QueueNode *cur = pq->head;
    while(cur)
    {
        ++ n;
        cur = cur->next;
    }
    return n;
}
bool QueueEmpty(Queue *pq)
{
    assert(pq);
    return pq->head == NULL;//空则返回1
}


//用队列实现栈
// typedef int QDataType;
// typedef struct QueueNode
// {
//     struct QueueNode *next;
//     QDataType data;
// } QueueNode;

// typedef struct Queue
// {
//     QueueNode *head;
//     QueueNode *tail;
// } Queue;

// void QueueInit(Queue *pq)
// {
//     assert(pq);
//     pq->head = NULL;
//     pq->tail = NULL;
// }
// void QueueDestroy(Queue *pq)
// {
//     assert(pq);
//     QueueNode *cur = pq->head;
//     while (cur)
//     {
//         QueueNode *next = cur->next;
//         free(cur);
//         cur = next;
//     }
//     pq->head = pq->tail = NULL;
// }
// QueueNode *Buynewnode(Queue *pq, QDataType x)
// {
//     assert(pq);
//     QueueNode *newnode = (QueueNode *)malloc(sizeof(QueueNode));
//     newnode->data = x;
//     newnode->next = NULL;
//     return newnode;
// }
// void QueuePush(Queue *pq, QDataType x)
// {
//     assert(pq);
//     if (pq->tail == NULL)
//     {
//         pq->tail = pq->head = Buynewnode(pq, x);
//     }
//     else
//     {
//         QueueNode *newnode = Buynewnode(pq, x);
//         pq->tail->next = newnode;
//         pq->tail = newnode;
//     }
// }
// int QueueEmpty(Queue *pq)
// {
//     assert(pq);
//     return pq->head == NULL; //空则返回1
// }
// void QueuePop(Queue *pq)
// {
//     assert(pq);
//     assert(!QueueEmpty(pq));

//     QueueNode *next = pq->head->next;
//     free(pq->head);
//     pq->head = next;
//     if (pq->head == NULL)
//     {
//         pq->tail = NULL;
//     }
// }
// QDataType QueueFront(Queue *pq)
// {
//     assert(pq);
//     assert(!QueueEmpty(pq));
//     //队尾
//     return pq->head->data;
// }
// QDataType QueueBack(Queue *pq)
// {
//     assert(pq);
//     assert(!QueueEmpty(pq));
//     //队尾
//     return pq->tail->data;
// }
// int QueueSize(Queue *pq)
// {
//     assert(pq);
//     int n = 0;
//     QueueNode *cur = pq->head;
//     while (cur)
//     {
//         ++n;
//         cur = cur->next;
//     }
//     return n;
// }

// typedef struct
// {
//     Queue q1;
//     Queue q2;
// } MyStack;

// MyStack *myStackCreate()
// {
//     //我们不能直接定义变量然后返回他的地址，因为本身这个局部变量出函数就销毁了。
//     //只能malloc
//     MyStack *st = (MyStack *)malloc(sizeof(MyStack)); // st是malloc出来的节点的地址
//     QueueInit(&st->q1);
//     QueueInit(&st->q2);
//     return st; //返回的是地址用一级指针接收
// }

// void myStackPush(MyStack *obj, int x)
// {
//     //传的是一级指针obj，是st的地址，obj->q1就是q1这个队列
//     // QueueEmpty需要传递的是Queue的地址，所以需要取地址
//     if (!QueueEmpty(&obj->q1))
//     {
//         QueuePush(&obj->q1, x);
//     }
//     else
//     {
//         QueuePush(&obj->q2, x);
//     }
// }

// int myStackPop(MyStack *obj)
// {
//     Queue *qEmpty = &obj->q1;
//     Queue *qNonEmpty = &obj->q2;
//     if (!QueueEmpty(&obj->q1))
//     {
//         qEmpty = &obj->q2;
//         qNonEmpty = &obj->q1;
//     }
//     while (QueueSize(qNonEmpty) > 1)
//     {
//         QueuePush(qEmpty, QueueFront(qNonEmpty));
//         QueuePop(qNonEmpty);
//     }
//     int top = QueueFront(qNonEmpty);
//     QueuePop(qNonEmpty);
//     return top;
// }

// int myStackTop(MyStack *obj)
// {
//     if (!QueueEmpty(&obj->q1))
//     {
//         return QueueBack(&obj->q1);
//     }
//     else
//         return QueueBack(&obj->q2);
// }

// bool myStackEmpty(MyStack *obj)
// {
//     return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
// }

// void myStackFree(MyStack *obj)
// {
//     QueueDestroy(&obj->q1);
//     QueueDestroy(&obj->q2);
//     free(obj);
// }
