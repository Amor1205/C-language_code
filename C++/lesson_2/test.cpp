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

class Date
{
public:
    void Init(int year, int month, int date)
    {
        // Date::year = year
        _year = year;
        _month = month;
        _date = date;
    }
    void Print()
    {
        cout << _year << "-" << _month << "-" << _date << endl;
    }

private:
    // int year;//如果不加_，需要用Date::和函数中形参区分。
    int _year; //加_就是为了区分函数中的形参和实参
    int _month;
    int _date;
};

int main()
{
    Date d1;
    Date d2;
    d1.Init(2022, 10, 15);
    d1.Print();
    d2.Init(2022, 12, 15);
    d2.Print();
    return 0;
}
// d1.Print(&d1), d2.Print(&d2);