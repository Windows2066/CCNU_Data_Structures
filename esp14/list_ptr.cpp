#include <iostream>
#ifndef list_ptr_h
#define list_ptr_h

typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
    Node(int x) : data(x), next(nullptr) {}
} *LinkList;

// 初始化链表
void InitList(LinkList &L)
{
    L = nullptr;
}

// 销毁链表
void DestroyList(LinkList &L)
{
    LinkList current = L;
    while (current != nullptr)
    {
        LinkList next = current->next;
        delete current;
        current = next;
    }
    L = nullptr;
}

// 清空链表
void ClearList(LinkList &L)
{
    DestroyList(L);
}

// 判断链表是否为空
bool ListEmpty(LinkList L)
{
    return L == nullptr;
}

// 获取链表长度
int ListLength(LinkList L)
{
    int length = 0;
    LinkList current = L;
    while (current != nullptr)
    {
        ++length;
        current = current->next;
    }
    return length;
}

// 获取链表中的第i个元素
bool GetElem(LinkList L, int i, ElemType &e)
{
    if (i < 1)
        return false;
    LinkList current = L;
    for (int index = 1; current != nullptr && index < i; ++index)
    {
        current = current->next;
    }
    if (current == nullptr)
        return false;
    e = current->data;
    return true;
}

// 定位元素在链表中的位置
int LocateElem(LinkList L, ElemType e)
{
    LinkList current = L;
    int index = 1;
    while (current != nullptr)
    {
        if (current->data == e)
            return index;
        current = current->next;
        ++index;
    }
    return 0;
}

// 获取链表中元素的前驱
bool PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e)
{
    if (L == nullptr || L->data == cur_e)
        return false;
    LinkList current = L;
    while (current->next != nullptr && current->next->data != cur_e)
    {
        current = current->next;
    }
    if (current->next == nullptr)
        return false;
    pre_e = current->data;
    return true;
}

// 获取链表中元素的后继
bool NextElem(LinkList L, ElemType cur_e, ElemType &next_e)
{
    LinkList current = L;
    while (current != nullptr && current->data != cur_e)
    {
        current = current->next;
    }
    if (current == nullptr || current->next == nullptr)
        return false;
    next_e = current->next->data;
    return true;
}

// 在链表中的第i个位置插入元素
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if (i < 1)
        return false;
    LinkList newNode = new Node(0);
    newNode->data = e;
    if (i == 1)
    {
        newNode->next = L;
        L = newNode;
    }
    else
    {
        LinkList current = L;
        for (int index = 1; current != nullptr && index < i - 1; ++index)
        {
            current = current->next;
        }
        if (current == nullptr)
            return false;
        newNode->next = current->next;
        current->next = newNode;
    }
    return true;
}

// 删除链表中的第i个元素
bool ListDelete(LinkList &L, int i, ElemType &e)
{
    if (i < 1 || L == nullptr)
        return false;
    LinkList current = L;
    if (i == 1)
    {
        L = current->next;
    }
    else
    {
        LinkList prev = nullptr;
        for (int index = 1; current != nullptr && index < i; ++index)
        {
            prev = current;
            current = current->next;
        }
        if (current == nullptr)
            return false;
        prev->next = current->next;
    }
    e = current->data;
    delete current;
    return true;
}

// 遍历链表
void ListTraverse(LinkList L)
{
    LinkList current = L;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

#endif // list_ptr_h