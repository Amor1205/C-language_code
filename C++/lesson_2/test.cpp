#include <iostream>
using namespace std;

// struct Student
// {
//     //成员变量
//     char _name[20];
//     int _age;
//     int _studentId;
//     //成员方法
//     void Init(const char* name,int age,int studentId)
//     {
//         strcpy(_name, name);
//         _age = age;
//         _studentId = studentId;
//     }
//     void Print()
//     {
//         cout << _name << endl;
//         cout << _age << endl;
//         cout << _studentId << endl;
//     }
// };
// int main()
// {
//     struct Student s1; //兼容C
//     Student s2;        //用类名创建对象
//     //旧的方法
//     strcpy(s1._name, "YYDS");
//     s1._age = 18;
//     s1._studentId = 10001;
//     //新的方法
//     s1.Init("YYDS", 19, 10002);
//     s2.Init("Xiaohong", 20, 10003);
//     s1.Print();
//     s2.Print();
//     return 0;
// }

// class Student
// {
//     //成员变量
//     char _name[20];
//     int _age;
//     int _studentId;
//     //成员方法
// public:
//     void Init(const char *name, int age, int studentId)
//     {
//         strcpy(_name, name);
//         _age = age;
//         _studentId = studentId;
//     }

// private:
//     void Print()
//     {
//         cout << _name << endl;
//         cout << _age << endl;
//         cout << _studentId << endl;
//     }
// };
// //.h
// class Stack
// {
// private:
//     int *_a;
//     int _capacity;
//     int _top;

// private:
//     void Init();

// public:
//     void Top();
// };
// //.cpp
// void Stack::Init()
// {
//     _a = nullptr;
//     _top = _capacity = 0;
// }

// //类中既有成员变量，也有成员函数
// class A1{
//     public:
//     void f1(){}
//     private:
//         int _a;
// };
// //类中仅有成员函数
// class A2{
//     public:
//     void f2(){}
// };
// //类中什么都没--空类
// class A3{};
// int main()
// {
//     A1 a1;
//     A2 a2;
//     A3 a3;
//     cout << sizeof(a1) << endl;//4
//     cout << sizeof(a2) << endl;//1
//     cout << sizeof(a3) << endl;//1

//     return 0;
// }

// class Date
// {
// public:
//     void Init(int year, int month, int date)
//     {
//         // Date::year = year
//         _year = year;
//         _month = month;
//         _date = date;
//     }
//     void Print()
//     {
//         cout << _year << "-" << _month << "-" << _date << endl;
//     }

// private:
//     // int year;//如果不加_，需要用Date::和函数中形参区分。
//     int _year; //加_就是为了区分函数中的形参和实参
//     int _month;
//     int _date;
// };

// int main()
// {
//     Date d1;
//     Date d2;
//     d1.Init(2022, 10, 15);
//     d1.Print();
//     d2.Init(2022, 12, 15);
//     d2.Print();
//     return 0;
// }
// d1.Print(&d1), d2.Print(&d2);

// class A
// {
// public:
//     void Show()
//     {
//         cout << "Show()" << endl;
//     }

// private:
//     int _a;
// };
// class B
// {
// public:
//     void Show()
//     {
//         cout << "_b" << endl;
//     }

// private:
//     int _b;
// };
// int main()
// {
//     A *pa = nullptr;
//     B *pb = nullptr;

//     pa->Show();
//     pb->Show();
// }

// int main()
// {
//     Date d1;               //无参数初始化d1
//     Date d2(2022, 10, 16); //有参数初始化d2
//     return 0;
// }
class Stack
{
public:
    Stack(size_t capacity = 4)
    {
        _a = (int *)malloc(sizeof(int) * capacity);
        if (_a == nullptr)
        {
            perror("malloc");
            exit(-1);
        }
        _top = 0;
        _capacity = capacity;
    }
    ~Stack()
    {
        free(_a);
        _a = nullptr;
        _top = _capacity = 0;
    }

private:
    int *_a;
    size_t _capacity;
    size_t _top;
};

// int main()
// {
//     Date d1;               //无参数初始化d1
//     Date d2(2022, 10, 16); //有参数初始化d2

//     Stack s1;
//     Stack s2(10);

//     return 0;
// }

class Date
{
public:
    Date(int year = 0, int month = 1, int date = 1)
    {
        _year = year;
        _month = month;
        _date = date;
    }
    ~Date()
    {
    } // Date类没有资源需要清理，所以Date不实现析构函数都是可以的。
    Date(Date &d)
    {
        _year = d._year;
        _month = d._month;
        _date = d._date;
    }
    bool operator>(const Date &d)
    {
        if (_year > d._year)
        {
            return true;
        }
        else if (_year == d._year && _month > d._month)
        {
            return true;
        }
        else if (_year == d._year && _month == d._month && _date > d._date)
        {
            return true;
        }
        return false;
    }
    //返回类型为void的赋值重载：由于返回值是void，所以只能赋值一次，不能像int一样可以连续赋值，如x=y=z
    // void operator=(const Date& d)
    // {
    //     _year = d._year;
    //     _month = d._month;
    //     _date = d._date;
    // }
    //连续赋值重载
    // Date& operator=(const Date& d)
    // {
    //         _year = d._year;
    //         _month = d._month;
    //         _date = d._date;
    //         //并不是返回this，因为this是个指针
    //         //返回*this
    //         //直接传值返回会进行一次拷贝构造
    //         //由于*this是全局的，出作用域不会销毁。
    //         //我们可以传引用返回。
    //         return *this;
    // }
    //自己给自己赋值的优化
    Date &operator=(const Date &d)
    {
        if(this!=&d)
        {
            _year = d._year;
            _month = d._month;
            _date = d._date;
        }

        return *this;
    }

private:
    int _year;
    int _month;
    int _date;
};
//函数名就是operator操作符
//返回类型要看操作符运算后返回的值是什么
//操作符有几个操作时就有几个参数

//int operator-(const Date &d1, const Date &d2);
// int main()
// {
//     Date d1(2022, 10, 16);
//     Date d2(2022, 12, 16);
//     cout << (d1 > d2) << endl;
//     cout << d1.operator>(d2) << endl;
//     return 0;
// }

int main()
{

    Date d1(2022, 10, 16);
    Date d3(2000, 12, 05);
    //一个已经存在的对象初始化一个马上创建实例化的对象
    Date d2(d1); //拷贝构造

    //两个已经存在的对象之间进行赋值拷贝
    d3 = d1;//赋值重载
    d3.operator=(d1);
    return 0;
}