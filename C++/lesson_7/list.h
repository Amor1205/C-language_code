#pragma once

#include <iostream>
#include <list>
using namespace std;
#include "reverse_iterator.h"
namespace Amor
{
    template <class T>
    struct ListNode
    {
        ListNode<T> *_next;
        ListNode<T> *_prev;
        T _data;

        ListNode(const T &data = T())
            : _next(nullptr), _prev(nullptr), _data(data)
        {
        }
    };
    template <class T, class Ref, class Ptr>
    struct __list_iterator
    {
        //如果不typedef一下Ref 和 Ptr，我们是无法拿到的
        //因为我们没办法拿到模板参数，只能typedef
        typedef Ref reference;
        typedef Ptr pointer;
        typedef ListNode<T> Node;
        typedef __list_iterator<T, Ref, Ptr> self;
        // typedef __list_iterator



        Node *_node;

        __list_iterator(Node *x)
            : _node(x)
        {
        }
        //区分前置和后置++
        self &operator++()
        {
            _node = _node->_next;
            return *this;
        }
        self &operator++(int)
        {
            self tmp(*this);
            _node = _node->_next;
            return tmp;
        }
        self& operator--()
        {
            _node = _node->_prev;
            return *this;
        }
        self& operator--(int)
        {
            self tmp(*this);
            _node = _node->_prev;
            return *this;
        }
        Ptr operator->()
        {
            return &_node->_data;
        }
        Ref operator*() //不加& 因为后面定义的时候加了&
        {
            return _node->_data;
        }
        bool operator==(const self &it) const
        {
            return _node == it._node;
        }
        bool operator!=(const self &it) const
        {
            return !(_node == it._node);
        }
    };
    template <class T>
    class list
    {
        typedef ListNode<T> Node;

    public:
        typedef __list_iterator<T, T &, T *> iterator;
        typedef __list_iterator<T, const T &, const T *> const_iterator;

        // typedef Amor::reverse_iterator<iterator, T &, T *> reverse_iterator;
        // typedef Amor::reverse_iterator<const_iterator, const T &, const T *> const_reverse_iterator;
        typedef Amor::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef Amor::reverse_iterator<iterator> reverse_iterator;
        reverse_iterator rbegin()
        {
            return reverse_iterator(end());
        }
        reverse_iterator rend()
        {
            return reverse_iterator(begin());
        }
        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(end());
        }
        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(begin());
        }
        list()
        {
            _head = new Node;
            _head->_next = _head;
            _head->_prev = _head;
        }
        ~list()
        {
            clear();
            delete _head;
            _head = nullptr;
        }

        //传统方式
        // list lt2(lt)
        // list(const list<int> &lt)
        // {
        //     _head = new Node;
        //     _head->_next = _head;
        //     _head->_prev = _head;

        //     for (auto e : lt)
        //     {
        //         push_back(e);
        //     }
        // }
        // // list lt2 = lt
        // list<int> &operator=(const list<int> &lt)
        // {
        //     if (this != &lt)
        //     {
        //         clear();
        //         for (auto e : lt)
        //         {
        //             push_back(e);
        //         }
        //     }
        //     return *this;
        // }

        //现代写法
        template <class InputIterator>
        list(InputIterator first, InputIterator last)
        {
            //创建头节点
            _head = new Node;
            _head->_next = _head;
            _head->_prev = _head;

            while (first != last)
            {
                push_back(*first);
                ++first;
            }
        }
        list(const list<T> &lt)
        {
            _head = new Node;
            _head->_next = _head;
            _head->_prev = _head;

            list<T> tmp(lt.begin(), lt.end());
            std::swap(_head, tmp._head);
        }
        list(size_t n, const T &val = T())
        {
            _head = new Node;
            _head->_next = _head;
            _head->_prev = _head;

            for (size_t i = 0; i < n; i++)
            {
                push_back(val);
            }
        }
        list<T> &operator=(list<T> lt)
        {
            swap(_head, lt._head);
            return *this;
        }
        iterator begin()
        {
            return iterator(_head->_next);
        }
        iterator end()
        {
            return iterator(_head);
        }
        const_iterator begin() const
        {
            return const_iterator(_head->_next);
        }
        const_iterator end() const
        {
            return const_iterator(_head);
        }

        void clear()
        {
            iterator it = begin();
            while (it != end())
            {
                // iterator next = it + 1;//不支持+1！我们实现的是双向迭代器，只有随机迭代器才支持+1
                erase(it++);
            }
        }
        void push_back(const T &x)
        {
            Node *tail = _head->_prev;
            Node *newnode = new Node(x);
            tail->_next = newnode;
            newnode->_prev = tail;
            newnode->_next = _head;
            _head->_prev = newnode;
        }
        void insert(iterator pos, const T &x)
        {
            Node *cur = pos._node; //迭代器是一个对象，不是一个指针，指针的话才能用->，对象访问成员应该用.
            Node *prev = cur->_prev;
            Node *newnode = new Node(x);
            prev->_next = newnode;
            newnode->_prev = prev;
            newnode->_next = cur;
            cur->_prev = newnode;
        }
        void erase(iterator pos)
        {
            assert(pos != end()); //不能erase哨兵位。
            Node *next = pos._node->_next;
            Node *prev = pos._node->_prev;
            delete pos._node;
            prev->_next = next;
            next->_prev = prev;
        }
        list(int n, const T &val = T())
        {
            _head = new Node;
            _head->_next = _head;
            _head->_prev = _head;

            for (size_t i = 0; i < n; i++)
            {
                push_back(val);
            }
        }
        // void push_back(const T &x)
        // {
        //     insert(end(), x); // end()是哨兵头节点_head，begin()是_head->_next;
        // }
        // void push_front(const T &x)
        // {
        //     insert(begin(), x);
        // // }
        // void pop_back()
        // {
        //     erase(--end());
        //     // end要--，因为end()是哨兵头节点，--end()才是尾删
        // }
        // void pop_front()
        // {
        //     erase(begin());
        // }

    private:
        Node *_head;
    };
    void print_list(const list<int> &lt)
    {
        list<int>::const_iterator it = lt.begin();
        while (it != lt.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
    }
    void test_list1()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);
        lt.push_back(5);
        lt.push_back(6);
        lt.push_back(7);

        //只有const list<int> 类型才能用 const_iterator
        list<int>::iterator it = lt.begin();
        while (it != lt.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
        print_list(lt);
    }
    struct Date
    {
        int _year;
        int _month;
        int _day;

        Date(int year = 1, int month = 1, int day = 1)
            : _year(year), _month(month), _day(day)
        {
        }
    };
    void test_list2()
    {
        list<Date> lt;
        lt.push_back(Date(2022, 3, 12));
        lt.push_back(Date(2022, 3, 13));
        lt.push_back(Date(2022, 3, 14));

        list<Date>::iterator it = lt.begin();
        while (it != lt.end())
        {
            // cout << (*it)._year << "/" << (*it)._month << "/" << (*it)._day << endl;
            cout << it->_year << "/" << it->_month << "/" << it->_day << endl;

            ++it;
        }
        cout << endl;
    }
    void test_list3()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(1);
        lt.push_back(3);
        lt.push_back(1);
        lt.push_back(5);

        list<int> lt2(lt);
        for (auto e : lt2)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    void test_list4()
    {
        list<Date> lt1(5, Date(2000, 1, 1));
        for (auto e : lt1)
        {
            cout << e._year << "/" << e._month << "/" << e._day << endl;
        }
    }
    void test_list5()
    {
        list<int> lt1(5, 1);
        for (auto e : lt1)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    void test_list6()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);
        lt.push_back(5);

        list<int>::reverse_iterator rit = lt.rbegin();
        while (rit != lt.rend())
        {
            cout << *rit << " ";
            ++rit;
        }
        cout << endl;
    }
} // namespace Amor