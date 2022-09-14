//头文件
#pragma once
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_tELE 20
#define MAX_ADDR 30
//类型的声明

//人的信息
typedef struct PeoInfo
{
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tele[MAX_tELE];
    char addr[MAX_ADDR];
} PeoInfo;

//通讯录信息
typedef struct Addbook
{
    PeoInfo data[MAX]; //存放人的信息
    int count;         //记录当前通讯录中人的个数
} Addbook;
void InitAddbook(Addbook *);   //初始化通讯录
void AddInfo(Addbook *);       //增加联系人
void ShowAbk(const Addbook *); //显示通讯录的信息（打印）
void DelAdd(Addbook *);        //删除
void SearchAdd(Addbook *);     //搜索
void ModifyAdd(Addbook *);     //修改
void SortAbk(Addbook *);       //排序