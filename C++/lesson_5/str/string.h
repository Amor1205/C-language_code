#pragma once
#include <iostream>
#include <string>
#include<assert.h>

using namespace std;
//定义一个，防止与std的重定义
namespace Amor
{

    class string
    {
    private:
        /* data */
        char *_str;
        size_t _size;
        size_t _capacity;

    public:
        //构造函数
        string();
        //拷贝构造
        string(const char *str );
        //复制拷贝构造
        string(const string &s);
        //赋值
        string &operator=(const string &s);
        ~string();
        typedef char *iterator;
        iterator begin();
        iterator end();

        //增
        //删

        //查
        size_t size() const;
        char &operator[](size_t pos);
        char *c_str();
        //改
    }; // class string

    string::string()
        : _str(new char[1]) //用[]
          ,
          _size(0), _capacity(0)
    {
        _str[0] = '\0';
    }
    string::string(const char *str)//const char* str = ""
        : _size(strlen(str)), _capacity(_size)
    {
        _str = (new char[_capacity + 1]);
        strcpy(_str, str);
    }

    string::string(const string &s)
        : _size(s._size), _capacity(s._capacity)
    {
        _str = (new char[_capacity + 1]);
        stpcpy(_str, s._str);
    }

    string::~string()
    {
        delete[] _str;
        _str = nullptr;
        _capacity = _size = 0;
    }
    string &string::operator=(const string &s)
    {
        //考虑左右值相等
        if (this == &s)
        {
            return *this;
        }
        // delete[] _str;
        // _str = (new char[strlen(s._str) + 1]);//new可能会失败！所以先拷贝再delete

        char *tmp = new char[s._capacity + 1];
        strcpy(tmp, s._str);
        delete[] _str;
        _str = tmp;
        _size = s._size;
        _capacity = s._capacity;
        return *this;
    }

    size_t string::size() const
    {
        return _size;
    }
    char &string::operator[](size_t pos)
    {
        assert(pos < _size);
        return _str[pos];
    }
    char *string::c_str()
    {
        return _str;
    }
    string::iterator string::begin()
    {
        return _str;
    }
    string::iterator string::end()
    {
        return _str + _size;
    }

} // namespace str
