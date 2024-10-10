#ifdef STACK_SQLIDT_CPP
#include "Stack_Sqlist.cpp"

bool validateStackSequences(vector<int> &pushed, vector<int> &popped, vector<pair<int, int>> &ans)
{
    Stack S;
    InitStack(S);
    int i = 0;
    for (auto x : pushed)
    {
        Push(S, x);
        ans.push_back({1, x});
        while (!StackEmpty(S) && S.data[S.top] == popped[i])
        {
            int e;
            Pop(S, e);
            ans.push_back({2, e});
            i++;
        }
    }
    return StackEmpty(S);
}

#endif

#ifdef STACK_STL_CPP
#include "Stack_stl.cpp"

bool validateStackSequences(vector<int> &pushed, vector<int> &popped, vector<pair<int, int>> &ans)
{
    Stack S;
    InitStack(S);
    int i = 0;
    for (auto x : pushed)
    {
        Push(S, x);
        ans.push_back({1, x});
        while (!StackEmpty(S) && S.s.top() == popped[i])
        {
            int e;
            Pop(S, e);
            ans.push_back({2, e});
            i++;
        }
    }
    return StackEmpty(S);
}

#endif