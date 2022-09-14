//封装函数
//实现一个通讯录
//人的信息：名字年龄性别电话地址
// 1.存放100个人的信息
// 2.增加联系人
// 3.删除指定联系人
// 4.查找联系人
// 5.修改联系人
// 6.排序
// 7.显示联系人
#include "addbook.h"
void InitAddbook(Addbook *pc)
{
    assert(pc);
    pc->count = 0;
    memset(pc->data, 0, sizeof(pc->data)); //把pc中data部分内存全部变成0，不知道的字节数直接用sizeof计算
}

void AddInfo(Addbook *pc)
{
    assert(pc);
    if (pc->count == MAX)
    {
        printf("Address book is already full.\n");
        return;
    }
    printf("please input the name:>\n");
    scanf("%s", pc->data[pc->count].name); // scanf需要取地址，但是name[]是数组名本来就是地址。
    printf("please input the age of %s:>\n", pc->data[pc->count].name);
    scanf("%d", &(pc->data[pc->count].age));
    printf("please input the sex of %s:>\n", pc->data[pc->count].name);
    scanf("%s", pc->data[pc->count].sex);
    printf("please input the tele of %s:>\n", pc->data[pc->count].name);
    scanf("%s", pc->data[pc->count].tele);
    printf("please input the address of %s:>\n", pc->data[pc->count].name);
    scanf("%s", pc->data[pc->count].addr);
    printf("add information successfully");
}
void ShowAbk(const Addbook *pc)
{
    assert(pc);
    for (int i = 0; i < pc->count; i++)
    {
        printf("%-20s\t%-3s\t%-5s\t%-12s\t%-30s\n", "name", "age", "sex", "tele", "addr");
        printf("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
    }
}
static int Findbyname(Addbook *pc, char name[]) //别的地方不声明，可以保护
{
    assert(pc);
    for (int i = 0; i < pc->count; i++)
    {
        if (0 == strcmp(pc->data[i].name, name))
        {
            return i;
        }
    }
    return -1;
}

void DelAdd(Addbook *pc)
{
    char name[MAX_NAME] = {0};
    assert(pc);
    if (pc->count == 0)
    {
        printf("the address book is empty, nothing can be deleted.\n");
        return;
    }
    printf("please input the name whom you want to delete:>");
    scanf("%s", name);

    //删除需要先进行查找，
    int pos = Findbyname(pc, name);
    if (pos == -1)
    {
        printf("nonexist\n");
        return;
    }
    else
    //在进行删除(后面的元素往前覆盖)
    {
        for (int i = pos; i < pc->count - 1; i++)
        {
            pc->data[i] = pc->data[i + 1];
        }
        pc->count--;
        printf("delete successfully\n");
    }
}
void SearchAdd(Addbook *pc)
{
    assert(pc);
    char name[MAX_NAME] = {0};
    printf("please input the name whom you want to search:>");
    scanf("%s", name);
    // 1.查找
    int pos = FindByName(pc, name);
    if (pos == -1)
    {
        printf("nonexist");
        return;
    }
    // 2.打印

    printf("%-20s\t%-3s\t%-5s\t%-12s\t%-30s\n", "name", "age", "sex", "tele", "addr");
    printf("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n", pc->data[pos].name, pc->data[pos].age, pc->data[pos].sex, pc->data[pos].tele, pc->data[pos].addr);
}
void ModifyAdd(Addbook *pc)
{
    assert(pc);
    char name[MAX_NAME] = {0};
    printf("please input the name whom you want to modify:>");
    scanf("%s", name);
    // 1.查找
    int pos = FindByName(pc, name);
    if (pos == -1)
    {
        printf("nonexist\n");
        return;
    }

    // 2.修改
    printf("please input the name:>\n");
    scanf("%s", pc->data[pos].name);
    printf("please input the age of %s:>\n", pc->data[pos].name);
    scanf("%d", &(pc->data[pos].age));
    printf("please input the sex of %s:>\n", pc->data[pos].name);
    scanf("%s", pc->data[pos].sex);
    printf("please input the tele of %s:>\n", pc->data[pos].name);
    scanf("%s", pc->data[pos].tele);
    printf("please input the address of %s:>\n", pc->data[pos].name);
    scanf("%s", pc->data[pos].addr);
    printf("modify information successfully");
}
//按照名字来排序
int cmp_peo_by_name(const void *e1, const void *e2)
{
    return strcmp(((PeoInfo *)e1)->name, ((PeoInfo *)e2)->name);
}
void SortAbk(Addbook *pc)
{
    assert(pc);
    qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_peo_by_name);
    printf("Sort successfully");
}
