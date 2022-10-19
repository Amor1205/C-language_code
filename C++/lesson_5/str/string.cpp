#include"string.h"

void Test_string1()
{
    Amor::string s1("hello");
    Amor::string s2("world");
    //cout << s1 << endl;
    //cout << s2 << endl;
    // printf("%s", s1);
    // printf("%s", s2);
    // Amor::string
    Amor::string s3(s1);
}
void Test_string2()
{
    Amor::string s1("hello world");
    cout << s1.c_str() << endl;
    s1[1] = 'x';
    for (size_t i = 0; i < s1.size(); i++)
    {
        cout << s1[i] << " ";
    }
    cout << endl;
}
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

int main()
{
    Test_string3();

    return 0;
}