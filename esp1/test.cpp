#include <bits/stdc++.h>
// #include "Sqlist_vector.cpp"
#include "Sqlist_array.cpp"
#include "SqlistFunction.cpp"
using namespace std;

#ifdef Sqlist_array_h
signed main()
{
    SqList L;
    InitList(L);
    // L.data.resize(5);
    ListInsert(L, 1, 23);
    ListInsert(L, 2, 56);
    ListInsert(L, 3, 89);
    ListInsert(L, 4, 76);
    ListInsert(L, 5, 18);
    // ListTraverse(L);
    int i = 3, x = 56, y = 88, e = 0;
    cout << ListLength(L) << endl;
    GetElem(L, i, e);
    cout << e << endl;
    PriorElem(L, x, e);
    cout << e << endl;
    NextElem(L, x, e);
    cout << e << endl;
    cout << LocateElem(L, x) << endl;
    ListInsert(L, i, y);
    ListTraverse(L);
    ListDelete(L, i + 1, e);
    ListTraverse(L);
    cout << e << endl;
    SqList a, b;
    InitList(a);
    InitList(b);
    ListInsert(a, 1, 1);
    ListInsert(a, 2, 2);
    ListInsert(a, 3, 3);
    ListInsert(a, 4, 4);
    ListInsert(a, 5, 5);
    ListInsert(b, 1, 4);
    ListInsert(b, 2, 5);
    ListInsert(b, 3, 6);
    ListInsert(b, 4, 7);
    ListInsert(b, 5, 8);
    cout << "a: ";
    ListTraverse(a);
    cout << "b: ";
    ListTraverse(b);
    cout << "a+b(With B): ";
    unionListWithB(a, b);
    // cout << "a+b(Without B): ";
    // unionListWithoutB(a, b);
    ListTraverse(a);
    cout << "b: ";
    ListTraverse(b);
}
#endif

#ifdef Sqlist_vector_h
signed main()
{
    SqList L;
    InitList(L);
    L.data.resize(5);
    L.data = {23, 56, 89, 76, 18};
    // ListInsert(L, 1, 23);
    // ListInsert(L, 2, 56);
    // ListInsert(L, 3, 89);
    // ListInsert(L, 4, 76);
    // ListInsert(L, 5, 18);
    // ListTraverse(L);
    int i = 3, x = 56, y = 88, e = 0;
    cout << ListLength(L) << endl;
    GetElem(L, i, e);
    cout << e << endl;
    PriorElem(L, x, e);
    cout << e << endl;
    NextElem(L, x, e);
    cout << e << endl;
    cout << LocateElem(L, x) << endl;
    ListInsert(L, i, y);
    ListTraverse(L);
    ListDelete(L, i + 1, e);
    ListTraverse(L);
    cout << e << endl;
    SqList a, b;
    InitList(a);
    InitList(b);
    a.data.resize(5);
    b.data.resize(5);
    a.data = {1, 2, 3, 4, 5};
    b.data = {4, 5, 6, 7, 8};
    cout << "a: ";
    ListTraverse(a);
    cout << "b: ";
    ListTraverse(b);
    // cout << "a+b(With B): ";
    // unionListWithB(a, b);
    cout << "a+b(Without B): ";
    unionListWithoutB(a, b);
    ListTraverse(a);
    cout << "b: ";
    ListTraverse(b);
}
#endif