#include <bits/stdc++.h>
#include "BinaryTree_list.cpp"
using namespace std;

string postOrder;

bool NewCreateBiTree(BiTree &T, const string &preOrder, const string &inOrder, int preStart, int preEnd, int inStart, int inEnd)
{
    if (preStart > preEnd || inStart > inEnd)
        return false;
    char root = preOrder[preStart];
    int inRoot = inOrder.find(root, inStart);
    int leftSize = inRoot - inStart;
    // cerr << root << " " << inRoot << " " << leftSize << endl;
    T = new BiTNode(root);
    // 递归左子树
    NewCreateBiTree(T->lchild, preOrder, inOrder, preStart + 1, preStart + leftSize, inStart, inRoot - 1);
    // 递归右子树
    NewCreateBiTree(T->rchild, preOrder, inOrder, preStart + leftSize + 1, preEnd, inRoot + 1, inEnd);
    return true;
}

int main()
{
    string preOrder = "ABCDEFGH";
    string inOrder = "CBEDFAGH";
    // 此时二叉树为
    //          A
    //         / \
    //        B   G
    //       / \   \
    //      C   D   H
    //         / \
    //        E   F
    BiTree T;
    InitBiTree(T);
    NewCreateBiTree(T, preOrder, inOrder, 0, 7, 0, 7);
    PostOrderTraverse(T);
    cout << endl;
    return 0;
}
