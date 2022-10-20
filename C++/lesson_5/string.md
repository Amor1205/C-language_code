# string类

## 为什么学习string类

> c语言中，字符串是以 '\0' 结尾的一些字符的集合，为了操作方便，C标准库中提供了一些str系列的库函数，但是这些库函数与字符串是分离开的，不太符合OOP的思想，而且底层空间需要用户自己管理，稍不留神可能还会越界访问。

string类对象的常见构造：

| constructor                   | 功能说明                   |
| ----------------------------- | -------------------------- |
| ***string()***                | 构造空字符串               |
| ***string(const char*s)***    | 用C-string来构造           |
| ***string(const string& s)*** | 构造拷贝函数               |
| string(size_t n, char c)      | string类对象中包含n个字符c |

string类对象的容量操作

| name          | 功能                                                         |
| ------------- | ------------------------------------------------------------ |
| ***size***    | ***返回字符串有效字符长度***                                 |
| ***empty***   | ***检查是否为空，是返回true，否则返回false***                |
| ***clear***   | ***清空有效字符***                                           |
| ***reserve*** | ***为字符串预留空间***，为字符串申请预留x个的空间(capacity > x)，可能会大于，因为要对齐 |
| ***resize***  | ***将有效字符个数改成n个，并用字符c填充***,size变为n，capacity>n, 如果不给字符，会用'\0'填充。如果本来就有字符，用resize(100), 只改变capacity, size不变；如果本来有字符, 用resize(100, 'x'), capacity改变，size也会变成100，除了给定的字符，其余字符变为‘x’；如果给的resize值比字符串长度小，会删除 |

```c++
void Test1()
{
    string s;
    size_t sz = s.capacity();
    cout << "capacity :" << sz << endl;
    cout << "making s grow:\n";
    for (int i = 0; i < 100;i++)
    {
        s += 'c';
        if(sz!=s.capacity())
        {
            sz = s.capacity();
            cout << "capacity changed: " << sz << '\n';
        }
    }
}
```



类对象的访问

| name            | function                                                     |
| --------------- | ------------------------------------------------------------ |
| **operator[]**  | **返回pos位置的字符，const string类对象调用**                |
| **begin+end**   | **begin获取一个字符的迭代器+ end获取最后一个字符下一个位置的迭代器** |
| **rbegin+rend** | **begin获取一个字符的迭代器+ end获取最后一个字符下一个位置的迭代器** |
| 范围for         | C++11支持更简洁的范围for的新遍历方式                         |

类对象的修改操作

| name            | function                                                     |
| --------------- | ------------------------------------------------------------ |
| **operator+=**  | **追加字符串str**                                            |
| **find + npos** | **从字符串pos位置开始往后找字符c，返回该字符所在位置.**      |
| rfind           | 倒着查找，其他一样                                           |
| **c_str**       | **返回char*格式的字符串，可以用于打印C格式字符串**           |
| **substr**      | **返回拷贝的字符串，string substr (size_t pos = 0, size_t len = npos) const;** |
| insert          | 因为插入和删除代价非常大，所以不到万不得已不用。string& insert (size_t pos, const string& str); |
| erase           | string& erase (size_t pos = 0, size_t len = npos);少用头部和中间的删除，因为挪动数据，效率低。 |

```c++
//查找
void Test3()
{
    string file("test.txt");
    // FILE *fout = fopen(file.c_str(),"w");

    //取出后缀
    size_t pos = file.find('.');
    if(pos!=string::npos)//npos是size_t的-1 就是最大的数，如果不等就说明取到了
    {
        string suffix = file.substr(pos);//输出.txt
        cout << suffix << endl;
    }
}
```



迭代器iterator

| name       | function                                                     |
| ---------- | ------------------------------------------------------------ |
| **begin**  | **Return iterator to beginning (public member function)**    |
| **end**    | **Return iterator to end (public member function)/非0字符的下一个** |
| **rbegin** | **Return reverse iterator to reverse beginning**             |
| **rend**   | **Return reverse iterator to reverse end**                   |
| cbegin     | Return const_iterator to beginning                           |
| cend       | Return const_iterator to end                                 |
| crbegin    | Return const_reverse_iterator to reverse beginning           |
| crend      | Return const_reverse_iterator to reverse end                 |

string类非成员函数

| name                     | function           |
| ------------------------ | ------------------ |
| **operator>>**           | **输入运算符重载** |
| **operator<<**           | **输出运算符重载** |
| **getline**              | **获取一行字符串** |
| **relational operators** | **大小比较**       |

不同类型转换

| name          | function                        |
| ------------- | ------------------------------- |
| **stod**      | **string to double**            |
| stoi          | string to int                   |
| **to_string** | **all types of val to string.** |
| to_wstring    |                                 |

遍历方式：

- 方式1: 

  ```c++
  for(int i = 0;i<s.size();i++)
  {
  		cout<<s[i]<<" ";//遍历
    	s[i]+=1; //修改
    
  }
  cout<<endl;
  ```

- 迭代器

  用来访问和修改容器的。

  用法：

  ```c++
  //迭代器现在可以简单认为就是像指针。
  //end()是最后一个非空字符的下一个
  string::iterator it = s.begin();//可以用auto代替
  while(it != s.end())//不建议用<，<只适用于连续的，!=普适
  {
  cout<<*it<<" ";
  ++it;
  }
  cout<<endl;
  ```

  反向迭代器

  ```c++
  string::reverse_iterator rit = s.rbegin();
  while(rit != s.rend())
  {
  cout<< *rit<<" ";
  ++rit;
  }
  cout<<endl;
  ```

  > 对于string，无论是正着遍历还是倒着遍历，都可以用下标+[]都够好用，那么学习迭代器遍历的意义是什么？
  >
  > 对于string，下标+[]就足够好用，确实可以不用迭代器。
  >
  > 但是其他容器，迭代器好用，甚至很多都不支持下标[]遍历，所以迭代器是比较统一的方式去遍历。

- 范围for

  不需要自己++，不需要判断结束。

  ```c++
  //for(auto e: s)//这是把s里的字符赋值给e，如果要修改,加引用
  for(auto& e:s)  
  {
  		cout << e << " ";
  }
  cout << endl;
  ```

## string的模拟实现

首先我们定义一个命名空间，以便我们的string和std里面的string区分开。然后我们需要模拟实现，就是需要对string进行增删查改，所以我们需要定义size和capacity来实现对字符串的追加等功能。

```c++

//定义一个，防止与std的重定义
namespace Amor
{
    class string
    {
      private:
        /* data */
        char *_str;
  	    size_t _size;
        size_t _capacity;
      public:
      //construction:
      string();
      string(const char* str);
      string(const string& s);
      //destruction:
      ~string();
      //operator:
      string& operator=(const string &s);
      char& operator[](size_t pos);
      
      string &operator+=(char ch);
      string &operator+=(const char *str);
      //iterator:
      typedef char *iterator;
      typedef const char *const_iterator;
    };
  //实现
}
```

### construction (构造函数)

类外实现，需要加string

```c++
string::string()
		:_str(new char[1]),_size(0),_capacity(0)
{
      _str[0] = '\0'
    }
string::string(const char* str)
		:_size(strlen(str),_capacity(_size))
{
      _str = new char[_capacity + 1];
      strcpy(_str,str);
}	
//传统写法
string::string(const string &s)
    : _size(s._size), _capacity(s._capacity)
{
      _str = (new char[_capacity + 1]);
      stpcpy(_str, s._str);
}
```

大家可以看到上面写了传统写法，就是自己创建空间来进行拷贝构造，这种是比较麻烦的，可以做如下简化：

```c++
    string::string(const string &s)
        : _str(nullptr), _size(0), _capacity(0)
    {
        string tmp(s._str);
        swap(_str, tmp._str);
        swap(_size, tmp._size);
        swap(_capacity, tmp._capacity);
    }
```

这样实际上是对拷贝构造函数的复用，创建了临时变量，然后让临时变量的_str与this指针指向的 str交换即可，这样实际上是交换了指针，随后临时变量销毁，而我们成功拿到了拷贝构造好的*this。

并且，因为这种现代写法非常普遍，在实现其他函数的时候也会经常用到三个swap，所以我们不妨重载swap函数：

```c++
        void swap(string &s)
        {
            std::swap(_str, s._str);
            std::swap(_size, s._size);
            std::swap(_capacity, s._capacity);
        }
```

这种写法必须掌握，非常重要！因为在之后的学习中还会频繁的使用，尤其是当传统写法非常麻烦时。

### destruction (解构函数)

```c++
    string::~string()
    {
        delete[] _str;
        _str = nullptr;
        _capacity = _size = 0;
    }
```

### iterator (迭代器)

迭代器是一种我们之前没怎么见过的东西，实际上就是一种类似指针的自定义类型，而在官方的string类中，iterator就是指针类型。我们可以用typedef定义它。

```c++
typedef char *iterator;
typedef const char *const_iterator; 
iterator begin();
iterator end();
iterator rbegin();
iterator rend();
```

```c++
    string::iterator string::begin()
    {
        return _str;
    }

    string::iterator string::end()
    {
        return _str + _size;
    }

    string::iterator string::rbegin()
    {
        return _str + _size - 1;
    }

    string::iterator string::rend()
    {
        return _str - 1;
    }
```

同样的，我们应该对迭代器进行重载，以此来适用const类型的对象。

```c++
        const_iterator end() const
        {
            return _str + _size;
        }
        const_iterator begin() const
        {
            return _str;
        }
```

我们可以用测试函数对其进行测试来验证是否正确。

```c++
void Test_string3()
{
    Amor::string s1("hello world");
    Amor::string::iterator it = s1.begin();
    while(it!=s1.end())
    {
        *it += 1;
        ++it;
    }
    it = s1.begin();
    while(it!=s1.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}
void Test_string4()
{
    //范围for本质就是使用的标准的迭代器
  	//如果我们把自己定义的迭代器进行简单的名称修改，就会发现范围for无法再使用了，这是因为：
  	//范围for用的是标准的迭代器。
    Amor::string s1("hello world");
    for(auto e:s1)
    {
        cout << e << " ";
    }
    cout << endl;
}
```

### operator (操作符重载)

```c++
char &operator[](size_t pos);
string &operator+=(const char *str);
string &operator+=(char ch);
string &operator=(const string &s);
```

#### operator[]

```c++
char &string::operator[](size_t pos)
{
		assert(pos < _size);
		return _str[pos];
}
const char & string::operator[](size_t pos) const
{
		assert(pos < _size);  
  	return _str[pos];
}
//构成函数重载，让const对象可以使用。
```

#### operator=

```c++
//传统写法：   
		string &string::operator=(const string &s)
    {
        //考虑左右值相等
        if (this == &s)
        {
            return *this;
        }
        // delete[] _str;
        // _str = (new char[strlen(s._str) + 1]);//new可能会失败！所以先拷贝再delete

        char *tmp = new char[s._capacity + 1];
        strcpy(tmp, s._str);
        delete[] _str;
        _str = tmp;
        _size = s._size;
        _capacity = s._capacity;
        return *this;
    }
```

可见传统的=重载是非常麻烦的，我们同样采用上面提到的现代写法来简化它。

```c++
    //现代1:
    string &string::operator=(const string &s)
    {
        if(this!=&s)
        {
            string tmp(s._str);
            swap(tmp);
        }
        return *this;
    }
```

更有牛人采用更牛逼的方法：

```c++
    //现代2：
    string &string::operator=(string s)
    {
        swap(tmp);
        return *this;
    }
//传值传参会调用拷贝构造 构造出形参s
//使用形参s来进行交换不会影响实参。
//需要注意传参类型的变化，同时需要修改声明。
```

#### operator+=

```c++
//我们先实现尾插然后复用即可
    string& string::operator+=(char ch)
    {
        push_back(ch);
        return *this;
    }
    string &string::operator+=(const char* str)
    {
        append(str);
        return *this;
    }
```

#### relational operator > < == >= <=

在这里我们可以选择把他们定义为成员函数也可以选择定义为全局函数，但是有一些区别，以>为例。

```c++
//成员函数
bool operator>(const string& s)
{
		if(strcmp(_str, s._str))
		{
				return true;
		}
		else
		{
				return false;
		}
}
//全局函数
bool operator>(const string& s1,const string& s2)
{
  		size_t i1 = 0,i2 = 0;
  		while(i1<s.size() && i2.size())
      {
        	if(s1[i1] > s2[i2])
          {
            	return true;
          }
        else if(s1[i1] < s2[i2])
        {
          		return false;
        }
        else
        {
          		++i1;
          		++i2;
        }
      }
			return i1<s1.size()?true:false;
}

//当然我们也可以使用我们定义的c_str()函数，就可以继续使用上面的_str去strcmp了。如下
bool operator>(const string& s1,const string& s2)
{
  	return strcmp(s1.c_str(),s2.c_str())>0;
  //这种写法是对第一种写法的简写。改用三目操作符。
}
```

```c++
bool operator==(const string& s)
{
		return strcmp(_str,s._str)==0;
}
```

写两个剩余的全部复用

```
bool operator<(const string& s)
{
		return ! (_str>=s._str)
}
bool operator<=(const string& s)
{
		return !(_str>s._str);
}
bool operator>=(const string& s)
{
		return _str==s._str || _str>s._str;
}
bool operator!=(const string& s)
{
		return !(_str==s._str) ;
}
```

#### operator >> <<

这个是必须重载成全局函数，因为第一个位置要放cout和cin。带返回值是因为要支持链式的调用。如cout<< s1 << endl;连续的两个<<必须要有返回值。

```c++
ostream<<(ostream& out,const string& s)//有返回值
{
//范围for
		for(auto ch : s)
		{
		 		out << ch;
		}
		return out;
}
//法2
ostream<<(ostream& out,const string& s)//有返回值
{
//数组遍历
		for(size_t i = 0; i< s.size(); i++)
		{
				cout<< s[i];
		}
		return out;
}
//注意：不可以这么写：
ostream<<(ostream& out,const string& s)//有返回值
{
		out << s.c_str();
		//因为这样实际上遇到了'\0'会自动终止。
		return out;
}
//--------------上面是错误的-------------------
istream<<(istream& in,string& s)//不写const了，因为要修改。
{
		char ch = in.get();
  	while(ch != ' ' && ch != '\n')
    {
      	s+=ch;
      	ch = in.get();
    }
  	return in;
}
```



### 其他函数

一般只有流插入和流提取重载才会放在全局里定义，其他的放在成员函数即可。

#### 成员变量的访问

为了我们在类外可以查看或者修改成员变量，我们写一些接口函数来对其进行访问，因为_size不需要修改，所以后面加const。

> 问：为什么有的需要对const对象和普通对象进行分别定义函数重载，如[]等操作符，而size()就不会？
>
> 答：因为size()标const是权限缩小，有的函数是不需要修改的，如size，这时候无论是const对象还是普通对象都是可以调用函数的。而operator[]则不然，如果只写一个const版本会让普通对象无法修改。所以需要写两个。
>
> 总结：函数中不涉及修改的可以只写const，否则写重载。

```c++
size_t size() const
{
		return _size;
}
char *c_str() const
{
		return _str;
}
```

#### swap()

> 问：我们在上面construction章节也对自己定义了swap函数，同样的，std库里和标准string类里也同样都定义了swap函数，那么二者有无差别？或者说，二者的效率哪个更高些？

```c++
//std库里是一个模板函数
template <class T> 
void swap ( T& a, T& b )
{
  T c(a);
  a=b;
  b=c;
}
//调用方法：
string s1;
string s2;
swap(s1,s2);
```

```c++
//string标准库里
void swap (string& str);
{
 		std::swap(_str, s._str);
    std::swap(_size, s._size);
    std::swap(_capacity, s._capacity);
}
//调用
string s1;
string s2;
s1.swap(s2);
```

> 答：**<c++98>**
> **string标准库里的效率更高，因为其定义也是使用std库swap函数 对每个成员变量交换，代价很小。**而std库里的swap对string进行了三次深拷贝。
>
> std库swap函数只适合于内置类型的交换，不太适用于自定义类型。因为代价很大。

#### reserve()

如果我们想尾插字符或者字符串，首先需要解决的问题就是容量不够的情况下增容的问题。在官方string库中，使用的是reserve()函数来增容，我们在这里同样也可以模拟实现一下。

```c++
void string::reserve(size_t n)
//reserve(100)是让容量到100，不包含'\0'
    {
        if(n>_capacity)
        {
          //开辟n+1个字节的空间，最后一个为'\0'
          //虽然_capacity不算'\0'，但是我们要记得开空间。
            char *tmp = new char[n + 1];
            strcpy(tmp, _str);
            delete[] _str;

            _str = tmp;
            _capacity = n;
        }
    }
```

#### resize(size_t n, char ch)

标准的库一般不会缩容。只会改变_size

首先我们看一下几种情况：

- n>_capacity
- n<_capacity && n>size
- n<=_size，只需要改变size到n，然后 _str的第n个位置置'\0'

```c++
    void string::resize(size_t n, char ch )
    {
        if (n <= _size)
        {
            _size = n;
            _str[_size] = '\0';
        }
        else
        {
            if (n > _capacity)
            {
                reserve(n);
            }

            memset(_str+_size, ch, n - _size);
            _size = n;
            _str[_size] = '\0';
        }
```

#### push_back(char ch)

```c++
    void string::push_back(char ch)
    {
        if (_size == _capacity)
        {
            reserve(_capacity == 0 ? 4 : _capacity * 2);
            //增容
        }
        //添加
        _str[_size] = ch;
        ++_size;
        //加'\0'
        _str[_size] = '\0';
    }
```

#### append(const char* str)

```c++
    void string::append(const char *str)
    {
        //不能粗暴的扩大二倍
        //因为不知道尾插的字符串多长
        size_t len = strlen(str);
        if((_size+len)>_capacity)// = 是正好放进去
        {
            reserve(_size + len);
        }
        strcpy(_str + _size, str);
        _size += len;
    }
```

#### find()

```c++
    size_t string::find(char ch)
    {
        for (size_t i = 0; i < _size;++i)
        {
            if(ch == _str[i])
            {
                return i;
            }
        }
        return npos;
    }
    size_t string::find(const char *str);
    size_t string::find(const char *str, size_t pos = 0)
    {
        const char* ptr = strstr(_str + pos, str);
        if(ptr == nullptr)
        {
            return npos;
        }
        else
        {
            return ptr - _str;
        }
    }
```

#### insert()

```c++
string &string::insert(size_t pos, char ch)
    {
        assert(pos <= _size);
        if (_size == _capacity)
        {
            reserve(_capacity == 0 ? 4 : 2 * _capacity);
        }
        if (pos == _size)
            push_back(ch);
        else
        {
            // size_t end = _size;
            // while(end>=pos)//size_t非常容易越界，考虑pos=0，end=0，end--后变为-1为无穷大，所以要修改。
            //{
            //    _str[end + 1] = _str[end];
            //  --end;
            //}
            size_t end = _size + 1;
            //记得挪动'\0'
            while (end > pos)
            {
                _str[end] = _str[end - 1];
                --end;
            }
            _str[pos] = ch;
            ++_size;
        }
        return *this;
    }
    string &string::insert(size_t pos, const char *str)
    {
        assert(pos <= _size);
        size_t len = strlen(str);
        if (_size + len > _capacity)
        {
            reserve(_size + len);
        }
        size_t end = _size + len;
        while (end >= pos + len)
        {
            //记得挪动'\0'
            _str[end] = _str[end - len];
            --end;
        }
        memcpy(_str + pos, str, len);
        _size += len;
        return *this;
    }
```

#### erase()

```c++
    string& string::erase(size_t pos = 0, size_t len = npos)
    {
        if(len == npos || len+pos>=_size)
        {
            _str[pos] = '\0';
            _size = pos;
        }
        else
        {
            strcpy(_str + pos, _str + pos + len);
            _size -= len;
        }
    }
```

