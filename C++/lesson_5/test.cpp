#include <iostream>
#include <string>
using namespace std;

// int main()
// {
//     string s1;
//     string s2("hello world");
//     string s3(s2);

//     cin >> s1;
//     //cout << s1 << endl;

//     //string s4(s2, 2, 6);
//     // cout << s4 << endl;

//     cout << s1.size() << endl;
//     cout << s1.length() << endl;
//     //不包含'\0'，推荐size
//     cout << s1.capacity()<< endl;//容量，还能容纳多少个字符，但实际上容量是这个输出值+1，因为有'\0'，所以减了一。
//     s1.clear();//只清了数据，没清空间。
//     s1.empty();//是否为空

// }

// []重载的原理如下，这里的引用并非减少拷贝，而是为了支持修改返回对象。
// char& operator[](size_t pos)
// {
//     return _str[pos];
// }

//引用 可以 减少拷贝
//引用 可以 支持修改

// int main()
// {
//     string s1("hello world");
//     for (size_t i = 0; i < s1.size();++i)
//     {
//         cout << s1[i] << " ";
//         // cout << s1.operator[](i)<<“ ”；
//         //本质是调用了[]重载函数，这个重载让字符可以像数组一样访问。
//     }
//     cout << endl;

//     //不仅能读，还能写。
//     for (size_t i = 0; i < s1.size(); ++i)
//     {
//         s1[i] += 2;
//     }
//     cout << s1 << endl;

//     return 0;
// }

//插入字符
//三种方式都可以：push_back、append、+=
//推荐 +=
// int main()
// {
//     string s1;
//     s1.append("abcdef");

//     cout << s1 << endl;
//     s1.push_back(':');

//     cout << s1 << endl;
//     s1 += "hello";

//     cout << s1 << endl;

//     return 0;
// }
// void CaseConversion(char &ch)
// {
//     if (ch <= 'Z' && ch >= 'A')
//     {
//         ch += 32;
//     }
// }
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
void Test2()
{
    string s("hello");
    string::iterator it = s.begin();
    while (it != s.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}
void Test3()
{
    string file("test.txt");
    // FILE *fout = fopen(file.c_str(),"w");

    //取出后缀
    size_t pos = file.find('.');
    if(pos!=string::npos)
    {
        string suffix = file.substr(pos);
        cout << suffix << endl;
    }
}
void Test4()
{
    string url("https://cplusplus.com/reference/string/string/?kw=string");
    size_t pos1 = url.find(":");
    string protocol = url.substr(0, pos1 - 0);//前面的参数是位置，后面的参数是取出的长度
    cout << protocol << endl;
    size_t pos2 = url.find('/', pos1 + 3); //把：后的/跳过去，注意pos1是指：的位置
    string domainName = url.substr(pos1 + 3, pos2 - pos1 - 3);
    cout << domainName << endl;
    string uri = url.substr(pos2 + 1);
    cout << uri << endl;
}
void Test5()
{
    string s1("hello world");
    string s2("string");
    cout << (s1 > s2) << endl;
    cout << ("zaj" > s2) << endl;
}
void Test6()
{
    int val = stoi("13234");
    cout << val << endl;

    string str = to_string(3.14);
    cout << str << endl;
}
int main()
{
    // Test1();
    // Test3();
    // Test4();
    Test5();
    return 0;
}