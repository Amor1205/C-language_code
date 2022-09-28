#include "Seqlist.h"
void SeqListCheckCapacity(SL *ps)
{
    //没空间，就扩容
    if (ps->size == ps->capacity)
    {
        int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
        //扩容二倍
        // realloc 如果原来指针是NULL，功能等同malloc
        SLDataType *tmp = (SLDataType *)realloc(ps->a, newcapacity * sizeof(SLDataType));
        if (tmp == NULL)
        {
            // printf("realloc fail\n");
            perror("realloc\n");
            exit(-1);
        }
        ps->a = tmp;
        ps->capacity = newcapacity;
    }
}
void SeqListInit(SL *ps)
{
    ps->a = NULL;
    ps->size = ps->capacity = 0;
}
// void SeqListPushBack(SL *ps, SLDataType x)
// {
//     //没空间，就扩容
//     SeqListCheckCapacity(ps);

//     ps->a[ps->size] = x;
//     ps->size++;
// }
//情况分别
// 1.全部为空，没空间
// 2.空间不够->扩容，一般是空间满了就扩容二倍。
// 3.空间足够->直接插

void SeqListPrint(const SL *ps)
{
    for (int i = 0; i < ps->size; ++i)
    {
        printf("%d", ps->a[i]);
    }
    printf("\n");
}
void SeqListDestroy(SL *ps)
{
    free(ps->a);
    ps->a = NULL;
    ps->size = ps->capacity = 0;
}
void SeqListPopBack(SL *ps)
{
    //温柔的方式
    // if (ps->size > 0)
    //     ps->size--; //直接减减，因为size就表示着储存的数据个数
    //断言方式
    assert(ps->size > 0);
    ps->size--;
}

// void SeqListPushFront(SL *ps, SLDataType x)
// {
//     SeqListCheckCapacity(ps);
//     int end = ps->size - 1;
//     while (end >= 0)
//     {
//         ps->a[end + 1] = ps->a[end];
//         --end;
//     }
//     ps->a[0] = x;
//     ps->size++;
// }
// void SeqListPopFront(SL *ps)
// {
//     assert(ps->size > 0);

//     //头删要求，往前往后地向前挪动 然后size--
//     int begin = 0;
//     while (begin < ps->size - 1)
//     {
//         ps->a[begin] = ps->a[begin + 1];
//         begin++;
//     }
//     ps->size--;
// }
int SeqListFind(SL *ps, SLDataType x)
{
    //从开始进行查找，找到为止
    int begin = 0;
    while (begin <= ps->size)
    {
        if (ps->a[begin] == x)
            return begin;
        else
            begin++;
    }
    return -1;
}
void SeqListInsert(SL *ps, int pos, SLDataType x)
{
    SeqListCheckCapacity(ps);
    //从pos位置，从前往后挪动数据
    assert(pos <= ps->size && pos >= 0);
    // if(pos >ps->size || pos<0)
    // {
    //     printf("pos is invalid\n");
    //     return;
    // }
    int end = ps->size - 1;
    while (end >= pos)
    {
        ps->a[end + 1] = ps->a[end];
        end--;
    }
    ps->a[pos] = x;
    ps->size++;
}
void SeqListErase(SL *ps, int pos)
{
    assert(pos < ps->size && pos >= 0); //不能等于，等于size处没有数据
    //从前往后向前挪动数据
    int begin = pos;
    while (begin < ps->size - 1)
    {
        ps->a[begin] = ps->a[begin + 1];
        begin++;
    }
    ps->size--;
}
//写完insert之后，可以直接进行复用，大大简化头插和尾插
// erase同理
void SeqListPushBack(SL *ps, SLDataType x)
{
    SeqListCheckCapacity(ps);
    SeqListInsert(ps, ps->size, x);
}
void SeqListPushBack(SL *ps, SLDataType x)
{
    SeqListCheckCapacity(ps);
    SeqListInsert(ps, 0, x);
}
void SeqListPopFront(SL *ps)
{
    assert(ps);
    SeqListErase(ps, 0);
}
void SeqListPopBack(SL *ps)
{
    assert(ps);
    SeqListErase(ps, ps->size - 1);
}