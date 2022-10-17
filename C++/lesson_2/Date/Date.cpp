#include "Date.h"
int Date::GetMonthDay(int year, int month) const
{
    //改成静态的,否则每次都创建
    static int monthDayArray[13] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = monthDayArray[month];
    if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            //闰年
            day += 1;
        }
    }
    return day;
}
bool Date::isFairDate(int year, int month, int date) const
{
    if (!(year >= 0 && month > 0 && month < 13 && date > 0 && date < 32))
    {
        return false;
    }
    if (date > GetMonthDay(year, month))
    {
        return false;
    }
    return true;
}
Date::Date(int year, int month, int date)
{
    _year = year;
    _month = month;
    _date = date;
    if (!isFairDate(year, month, date))
    {
        cout << "unfairDate:";
        Print();
    }
}
//拷贝构造是不用写的。因为类里面全是系统自带类型
Date::Date(const Date &d)
{
    _year = d._year;
    _month = d._month;
    _date = d._date;
}
bool Date::operator>(const Date &d) const
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
void Date::Print() const
{
    cout << _year << "-" << _month << "-" << _date << endl;
}
Date Date::operator+(int day) const
{
    Date d(*this);
    d += day;
    return d;
}
Date &Date::operator+=(int day)
{
    //实际上实现的是+=  ！！！
    //因为会改变自身的值
    if (day < 0)
    {
        return *this -= -day;
    }
    _date += day;
    while (!isFairDate(_year, _month, _date))
    {
        _date -= GetMonthDay(_year, _month);
        if (_month == 12)
        {
            _month = 1;
            _year++;
        }
        else
        {
            _month++;
        }
    }
    return *this;
}
Date &Date::operator++()
{
    *this += 1;
    return *this;
    //自定义类型++要用前置
}
Date Date::operator++(int)
{
    //后置要拷贝构造两次
    Date d(*this);
    *this += 1;
    return d;
}

bool Date::operator==(const Date &d) const
{
    return (_year == d._year && _month == d._month && _date == d._date);
}
bool Date::operator<(const Date &d) const
{
    return !((*this > d) || (*this == d));
}
bool Date::operator>=(const Date &d) const
{
    return ((*this > d) || (*this == d));
}
bool Date::operator<=(const Date &d) const
{
    return (!(*this > d));
}
bool Date::operator!=(const Date &d) const
{
    return (!(*this == d));
}
Date &Date::operator-=(int day)
{
    if (day < 0)
    {
        return *this += (-day);
    }
    _date -= day;
    while (!isFairDate(_year, _month, _date))
    {
        _date += GetMonthDay(_year, _month - 1);
        if (_month == 1)
        {
            _month = 12;
            _year--;
        }
        else
        {
            _month--;
        }
    }
    return *this;
}
Date Date::operator-(int day) const
{
    Date d(*this);
    d -= day;
    return d;
}

Date &Date::operator--()
{
    *this -= 1;
    return *this;
}
Date &Date::operator--(int)
{
    Date d(*this);
    d -= 1;
    return d;
}
int Date::operator-(const Date &d) const
{
    Date smallerDate(*this);
    Date biggerDate(d);
    if (biggerDate < smallerDate)
    {
        biggerDate = *this;
        smallerDate = d;
    }
    int ret = 0;
    while (smallerDate < biggerDate)
    {
        smallerDate++;
        ret++;
    }
    return ret;
}
void Date::PrintWeekDay() const
{
    const char *weekday[] = {"Mon", "Tue", "Wed", "Thur", "Fri", "Sate", "Sun"};
    Date start(1900, 1, 1);
    int count = *this - start;
    cout << weekday[count % 7] << endl;
}
//----------------------------------------------------
void TestDate1()
{
    // Date d1;
    Date d2(2022, 7, 8);
    // Date d3(2000, 12, 32);
    // d1.Print();
    d2 += 100;
    d2.Print();
}
void TestDate2()
{
    Date d1(2022, 10, 16);
    Date d2 = (d1 + 100); //算今天后100天后是哪一天
    d1.Print();
}
void TestDate3()
{
    Date d1(2022, 1, 17);
    d1 += -1500;
    d1.Print();
}
void TestDate4()
{
    Date d1(2022, 10, 17);
    Date d2(2021, 9, 1);
    cout << (d1 - d2) << endl;
    d1.PrintWeekDay();
}
void TestDate5()
{
    //我们说了成员函数调用的时候会默认产生this指针，这个this指针的类型默认是Date* const this类型。其中const是用来保护this不被改变。

    Date d1;    //取地址后是Date*，可以传过去
    d1.Print(); //传过去的this指针是Date* const this类型,权限不变

    // const Date d2;//取地址后类型为 const Date*
    // d2.Print();   //传过去的this指针依然为Date* const this，会导致权限放大。
    //我们应该在定义函数后面加const，如下
    // void Date::Print() const

    //这样，或权限缩小，或权限不变，都可以运行通过。

    //成员函数加const是好的，建议能加const都加上。这样普通对象和const对象都可以调用了。
    //但是如果要修改成员变量的函数不能加const。
}
int main()
{
    // TestDate1();
    // TestDate2();
    // TestDate3();
    // TestDate4();
    TestDate4();

    return 0;
}