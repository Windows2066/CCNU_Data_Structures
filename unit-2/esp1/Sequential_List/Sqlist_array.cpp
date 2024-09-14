#include <iostream>

#ifndef Sqlist_array_h
#define Sqlist_array_h

#define INIT_SIZE 100 // 顺序表的初始容量
#define INCREMENT 50  // 顺序表扩容的增量

typedef int ElemType;

typedef struct
{
    ElemType *data;
    int Length;
    int ListSize;
} SqList;

// 初始化顺序表
void InitList(SqList &L)
{
    L.data = new ElemType[INIT_SIZE];
    L.Length = 0;
    L.ListSize = INIT_SIZE;
}

// 销毁顺序表
void DestroyList(SqList &L)
{
    delete[] L.data;
    L.data = nullptr;
    L.Length = 0;
    L.ListSize = 0;
}

// 清空顺序表
void ClearList(SqList &L)
{
    L.Length = 0;
}

// 判断顺序表是否为空
bool ListEmpty(SqList L)
{
    return L.Length == 0;
}

// 获取顺序表长度
int ListLength(SqList L)
{
    return L.Length;
}

// 获取第 i 个元素
bool GetElem(SqList L, int i, ElemType &e)
{
    if (i < 1 || i > L.Length)
        return false;
    e = L.data[i - 1];
    return true;
}

// 定位元素，返回第一个与 e 相等的元素位置
int LocateElem(SqList L, ElemType e)
{
    for (int i = 0; i < L.Length; i++)
    {
        if (L.data[i] == e)
            return i + 1;
    }
    return 0;
}

// 获取前驱元素
bool PriorElem(SqList L, ElemType cur_e, ElemType &pre_e)
{
    for (int i = 1; i < L.Length; i++)
    {
        if (L.data[i] == cur_e)
        {
            pre_e = L.data[i - 1];
            return true;
        }
    }
    return false;
}

// 获取后继元素
bool NextElem(SqList L, ElemType cur_e, ElemType &next_e)
{
    for (int i = 0; i < L.Length - 1; i++)
    {
        if (L.data[i] == cur_e)
        {
            next_e = L.data[i + 1];
            return true;
        }
    }
    return false;
}

// 插入元素
bool ListInsert(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.Length + 1)
        return false;
    if (L.Length >= L.ListSize)
    {
        ElemType *newData = new ElemType[L.ListSize + INCREMENT];
        for (int j = 0; j < L.Length; j++)
        {
            newData[j] = L.data[j];
        }
        delete[] L.data;
        L.data = newData;
        L.ListSize += INCREMENT;
    }
    for (int j = L.Length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.Length++;
    return true;
}

// 删除元素
bool ListDelete(SqList &L, int i, ElemType &e)
{
    if (i < 1 || i > L.Length)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.Length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.Length--;
    return true;
}

// 打印顺序表
bool ListTraverse(SqList L)
{
    if (L.Length == 0)
        return false;
    for (int i = 0; i < L.Length; i++)
    {
        std::cout << L.data[i] << " ";
    }
    std::cout << std::endl;
    return true;
}
#endif