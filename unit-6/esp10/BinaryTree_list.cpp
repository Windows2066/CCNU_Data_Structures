#include <iostream>
#ifndef BINARTREE_LIST_CPP
#define BINARTREE_LIST_CPP

typedef int ElemType;

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 初始化二叉树
void InitBiTree(BiTree &T)
{
    T = nullptr;
}

// 销毁二叉树
bool DestoyBiTree(BiTree &T)
{
    if (T == nullptr)
        return false;
    DestoyBiTree(T->lchild);
    DestoyBiTree(T->rchild);
    delete T;
    T = nullptr;
    return true;
}

// 创建二叉树（示例：前序输入，-1表示空）
bool CreateBiTree(BiTree &T)
{
    ElemType val;
    std::cin >> val;
    if (val == -1)
        T = nullptr;
    else
    {
        T = new BiTNode;
        T->data = val;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return true;
}

// 判断二叉树是否为空
bool BiTreeEmpty(BiTree T)
{
    return T == nullptr;
}

// 计算二叉树的深度
int BiTreeDepth(BiTree T)
{
    if (T == nullptr)
        return 0;
    int leftDepth = BiTreeDepth(T->lchild);
    int rightDepth = BiTreeDepth(T->rchild);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// 查找父节点
ElemType Parent(BiTree T, ElemType e)
{
    if (T == nullptr || T->data == e)
        return -1;
    if ((T->lchild && T->lchild->data == e) || (T->rchild && T->rchild->data == e))
        return T->data;
    int res = Parent(T->lchild, e);
    if (res != -1)
        return res;
    return Parent(T->rchild, e);
}

// 辅助函数：查找节点
BiTree FindNode(BiTree T, ElemType e)
{
    if (T == nullptr)
        return nullptr;
    if (T->data == e)
        return T;
    BiTree left = FindNode(T->lchild, e);
    if (left != nullptr)
        return left;
    return FindNode(T->rchild, e);
}

// 查找左子节点
int LeftChild(BiTree T, ElemType e)
{
    BiTree node = FindNode(T, e);
    if (node != nullptr && node->lchild != nullptr)
        return node->lchild->data;
    return -1;
}

// 查找右子节点
int RightChild(BiTree T, ElemType e)
{
    BiTree node = FindNode(T, e);
    if (node != nullptr && node->rchild != nullptr)
        return node->rchild->data;
    return -1;
}

// 查找左兄弟节点
int LeftSibling(BiTree T, ElemType e)
{
    if (T == nullptr || T->data == e)
        return -1;
    int parent = Parent(T, e);
    if (parent == -1)
        return -1;
    int ls = LeftChild(T, parent);
    if (ls == e)
        return -1;
    return ls;
}

// 查找右兄弟节点
int RightSibling(BiTree T, ElemType e)
{
    if (T == nullptr || T->data == e)
        return -1;
    int parent = Parent(T, e);
    if (parent == -1)
        return -1;
    int rs = RightChild(T, parent);
    if (rs == e)
        return -1;
    return rs;
}

// 插入子节点
bool InsertChild(BiTree T, ElemType p, int LR, BiTree c)
{
    if (T == nullptr)
        return false;
    if (T->data == p)
    {
        if (LR == 0)
            T->lchild = c;
        else
            T->rchild = c;
        return true;
    }
    if (InsertChild(T->lchild, p, LR, c))
        return true;
    return InsertChild(T->rchild, p, LR, c);
}

// 删除子节点
bool DeleteChild(BiTree T, ElemType p, int LR)
{
    if (T == nullptr)
        return false;
    if (T->data == p)
    {
        BiTree child = (LR == 0) ? T->lchild : T->rchild;
        DestoyBiTree(child);
        if (LR == 0)
            T->lchild = nullptr;
        else
            T->rchild = nullptr;
        return true;
    }
    if (DeleteChild(T->lchild, p, LR))
        return true;
    return DeleteChild(T->rchild, p, LR);
}

// 遍历二叉树（先序）
bool PreOrderTraverse(BiTree T)
{
    if (T == nullptr)
        return false;
    std::cout << T->data << " ";
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
    return true;
}

// 遍历二叉树（后序）
bool PostOrderTraverse(BiTree T)
{
    if (T == nullptr)
        return false;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    std::cout << T->data << " ";
    return true;
}

// 遍历二叉树（中序）
bool Traverse(BiTree T)
{
    if (T == nullptr)
        return false;
    Traverse(T->lchild);
    std::cout << T->data << " ";
    Traverse(T->rchild);
    return true;
}

#endif // BINARTREE_LIST_CPP