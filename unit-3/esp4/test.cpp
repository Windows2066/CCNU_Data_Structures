#include <bits/stdc++.h>
#include "Doubly_Linked_List.cpp"
using namespace std;

int main()
{
    DuLinkList L;
    InitList(L);
    ReadStuMsg("stumsg.txt", L);
    cout << "Befort QSort:" << endl;
    ShowStuMsg(L);
    QSort(L->next, L->prior);
    cout << "After QSort:" << endl;
    ShowStuMsg(L);
    DestroyList(L);
    return 0;
}