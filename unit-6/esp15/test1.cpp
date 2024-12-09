#include <bits/stdc++.h>
#include "BinaryTree_list.cpp"
using namespace std;

// 计算WPL的递归函数
int calculateWPL(BiTree node, int depth)
{
    if (node == nullptr)
        return 0;
    // 如果是叶节点，返回其权值乘以当前深度
    if (node->lchild == nullptr && node->rchild == nullptr)
        return node->data * depth;
    // 递归计算左子树和右子树的WPL
    return calculateWPL(node->lchild, depth + 1) + calculateWPL(node->rchild, depth + 1);
}

int main()
{
    BiTree T;
    CreateBiTree(T);
    // 此时二叉树如下：
    //        1
    //       / \
    //      2   3
    //     / \   
    //    4   6
    //       /
    //      7
    //     / \
    //    8   9
    // WPL = 4*2+8*4+9*4+3*1 = 79
    cout << "该二叉树的WPL为: " << calculateWPL(T, 0) << endl;
}