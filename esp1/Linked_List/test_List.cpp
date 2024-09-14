#include <bits/stdc++.h>
using namespace std;
#include "list_stl.cpp"
// #include "list_ptr.cpp"
#include "ListFunction.cpp"

#ifdef list_ptr_h
signed main()
{
    List L;
    InitList(L);
    ListInsert(L, 1, 23);
    ListInsert(L, 2, 56);
    ListInsert(L, 3, 89);
    ListInsert(L, 4, 76);
    ListInsert(L, 5, 18);
    ListTraverse(L);
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
    List a, b;
    InitList(a);
    InitList(b);
    ListInsert(a, 1, 1);
    ListInsert(a, 2, 1);
    ListInsert(a, 3, 2);
    ListInsert(a, 4, 2);
    ListInsert(a, 5, 3);
    ListInsert(a, 6, 3);
    ListInsert(a, 7, 4);
    ListInsert(a, 8, 4);
    ListInsert(a, 9, 5);
    ListInsert(a, 10, 5);
    ListInsert(b, 1, 4);
    ListInsert(b, 2, 5);
    ListInsert(b, 3, 6);
    ListInsert(b, 4, 7);
    ListInsert(b, 5, 8);
    cout << "a: ";
    ListTraverse(a);
    cout << "b: ";
    ListTraverse(b);
    cout << "a∪b: ";
    MergeLists(a, b);
    ListTraverse(a);
    cout << "Pure(a): ";
    PurifyList(a);
    ListTraverse(a);
}
#endif

#ifdef list_stl_h
signed main()
{
    List L;
    InitList(L);
    L.data = {23, 56, 89, 76, 18};
    ListTraverse(L);
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
    List a, b;
    InitList(a);
    InitList(b);
    a.data = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    b.data = {4, 5, 6, 7, 8};
    cout << "a: ";
    ListTraverse(a);
    cout << "b: ";
    ListTraverse(b);
    cout << "a∪b: ";
    MergeLists(a, b);
    ListTraverse(a);
    cout << "Pure(a): ";
    PurifyList(a);
    ListTraverse(a);
}
#endif