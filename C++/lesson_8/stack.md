[toc]

# stack&queue

## stack的使用

### 认识stack & queue

> stack实际上不属于容器，而是属于适配器。
>
> ```c++
> template <class T, class Container = deque<T> > class stack;
> ```
>
> 其核心接口是push 、 pop、 top。

> 顺便理解一下队列queue
>
> ```c++
> template <class T, class Container = deque<T> >class queue;
> //FIFO queue
> //container adapter.
> ```
>
> 核心借口push、pop、front、back

### 使用栈

```c++
void test_stack1()
{
    //栈后进先出
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
```

### 使用队列

```c++
void test_queue1()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
```

### 题目

#### 最小栈

> 设计一个支持 push ，pop ，top 操作，并能在**常数时间内**检索到最小元素的栈。O(1)
>
> 实现 MinStack 类:
>
> - MinStack() 初始化堆栈对象。
> - void push(int val) 将元素val推入堆栈。
> - void pop() 删除堆栈顶部的元素。
> - int top() 获取堆栈顶部的元素。
> - int getMin() 获取堆栈中的最小元素。

用C++的STL库整体实现。

> 如果我们定义一个变量，记录stack的最小值，如果我们pop掉一个数据，恰好就是最小值，那么我们的Min就失效了，必须得重新遍历找到最小值，不满足O(1)要求。
>
> 所以我们再定义一个栈，用这个栈存储最小值，每push一次，找到一个最小值，每pop一次也删除一个当前的最小值，删除完这个最小值后，栈顶的数据就是我们想要的更新后的最小值了。
>
> 思路：**空间换时间**
>
> 但是这样子可能会在存储最小值的栈里面存储大量相同的值，我们可以**优化**一下：
>
> > 最小值更新才入最小值栈，否则不入。
> >
> > 在普通栈里删除的值等于最小值栈的栈顶元素时，我们才删除掉最小值栈顶元素。
> >
> > 但是这样有一个bug：如果两个连续最小值入普通栈，我们如果不入，删除时会出错。所以<=最小值入栈。

```c++
class MinStack {
public:
    //构造函数不需要写，会调用stack的构造函数
    MinStack() 
    {}
    
    void push(int val) {
        s.push(val);
        if(Mins.empty() )
        {
            Mins.push(val);
        }
        else
        {
            int top = Mins.top();
            if(top>=val)
            {
                Mins.push(val);
            }
        }
    }
    
    void pop() {
        if(Mins.top()== s.top())
        {
            Mins.pop();
        }
        s.pop();
 
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return Mins.top();
    }
private:
    stack<int> s;
    stack<int> Mins;
};
```

#### 栈的压入、弹出序列

>输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。 
>
>1. 0<=pushV.length == popV.length <=1000
>2. -1000<=pushV[i]<=1000
>3. pushV 的所有数字均不相同

> 思路：
>
> 拿入栈顺序去模拟出栈顺序，如果可以模拟出来就是ok的，如果不能就不行。
>
> > 如果入栈位置和出栈位置的值不相等，那么这个值要先入，后面再出，
> >
> > 如果入栈位置和出栈位置的值相等，匹配上了，这时候这个值要出掉，但是出掉还要判断之前的顶和出栈位置的栈顶的值相等与否，因为可能是连续出栈的。所以这个值还是入栈，持续出数据，直到栈为空或者栈顶的元素跟出栈序列的值不匹配。才能停止。
> >
> > 结果就是看入栈结束的时候，栈为不为空或者出栈序列到没到尾。

```c++
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        size_t pushI = 0;
        size_t popI = 0;
        while(pushI< pushV.size())
        {
            //先入，因为不管相不相等都要入
            s.push(pushV[pushI]);
            ++pushI;
            while(!s.empty() && s.top()==popV[popI])
            {
                s.pop();
                popI++;
            }
        }
        return popI == popV.size();
    }
};
```

#### 逆波兰表达式求职

> 根据 **逆波兰表示法 (后缀表达式)**，求表达式的值。
>
> > 中缀表达式： 1 + 2 * 3
> >
> > 因为中缀表达式运算符放在操作数的中间，需要看运算符的优先级。中缀表达式计算机是无法运算的，因为它是从左到右开始读，读到1+2无法判断是否可以运算。所以实际上是计算机把中缀转换成后缀，然后再运算。
> >
> > 后缀表达式：1 2 3 * +
> >
> > 特征就是操作符放到操作数的后面，运算符按照优先级排列好，不一定在最后。
> >
> > ***中缀转后缀：***
> >
> > > 中缀转后缀要借助栈，比较复杂。
> > >
> > > 1. 遇到操作数，直接输出
> > > 2. 遇到操作符：
> > >    - 如果栈为空，入栈
> > >    - 如果栈不为空，跟栈顶的操作符比较优先级。
> > >      - 如果当前运算符比栈顶运算符优先级高，可能还会有优先级更高的，所以运算符入栈。
> > >      - 如果当前运算符比栈顶运算符优先级低或者相等，栈顶运算符先出栈，继续跟栈顶的数据比较，直到栈为空或者比栈顶优先级高。
> > > 3. 遇到最后一个操作数，输出操作数后出栈。结束转换。
> >
> > ***后缀的运算：***
> >
> > >还是要借助栈：
> > >
> > >1. 操作数入栈。
> > >2. 操作符，连续取两个栈顶元素，先取的操作数是右值，运算结果继续入栈。
> > >3. 结束后，栈里的值就是运算结果。
> >
> > 如果遇到括号，括号的特征是优先级变高，设立一个flag 标记一下，标记过的不按常规的规则比较优先级，按照最高的优先级比较。
> >
> > 控制优先级可以用map, 不会map可以用ASCII码表，左右括号，加减乘除运算符都是符号，
> >
> > ```c++
> > int priorytySymbol [48] = {-1};
> > priorytySymbol[40] = 0;//(
> > priorytySymbol[41] = 0;//)
> > priorytySymbol[43] = priorytySymbol[45] = 1;//+ -
> > priorytySymbol[42] = priorytySymbol[47] = 2;//* /
> > 
> > //取优先级就用priorytySymbol['('] 就可以;
> > 
> > //用函数判断也可以
> > ```
>
> 有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
>
> 注意 两个整数之间的除法只保留整数部分。
>
> 可以保证给定的逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

本题目相当简单，需要注意的就是如果用int类型可能会越界，这时需要强转为long。

```c++
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(const auto& e: tokens)
        {
            //不能用switch case，switch只能用整数
            //string类型的e 需要和""双引号的字符串比较
            if(e == "+" || e == "-" ||e == "*" || e == "/" )
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                //运算,运算的结果入栈，如果走到default出问题。
                switch(e[0]){
                    case '+':
                    st.push(left+right);
                    break;
                    case '-':
                    st.push(left-right);
                    break;
                    case '*':
                    st.push((long)left*(long)right);
                    break;
                    case '/':
                    st.push(left/right);
                    break;
                    default:
                    assert(false);
                }
            }
            else
            {
                st.push(stoi(e));
            }
        }
        return st.top();
    }
};
```

## stack的实现

> 适配器是一种设计模式，设计模式是一套被反复使用的、多数人知晓的、经过分类编目的、代码设计经验的总结，这种模式是将一个类的接口转换成客户希望的另外一个的接口。

如果我们要实现栈，不必须要使用vector、也不是必须要使用list，我们只需要保证栈的特性，也就是后进先出就好。

所以我们定义一个类模板

```c++
    template <class T, class Container>
```

这样就可以使用vector、list、deque等了。

```c++
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
```

用这个来进行测试

```c++
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
```

## queue的实现

queue的实现与stack完全类似。但是queue不支持vector作为容器。

```c++
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
        //取队头
        const T &front()
        {
            return _con.front();
        }
        //取队尾
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
```

用这个来进行测试

```
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
```

## 了解deque

deque：双端队列，它想融合vector和list的优点

>vector：
>
>- vector优点：下标随机访问、尾插尾删效率高(cpu高速缓存命中高)
>- vector缺点：扩容、不适合头插头删
>
>list：
>
>- list优点：按需申请释放空间、任意位置O(1)插入删除
>- list缺点：不支持下标的随机访问

deque : 随机迭代器。支持push_back、 push_front、 pop_back、 pop_front ，还支持 下标[] 、 at、 front、 back 访问

但是deque支持的随机迭代器是伪随机，是需要经过计算的，所以频繁的使用下标访问并不推荐用deque，因为效率很多，因此deque不支持排序，效率极低。但是deque也有优点，比如适合头尾的插入和删除。**deque的头尾插入和删除是比list好的**，所以在stl里选择用deque作为stack和queue的默认容器。如果没有deque，只能是栈用vector或list默认适配，队列只能用list。

| name  | vector                   |        list        | deque                                                        |
| ----- | ------------------------ | :----------------: | ------------------------------------------------------------ |
| Stack | 随机访问数据，用尾插尾删 | 可以头尾删除和插入 | 相比vector：扩容代价不大、不需要拷贝数据、浪费空间不多。     |
| Queue |                          |                    | 相比list：cpu高速cache命中，其次不会频繁申请小块空间。申请和释放小空间的次数低代价低。 |

所以，deque作为stack和queue的默认容器是完胜的。胜任可以头尾插删和偶尔下标访问的场景。但是要高频随机访问需要vector，要任意位置插入删除还是list。