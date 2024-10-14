#include <bits/stdc++.h>
using namespace std;
#include "Stack_Sqlist.cpp"
// #include "Stack_stl.cpp"

int main()
{
    string s;
    cin >> s;
    Stack S;
    InitStack(S);
    for (int i = 0; i < s.length() / 2; i++)
        Push(S, s[i]);
    for (int i = (s.length() + 1) / 2; i < s.length(); i++)
    {
        char e;
        GetTop(S, e);
        if (e != s[i])
        {
            cout << "不是回文字符串" << endl;
            return 0;
        }
        Pop(S, e);
    }
    cout << "是回文字符串" << endl;
}