#pragma once
#include <iostream>
using namespace std;
class Date
{
public:
    Date(int year = 0, int month = 1, int date = 1);
    void Print();
    int GetMonthDay(int year, int month);
    bool isFairDate(int year, int month, int date);
    bool operator>(const Date &d);
    Date(const Date &d); //拷贝构造是不用写的。因为类里面全是系统自带类型
    Date &operator+=(int day);
    Date operator+(int day);
    Date &operator++(); //区分前后置
    // d1++；后置为了跟前置++区分开，增加一下参数占位
    // 跟前置++构成函数重载。具体值是多少无所谓，但是必须得有
    // 必须是int
    Date operator++(int);
    bool operator<(const Date &d);
    bool operator==(const Date &d);
    bool operator>=(const Date &d);
    bool operator<=(const Date &d);
    bool operator!=(const Date &d);
    Date &operator-=(int day);
    Date operator-(int day);
    Date &operator--();
    Date &operator--(int); //区分前后置
    int operator-(const Date &d);

private:
    int _year;
    int _month;
    int _date;
};
