//在创建时发生了一点问题，因为我们用的是stack.h的文件名，估计是和stl库里的重复，导致报错，无法包头文件iostream，需要注意。

#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;
namespace Amor
{
    template <class T, class Container = deque<T> >
    class stack
    {
    public:
        //尾插
        void push(const T &x)
        {
            _con.push_back(x);
        }
        //尾删
        void pop()
        {
            _con.pop_back();
        }
        //取顶
        const T &top()
        {
            return _con.back();
        }
        size_t size() const
        {
            return _con.size();
        }
        bool empty() const
        {
            return _con.empty();
        }

    private:
        Container _con;
    };

    template <class T, class Container = deque<T> >
    class queue
    {
    public:
        //尾插
        void push(const T &x)
        {
            _con.push_back(x);
        }
        //尾删
        void pop()
        {
            _con.pop_front();
        }
        //取顶
        const T &front()
        {
            return _con.front();
        }
        const T &back()
        {
            return _con.back();
        }
        size_t size() const
        {
            return _con.size();
        }
        bool empty() const
        {
            return _con.empty();
        }

    private:
        Container _con;
    };
    void test_stack1()
    {
        stack<int, list<int> > s;
        s.push(1);
        s.push(5);
        s.push(4);
        s.push(3);
        s.push(2);

        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }

    void test_queue1()
    {
        queue<int, list<int> > q;
        q.push(1);
        q.push(5);
        q.push(4);
        q.push(3);
        q.push(2);

        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
};