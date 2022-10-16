#include "Date.h"
int Date::GetMonthDay(int year, int month)
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
bool Date::isFairDate(int year, int month, int date)
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
bool Date::operator>(const Date &d)
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
void Date::Print()
{
    cout << _year << "-" << _month << "-" << _date << endl;
}
Date Date::operator+(int day)
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

bool Date::operator==(const Date &d)
{
    return (_year == d._year && _month == d._month && _date == d._date);
}
bool Date::operator<(const Date &d)
{
    return !((*this > d) || (*this == d));
}
bool Date::operator>=(const Date &d)
{
    return ((*this > d) || (*this == d));
}
bool Date::operator<=(const Date &d)
{
    return (!(*this > d));
}
bool Date::operator!=(const Date &d)
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
Date Date::operator-(int day)
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
int Date::operator-(const Date &d)
{
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
    Date d1(2022, 1, 17);
    Date d2(2021, 9, 1);
    cout << (d1 - d2) << endl;
}
int main()
{
    // TestDate1();
    // TestDate2();
    TestDate3();

    return 0;
}