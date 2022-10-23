# list

双向带头循环链表 <doubly-linked list>

list表示的是一个**双向带头循环链表**，允许在常数范围内的任意位置进行插入和删除，且前后可以进行双向迭代。其缺陷和链表一样就是不能支持随机访问（下标访问），但是在任意位置进行插入的效率更高。

```c++
template <class T,class Alloc = allocator<T>> calss list;
```

> vector的缺陷：
>
> 连续的物理空间，是优势，也是劣势。
>
> > 优势：支持高效随机访问。
>
> > 劣势：
> >
> > - 空间不够要增容，增容代价比较大。
> > - 可能存在一定的空间浪费，按需申请，会导致频繁的增容，所以一般会按照2倍左右扩容
> > - 头部或者中部插入删除需要挪动数据，效率低下。

> list很好的解决了vector的以上问题：
>
> 1. 按需申请释放空间。
> 2. list任意位置支持O(1)插入删除。
>
> 所以本质上vector和list是互补的两个数据结构。

## list的使用

list使用与vector非常类似。浅浅的使用一下。

```c++
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
```

## list的模拟实现

### list大框架构建

#### ListNode结构体的定义

要模拟实现list，我们先设定好ListNode结构体，然后在ListNode的基础上实现。

和带头双向循环链表一样，我们需要设定_next, _prev , _data作为成员变量。

```c++
namespace Amor
{
    template <class T>
    struct ListNode
    {
        ListNode<T> *_next;
        ListNode<T> *_prev;
        T _data;
    };
```

#### list的基础框架

> 我们要实现list，首先简化一下ListNode的书写，typedef其为Node。

>  list的成员变量很简单，只有一个 Node* _head，这个成员变量看起来简单，但是因为其是Node*类型，我们可以通过 ->去访问其前一个节点的位置和后一个节点的位置，也可以用 _head-> _data去访问和修改自己节点数据的值。

> **构造函数：**一般构造函数是需要初始化列表来进行初始化的，但是list不用，因为我们list的构造函数做的工作是构造哨兵位头节点，步骤就是new一个节点，然后将节点的next和prev都指向自己即可。
>
> **但是问题来了：**我们需要构造出头节点，需要new Node，这需要我们提供Node (也就是ListNode)的构造函数。这是相当简单的。
>
> ```c++
>  ListNode(const T &data = T())
>             : _next(nullptr), _prev(nullptr), _data(data)
>         {}
> ```

```c++
    template<class T>
    class list
    {
        typedef ListNode<T> Node;
    public:
      //构造函数
    list()
    {
        _head = new Node;
        _head->_next = _head;
        _head->_prev = _head;
    }
    private:
        Node *_head;
    };
```

#### push_back( )的编写

写好了构造函数，搭好了框架，现在我们只需要写一个尾插函数来验证自己的框架构建的成功与否。

> 尾插相当的简单，这是因为我们要实现的list是一个带哨兵位的双向循环链表，_head-> _prev就是我们的尾。
>
> 我们定义tail作为原链表的尾巴，然后修改tail和_head的指向即可。

```c++
    void push_back(const T& x)
    {
        Node *tail = _head->_prev;
        Node *newnode = new Node(x);
        tail->_next = newnode;
        newnode->_prev = tail;
        newnode->_next = _head;
        _head->_prev = newnode;
    }
```

#### 框架检验

写代码，写一点测试一点，现在的基础框架已经写好（有了构造函数我们就可以创建对象，有了尾插我们就可以进行对对象的修改），通过调试就可以看到内部的变化。如果可以成功运行，那么就算框架搭建成功了。

```c++
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
    }
```

经过调试，程序没有出现问题。我们可以继续编写list了。

#### 迭代器的实现

我们要实现迭代器，从而进行遍历、打印链表、修改数据等功能。

list迭代器的实现与之前的string和vector不同，之前的两个容器他们的物理空间连续，++it 就可以实现从一个元素跳转到另外一个元素，但是list不行。因为其本身是通过解引用ListNode访问里面的一个指针得到下一个节点的，物理空间不连续，++it 不会得到下一个节点。

但是C++的优点就在于我们可以通过对指针的封装 和 通过运算符++重载，来实现从一个节点跳跃到下一个节点。

想象一个迭代器的基本使用场景，无非是如下：
```c++
list<int> lt;
list<int>::iterator it = lt.begin();
while(it!=lt.end())
{
	cout<<*it<<" ";
	++it;
}
cout<<endl;
```

我们从这里就可以看到迭代器需要使用的运算符或者成员函数：

!=    *     ++     begin().   end().  等等等等。

而string和vector的迭代器的定义方式非常简单，只需要typedef

```c++
typedef T* iterator;
typedef const T* const_iterator; 
```

list的迭代器确实也需要重定义，但是并不只是如此，因为我们如果仅仅按照下面的重定义：

```c++
typedef Node* iterator;
typedef const Node* iterator;
```

那就大错特错了，因为Node*类型的++做不到让其指向下一个节点，Node *类型的 解引用也无法做到直接访问data数据，所以我们应该重新定义一个类，把Node *封装在类里面，在里面进行操作符的重载。

```
template<class T>
struct __list_iterator
{
	//首先简写ListNode
	typedef ListNode<T> Node;
	
	//成员变量
	Node* _node;
	
};
```

> 简单考虑一下我们需要写什么成员函数呢？
>
> - operator ++
> - operator*
> - operator!=

我们暂且实现这几个函数。

```c++
//前置++
__list_iterator<T>& operator++()
{
		_node = _node->_next;
		return *this
}
//后置++, 后置的++需要先拷贝构造然后再让node指向下一个，否则会获取不到之前的位置
//内置int类型，默认是后置++
__list_iterator<T>& operator++(int)
{
	__list_iterator tmp(*this);
	_node = _node->_next;
	return tmp;
}
```

> 有的小伙伴看到了需要拷贝构造就要自己写一个拷贝构造，思考一下在这里需要自己拷贝构造吗？
>
> 不必！编译器会默认生成拷贝构造函数，这个拷贝构造实现的是浅拷贝，而*this里储存的是Node * ，即Node的地址，这个正是我们希望拷贝的。因为迭代器是借助节点的指针来访问修改链表，所以使用默认生成即可。
>
> **只有需要实现深拷贝的时候我们才需要自己实现拷贝构造。**
>
> 同样的，赋值重载和析构函数也都不需要自己实现。

继续编写：

```c++
//因为!=不修改二者的值，所以加const。
bool operator!=(const __list_iterator& it) const
{
  return _node != it._node;
}
bool operator==(const __list_iterator& it) const
{
	return _node == it._node;
}

__list_iterator<T>& operator*()
{
	return _node->_data;
}
```

写好__list_iterator类里的重载函数，我们基本上可以开始编写class list里的迭代器了。迭代器一般分为两个版本，一个是只读的const版本，一个是可读可写的普通版本。两个版本通过函数的重载而实现迭代器。

```c++
//重定义
typedef __list_iterator<T> iterator;
typedef __list_iterator<T> const_iterator; //命名冲突？编译器识别不出来到底是iterator还是应该命名为const_iterator.
//如果这么重定义：
typedef const __list_iterator<T> const_iterator;
//也是错的：如果迭代器类型是const版本，那么++it将无法实现。
//我们暂且不写const版本，这后面会详细解释。

//成员函数 begin&end
iterator begin()
{
//begin应该是遍历list时的第一个节点，即头节点的后一个。
	return iterator(_head->_next);
}
iterator end()
{
//end是遍历完后的下一个，即头节点。
	return iterator(_head);
}
```

> 写到这里，我们发现：我们用到了iterator(_head->next)，但是我们并没有自己编写iterator的构造函数，即__list_iterator的构造函数，这需要我们自己编写吗？
>
> 答案是：需要。因为我们看__list_iterator的成员变量为Node*类型的 _node，涉及到自定义类型Node，只有我们提供构造函数，才会在调用时继续调用Node的构造函数：
>
> ```c++
> __list_iterator(Node* x)
> 		:_node(x){}
> ```

> 解决完了这个问题，我们还有一个横亘在我们面前的巨大问题，就是如何设计const版本的iterator。
>
> - 一个最简单粗暴的方法是最容易想到的：拷贝一份__list_iterator类及其成员函数，改写为一份 const_list_iterator的类，这种是最简单粗暴的，但是也会造成代码冗余而且不符合C++的泛型编程思想--因为本来只是类型的区别，却多写了几十行完全相似的代码。虽然不推荐，但是在这里笔者也实现出来以提供参考。
>
>   ```c++
>   template<class T>
>   struct __const_list_iterator
>   {
>   	typedef ListNode<T> Node;
>   	Node* _node;
>   
>   	__const_list_iterator(Node* x)
>   		:_node(x)
>   	{}
>   
>   	// it2 = it1 浅拷贝,不要拷贝构造
>   	const T& operator*()
>   	{
>   		return _node->_data;
>   	}
>   
>   	// ++it
>   	__const_list_iterator<T>& operator++()
>   	{
>   		_node = _node->_next;
>   		return *this;
>   	}
>   
>   	// it++
>   	__const_list_iterator<T> operator++(int)
>   	{
>   		__const_list_iterator<T> tmp(*this);
>   		_node = _node->_next;
>   		return tmp;
>   	}
>   
>   	// --it
>   	__const_list_iterator<T>& operator--()
>   	{
>   		_node = _node->_prev;
>   		return *this;
>   	}
>   
>   	// it--
>   	__const_list_iterator<T> operator--(int)
>   	{
>   		__list_iterator<T> tmp(*this);
>   		_node = _node->_prev;
>   		return tmp;
>   	}
>   
>   	bool operator!=(const __const_list_iterator<T>& it) const
>   	{
>   		return _node != it._node;
>   	}
>   
>   	bool operator==(const __const_list_iterator<T>& it) const
>   	{
>   		return _node != it._node;
>   	}
>   };
>   ```
>
>   从代码角度去看也是完全冗余的。所以及其不推荐这种方式。
>
> - **推荐写法：**
>
>   实现C++的泛型编程的一大助力就是类模板，我们可以继续从类模板入手去看这份代码：
>
>   ```c++
>   //关于operator*	
>   	const T& operator*()
>   	{
>   		return _node->_data;
>   	}
>   //---------------------------------------
>   	T& operator*()
>   	{
>   		return _node->_data;
>   	}
>   //关于operator++
>   	__const_list_iterator<T>& operator++()
>   	{
>   		_node = _node->_next;
>   		return *this;
>   	}
>   //---------------------------------------
>   	__list_iterator<T>& operator++()
>     {
>       _node = _node->_next;
>     }
>   //---------------------------------------
>   ```
>
>   可以发现，他们的不同全在于他们的返回值类型，如果我们修改类模板，修改为：
>
>   ```c++
>       template <class T, class Ref>
>   ```
>
>   那么岂不是我们也可以区分清二者，而不会搞出来命名冲突的问题了吗。请看：
>
>   ```c++
>   //刚刚的重定义
>   typedef __list_iterator<T> iterator;
>   typedef __list_iterator<T> const_iterator; //命名冲突
>   
>   //但是现在：
>   typedef __list_iterator<T, T&> iterator;
>   typedef __list_iterator<T, const T&> const_iterator; 
>   //根据传入的值的类型来区分iterator和const_iterator
>   ```
>
>   我们发现冲突的问题解决了，与此同时，我们的返回值的问题也解决了。因为我们只要上面的返回值填Ref即可，就不需要所有的函数写两遍了。
>
>   ```c++
>   	Ref& operator*()
>   	{
>   		return _node->_data;
>   	}
>   ```
>
>   综上，我们通过添加类模板的类的个数，来达到区分const_iterator和iterator 以及 在一个类里面实现不同迭代器的重载。整体的代码如下：

```c++
//在class list里定义迭代器、typedef迭代器iterator、const_iterator名称，因为迭代器是用来访问list对象的。   
//在struct __list_iterator里定义关于迭代器的运算符重载、迭代器的构造函数。
template <class T, class Ref>
struct __list_iterator
{
	typedef ListNode<T> Node;
	//重命名self以简写，否则类型名太长
	typedef __list_iterator<T, Ref> self;
	Node *_node;
	
	__list_iterator(Node *x)
     : _node(x){}
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
	
	Ref operator*()//不加& 因为后面定义的时候加了&
  {return _node->_data;}
  
  bool operator==(const self &it) const
  {return _node == it._node;}
  
  bool operator!=(const self &it) const
  {return !(_node == it._node);}
};
```

在list类里面，同样进行begin和end的重载。如果是const对象，调用const begin( )，const begin 返回的是const_iterator, 然后会使用const T&传给Ref，返回const指针，只读。这样就完成了对普通迭代器和const迭代器的实现。

```c++
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
```

#### 链表遍历 (打印)

好的，这样困扰我们不能打印的烦恼就基本消除了，我们写一下print函数，让它可以帮助我们打印链表。

```c++
void print_list(const list<int>& lt)//打印是只读类型
{
  list<int>::const_iterator it = lt.begin();
  while (it != lt.end())
  {
     cout<< *it << " ";
     ++it;
  }
  cout << endl;
}
```

#### 重载->操作符

下面我们还要继续重载->操作符。

这是因为->在一些情景下非常常见，比如我们实现日期类。

```c++
//简单日期类的创建，因为举例子会用到    
struct Date
    {
        int _year;
        int _month;
        int _day;

        Date(int year = 1, int month = 1, int day = 1)//要给默认的构造函数，就是全缺省的，因为list<Date> lt会开辟一个带哨兵位的头节点。
            : _year(year), _month(month), _day(day)
        {}
    };
```

先简单的写一下，**不保证对**：

```c++
T* operator->()
{
	return &_node->_data; 
  // ->操作符是一个自定义指针类型指向类的一个成员变量，所以我们在这里需要返回自定义指针类型
}
```

```c++
    void test_list2()
    {
        list<Date> lt;//在这里会用到Date的构造函数，开辟哨兵节点用。
        lt.push_back(Date(2022, 3, 12));
        lt.push_back(Date(2022, 3, 13));
        lt.push_back(Date(2022, 3, 14));

        list<Date>::iterator it = lt.begin();
        while (it != lt.end())
        {
//cout<< *it << endl;不能用！
//不支持流插入，如果想这样输出可以选择重载流插入运算符。
//可以解引用然后用.访问成员变量。*it是Date的引用，Date._year访问没有问题。如下line14
// cout << (*it)._year << "/" << (*it)._month << "/" << (*it)._day << endl;
          
//按理说是应该是it->->_year的。因为it是Date*类型的数据
//我们要重载->，it->实际上是 it.operator->(), operator->返回值是一个T*，在这里也就是Date*，Date*去访问应该再加->。
//所以本来应该是it->->_year，但是这样写的话，运算符可读性太差了。所以这里编译器进行了优化，省略了一个->。
//所有类型只要想重载->都是这样，都会优化省略一个->
            cout << it->_year << "/" << it->_month << "/" << it->_day << endl;
            ++it;
        }
        cout << endl;
    }
```

但是这样又面临一个问题，如果是const迭代器，那么加指针也能修改数据了，所以我们应该多加一个模板参数T*，如果是普通迭代器，返回T星，const迭代器返回const T星。

```c++
    template <class T, class Ref,class Ptr>
      
      //里面的->重载返回类型改为Ptr
        Ptr operator->()
        {
            return &_node->_data;
        }
```

```c++
//修改self
typedef __list_iterator<T, Ref, Ptr> self;
```

```c++
//修改typedef
typedef __list_iterator<T, T &, T *> iterator;
typedef __list_iterator<T, const T &, const T *> const_iterator;
```

至此，我们的类模板参数终于添加完毕，如果我们回过头去参照STLlist部分的源码，会发现其实源码也是用了三个模板参数，分别对应着 T 、T&、 T*，这是我们需要学习的部分。学会了添加模板参数，就可以大幅度简化代码，通过一份代码和其中的函数及运算符重载，实现不同的输入导向不同的结果，完美契合C++泛型编程思想。

### list的完善

#### insert()

插入非常简单，因为双向链表很容易访问前一个节点，需要注意的：

- pos._node 而不用->，迭代器实际上是__list_iterator， _node是他的一个成员，对象访问成员，用.操作符。
- stl库里实现的有返回值，类型iterator，返回新插入的节点的位置

```c++
        iterator insert(iterator pos, const T& x)
        {
            Node *cur = pos._node;//迭代器是一个对象，不是一个指针，指针的话才能用->，对象访问成员应该用.
            Node *prev = cur->_prev;
            Node *newnode = new Node(x);
            prev->_next = newnode;
            newnode->_prev = prev;
            newnode->_next = cur;
            cur->_prev = newnode;
        		//实现的是在pos的前一个位置插入。
          return iterator(newnode); 
        }
```

> 看一个问题：insert后，pos是否会失效？
>
> 答：不会。因为虽然new了新节点出来，pos迭代器仍然指向原来指向的节点。所以没有失效。空间和意义上都不存在失效问题。

可以任意位置插入后，尾插、头插可以复用：

```c++
 void push_back(const T& x)
 {
 		insert(end(),x); //end()是哨兵头节点_head，begin()是_head->_next;
 }
void push_front(const T& x)
{
  	insert(begin(),x);
}
```

#### erase()

返回删除之后的下一个位置的迭代器。

```c++
        iterator erase(iterator pos)
        {
            assert(pos != end());//不能erase哨兵位。
            Node *next = pos._node->_next;
            Node *prev = pos._node->_prev;
            delete pos._node;
            prev->_next = next;
            next->_prev = prev;
          return iterator(next);
        }
```

> 问：erase后pos失效吗？
>
> 答：必失效。因为erase后pos指向的空间都被销毁了。直接空间上失效了。
>
> vector的erase后也会失效。失效的原因是意义上的失效。

复用，尾删和头删

```
void pop_back()
{
	erase(--end());
	//end要--，因为end()是哨兵头节点，--end()才是尾删
}
void pop_front()
{
	erase(begin());
}
```

#### 浅拷贝的解决办法

我们如果写一个函数来测试list是否可以拷贝构造如下

```c++
    void test_list3()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(1);
        lt.push_back(3);
        lt.push_back(1);
        lt.push_back(5);

        list<int> lt2(lt);
        for(auto e:lt2)
        {
            cout << e << " ";
        }
        cout << endl;   
    }
```

可以发现程序是正常运行的，但是其实我们实现的是浅拷贝，之所以不会报错，是因为浅拷贝的问题根源在于析构两次，因为lt2浅拷贝lt，二者的地址相同，但由于是两个list，出作用域会销毁，第二次调用析构函数时因为已经销毁了，所以会报错。

我们首先实现一个clear函数。

```c++
void clear()
{
  iterator it = begin();
  while(it!=end())
  {
    //首先我们不能直接delete it._node
		// iterator next = it + 1;//不支持+1！我们实现的是双向迭代器，只有随机迭代器才支持+1
		iterator dele = it++;
    delete dele;
  }
  //必须要链接起来
  _head->_next = _head;
  _head->_prev = _head;
}

//或者换成下面的写法。
void clear()
{
  iterator it = begin();
  while(it!=end())
  {
    erase(it++);
    //erase已经链接了。
  }
}
```

可以发现我们是使用了++的特性，dele迭代器先复制了it，it又进行了++，然后删除掉dele，这样我们就可以做到删除除头节点外的所有节点。

接下来写析构函数。析构函数就是在clear的基础上把头节点删除掉。

```c++
        ~list()
        {
            clear();
            delete _head;
            _head = nullptr;
        }
```

如果我们现在再运行拷贝构造的那串代码，就会发现程序崩溃了，因为析构了两次，delete了不存在的头节点。

做深拷贝有如下几种方式：

```c++
//传统方式
//list lt2(lt)
list(const list<T>& lt)
{
    _head = new Node;
    _head->_next = _head;
    _head->_prev = _head;
    
    for(auto e:lt)
    {
        push_back(e);
    }
}
//list lt2 = lt
list<T>& operator=(const list<T>& lt)
{
    if(this != &lt)
    {
        clear();
        for (auto e : lt)
        {
            push_back(e);
        }
    }
    return *this;
}
```

```c++
//现代写法
//先写一个拷贝构造函数模板
template<class InputIterator>
list(InputIterator first,InputIterator last)
{
    //创建头节点
    _head = new Node;
    _head->_next = _head;
    _head->_prev = _head;

    while(first!=last)
    {
        push_back(*first);
        ++first;
    }
}
//复用即可。
list(const list<T>& lt)
{
  //会报错！因为_head是默认生成的构造函数生成的list对象，没有头节点。我们应该先给其创建_head头节点
    //list<T> tmp(lt.begin(), lt.end());
    //std::swap(_head, tmp);
	_head = new Node;
	_head->_next = _head;
	_head->_prev = _head;
	list<T> tmp(lt.begin(), lt.end());
	swap(_head, tmp._head);
}
list<T>& operator=(list<T> lt)
{
  //交换两个节点的指针
    std::swap(_head, lt._head);
    return *this;
}
```

#### 不同构造函数的冲突问题

如果我们写一个构造函数用来创建n个相同val值的list。

```c++
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
```

他会和迭代器区间初始化发生冲突。举一个例子

>使用test_list4( )时，编译器不会报错
>
>```c++
>    void test_list4()
>    {
>        list<Date> lt1(5, Date(2000, 1, 1));
>        for (auto e : lt1)
>        {
>            cout << e._year << "/" << e._month << "/" << e._day << endl;
>        }
>    }
>```
>
>使用test_list5( )时，编译器报错：说寻址错误indirection requires pointer operand ('int' invalid)
>
>```c++
>    void test_list5()
>    {
>        list<int> lt1(5, 1);
>        for (auto e : lt1)
>        {
>            cout<<e <<" ";
>        }
>        cout << endl;
>    }
>```
>
>这是因为我们看两个拷贝构造函数重载，编译器会默认选择更匹配的函数。
>
>```c++
>list(size_t n, const T &val = T());
>list(InputIterator first,InputIterator last);
>```
>
>明显line2的 InputIterator 是int更加匹配。int不能解引用所以会报错。

我们在这里应该在原来函数的基础上再添加一个函数，来专门解决输入int类型报错的问题。

```c++
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
```

因为编译器看到现成的int，就不会用模板函数套用int了。这样就解决了问题，但是最好不要把原来函数的size_t换成int，因为stl库里使用的就是无符号整型，只需添加这个int类型的函数重载即可。

#### 反向迭代器的实现

反向迭代器实际上是对正向迭代器的一种封装，反向迭代器的++实现的实际上是正向迭代器的--，其实非常简单，我们只需要另外写一个reverse_iterator类即可。

##### 法1

和__list_iteator类一样，我们类模板同样用iterator、Ref、Ptr，其中Ref作为 解引用操作符*重载函数 的返回值，Ptr作为->操作符重载函数的返回值。

```c++
namespace Amor
{
    template <class iterator, class Ref, class Ptr>
    class reverse_iterator
    {
        typedef reverse_iterator<iterator, Ref, Ptr> self;

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
        Ref operator*() //解引用不知道返回的类型是什么，所以需要多传模板参数Ref过来
        {
            iterator it = _it;
            return *(--it);
            //operator*取前一个位置，主要就是为了让反向迭代器的开始和结束跟正 向迭代器对称。
            // self it = _it;
            // return *(++it);
            //不能用反向迭代器，因为反向迭代器会自己调自己，会导致栈溢出.
        }
        Ptr operator->()
        {
            return &operator*();
        }
    private:
        iterator _it;
    };
}
```

同样的，需要在list类里面重命名,并且添加rbegin，rend函数及其const版本重载函数。

```c++
typedef Amor::reverse_iterator<iterator, T &, T *> reverse_iterator;
typedef Amor::reverse_iterator<const_iterator, const T &, const T *> const_reverse_iterator;

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
```

这样我们就实现了反向迭代器。反向迭代器的精髓实际上是我们iterator 是那个容器的迭代器，reverse_iterator<iterator>就可以适配出哪个容器的反向迭代器，这样就可以通过复用来完成多类型的适配。

##### 法2

法1用的是传三个模板参数，我们也可以传一个模板参数做到上述的功能。

```c++
template <class iterator>//不传模板参数
class reverse_iterator
{
typedef reverse_iterator<iterator, Ref, Ptr> self;

//typedef iterator::reference Ref;
//typedef iterator::pointer Ptr;
//如果我们要取模板参数iterator的内嵌类型(在里面定义的类型如typedef的类型，我们需要用typename，因为我们的模板参数还没有实例化，它可以告诉编译器这是一个内嵌类型，编译的时候会去iterator里找这个类型)

typedef typename iterator::reference Ref;
typedef typename iterator::pointe Ptr;

//当然可以不typedef，但是如果不typedef的话，就需要在返回值那写typename iterator::reference，如下, 会更麻烦
typename iterator::reference operator*() 
```

> 捋一遍：
>
> 根据list里的typedef:
>
> ```c++
> //list里的typedef:
> 
> //只传iterator 和 const_iterator
> typedef Amor::reverse_iterator<iterator> reverse_iterator;
> typedef Amor::reverse_iterator<const_iterator> const_reverse_iterator;
> ```
>
> 传给反向迭代器的是const_iterator 或者是 iterator。在反向迭代器类里面定义了一个成员变量，_it，就是根据传过来的迭代器类型：
>
> ```c++
> //reverse_iterator:
>     private:
>         iterator _it;
> ```
>
> 但是这个反向迭代器不知道传过来的到底是普通迭代器还是const迭代器，所以我们在list里typedef itetator和const_iterator如下
>
> ```c++
> typedef __list_iterator<T, T &, T *> iterator;
> typedef __list_iterator<T, const T &, const T *> const_iterator;
> ```
>
> 因为在反向迭代器定语的时候只用一个类模板，我们只能获取一个参数，来判断其到底是普通还是const反向迭代器。我们如何取到__list_iterator的内嵌类型Ref和Ptr呢？
>
> ```c++
>     template <class T, class Ref, class Ptr>
>     struct __list_iterator
>     {
>         //如果不typedef一下Ref 和 Ptr，我们是无法拿到的
>         //因为我们没办法拿到模板参数，只能typedef
>         typedef Ref reference;
>         typedef Ptr pointer;
> ```
>
> 这样子，我们就可以用typename iterator::reference 来取到了。而且：因为iterator在typedef的时候传入的是Ref = T&, Ptr = T*.所以我们取出来普通反向迭代器就是typename iterator::reference  = T&类型。

但是这样子是有副作用的，只有自定义类型才会有内嵌类型，如果是内置类型则不会有，如果迭代器是原生指针，如vector、string，我们就无法取出iterator的内嵌类型，就会导致报错。所以法2的适配性不强，我们用法1即可。法1虽然传模板参数传的多，但是还是相对来说更好用。 

## 总结

至此，我们的list篇就结束啦！

