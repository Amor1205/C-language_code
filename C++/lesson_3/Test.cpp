#include <iostream>
using namespace std;

//对比一下C++和C定义类别的一些区别和联系
//以Stack为例

int globalVar = 1;
static int staticGlobalvar = 1;
void Test()
{
    static int staticvar = 1;
    int localvar = 1;

    int num1[10] = {1, 2, 3, 4, 5};
    char char2[] = "abcd";
    const char *pChar3 = "abcd";
    int *ptr1 = (int *)malloc(sizeof(int) * 4);
    int *ptr2 = (int *)calloc(4, sizeof(int));
    int *ptr3 = (int *)realloc(ptr2, sizeof(int) * 4);
    free(ptr1);
    free(ptr3);
}

// int main()
// {
//     int *p1 = (int *)malloc(sizeof(int));
//     int *p2 = (int *)malloc(sizeof(int) * 10);

//     int *p3 = new int;
//     int *p4 = new int[10];

//     free(p1);
//     free(p2);
//     delete p3;
//     delete[] p4;

//     return 0;
// }

class Stack
{
public:
    Stack(int capacity = 4)
        : _top(0), _capacity(capacity)
    {
        _a = new int[capacity];
    }
    ~Stack()
    {
        delete[] _a;
        _a = nullptr;
        _capacity = _top = 0;
    }

private:
    int *_a;
    int _top;
    int _capacity;
};

// int main()
// {
//     Stack st1; //函数里面的局部变量在栈上
//     //如果我们想在堆上构造一个栈
//     Stack *pst2 = new Stack;//开空间+构造函数初始化
//     //pst2指向动态开辟的空间，指向栈对象
//     //主动释放

//     delete pst2;//析构函数(清理对象中的资源) + 释放空间
//     return 0;
// }

class ListNode
{
public:
    ListNode(int data)
        : _next(nullptr), _prev(nullptr), _data(data)
    {
    }

    ListNode *_next;
    ListNode *_prev;
    int _data;
};
class List
{
public:
    List()
    {
        _head = new ListNode(-1);
        _head->_next = _head;
        _head->_prev = _head;
    }
    ~List()
    {
        ListNode* cur = _head->_next;
        while(cur!= _head)
        {
            ListNode *next = cur->_next;
            delete cur;
            cur = next;
        }
        delete _head;
        _head = nullptr;
    }
    void PushBack(int val)
    {
        ListNode *newnode = new ListNode(val);
        ListNode *tail = _head->_prev;
        tail->_next = newnode;
        newnode->_prev = tail;
        _head->_prev = newnode;
        newnode->_next = _head;
    }
    void Print()
    {
        ListNode *tail = _head->_prev;
        ListNode *head = _head->_next;
        while (tail != head->_prev)
        {
            cout << head->_data << endl;
            head = head->_next;
        }
    }

private:
    ListNode *_head;
};
int main()
{
    List l;
    l.PushBack(1);
    l.PushBack(2);
    l.PushBack(3);
    l.PushBack(4);
    l.PushBack(5);
    l.Print();
    return 0;
}