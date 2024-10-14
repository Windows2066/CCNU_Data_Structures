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
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[')
            Push(S, s[i]);
        else if (s[i] == ')')
        {
            char e;
            GetTop(S, e);
            if (e == '(')
                Pop(S, e);
            else
            {
                cout << "表达式括号不匹配" << endl;
                return 0;
            }
        }
        else if (s[i] == ']')
        {
            char e;
            GetTop(S, e);
            if (e == '[')
                Pop(S, e);
            else
            {
                cout << "表达式括号不匹配" << endl;
                return 0;
            }
        }
    }
    if (StackEmpty(S))
        cout << "表达式括号匹配" << endl;
    else
        cout << "表达式括号不匹配" << endl;
}