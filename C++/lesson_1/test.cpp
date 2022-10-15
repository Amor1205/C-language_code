#include <iostream>
using namespace std;

// namespace space
// {
//     //命名空间可以定义变量/函数/类型
//     int rand = 0;
//     int Add(int left, int right)
//     {
//         return left + right;
//     }
//     struct Node
//     {
//         struct Node *next;
//         int val;
//         /* data */
//     };
// }
// namespace N1
// {
//     int a;
//     namespace N2
//     {
//         int b;
//         namespace N3
//         {
//             int c;
//         }
//     }
// }
// int main()
// {
//     space::rand = 10;
//     struct space::Node node;
//     space::Add(1, 2);
//     int a = N1::a + N1::N2::b + N1::N2::N3::c;
//     cout << "hello world" << endl;
//     int i = 10;
//     double d = 10.1010;
//     printf("%d %f", i, d);
//     cout << i << " " << d << endl;
// }
// struct Time
// {
//     int year;
//     int month;
//     int date;
// };
// int main()
// {
//     struct Time t = {2000, 12, 05};
//     cout << "Year: " << t.year << endl;
//     cout << "Mon: " << t.month << endl;
//     cout << "Date: " << t.date << endl
//          << endl;
//     printf("Year: %d, Mon: %d, Date: %d", t.year, t.month, t.date);
//     // cpp
//     cin >> t.year >> t.month >> t.date;
//     // c
//     scanf("%d%d%d", &t.year, &t.month, &t.date);
//     return 0;
// }

// void Function(int a , int b = 20, int c = 30)
// {
//     cout << a << endl;
//     cout << b << endl;
//     cout << c << endl
//          << endl;
// }
// int main()
// {
//     //Function();
//     Function(1);
//     Function(1,2);
//     Function(1,2,3);

//     return 0
// }
// struct Stack
// {
//     int *a;
//     int top;
//     int capacity;
// };
// void StackInit(struct Stack *ps, int capacity = 4)
// {
//     ps->a = (int*)malloc(sizeof(int)*capacity);
//     ps->top = 0;
//     ps->capacity = capacity;
// }
// int main()
// {
//     struct Stack st;
//     StackInit(&st);//不知道栈要存多少个数据，就用缺省值初始化。
//     StackInit(&st,100);//知道栈最多存一百个数据，显式传值。
//     return 0;
// }

// int Add(int x,int y)
// {
//     cout << "int Add(int x,int y)" << endl;
//     return x + y;
// }
// double Add(double x, double y)
// {
//     cout << "double Add(double x,double y)" << endl;
//     return x + y;
// }
// int main()
// {
//     Add(1, 2);
//     Add(1.1, 2.2);
//     return 0;
// }
// void Func()
// {
//     cout << "void Func()" << endl;
// }
// void Func(int a)
// {
//     cout << "void Func(int a)" << endl;
// }
// int main()
// {
//     Func();
//     Func(10);
//     return 0;
// }

// void func(int a ,char c)
// {
//     cout << "void func(int a ,char c)" << endl;
// }
// void func(char c,int a)
// {
//     cout << "void func(char c,int a)" << endl;
// }
// int main()
// {
//     func(10, a);
//     func(a, 10);
//     return 0;
// }

// int main()
// {
//     int a = 10;
//     int &ra = a;//引用
//     int &b = a;
//     int c = 20;
//     b = c;
//     int *p = &a; //取地址
//     return 0;
// }
// void Swap(int*px,int*py)
// {
//     inttmp = *px;
//     *px = *py;
//     *py = tmp;
// }
// void swap2(int&r1,int&r2)
// {
//     int tmp = r1;
//     r1 = r2;
//     r2 = tmp;
// }
// int main()
// {
//     int x = 0, y = 1;
//     Swap(&x,&y);
//     swap2(x, y);
//     return 0;
// }

// void SListPushBack(SLTNode **pphead, SLTDataType x)
// {
//     SLTNode *newnode = BuyListNode(x);

//     if (*pphead == NULL)
//     {
//         *pphead = newnode;
//     }
//     SLTNode *tail = *pphead;
//     while (tail->next != NULL)
//     {
//         tail = tail->next;
//     }

//     tail->next = newnode;
// }

// int main()
// {
//     int a = 10;
//     int &b = a;

//     int *p1 = &a;
//     int *&p2 = p1;

//     return 0;
// }

// int& Add(int a,int b)
// {
//     int c = a + b;
//     return c;
// }
// int main()
// {
//     int& ret = Add(1, 2);
//     cout << ret << endl;
//     return 0;
// }

// struct A{
//     int a[10000];
// };
// A a;
// A TestFunc1(){
//     return a;
// }
// A& TestFunc2(){
//     return a;
// }

// int main()
// {
//     const int a = 10;
//     int &b = a;
//     //会报错，权限的放大
//     //const 权限是只读
//     //而引用的权限是读和写
//     //需要在引用前面加const
//     const int &b = a;

//     //权限缩小可以。
//     int c = 10;
//     const int &d = c;
//     //可以，不报错
//     return 0;
// }

//如果x是一个大对象或者是后面学习到的深拷贝对象
//那么尽量用引用传参，减少拷贝。如果f函数中不改变x
//建议尽量用引用const传参
//因为本身const类型的如果引用传参会报错（权限放大了）
//本身不是const类型可以引用传参
//但是如果用const传参的话，都不会报错。
void f(int &x)
{
    cout << x << endl;
}
// extern "C"
// {
//     #include "??.lib"
// }

#ifdef __cplusplus
extern "C"
{
#endif

    //此处写函数声明
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif

EXTERN_C; //函数声明
EXTERN_C; //函数声明
EXTERN_C; //函数声明
EXTERN_C; //函数声明
EXTERN_C; //函数声明
EXTERN_C; //函数声明

//宏
// #define ADD(x,y) ((x)+(y))
// cout << 10 * ADD(1, 2) << endl;

// int main()
// {
//     // int a = 10;
//     // // auto b = &a;  //int*
//     // // auto *c = &a; //int*
//     // // auto &d = a;  //int

//     // auto b = 'c';
//     // auto c = "adjadkw";

//     // cout << typeid(a).name() << endl;
//     // cout << typeid(b).name() << endl;
//     // cout << typeid(c).name() << endl;

//     // std::map<std::string, std::string> dic = {{"sort", "排序"} {"insert", "插入"}};
//     // std::map<std::string, std::string>::iterator it = dict.begin();
//     // auto it = dict.begin();

//     int i = 0;
//     auto j;

//     return 0;
// }

int main()
{
    //语法糖 -- 范围for
    int array[] = {1, 2, 3, 4, 5};
    //传统c/c++遍历数组
    // for (int i = 0; i < sizeof(array)/sizeof(int); i++)
    // {
    //     cout << array[i] << endl;
    // }

    // c++11范围for
    //依次自动取array中的每个元素赋值给e
    for (auto &e : array)
    {
        e++;
    }
    for (auto e : array)
    {
        cout << e << endl;
    }
    // c++98/03
    int *p1 = NULL;
    int *p2 = 0;
    // c++11
    int *p3 = nullptr;

    return 0;
}