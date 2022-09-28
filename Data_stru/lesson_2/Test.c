#include "Seqlist.h"
//建议不要一上来就写菜单，最好先写单元测试
//等把借口函数全部写完测试完再写
//因为菜单调试非常麻烦
void TestSeqList1()
{
    SL sl;
    SeqListInit(&sl);
    SeqListPushBack(&sl, 1);
    SeqListPushBack(&sl, 2);
    SeqListPushBack(&sl, 3);
    SeqListPushBack(&sl, 4);
    SeqListPushBack(&sl, 5);
    SeqListPrint(&sl);

    SeqListDestroy(&sl); //如果越界一般在destroy的时候会报错
}

void menu()
{
    printf("**************************************************\n");
    printf("********* please choose your operation ***********\n");
    printf("********* 1.PushFront 2.PushBack       ***********\n");
    printf("********* 3.PopFront  4.PopBack        ***********\n");
    printf("********* 5.Find      6.Erase          ***********\n");
    printf("********* 7.Print     8.Exit           ***********\n");
    printf("**************************************************\n");
}
void MenuTest()
{
    SL sl;
    SeqListInit(&sl);
    int input;
    while (input != -1)
    {
        Menu();
        scanf("%d", &input);
        int x = 0;
        switch (input)
        {
        case 1:
            printf("please input the number you want to push front, end with -1\n");
            scanf("%d", &x);
            while (x != -1)
            {
                SeqListPushFront(&sl, x);
                scanf("%d", &x);
            }
            break;
        case 2:
            SeqListPushBack(&sl, x);
            break;
        case 3:

            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        default:
            break;
        }
    }
    SeqListDestroy(&sl);
}
int main()
{

    TestSeqList1();
    return 0;
}
