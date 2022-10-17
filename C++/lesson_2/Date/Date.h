#pragma once
#include <iostream>
using namespace std;
class Date
{
    friend ostream &operator<<(ostream &out, const Date d);
    friend istream &operator>>(istream &in, Date &d);

public:
    Date(int year = 0, int month = 1, int date = 1);
    void Print() const;
    int GetMonthDay(int year, int month) const;
    bool isFairDate(int year, int month, int date) const;
    bool operator>(const Date &d) const;
    Date(const Date &d); //拷贝构造是不用写的。因为类里面全是系统自带类型
    Date &operator+=(int day);
    Date operator+(int day) const;
    Date &operator++(); //区分前后置
    // d1++；后置为了跟前置++区分开，增加一下参数占位
    // 跟前置++构成函数重载。具体值是多少无所谓，但是必须得有
    // 必须是int
    Date operator++(int);
    bool operator<(const Date &d) const;
    bool operator==(const Date &d) const;
    bool operator>=(const Date &d) const;
    bool operator<=(const Date &d) const;
    bool operator!=(const Date &d) const;
    Date &operator-=(int day);
    Date operator-(int day) const;
    Date &operator--();
    Date &operator--(int); //区分前后置
    int operator-(const Date &d) const;
    void PrintWeekDay() const;
    Date *operator&();
    const Date *operator&() const;

private:
    int _year;
    int _month;
    int _date;
};
