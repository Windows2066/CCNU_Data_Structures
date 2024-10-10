#include <bits/stdc++.h>

#ifndef STACK_STL_CPP
#define STACK_STL_CPP

typedef int ElemType;

struct Stack
{
    std::stack<ElemType> s;
    bool is_init = false;
} S;

void InitStack(Stack &S)
{
    S.is_init = true;
    while (!S.s.empty())
        S.s.pop();
}

bool DestroyStack(Stack &S)
{
    if (!S.is_init)
        return false;
    InitStack(S);
    S.is_init = false;
    return true;
}

bool ClearStack(Stack &S)
{
    if (!S.is_init)
        return false;
    InitStack(S);
    return true;
}

bool StackEmpty(Stack &S)
{
    if (!S.is_init)
    {
        std::cerr << "Stack is not initialized!" << std::endl;
        return false;
    }
    return S.s.empty();
}

int StackLength(Stack &S)
{
    if (!S.is_init)
    {
        std::cerr << "Stack is not initialized!" << std::endl;
        return -1;
    }
    return S.s.size();
}

bool GetTop(Stack S, int &e)
{
    if (!S.is_init)
    {
        std::cerr << "Stack is not initialized!" << std::endl;
        return false;
    }
    if (S.s.empty())
        return false;
    e = S.s.top();
    return true;
}

bool Push(Stack &S, int e)
{
    if (!S.is_init)
    {
        std::cerr << "Stack is not initialized!" << std::endl;
        return false;
    }
    S.s.push(e);
    return true;
}

bool Pop(Stack &S, int &e)
{
    if (!S.is_init)
    {
        std::cerr << "Stack is not initialized!" << std::endl;
        return false;
    }
    if (S.s.empty())
        return false;
    e = S.s.top();
    S.s.pop();
    return true;
}

bool StackTraverse(Stack S)
{
    if (!S.is_init)
    {
        std::cerr << "Stack is not initialized!" << std::endl;
        return false;
    }
    if (S.s.empty())
    {
        std::cout << "Stack is empty!" << std::endl;
        return true;
    }
    std::stack<int> temp = S.s;
    while (!temp.empty())
    {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << std::endl;
    return true;
}

#endif // STACK_STL_CPP