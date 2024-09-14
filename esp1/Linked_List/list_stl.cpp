#include <iostream>
#ifndef list_stl_h
#define list_stl_h
#include <list>
#include <algorithm>
typedef struct
{
    std::list<int> data;
} List;

// 初始化双向链表
void InitList(List &List)
{
    List.data.clear();
}

// 销毁双向链表
void DestroyList(List &List)
{
    List.data.clear();
}

// 清空双向链表
void ClearList(List &List)
{
    List.data.clear();
}

// 判断双向链表是否为空
bool ListEmpty(List &List)
{
    return List.data.empty();
}

// 获取双向链表长度
int ListLength(List &List)
{
    return List.data.size();
}

// 获取第 i 个元素
bool GetElem(List &List, int i, int &e)
{
    if (i < 1 || i > List.data.size())
        return false;
    auto it = List.data.begin();
    std::advance(it, i - 1);
    e = *it;
    return true;
}

// 定位元素，返回第一个与 e 相等的元素位置
int LocateElem(List &List, int e)
{
    auto it = std::find(List.data.begin(), List.data.end(), e);
    if (it == List.data.end())
        return 0;
    return std::distance(List.data.begin(), it) + 1;
}

// 获取前驱元素
bool PriorElem(List &List, int cur_e, int &pre_e)
{
    auto it = std::find(List.data.begin(), List.data.end(), cur_e);
    if (it == List.data.begin() || it == List.data.end())
        return false;
    pre_e = *(--it);
    return true;
}

// 获取后继元素
bool NextElem(List &List, int cur_e, int &next_e)
{
    auto it = std::find(List.data.begin(), List.data.end(), cur_e);
    if (it == List.data.end() || ++it == List.data.end())
        return false;
    next_e = *it;
    return true;
}

// 插入元素
bool ListInsert(List &List, int i, int e)
{
    if (i < 1 || i > List.data.size() + 1)
        return false;
    auto it = List.data.begin();
    std::advance(it, i - 1);
    List.data.insert(it, e);
    return true;
}

// 删除元素
bool ListDelete(List &List, int i, int &e)
{
    if (i < 1 || i > List.data.size())
        return false;
    auto it = List.data.begin();
    std::advance(it, i - 1);
    e = *it;
    List.data.erase(it);
    return true;
}

// 打印双向链表
void ListTraverse(List &List)
{
    for (auto it = List.data.begin(); it != List.data.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

#endif // list_stl_h