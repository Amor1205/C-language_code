#include <iostream>
#include <list>
using namespace std;
#include"list.h"
void test_list1()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(4);
    lt.push_back(3);
    lt.push_back(5);

    //遍历
    list<int>::iterator it = lt.begin();
    while (it != lt.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    list<int>::reverse_iterator rit = lt.rbegin();
    while (rit != lt.rend())
    {
        cout << *rit << " ";
        ++rit;
    }
    cout << endl;

    for (auto e : lt)
    {
        cout << e << " ";
    }
    cout << endl;
}

void test_list2()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(4);
    lt.push_back(3);
    lt.push_back(5);

    // lt.sort();//排序,但一般不用
    lt.reverse();//逆序
    lt.unique();//去重，去重之前要先排序，否则效率太低。
    lt.remove(4);//给值，自己找自己删
    // lt.splice();//接合，一个链表转移链接到另外一个链表
}

int main()
{
    Amor::test_list6();
    return 0;
}

// template<class T>
// struct __const_list_iterator
// {
// 	typedef ListNode<T> Node;
// 	//typedef __list_iterator
// 	Node* _node;

// 	__const_list_iterator(Node* x)
// 		:_node(x)
// 	{}

// 	// it2 = it1 浅拷贝
// 	// 拷贝构造和赋值重载是否需要我们自己实现
// 	// 析构呢？-> 迭代器是借助节点的指针访问修改链表
// 	// 节点属于链表，不属于迭代器，所以他不管释放
// 	// 都不需要自己实现，默认生成的即可
// 	const T& operator*()
// 	{
// 		return _node->_data;
// 	}

// 	// ++it
// 	__const_list_iterator<T>& operator++()
// 	{
// 		_node = _node->_next;
// 		return *this;
// 	}

// 	// it++
// 	__const_list_iterator<T> operator++(int)
// 	{
// 		__const_list_iterator<T> tmp(*this);
// 		_node = _node->_next;
// 		return tmp;
// 	}

// 	// --it
// 	__const_list_iterator<T>& operator--()
// 	{
// 		_node = _node->_prev;
// 		return *this;
// 	}

// 	// it--
// 	__const_list_iterator<T> operator--(int)
// 	{
// 		__list_iterator<T> tmp(*this);
// 		_node = _node->_prev;
// 		return tmp;
// 	}

// 	bool operator!=(const __const_list_iterator<T>& it) const
// 	{
// 		return _node != it._node;
// 	}

// 	bool operator==(const __const_list_iterator<T>& it) const
// 	{
// 		return _node != it._node;
// 	}
// };