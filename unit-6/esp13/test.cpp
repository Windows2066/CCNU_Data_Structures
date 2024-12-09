#include <bits/stdc++.h>
#include "BinaryTree_list.cpp"
using namespace std;

// 以直观的方式输出二叉树
void printTree(BiTNode *root, string indent, bool last)
{
    if (root != nullptr)
    {
        cout << indent;
        if (last)
        {
            cout << "└─";
            indent += "  ";
        }
        else
        {
            cout << "├─";
            indent += "| ";
        }
        cout << root->data << endl;
        printTree(root->lchild, indent, false);
        printTree(root->rchild, indent, true);
    }
}

// 层次遍历并计算深度
int levelOrderTraversal(BiTNode *root)
{
    if (root == NULL)
        return 0;
    queue<BiTNode *> q;
    q.push(root);
    int depth = 0;
    while (!q.empty())
    {
        int size = q.size();
        depth++;
        for (int i = 0; i < size; i++)
        {
            BiTNode *node = q.front();
            q.pop();
            if (node->lchild)
                q.push(node->lchild);
            if (node->rchild)
                q.push(node->rchild);
        }
    }
    return depth;
}

int main()
{
    BiTree T;
    InitBiTree(T);
    CreateBiTree(T);
    // 创建的二叉树如下：
    //       1
    //      / \
    //     2   3
    //    / \ / \
    //   4  5 6  7
    //       \    \
    //       8     9
    //      /
    //     10
    printTree(T, "", true);
    // ‘└─’后面的数字表示右子树
    // ‘├─’后面的数字表示左子树
    cout << "Depth: " << levelOrderTraversal(T) << endl;
}