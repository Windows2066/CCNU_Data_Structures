#ifdef Sqlist_array_h
#include "Sqlist_array.cpp"
#endif
#ifdef Sqlist_vector_h
#include "Sqlist_vector.cpp"
#endif

void unionListWithB(SqList &a, SqList b)
{
    for (int i = 1; i <= ListLength(b); i++)
    {
        ElemType e;
        GetElem(b, i, e);
        if (LocateElem(a, e) == 0)
            ListInsert(a, ListLength(a) + 1, e);
    }
}

void unionListWithoutB(SqList &a, SqList &b)
{
    while (!ListEmpty(b))
    {
        ElemType e;
        ListDelete(b, 1, e);
        if (LocateElem(a, e) == 0)
            ListInsert(a, ListLength(a) + 1, e);
    }
}