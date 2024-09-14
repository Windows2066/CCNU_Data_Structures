#include <iostream>
#include <vector>
#include <algorithm>

#ifndef Sqlist_vector_h
#define Sqlist_vector_h
typedef int ElemType;

struct SqList
{
    std::vector<ElemType> data;
};

// 初始化顺序表
void InitList(SqList &L)
{
    L.data.clear();
}

// 销毁顺序表
void DestroyList(SqList &L)
{
    L.data.clear();
}

// 清空顺序表
void ClearList(SqList &L)
{
    L.data.clear();
}

// 判断顺序表是否为空
bool ListEmpty(SqList L)
{
    return L.data.empty();
}

// 获取顺序表长度
int ListLength(SqList L)
{
    return L.data.size();
}

// 获取第 i 个元素
bool GetElem(SqList L, int i, ElemType &e)
{
    if (i < 1 || i > L.data.size())
        return false;
    e = L.data[i - 1];
    return true;
}

// 定位元素，返回第一个与 e 相等的元素位置
int LocateElem(SqList L, ElemType e)
{
    auto it = std::find(L.data.begin(), L.data.end(), e);
    if (it == L.data.end())
        return 0;
    return it - L.data.begin() + 1;
}

// 获取前驱元素
bool PriorElem(SqList L, ElemType cur_e, ElemType &pre_e)
{
    auto it = std::find(L.data.begin(), L.data.end(), cur_e);
    if (it == L.data.begin() || it == L.data.end())
        return false;
    pre_e = *(it - 1);
    return true;
}

// 获取后继元素
bool NextElem(SqList L, ElemType cur_e, ElemType &next_e)
{
    auto it = std::find(L.data.begin(), L.data.end(), cur_e);
    if (it == L.data.end() || it == L.data.end() - 1)
        return false;
    next_e = *(it + 1);
    return true;
}

// 插入元素
bool ListInsert(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.data.size() + 1)
        return false;
    L.data.insert(L.data.begin() + i - 1, e);
    return true;
}

// 删除元素
bool ListDelete(SqList &L, int i, ElemType &e)
{
    if (i < 1 || i > L.data.size())
        return false;
    e = L.data[i - 1];
    L.data.erase(L.data.begin() + i - 1);
    return true;
}

// 打印顺序表
bool ListTraverse(SqList L)
{
    if (L.data.empty())
        return false;
    for (int i = 0; i < L.data.size(); i++)
    {
        std::cout << L.data[i] << "\n "[i != L.data.size() - 1];
    }
    return true;
}
#endif