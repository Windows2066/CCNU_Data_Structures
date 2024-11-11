#include <bits/stdc++.h>
#include "BinaryTree_list.cpp"
using namespace std;

int cnt = 0;

bool NewCreateBiTree(BiTree &T)
{
    char val;
    std::cin >> val;
    if (val == '#')
        T = nullptr;
    else
    {
        T = new BiTNode;
        T->data = val;
        cnt++; // 增加节点计数
        NewCreateBiTree(T->lchild);
        NewCreateBiTree(T->rchild);
    }
    return true;
}

int main()
{
    BiTree T;
    InitBiTree(T);
    // 创建如下二叉树：
    //        A
    //       / \
    //      B   C
    //     / \
    //    D   E
    NewCreateBiTree(T);
    Traverse(T);
    std::cout << std::endl;
    std::cout << "节点总数: " << cnt << std::endl;
    return 0;
}