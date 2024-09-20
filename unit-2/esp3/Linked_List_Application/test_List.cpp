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
    LinkList L3 = FindFirstCommonNode(L1, L2);
    cout << "L3: ";
    if (L3 != nullptr)
        cout << L3->data << endl;
    else
        cout << "NULL" << endl;

    LinkList L4 = MergeSortedLists(L1, L2);
    cout << "L4(=L1+L2): ";
    ListTraverse(L4);
}
#endif