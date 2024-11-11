#include <bits/stdc++.h>
#include "BinaryTree_list.cpp"
using namespace std;

// 判断是否是AVL树
bool IsAVL(BiTree T)
{
    if (T == NULL)
        return true;
    int leftHeight = BiTreeDepth(T->lchild);
    int rightHeight = BiTreeDepth(T->rchild);
    if (abs(leftHeight - rightHeight) > 1)
        return false;                            // 左右子树高度差大于1，不是AVL树
    return IsAVL(T->lchild) && IsAVL(T->rchild); // 递归判断左右子树是否是AVL树
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
    CreateBiTree(T);
    Traverse(T);
    std::cout << std::endl;
    if (IsAVL(T))
        std::cout << "是AVL树" << std::endl;
    else
        std::cout << "不是AVL树" << std::endl;
    BiTree T1;
    InitBiTree(T1);
    // 创建如下二叉树：
    //        A
    //       / \
    //      B   C
    //     / \
    //    D   E
    //   / \
    //  F   G
    CreateBiTree(T1);
    Traverse(T1);
    std::cout << std::endl;
    if (IsAVL(T1))
        std::cout << "是AVL树" << std::endl;
    else
        std::cout << "不是AVL树" << std::endl;
    return 0;
}