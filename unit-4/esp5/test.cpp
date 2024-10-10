#include <bits/stdc++.h>
using namespace std;
// #include "Stack_Sqlist.cpp"
#include "Stack_stl.cpp"
#include "StackFunction.cpp"

int main()
{
    Stack S;
    InitStack(S);
    vector<int> pushed = {1, 2, 2};
    vector<int> popped = {2, 2, 2};
    vector<pair<int, int>> ans;
    if (validateStackSequences(pushed, popped, ans))
    {
        cout << "出入栈的顺序合法" << endl;
        for (auto x : ans)
        {
            if (x.first == 1)
                cout << "入栈：" << x.second << endl;
            else
                cout << "出栈：" << x.second << endl;
        }
    }
    else
        cout << "出入栈的顺序不合法" << endl;
    return 0;
}