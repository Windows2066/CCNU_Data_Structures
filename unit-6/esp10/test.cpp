#include <bits/stdc++.h>
#include "BinaryTree_list.cpp"
// #include "BinaryTree_stl.cpp"
using namespace std;
#ifdef BINARTREE_LIST_CPP
int main()
{
    BiTree T;

    // 1. 初始化二叉树
    InitBiTree(T);
    std::cout << "初始化二叉树完成。" << std::endl;

    // 2. 判断二叉树是否为空
    std::cout << "二叉树是否为空: " << (BiTreeEmpty(T) ? "是" : "否") << std::endl;

    // 3. 创建二叉树
    // 创建如下二叉树：
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    CreateBiTree(T);
    std::cout << "创建二叉树完成。" << std::endl;

    // 4. 判断二叉树是否为空
    std::cout << "二叉树是否为空: " << (BiTreeEmpty(T) ? "是" : "否") << std::endl;

    // 5. 计算二叉树的深度
    std::cout << "二叉树的深度: " << BiTreeDepth(T) << std::endl;

    // 6. 查找父节点
    std::cout << "父节点 of 4: " << Parent(T, 4) << std::endl;
    std::cout << "父节点 of 3: " << Parent(T, 3) << std::endl;
    std::cout << "父节点 of 1: " << Parent(T, 1) << std::endl; // -1

    // 7. 查找左子节点
    std::cout << "左子节点 of 2: " << LeftChild(T, 2) << std::endl;

    // 8. 查找右子节点
    std::cout << "右子节点 of 2: " << RightChild(T, 2) << std::endl;

    // 9. 查找左兄弟节点
    std::cout << "左兄弟节点 of 3: " << LeftSibling(T, 3) << std::endl;

    // 10. 查找右兄弟节点
    std::cout << "右兄弟节点 of 2: " << RightSibling(T, 2) << std::endl;

    // 11. 插入子节点
    // 插入节点6为节点3的左子节点
    BiTree node6 = new BiTNode{6, nullptr, nullptr};
    bool insertResult = InsertChild(T, 3, 0, node6);
    std::cout << "插入节点6到节点3的左子节点: " << (insertResult ? "成功" : "失败") << std::endl;

    // 12. 删除子节点
    // 删除节点2的右子节点（节点5）
    bool deleteResult = DeleteChild(T, 2, 1);
    std::cout << "删除节点2的右子节点: " << (deleteResult ? "成功" : "失败") << std::endl;

    // 此时二叉树如下：
    //        1
    //       / \
    //      2   3
    //     /   /
    //    4   6

    // 13. 遍历二叉树
    std::cout << "中序遍历二叉树: ";
    Traverse(T);
    std::cout << std::endl;

    // 14. 计算深度
    std::cout << "二叉树的深度 (更新后): " << BiTreeDepth(T) << std::endl;

    // 15. 销毁二叉树
    bool destroyResult = DestoyBiTree(T);
    std::cout << "销毁二叉树: " << (destroyResult ? "成功" : "失败") << std::endl;

    // 16. 判断二叉树是否为空 (销毁后)
    std::cout << "二叉树是否为空 (销毁后): " << (BiTreeEmpty(T) ? "是" : "否") << std::endl;

    return 0;
}
#endif
#ifdef BINARTREE_STL_CPP
int main()
{
    BiTree<int> T;

    // 1. 初始化二叉树
    T.InitBiTree();
    std::cout << "初始化二叉树完成。" << std::endl;

    // 2. 判断二叉树是否为空
    std::cout << "二叉树是否为空: " << (T.BiTreeEmpty() ? "是" : "否") << std::endl;

    // 3. 创建二叉树
    // 手动创建如下二叉树：
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    T.CreateBiTree();
    // T = new BiTNode{1, nullptr, nullptr};
    // T->lchild = new BiTNode{2, nullptr, nullptr};
    // T->rchild = new BiTNode{3, nullptr, nullptr};
    // T->lchild->lchild = new BiTNode{4, nullptr, nullptr};
    // T->lchild->rchild = new BiTNode{5, nullptr, nullptr};
    // std::cout << "创建二叉树完成。" << std::endl;

    // 4. 判断二叉树是否为空
    std::cout << "二叉树是否为空: " << (T.BiTreeEmpty() ? "是" : "否") << std::endl;

    // 5. 计算二叉树的深度
    std::cout << "二叉树的深度: " << T.BiTreeDepth() << std::endl;

    // 6. 查找父节点
    std::cout << "父节点 of 4: " << T.Parent(4) << std::endl;
    std::cout << "父节点 of 3: " << T.Parent(3) << std::endl;
    std::cout << "父节点 of 1: " << T.Parent(1) << std::endl; // -1

    // 7. 查找左子节点
    std::cout << "左子节点 of 2: " << T.LeftChild(2) << std::endl;

    // 8. 查找右子节点
    std::cout << "右子节点 of 2: " << T.RightChild(2) << std::endl;

    // 9. 查找左兄弟节点
    std::cout << "左兄弟节点 of 3: " << T.LeftSibling(3) << std::endl;

    // 10. 查找右兄弟节点
    std::cout << "右兄弟节点 of 2: " << T.RightSibling(2) << std::endl;

    // 11. 插入子节点
    // 插入节点5为节点3的左子节点
    bool insertResult = T.InsertChild(3, 0, 5);
    std::cout << "插入节点5到节点3的左子节点: " << (insertResult ? "成功" : "失败") << std::endl;

    // 12. 删除子节点
    // 删除节点2的右子节点（节点5）
    bool deleteResult = T.DeleteChild(2, 1);
    std::cout << "删除节点2的右子节点: " << (deleteResult ? "成功" : "失败") << std::endl;

    // 此时二叉树如下：
    //        1
    //       / \
    //      2   3
    //     /   /
    //    4   5

    // 13. 遍历二叉树
    std::cout << "中序遍历二叉树: ";
    T.Traverse();
    std::cout << std::endl;

    // 14. 计算深度
    std::cout << "二叉树的深度 (更新后): " << T.BiTreeDepth() << std::endl;

    // 15. 销毁二叉树
    bool destroyResult = T.DestroyBiTree();
    std::cout << "销毁二叉树: " << (destroyResult ? "成功" : "失败") << std::endl;

    // 16. 判断二叉树是否为空 (销毁后)
    std::cout << "二叉树是否为空 (销毁后): " << (T.BiTreeEmpty() ? "是" : "否") << std::endl;

    return 0;
}
#endif
