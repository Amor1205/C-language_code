#include <iostream>
using namespace std;
#include <string>

int main()
{

    string s = "\1\2\2";
    for (int i = 0; i < s.size(); ++i)
    {
        cout << s[i] << endl;
    }
    return 0;
}
