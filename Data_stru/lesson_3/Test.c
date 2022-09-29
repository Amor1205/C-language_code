#include "SList.h"

void SListTest1()
{
    SLTNode *plist = NULL;

    SListPushBack(&plist, 1);
    SListPushBack(&plist, 2);
    SListPushBack(&plist, 3);
    SListPushBack(&plist, 2);
    SListPushBack(&plist, 4);
    SListPushBack(&plist, 2);
    SListPushBack(&plist, 5);

    SListPrint(plist);
    //多次查找的代码
    // SLTNode* pos = SListFind(plist,2);
    // int i = 1;
    // while(pos)
    // {
    //     printf("第%d个pos节点: %p->%d\n", i++, pos, pos->data);
    //     pos = SListFind(pos->next, 2);
    // }
    //查找的同时也可以修改
    SLTNode *pos = SListFind(plist, 3);
    
}
int main()
{

    SListTest1();
    return 0;
}