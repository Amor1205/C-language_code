#include "vector.h"

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

int main()
{
    // test_vector6();
    Amor::test_vector_4();

    return 0;
}