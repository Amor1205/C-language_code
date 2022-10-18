#include <iostream>
using namespace std;

template <class T> // template<typename T>
void Swap(T &x, T &y)
{
    T tmp = x;
    x = y;
    y = tmp;
}
// int main()
// {
//     int x = 10, y = 20;
//     double a = 10.1, b = 20.2;
//     Swap<int>(x, y);
//     Swap<double>(a, b);

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