#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define N 100 //用宏去定义数组大小
typedef int SLDataType;
//静态数据表
//静态特点，如果满了就不让插入
//缺点，N给小了，不够用，N给大了浪费
// typedef struct SeqList
// {
//     SLDataType a[N];
//     int size; //数组中存储了多少个数据
// } SL;
//用动态开辟空间
typedef struct SeqList
{
    SLDataType *a; //实际上就是int*a，是由a[N]变种得到的。为的是动态开辟空间
    int size;      //数组中存储了多少个数据/个数
    int capacity;  //数组实际能存数据的空间容量。

} SL;
//接口函数- 明明按照STL走。
void SeqListInit(SL *ps);
void SeqListPushBack(SL *ps, SLDataType x);  //尾上插入
void SeqListPushFront(SL *ps, SLDataType x); //头插
void SeqListPopBack(SL *ps);                 //尾删
void SeqListPopFront(SL *ps);                //头删
void SeqListPrint(const SL *ps);
void SeqListDestroy(SL *ps);
void SeqListCheckCapacity(SL *ps);
int SeqListFind(SL *ps, SLDataType x);             //找到了返回x位置下标，找不到返回-1
void SeqListInsert(SL *ps, int pos, SLDataType x); //在pos位置插入数据
void SeqListErase(SL *ps, int pos);                //删除pos位置的数据