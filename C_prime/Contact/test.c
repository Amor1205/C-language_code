//用于测试功能
#include "addbook.h"
void menu()
{
    printf("******************************************\n");
    printf("******************************************\n");
    printf("***********  1.add     2.del      ********\n");
    printf("***********  3.search  4.modify   ********\n");
    printf("***********  5.show    6.sort     ********\n");
    printf("***********  0.exit               ********\n");
    printf("******************************************\n");
}
int main()
{
    int input = 0;
    Addbook abk; //通讯录
    //初始化通讯录
    InitAddbook(&abk); //要改变肯定要传递地址

    do
    {
        menu();
        printf("please input the number:> ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            AddInfo(&abk); //增加通讯录
            break;
        case 2:
            DelAdd(&abk);
            break;
        case 3:
            SearchAdd(&abk);
            break;
        case 4:
            ModifyAdd(&abk);
            break;
        case 5:
            ShowAbk(&abk);
            break;
        case 6:
            SortAbk(&abk);
            break;
        case 0:
            SaveAbk(&abk);
            printf("exit the address book\n");
            DestroyAdd(pc);
            break;
        default:
            printf("have choosen a wrong number\n");
            break;
        }
    } while (input);
    return 0;
}