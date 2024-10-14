#include <bits/stdc++.h>
#include "head_char.cpp"

#ifndef STACK_SQLIDT_CPP
#define STACK_SQLIST_CPP

struct Stack
{
    ElemType *data;
    int top;
    int stacksize;
    int incrementsize;
} SqStack;

void InitStack(Stack &S)
{
    S.data = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
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

int StackLength(Stack &S)
{
    if (!S.data)
    {
        std::cerr << "Stack is not initialized!" << std::endl;
        return -1;
    }
    return S.top + 1;
}

bool GetTop(Stack &S, ElemType &e)
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

bool Push(Stack &S, ElemType e)
{
    if (!S.data)
    {
        std::cerr << "Stack is not initialized!" << std::endl;
        return false;
    }
    if (S.top == S.stacksize - 1)
    {
        S.data = (ElemType *)realloc(S.data, (S.stacksize + S.incrementsize) * sizeof(ElemType));
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

bool Pop(Stack &S, ElemType &e)
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

bool StackTraverse(Stack &S)
{
    if (!S.data)
    {
        std::cerr << "Stack is not initialized!" << std::endl;
        return false;
    }
    for (int i = 0; i <= S.top; i++)
        std::cout << S.data[i] << " ";
    std::cout << std::endl;
    return true;
}

#endif // STACK_SQLIDT_CPP