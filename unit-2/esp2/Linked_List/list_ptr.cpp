#include <iostream>
#ifndef list_ptr_h
#define list_ptr_h

typedef struct LNode
{
    int data;
    struct LNode *prev;
    struct LNode *next;
} LNode;

typedef struct
{
    LNode *head;
    LNode *tail;
    int length;
} List;

// 初始化双向链表
void InitList(List &L)
{
    L.head = nullptr;
    L.tail = nullptr;
    L.length = 0;
}

// 销毁双向链表
void DestroyList(List &L)
{
    LNode *current = L.head;
    while (current != nullptr)
    {
        LNode *next = current->next;
        delete current;
        current = next;
    }
    L.head = nullptr;
    L.tail = nullptr;
    L.length = 0;
}

// 清空双向链表
void ClearList(List &L)
{
    DestroyList(L);
}

// 判断双向链表是否为空
bool ListEmpty(List &L)
{
    return L.length == 0;
}

// 获取双向链表的长度
int ListLength(List &L)
{
    return L.length;
}

// 获取双向链表中的第i个元素
bool GetElem(List &L, int i, int &e)
{
    if (i < 1 || i > L.length)
        return false;
    LNode *current = L.head;
    for (int index = 1; index < i; ++index)
    {
        current = current->next;
    }
    e = current->data;
    return true;
}

// 定位元素在双向链表中的位置
int LocateElem(List &L, int e)
{
    LNode *current = L.head;
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

// 获取双向链表中元素的前驱
bool PriorElem(List &L, int cur_e, int &pre_e)
{
    LNode *current = L.head;
    while (current != nullptr && current->data != cur_e)
    {
        current = current->next;
    }
    if (current == nullptr || current->prev == nullptr)
        return false;
    pre_e = current->prev->data;
    return true;
}

// 获取双向链表中元素的后继
bool NextElem(List &L, int cur_e, int &next_e)
{
    LNode *current = L.head;
    while (current != nullptr && current->data != cur_e)
    {
        current = current->next;
    }
    if (current == nullptr || current->next == nullptr)
        return false;
    next_e = current->next->data;
    return true;
}

// 在双向链表中的第i个位置插入元素
bool ListInsert(List &L, int i, int e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    LNode *newNode = new LNode();
    newNode->data = e;
    if (i == 1)
    {
        newNode->prev = nullptr;
        newNode->next = L.head;
        if (L.head != nullptr)
            L.head->prev = newNode;
        L.head = newNode;
        if (L.tail == nullptr)
            L.tail = newNode;
    }
    else
    {
        LNode *current = L.head;
        for (int index = 1; index < i - 1; ++index)
        {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr)
            current->next->prev = newNode;
        current->next = newNode;
        if (newNode->next == nullptr)
            L.tail = newNode;
    }
    ++L.length;
    return true;
}

// 删除双向链表中的第i个元素
bool ListDelete(List &L, int i, int &e)
{
    if (i < 1 || i > L.length)
        return false;
    LNode *current = L.head;
    for (int index = 1; index < i; ++index)
    {
        current = current->next;
    }
    e = current->data;
    if (current->prev != nullptr)
        current->prev->next = current->next;
    if (current->next != nullptr)
        current->next->prev = current->prev;
    if (i == 1)
        L.head = current->next;
    if (i == L.length)
        L.tail = current->prev;
    delete current;
    --L.length;
    return true;
}

// 遍历双向链表
void ListTraverse(List &L)
{
    LNode *current = L.head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

#endif // list_ptr_h