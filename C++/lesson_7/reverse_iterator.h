#pragma once

namespace Amor
{
    // template <class iterator, class Ref, class Ptr>
    template <class iterator>
    class reverse_iterator
    {
        typedef typename iterator::reference Ref;
        typedef typename iterator::pointer Ptr;

        typedef reverse_iterator<iterator> self;

    public:
        reverse_iterator(iterator it)
            : _it(it) {}
        self &operator++()
        {
            --_it;
            return *this;
        }
        self &operator++(int)
        {
            self tmp(*this);
            --_it;
            return tmp;
        }
        self &operator--()
        {
            ++_it;
            return *this;
        }
        self &operator--(int)
        {
            self tmp(*this);
            ++_it;
            return tmp;
        }
        bool operator==(const self &rit)
        {
            return _it == rit._it;
        }
        bool operator!=(const self &rit)
        {
            return _it != rit._it;
        }
        Ref operator*() //解引用不知道返回的类型是什么，所以需要多传模板参数过来
        {
            iterator it = _it;
            return *(--it);
            // self it = _it;
            // return *(++it);
            //不能用反向迭代器，因为反向迭代器会自己调自己，会导致栈溢出
        }
        Ptr operator->()
        {
            return &operator*();
        }

    private:
        iterator _it;
    };
}

// iterator 是那个容器的迭代器，reverse_iterator<iterator>就可以适配出哪个容器的反向迭代器，这样就可以通过复用来完成多类型的适配。