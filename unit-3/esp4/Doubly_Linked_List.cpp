#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct Student
{
    std::string id, name;
    int score, time;
} STUDENT;

typedef struct DuLNode
{
    STUDENT stu;
    int i;
    struct DuLNode *prior;
    struct DuLNode *next;
} DuLNode, *DuLinkList;

// 初始化双向循环链表
int InitList(DuLinkList &L)
{
    L = new DuLNode;
    if (!L)
        return -1;          // 内存分配失败
    L->prior = L->next = L; // 自循环
    L->i = 0;               // 初始化索引
    return 0;               // 成功
}

// 销毁双向循环链表
void DestroyList(DuLinkList &L)
{
    DuLNode *p = L->next;
    while (p != L)
    {
        DuLNode *q = p->next;
        delete p;
        p = q;
    }
    delete L;
    L = nullptr;
}

// 显示学生信息
void ShowStuMsg(DuLinkList L)
{
    DuLNode *p = L->next;
    while (p != L)
    {
        std::cout << "ID: " << p->stu.id << ", Name: " << std::setw(10) << p->stu.name
                  << ", Score: " << std::setw(3) << p->stu.score << ", Time: "
                  << std::setw(4) << p->stu.time << std::endl;
        p = p->next;
    }
}

// 插入学生信息到双向循环链表
void InsertDuLinkList(DuLinkList &L, STUDENT stu)
{
    DuLNode *newNode = new DuLNode;
    newNode->stu = stu;
    newNode->next = L->next;
    newNode->prior = L;
    L->next->prior = newNode;
    L->next = newNode;
    newNode->i = L->i + 1; // 设置新节点的索引
    L->i++;                // 更新头节点的索引
}

// 从文件读取学生信息并插入双向循环链表
void ReadStuMsg(const char *filename, DuLinkList &L)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    STUDENT stu;
    while (file >> stu.id >> stu.name >> stu.score >> stu.time)
    {
        InsertDuLinkList(L, stu);
    }

    file.close();
}

// 分区函数，用于快速排序
DuLNode *Partition(DuLNode *s, DuLNode *t)
{
    STUDENT pivot = s->stu;
    DuLNode *i = s, *j = s->next;

    while (j != t->next)
    {
        if (j->stu.score > pivot.score ||
            (j->stu.score == pivot.score && j->stu.time < pivot.time) ||
            (j->stu.score == pivot.score && j->stu.time == pivot.time && j->stu.id < pivot.id))
        {
            i = i->next;
            std::swap(i->stu, j->stu);
        }
        j = j->next;
    }
    std::swap(i->stu, s->stu);
    return i;
}

// 快速排序
void QSort(DuLNode *s, DuLNode *t)
{
    if (s != t && s != t->next)
    {
        DuLNode *p = Partition(s, t);
        QSort(s, p->prior);
        QSort(p->next, t);
    }
}

#endif // DOUBLY_LINKED_LIST_H