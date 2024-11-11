#include <bits/stdc++.h>
#include "BinaryTree_list.cpp"
using namespace std;

// 交换每个二叉树的左孩子和右孩子
void SwapChildren(BiTree T)
{
    if (T == nullptr)
        return;
    // 交换左孩子和右孩子
    BiTree temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;
    // 递归交换子树
    SwapChildren(T->lchild);
    SwapChildren(T->rchild);
}

int main()
{
    BiTree T;
    InitBiTree(T);
    // 3. 创建二叉树
    // 创建如下二叉树：
    //        A
    //       / \
    //      B   C
    //     / \
    //    D   E
    CreateBiTree(T);
    Traverse(T);
    std::cout << std::endl;
    SwapChildren(T);
    // 交换后二叉树变为：
    //        A
    //       / \
    //      C   B
    //         / \
    //        E   D
    Traverse(T);
    return 0;
}