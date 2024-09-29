#include <bits/stdc++.h>
using namespace std;
#include "list_ptr.cpp"
#include "ListFunction.cpp"

#ifdef list_ptr_h
signed main()
{
    LinkList L1;
    InitList(L1);
    LinkList L2;
    InitList(L2);

    // 插入节点，确保两个链表有公共节点
    ListInsert(L1, 1, 1);
    ListInsert(L1, 2, 2);
    ListInsert(L1, 3, 3);

    ListInsert(L2, 1, 4);
    ListInsert(L2, 2, 5);

    // 创建公共节点
    LinkList common = new Node;
    common->data = 6;
    common->next = new Node;
    common->next->data = 7;
    common->next->next = nullptr;

    // 将公共节点连接到两个链表的末尾
    LinkList temp = L1;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = common;

    temp = L2;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = common;

    cout << "L1: ";
    ListTraverse(L1);
    cout << "L2: ";
    ListTraverse(L2);
    LinkList Lc = FindFirstCommonNode(L1, L2);
    cout << "Lc: ";
    if (Lc != nullptr)
        cout << Lc->data << endl;
    else
        cout << "NULL" << endl;

    LinkList L3;
    InitList(L3);
    LinkList L4;
    InitList(L4);
    ListInsert(L3, 1, 1);
    ListInsert(L3, 2, 2);
    ListInsert(L3, 3, 3);
    ListInsert(L3, 4, 4);
    ListInsert(L3, 5, 5);
    ListInsert(L3, 6, 6);

    ListInsert(L4, 1, 3);
    ListInsert(L4, 2, 4);
    ListInsert(L4, 3, 5);
    ListInsert(L4, 4, 6);
    ListInsert(L4, 5, 7);
    ListInsert(L4, 6, 8);
    ListInsert(L4, 7, 9);

    LinkList L5 = MergeSortedLists(L3, L4);
    cout << "L5(=L3+L4): ";
    ListTraverse(L5);
}
#endif