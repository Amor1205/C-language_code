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

  

## 拷贝

补充

