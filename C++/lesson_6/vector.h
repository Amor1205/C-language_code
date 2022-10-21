#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

// stl库里面是定义的迭代器。
//  template <class T, class Alloc = alloc>
//  class vector{
//      public:
//      typedef T* iterator;
//      iterator start;
//      iterator finish;
//      iterator end_of_storage;
//  };
//我们之前用的是size_t _size, size_t _capacity
//实际上一样，用finish - start = _size , end_of_storage - start = _capacity.

namespace Amor
{
    template <class T>
    class vector
    {
    public:
        typedef T *iterator;
        typedef const T *const_iterator;
        vector()
            : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
        {
        }
        //传统写法
        // vector(const vector<T> &v)
        // {
        //     _start = new T[v.capacity()];
        //     _finish = _start + v.size();
        //     _end_of_storage = _start + v.capacity();

        //     memcpy(_start, v._start, v.size() * sizeof(T));
        // }
        //一个类模板的成员函数又可以是一个模板参数
        //函数模板的模板参数要穿迭代器区间时，命名的规范：
        //迭代器分类，有五种，
        // input_iterator(只写)、output_iterator(只读)、--没有实际对应的类型
        // forward_iterator(单向)、--forward list 只能++
        // Bidrectional_iterator(双向)、--list、map、set 可以++不能--
        // randomAccess_iterator(随机)--deque、vector、string随机指的是可以返回任意位置的，底层空间连续的容器，可以++ -- + -
        template <class InputIterator>
        vector(InputIterator first, InputIterator last)
            : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
        {
            while (first != last)
            {
                push_back(*first);
                ++first;
            }
        }

        //如果用swap(v1,v2)，涉及三个深拷贝，非常浪费。
        void swap(vector<T> &v) //仅仅交换成员变量指针，代价比较低
        {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_end_of_storage, v._end_of_storage);
        }
        //现代写法
        vector(vector<T> &v)
            : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
        {
            //用迭代器初始化
            swap(v);
        }
        //直接传值，就可以不创建tmp了
        vector<T> &operator=(vector<T> v)
        {
            swap(v);
            return *this;
        }

        ~vector()
        {
            if (_start)
                _start = _finish = _end_of_storage = nullptr;
        }
        size_t size() const
        {
            return _finish - _start;
        }
        size_t capacity() const
        {
            return _end_of_storage - _start;
        }
        void push_back(const T &x)
        {
            if (_finish == _end_of_storage)
            {
                //扩容
                reserve(capacity() == 0 ? 4 : 2 * capacity());
            }
            *_finish = x;
            ++_finish;
        }
        T &operator[](size_t i)
        {
            assert(i < size());
            return _start[i];
        }
        const T &operator[](size_t i) const
        {
            assert(i < size());
            return _start[i];
        }
        iterator begin()
        {
            return _start;
        }
        iterator end()
        {
            return _finish;
        }
        const_iterator begin() const
        {
            return _start;
        }
        const_iterator end() const
        {
            return _finish;
        }
        void reserve(size_t n)
        {
            if (n > capacity())
            {
                T *tmp = new T[n];
                if (_start)
                {
                    memcpy(tmp, _start, sizeof(T) * size());
                    delete[] _start;
                }
                _finish = tmp + size();
                _start = tmp;
                _end_of_storage = _start + n;
            }
        }
        void resize(size_t n, const T &t = T()) //由于匿名对象周期只在当前这一行，出行销毁，所以我们必须得加const。
        //如果自己写了构造函数和析构函数，加const引用就不会出这一行析构，而是出作用域析构。
        //如果只写了析构函数而没写构造函数，加const也会直接出行析构
        //这是vs的bug，应该加const就不该析构了。
        {
            if (n < size())
            {
                _finish = _start + n;
            }
            else
            {
                if (n > capacity())
                {
                    reserve(n);
                }
                while (_finish != _start + n)
                {
                    *_finish = t;
                    ++_finish;
                }
            }
        }
        iterator insert(iterator pos, const T &x) //不能在pos之前加引用，会导致只能传左值。
        {
            assert(pos >= _start && pos <= _finish); //可以等于_finish,这是尾插
            if (_finish == _end_of_storage)
            {
                //扩容就导致pos失效了，扩容后需要更新pos
                size_t len = pos - _start;
                reserve(capacity() == 0 ? 4 : 2 * capacity());
                pos = _start + len;
            }
            else
            {
                iterator end = _finish - 1;
                while (end >= pos)
                {
                    *(end + 1) = *end;
                    --end;
                }
                *pos = x;
                ++_finish;
            }
            return pos;
        }
        iterator erase(iterator pos) // erase也有迭代器失效的问题
        {
            assert(pos >= _start);
            assert(pos < _finish);
            iterator begin = pos + 1;
            while (begin < _finish)
            {
                *(begin - 1) = *begin;
                ++begin;
            }
            --_finish;
            return pos;
        }
        void pop_back()
        {
            assert(_finish);
            --_finish;
        }

    private:
        iterator _start;
        iterator _finish;
        iterator _end_of_storage;
    };

    void test_vector_1()
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(2);
        v.push_back(2);
        v.push_back(2);
        v.push_back(50);

        //下标遍历
        for (size_t i = 0; i < v.size(); ++i)
        {
            cout << v[i] << " ";
        }
        cout << endl;

        //迭代器遍历
        vector<int>::iterator it = v.begin();
        while (it != v.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
        //范围for
        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    class A
    {
    public:
        ~A()
        {
            cout << "~A()" << endl;
        }
    };
    void test_vector_2()
    {
        A();
        const A &x = A();
        int i = 0;
    }
    void test_vector_3()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        vector<int>::iterator it = find(v1.begin(), v1.end(), 2);
        if (it != v1.end())
        {
            //如果insert中发生扩容，会导致it指向的空间被释放
            // it本质就是一个野指针，这种问题，就叫做迭代器失效。
            v1.insert(it, 20);
        }
        for (auto e : v1)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    void test_vector_4()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        // v1.push_back(3);
        v1.push_back(4);
        v1.push_back(5);

        // erase也有迭代器失效的问题
        vector<int>::iterator it = v1.begin();
        // 1 2 3 4 5 正常
        // 1 2 3 4 崩溃
        // 1 2 4 5 结果错误
        while (it != v1.end())
        {
            if (*it % 2 == 0)
            {
                //如果是偶数，erase后就会导致一个数被跳过，这样it就失效了。
                // erase 以后，it指向位置的意义已经改变，直接++it可能会导致一些意料之外的结果，连续的偶数，导致后一个偶数没有判断，没删掉。
                //再其次，erase删除有些vector版本的实现，可能会缩容，这样，erase以后it也可能是野指针，跟insert类似
                //同样如果最后一个是偶数，会导致erase之后 it意义改变，再++一下，导致it和end的结束判断错过而失效。
                it = v1.erase(it);
            }
            else
            {
                ++it;
            }
        }
        for (auto e : v1)
        {
            cout << e << " ";
        }
        cout << endl;
    }
} // namespace Amor