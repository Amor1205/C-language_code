## vector的使用

vector是可改变size的数组，就是动态数据表。

```c++
void test_vector1() //构造
{
    vector<int> v1;        //用的最多的。
    vector<int> v2(10, 8); // 10个8
    vector<int> v3(v2.begin(), v2.end());
    vector<int> v4(v2);

    string s("hello world");
    vector<char> v5(s.begin(), s.end());
    // string结尾有'\0'，vector没有+=，没有查找，没有比较等等。
    //所以不能用vector替代string
}
```

```c++
void test_vector2() //遍历
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    //遍历
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    //遍历加修改
    for (size_t i = 0; i < v.size(); i++)
    {
        v[i] += 1;
        cout << v[i] << " ";
    }
    cout << endl;

    //迭代器
    vector<int>::iterator it = v.begin();
    while (it != v.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    //支持迭代器就支持范围for
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;

    //原生指针就是天然的迭代器，数组支持范围for，会被替换为指针。
    int a[] = {1, 2, 3};
    for (int *p = a; p < a + sizeof(a) / sizeof(a[0]); ++p)
    {
        cout << *p << " ";
    }
    cout << endl;
}
```

```c++

void test_vector3() // size相关
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    v.reserve(100); //修改_capacity,扩容
    // resize 扩容+初始化 / 删除数据，并且不改容量
    v.resize(100);    //不给后参数，使用缺省，int为0
    v.resize(100, 1); //给后参数，全部替换为参数1
}
```

```c++
void test_vector4() // find相关
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    // vector没有find，是因为每个容器都要find，所以抽出来放在algorithm里面了。
    //使用时先包<algorithm>头文件
    //返回值是一个迭代器 ： vector<int>::iterator类型
    vector<int>::iterator ret = find(v.begin(), v.end(), 3);
    //找到返回值的位置
    //没找到返回右边开区间的位置即v.end()。

    //在c++中，凡是使用迭代区间，都左闭右开。
    //(first,last) last是区间的最后一个的下一个

    // 为什么string有find ？
    // 因为string 的find提供查找子串。
}
```

```c++
void test_vector5() // insert相关
{
    //因为find返回的是迭代器，pos位置
    //所以insert传参也是迭代器。
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vector<int>::iterator ret = find(v.begin(), v.end(), 3);
    if(ret!= v.end())//必须验证3是否找到，否则是无效迭代器，直接插入或者删除会崩溃
    {
        cout << *ret << endl;
        //找到了3，打印3
        v.insert(ret, 10);
        //在3 的前面插入一个10

        //不能再插入之后再使用erase(原来的迭代器了)
        // v.erase(ret);
        //插入后会改变位置导致迭代器失效！！
    }
    for (auto e:v)
    {
        cout << e << " ";
    }

    //clear：清除数据，不清空间。
    v.clear();

    for (auto e : v)
    {
        cout << e << " ";
    }
}
```

```c++
void test_vector6()//如何增容
{
    size_t sz;
    vector<int> v;
    sz = v.capacity();
    cout << "making vector grow" << endl;
    for (size_t i = 0; i < 200;i++)
    {
        v.push_back(i);
        if(sz!=v.capacity())
        {
            sz = v.capacity();
            cout << "capacity changed:> " << sz << endl;
        }
    }
}
```

## 例题

### 只出现一次的数字

给定一个**非空**整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

> ```
> 输入: [2,2,1]
> 输出: 1
> ```
>
> ```
> 输入: [4,1,2,1,2]
> 输出: 4
> ```

这个问题我们在学习C语言的时候也学习过，只出现一次实际上就是用0去异或，因为两个相同的数异或会抵消。

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int value = 0;
        for(auto e:nums)
        {
            value^=e;
        }
        return value;
    }
};
```

### 杨辉三角

给定一个非负整数 *`numRows`，*生成「杨辉三角」的前 *`numRows`* 行。在「杨辉三角」中，每个数是它左上方和右上方的数的和。

> ```
> 输入: numRows = 5
> 输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
> ```
>
> ```
> 输入: numRows = 1
> 输出: [[1]]
> ```

核心思想其实是：每行头尾是1，中间第[i]个数字等于上一行的[j-1] + [ j ].

首先我们看用C++，只需要返回 vector<vector<int>>，相对于C语言的返回二级指针，方便了不少。

我们的思路就是用vector和vector<vector<int>>可以动态开辟空间的特性，来给不同的行以不同的空间。

```c++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      //开辟二维数组  
      vector<vector<int>> vv;
      //二维数组开辟空间resize  
      vv.resize(numRows);
      //二维数组的每个子对象都开辟空间，开辟空间的大小是它的行数，即其下标+1  
      for(size_t i = 0;i<numRows;++i)
        {
            vv[i].resize(i+1);
            //vv[i].front() = vv[i].back() = 1;
        //对数组的最左和最右的元素进行初始化    
        vv[i][0] = vv[i][vv[i].size()-1] = 1;
        }
      //用i表示行  
      for(size_t i = 0;i<vv.size();++i)
        {
        //用j表示列
            for(size_t j = 0;j<vv[i].size();++j)
            {
              //判断为0，即不是最左和最右的元素
                if(vv[i][j] == 0)
                {
                  //相加即可  
                  vv[i][j] = vv[i-1][j] + vv[i-1][j-1];
                }
            }
        }  
        return vv;
    }
};
```

### 电话号码的字母组合

给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

<img src="/Users/amor/Library/Application Support/CleanShot/media/media_yMwsaSPNK9/CleanShot 2022-10-21 at 13.15.53@2x.png" alt="CleanShot 2022-10-21 at 13.15.53@2x" style="zoom:50%;" />

> ```
> 输入：digits = "23"
> 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
> ```
>
> ```
> 输入：digits = ""
> 输出：[]
> ```
>
> ```
> 输入：digits = "2"
> 输出：["a","b","c"]
> ```

这个题目的思路是：

输入一串字符串，我们拿循环遍历它，取出它的每一个元素，元素会对应一串字符串，不同的元素会有不同的字符串，每个串中取一个字符进行排列组合(这实际上是多叉树的遍历)。这个排列组合作为一个str输出，输出所有的str。

首先建立数字和对应字符串的绝对映射。

```c++
string arr[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
```

传过来一个字符串，里面是数字，然后我们需要返回vector<string>类型。string是通过使用vector的尾插push_back( )函数来进行插入的。考虑到我们不知道会输入多少个字符的数字字符串，所以我们写一个子函数来进行多叉树的遍历。

```c++
vector<string>& _letterCombinations(const string& digits,size_t i)//姑且认为只有两个参数传入，这两个是必要的，一个是数字字符串，一个是数字字符串的下标
{
//我们要遍历树，首先想到的就是递归，递归的话必须有条件中止，中止的条件很简单，就是等树走完，在这里也就是下标等于这个字符串的大小。
	if(i==digits.size())
	{
		//还不知道要写啥
		//要结束了，应该是return 
	}
	//用一个string接受数字所对应的字符串。
	string str = arr[digits[i] - '0'];
	//此处应该写一个递归，但递归不是单向的，即不是只有一条路，所以我们应该写一个循环来遍历，循环中止的条件应该是本层内的都遍历完成了，所以条件应该写小于str的size
	for(size_t j = 0;j<str.size();++j)
  {
  //我们如果要写递归，那么怎么层层递归呢？i+1 即可，
  //递归一次我们想要让返回的vector里的string多加一个字符，所以必须要有一个字符串+字符的参数，我们在主函数里面设定combineStr就是用来相加的字符串。
  //因为要设定返回值，所以在主函数里加vetRet作为vector<string>& 类型的返回值，加引用是为了可以修改。
_letterCombinations(digits,i+1,combineStr+str[j],vetRet);
  }
  return vetRet;
}

```

```c++
//所以总的子函数为：
vector<string>& _letterCombinations(const string& digits,size_t i,string combineStr,vector<string>& vetRet)
    {
        if(i==digits.size())
        {
            vetRet.push_back(combineStr);
            return vetRet;
        }
        string str = arr[digits[i]-'0'];
        for(size_t j = 0;j<str.size();++j)
        {
            _letterCombinations(digits,i+1,combineStr+str[j],vetRet);
        }
        return vetRet;
    }
```

```c++
//主函数只需要定义对象， 引用子函数即可。
    vector<string> letterCombinations(string digits) {
        string combineStr;
        vector<string> vetRet;
      //判断一下如果digits为0或1	
        if(digits.empty())
        {
            return vetRet;
        }
        vetRet = _letterCombinations(digits,0,combineStr,vetRet);
    return vetRet;
    }
```

