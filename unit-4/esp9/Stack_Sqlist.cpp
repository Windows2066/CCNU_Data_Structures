#include <bits/stdc++.h>

#ifndef STACK_SQLIDT_CPP
#define STACK_SQLIST_CPP

typedef int ElemType;
constexpr int STACK_INIT_SIZE = 100;
constexpr int STACK_INCREMENT = 10;

struct Stack
{
    int *data;
    int top;
    int stacksize;
    int incrementsize;
};

void InitStack(Stack &S)
{
    S.data = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
    if (!S.data)
        std::cerr << "InitStack: Memory allocation failed!" << std::endl;
    S.top = -1;
    S.stacksize = STACK_INIT_SIZE;
    S.incrementsize = STACK_INCREMENT;
}

bool DestroyStack(Stack &S)
{
    if (!S.data)
        return false;
    free(S.data);
    S.data = nullptr;
    S.top = -1;
    S.stacksize = 0;
    S.incrementsize = 0;
    return true;
}

bool ClearStack(Stack &S)
{
    if (!S.data)
        return false;
    for (int i = 0; i < S.stacksize; i++)
        S.data[i] = 0;
    S.top = -1;
    return true;
}

bool StackEmpty(Stack &S)
{
    if (!S.data)
    {
        std::cerr << "Stack is not initialized!" << std::endl;
        return false;
    }
    return S.top == -1;
}

bool StackFull(Stack &S)
{
    if (!S.data)
    {
        std::cerr << "Stack is not initialized!" << std::endl;
        return false;
    }
    return S.top == S.stacksize - 1;
}

int StackLength(const Stack &S)
{
    if (!S.data)
    {
        std::cerr << "Stack is not initialized!" << std::endl;
        return -1;
    }
    return S.top + 1;
}

bool GetTop(Stack &S, int &e)
{
    if (!S.data)
    {
        std::cerr << "Stack is not initialized!" << std::endl;
        return false;
    }
    if (S.top == -1)
        return false;
    e = S.data[S.top];
    return true;
}

bool Push(Stack &S, int e)
{
    if (!S.data)
    {
        std::cerr << "Stack is not initialized!" << std::endl;
        return false;
    }
    if (S.top == S.stacksize - 1)
    {
        S.data = (int *)realloc(S.data, (S.stacksize + S.incrementsize) * sizeof(int));
        if (!S.data)
        {
            std::cerr << "Push: Memory allocation failed!" << std::endl;
            return false;
        }
        S.stacksize += S.incrementsize;
    }
    S.data[++S.top] = e;
    return true;
}

bool Pop(Stack &S, int &e)
{
    if (!S.data)
    {
        std::cerr << "Stack is not initialized!" << std::endl;
        return false;
    }
    if (S.top == -1)
        return false;
    e = S.data[S.top--];
    return true;
}

bool StackTraverse(const Stack &S)
{
    // if (!S.data)
    // {
    //     std::cerr << "Stack is not initialized!" << std::endl;
    //     return false;
    // }
    std::cout << "停车场目前有" << StackLength(S) << "辆车：\n";
    for (int i = 0; i <= 30; i++)
        std::cout << "-\n"[i == 30];
    for (int i = 0; i <= S.top; i++)
        std::cout << S.data[i] << " \n"[i == S.top];
    for (int i = 0; i <= 30; i++)
        std::cout << "-\n"[i == 30];
    return true;
}

#endif // STACK_SQLIDT_CPP