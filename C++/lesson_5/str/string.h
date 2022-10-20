#pragma once
#include <iostream>
#include <string>
#include <assert.h>

using namespace std;
//定义一个，防止与std的重定义
namespace Amor
{

    class string
    {
    private:
        /* data */
        char *_str;
        size_t _size;     //有效字符的个数
        size_t _capacity; //能存有效字符的空间数，不含'\0'
        static const size_t npos;

    public:
        //构造函数
        string();
        //拷贝构造
        string(const char *str);
        //复制拷贝构造
        string(const string &s);
        //赋值
        string &operator=(const string &s);
        ~string();
        typedef char *iterator;
        typedef const char *const_iterator;
        iterator begin();
        iterator end();
        iterator rbegin();
        iterator rend();
        const_iterator end() const
        {
            return _str + _size;
        }
        const_iterator begin() const
        {
            return _str;
        }
        //增
        void push_back(char ch);
        void append(const char *str);
        string &operator+=(const char *str);
        string &operator+=(char ch);
        void resize(size_t n, char ch);
        size_t find(char ch);
        size_t find(const char *str);
        size_t find(const char *str, size_t pos = 0);
        string &insert(size_t pos, char ch);
        string &insert(size_t pos, const char *str);

        //删
        string &erase(size_t pos = 0, size_t len = npos);
        //查
        size_t size() const;
        char &operator[](size_t pos);
        char *c_str();
        bool operator>(const char *);
        bool operator<(const char *);

        //改
        void swap(string &s)
        {
            std::swap(_str, s._str);
            std::swap(_size, s._size);
            std::swap(_capacity, s._capacity);
        }
        void reserve(size_t n);

    }; // class string

    const size_t string::npos = -1;

    string::string()
        : _str(new char[1]) //用[]
          ,
          _size(0), _capacity(0)
    {
        _str[0] = '\0';
    }
    string::string(const char *str) // const char* str = ""
        : _size(strlen(str)), _capacity(_size)
    {
        _str = (new char[_capacity + 1]);
        strcpy(_str, str);
    }
    // 传统写法
    // string::string(const string &s)
    //     : _size(s._size), _capacity(s._capacity)
    // {
    //     _str = (new char[_capacity + 1]);
    //     stpcpy(_str, s._str);
    // }
    //现代写法：偷鸡,直接调用构造函数然后交换
    string::string(const string &s)
        : _str(nullptr), _size(0), _capacity(0)
    {
        string tmp(s._str);
        swap(tmp);
    }
    string::~string()
    {
        delete[] _str;
        _str = nullptr;
        _capacity = _size = 0;
    }
    //传统写法
    // string &string::operator=(const string &s)
    // {
    //     //考虑左右值相等
    //     if (this == &s)
    //     {
    //         return *this;
    //     }
    //     // delete[] _str;
    //     // _str = (new char[strlen(s._str) + 1]);//new可能会失败！所以先拷贝再delete

    //     char *tmp = new char[s._capacity + 1];
    //     strcpy(tmp, s._str);
    //     delete[] _str;
    //     _str = tmp;
    //     _size = s._size;
    //     _capacity = s._capacity;
    //     return *this;
    // }

    // 现代1:
    // string &string::operator=(const string &s)
    // {
    //     if(this!=&s)
    //     {
    //         string tmp(s._str);
    //         swap(_str, tmp._str);
    //     }
    //     return *this;
    // }
    // 现代2：
    // string &string::operator=(string s)
    // {

    //     swap(_str, s._str);
    //     return *this;
    // }
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
    string::iterator string::rbegin()
    {
        return _str + _size - 1;
    }

    string::iterator string::rend()
    {
        return _str - 1;
    }
    void string::push_back(char ch)
    {
        // if (_size == _capacity)
        // {
        //     reserve(_capacity == 0 ? 4 : _capacity * 2);
        //     //增容
        // }
        // //添加
        // _str[_size] = ch;
        // ++_size;
        // //加'\0'
        // _str[_size] = '\0';
        insert(0, ch);
    }
    void string::reserve(size_t n) // reserve(100)是让容量到100，不包含'\0'
    {
        if (n > _capacity)
        {
            char *tmp = new char[n + 1];
            strcpy(tmp, _str);
            delete[] _str;

            _str = tmp;
            _capacity = n;
        }
    }
    void string::append(const char *str)
    {
        //不能粗暴的扩大二倍
        //因为不知道尾插的字符串多长
        // size_t len = strlen(str);
        // if ((_size + len) > _capacity) // = 是正好放进去
        // {
        //     reserve(_size + len);
        // }
        // strcpy(_str + _size, str);
        // _size += len;
        insert(_size, str);
    }

    string &string::operator+=(char ch)
    {
        push_back(ch);
        return *this;
    }
    string &string::operator+=(const char *str)
    {
        append(str);
        return *this;
    }
    void string::resize(size_t n, char ch)
    {
        if (n <= _size)
        {
            _size = n;
            _str[_size] = '\0';
        }
        else
        {
            if (n > _capacity)
            {
                reserve(n);
            }

            memset(_str + _size, ch, n - _size);
            _size = n;
            _str[_size] = '\0';
        }
    }
    size_t string::find(char ch)
    {
        for (size_t i = 0; i < _size; ++i)
        {
            if (ch == _str[i])
            {
                return i;
            }
        }
        return npos;
    }
    // size_t string::find(const char *str);
    size_t string::find(const char *str, size_t pos = 0)
    {
        const char *ptr = strstr(_str + pos, str);
        if (ptr == nullptr)
        {
            return npos;
        }
        else
        {
            return ptr - _str;
        }
    }

    string &string::insert(size_t pos, char ch)
    {
        assert(pos <= _size);
        if (_size == _capacity)
        {
            reserve(_capacity == 0 ? 4 : 2 * _capacity);
        }
        if (pos == _size)
            push_back(ch);
        else
        {
            // size_t end = _size;
            // while(end>=pos)//size_t非常容易越界，考虑pos=0，end=0，end--后变为-1为无穷大，所以要修改。
            //{
            //    _str[end + 1] = _str[end];
            //  --end;
            //}
            size_t end = _size + 1;
            //记得挪动'\0'
            while (end > pos)
            {
                _str[end] = _str[end - 1];
                --end;
            }
            _str[pos] = ch;
            ++_size;
        }
        return *this;
    }
    string &string::insert(size_t pos, const char *str)
    {
        assert(pos <= _size);
        size_t len = strlen(str);
        if (_size + len > _capacity)
        {
            reserve(_size + len);
        }
        size_t end = _size + len;
        while (end > pos)
        {
            //记得挪动'\0'
            _str[end] = _str[end - len];
            --end;
        }
        memcpy(_str + pos, str, len);
        _size += len;
        return *this;
    }
    string &string::erase(size_t pos = 0, size_t len = npos)
    {
        if (len == npos || len + pos >= _size)
        {
            _str[pos] = '\0';
            _size = pos;
        }
        else
        {
            strcpy(_str + pos, _str + pos + len);
            _size -= len;
        }
    }

    // void string::resize(size_t n, char ch = '\0')
    // {
    //     //n>_capacity
    //     //扩容 方法是开辟然后拷贝
    //     //n<_capacity && n>_size
    //     //像是减容，方法还是开辟然后拷贝
    //     //n<_size
    //     //和2类似
    //     if (n < _size)
    //     {
    //         char *tmp = new char[n + 1];
    //         //截断
    //         _str[n] = '\0';
    //         strcpy(tmp, _str);
    //         delete[] _str;

    //         _str = tmp;
    //         _capacity =_size =  n;
    //     }
    //     else if (n < _capacity && n > _size)
    //     {
    //         char *tmp = new char[n + 1];
    //         strcpy(tmp,_str);
    //         delete[] _str;
    //         _str = tmp;
    //         while (_size < _capacity)
    //         {
    //             _str += ch;
    //             _size++;
    //         }
    //     }
    //     else
    //     {
    //         reserve(n);
    //         while(_size<_capacity)
    //         {
    //             _str += ch;
    //             _size++;
    //         }
    //     }
    // }
    //成员函数
    // bool operator>(const string &s)
    // {
    //     if (strcmp(_str, s._str))
    //     {
    //         return true;
    //     }
    //     else
    //     {
    //         return false;
    //     }
    // }
    // //全局函数
    // bool operator>(const string &s1, const string &s2)
    // {
    //     size_t i1 = 0, i2 = 0;
    //     while (i1 < s.size() && i2.size())
    //     {
    //         if (s1[i1] > s2[i2])
    //         {
    //             return true;
    //         }
    //         else if (s1[i1] < s2[i2])
    //         {
    //             return false;
    //         }
    //         else
    //         {
    //             ++i1;
    //             ++i2;
    //         }
    //     }
    //     return i1 < s1.size() ? true : false;
    // }

    // //当然我们也可以使用我们定义的c_str()函数，就可以继续使用上面的_str去strcmp了。如下
    // bool operator>(const string &s1, const string &s2)
    // {
    //     return strcmp(s1.c_str(), s2.c_str()) > 0 ? true : false;
    //     //这种写法是对第一种写法的简写。改用三目操作符。
    // }
    // ostream << (ostream & out, const string &s) //有返回值
    // {
    //     //范围for
    //     for (auto ch : s)
    //     {
    //         out << ch;
    //     }
    //     return out;
    // }
    // //法2
    // ostream << (ostream & out, const string &s) //有返回值
    // {
    //     //数组遍历
    //     for (size_t i = 0; i < s.size(); i++)
    //     {
    //         cout << s[i];
    //     }
    //     return out;
    // }
    // //注意：不可以这么写：
    // ostream << (ostream & out, const string &s) //有返回值
    // {
    //     out << s.c_str();
    //     //因为这样实际上遇到了'\0'会自动终止。
    //     return out;
    // }
    // //--------------上面是错误的-------------------
    // istream << (istream & in, string &s) //不写const了，因为要修改。
    // {
    //     char ch = in.get();
    //     while (ch != ' ' && ch != '\n')
    //     {
    //         s += ch;
    //         ch = in.get();
    //     }
    //     return in;
    // }
} // namespace str
