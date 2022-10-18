# 模板

## 引子

假设我们需要使用C++写一个交换函数，很简单。

```c++
void Swap(int& x,int& y)
{
		int tmp = x;
		x = y;
		y = tmp;
}
```

下面我们要求再写double类型的交换函数，同样也很简单：我们在之前的学习中学习到了，C++支持函数重载。所以我们可以如下定义：

```c++
void Swap(double& x,double& y)
{
		double tmp = x;
		x = y;
		y = tmp;
}
```

这无非就是复制粘贴然后再进行简单的修改类型就可以实现，但是倘若我们需要实现float、char、long、longlong等等内置类型乃至自定义类型的交换呢？我们是不是需要挨个把他们都定义出来才可以呢？

我们可以发现，不同类型的Swap函数只有一个区别：参数类型不同。在这里，C++就定义了**模板**。

```c++
template<class T> // template<typename T> 模板参数列表 - 定义参数类型
void Swap(T& x,T& y) //函数参数列表 -定义参数对象
{
    T tmp = x;
    x = y;
    y = tmp;
}
```

当我们调用Swap函数时，会发生模板实例化，函数模板实例化出对应的函数。在编译器编译阶段，对于模板函数的使用，编译器需要根据传入的实参类型来推演生成对应类型的函数以供调用。比如：当用double类型使用函数模板时，编译器通过对实参类型的推演，将T确定为double类型，然后产生一份专门处理double类型的代码，对于字符类型也是如此。

## 函数模版

### 函数模板的格式

> 函数模板代表了一个函数家族，该函数模板与类型无关，在使用时被参数化，根据实参类型产生函数的特定类型版本。

> 函数模板格式：
>
> template<typename T1, typename T2,..,typename Tn>
>
> 返回值类型 函数名（参数列表）{}
>
> 注意：typename是用来定义模板参数关键字，也可以使用class(切记：不能使用struc代替class)

函数模板是一个蓝图，它本身并不是函数，是编译器用使用方式产生特定具体类型函数的模具。所以其实模板就是将本来应该我们做的重复的事情交给了编译器。在编译器编译阶段，对于模板函数的使用，编译器需要根据传入的实参类型来推演生成对应类型的函数以供调用。比如：当用double类型使用函数模板时，编译器通过对实参类型的推演，将T确定为double类型，然后产生一份专门处理double类型的代码，对于字符类型也是如此。

### 函数模板的实例化

用不同类型的参数使用函数模板时，称为函数模板的实例化。模板参数实例化分为：隐式实例化和显式实例化。

- 隐式实例化：并不规定实例化的类型，让编译器根据实参推演模板参数的实际类型

  ```c++
  template <class T> // template<typename T>
  void Swap(T &x, T &y)
  {
      T tmp = x;
      x = y;
      y = tmp;
  }
  int main()
  {
      int x = 10, y = 20;
      double a = 10.1, b = 20.2;
      cout << "x:" << x << "y:" << y << endl;
      Swap(x, y);
      cout << "x:" << x << "y:" << y << endl;
      cout << "a:" << a << "b:" << b << endl;
      Swap(a, b);
      cout << "a:" << a << "b:" << b << endl;
  
      return 0;
  }
  ```

- 显式实例化：在函数名后的<>中指定模板参数的实际类型

  ```c++
      int x = 10, y = 20;
      double a = 10.1, b = 20.2;
      Swap<int>(x, y);
      Swap<double>(a, b);
  		//如果我们想让x和a相加，要么强转，要么显示实例化
  		Swap((double)x,a);
  ```

  如果类型不匹配，编译器会尝试进行隐式类型转换，如果无法转换成功编译器将会报错。

- 一个非模板函数可以和一个同名的函数模板同时存在，而且该函数模板还可以被实例化为这个非模板函数
- 对于非模板函数和同名函数模板，如果其他条件都相同，在调动时会优先调用非模板函数而不会从该模板产生出一个实例。如果模板可以产生一个具有更好匹配的函数，那么将选择模板
- 模板函数不允许自动类型转换，但普通函数可以进行自动类型转换

## 类模板

我们在用C语言实现栈的时候，会定义一个类似于泛型类型的typedef。

```c++
typedef int StackDataType.
```

好像也可以实现类模板，因为我们可以通过修改上述重命名，把int都改为double，就把int变为了double。但是如果我们想定义两个栈，一个栈为int类型，一个为double类型，这时候C语言是无论如何也不能在一个程序中实现了。

c++ 给出了新的方式：类模板。

### 类模板的格式

```c++
template<class T1,class T2, ... , class Tn>
class TypeName
{
	//类内成员定义
};
```

```c++
template<class T>
class Stack
{
public:
    Stack(int capacity = 4)
        : _top(0), _capacity(capacity)
    {
        _a = new T[capacity];
    }
    ~Stack()
    {
        delete[] _a;
        _a = nullptr;
        _capacity = _top = 0;
    }

private:
    T *_a;
    int _top;
    int _capacity;
};
```

### 类模板的实例化

类模板实例化与函数模板实例化不同，**类模板实例化需要在类模板名字后跟<>**，**然后将实例化的类型放在<>即可**，类模板名字不是真正的类，而实例化的结果才是真正的类。

```c++
Stack<int> st1;
Stack<double> st2;
Stack<char> st3;
```





