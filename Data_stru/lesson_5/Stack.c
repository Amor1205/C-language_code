#include "Stack.h"

StackInit(ST *ps)
{
    assert(ps);
    ps->a = NULL;
    ps->top = 0; //初始化时top给0，意味着top指向栈顶数据的下一个
    ps->capacity = 0;
}
void StackDestroy(ST *ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->capacity = ps->top = 0;
}
void StackPush(ST *ps, STDataType x)
{
    assert(ps);
    //考虑增容
    if (ps->top == ps->capacity)
    {
        //给定大小
        int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
        //开辟空间
        STDataType *tmp = realloc(ps->a, sizeof(STDataType) * newCapacity);
        if (!tmp)
        {
            perror("realloc");
            return -1;
        }
        ps->a = tmp;
        ps->capacity = newCapacity;
    }
    ps->a[ps->top] = x;
    ps->top++;
}
void StackPop(ST *ps)
{
    assert(ps);
    assert(ps->top > 0);
    //或者用assert(!StackEmpty(ps));
    ps->top--;
}
STDataType StackTop(ST *ps)
{
    assert(ps);
    assert(ps->top > 0);
    //或者用assert(!StackEmpty(ps));
    return ps->a[ps->top - 1];
}
int StackSize(ST *ps)
{
    assert(ps);
    return ps->top;
}
bool StackEmpty(ST *ps)
{
    assert(ps);
    return ps->top == 0;
    //空则返回1，真
}
