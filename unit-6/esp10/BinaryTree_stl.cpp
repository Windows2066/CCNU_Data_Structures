#include <iostream>
#include <vector>
#include <functional>
#ifndef BINARTREE_STL_CPP
#define BINARTREE_STL_CPP

template <typename T>
struct BiTree
{
    std::vector<std::vector<std::pair<T, char>>> tr;
    BiTree() {};
    BiTree(int n)
    {
        tr.resize(n + 1);
    }
    void InitBiTree()
    {
        tr.clear();
    }
    bool DestroyBiTree()
    {
        tr.clear();
        return true;
    }
    bool CreateBiTree()
    {
        std::cout << "请输入节点个数：" << std::endl;
        int n;
        std::cin >> n;
        tr.resize(n + 1);
        std::cout << "请输入节点信息：(fa,val,l/r)" << std::endl;
        for (int i = 1; i < n; ++i)
        {
            int u, v;
            char lr;
            std::cin >> u >> v >> lr;
            tr[u].push_back({v, lr});
        }
        return true;
    }
    bool BiTreeEmpty()
    {
        bool flag = true;
        for (auto &v : tr)
        {
            if (!v.empty())
            {
                flag = false;
                break;
            }
        }
        return flag;
    }
    int BiTreeDepth()
    {
        if (tr.empty() || tr[1].empty())
        {
            return 0;
        }
        std::function<int(int, int)> depth = [&](int u, int d) -> int
        {
            int maxDepth = d;
            for (auto &[v, c] : tr[u])
            {
                maxDepth = std::max(maxDepth, depth(v, d + 1));
            }
            return maxDepth;
        };
        return depth(1, 1);
    }
    int Parent(int e)
    {
        for (int i = 1; i < tr.size(); ++i)
        {
            for (auto [v, c] : tr[i])
            {
                if (v == e)
                {
                    return i;
                }
            }
        }
        return -1;
    }
    int LeftChild(int e)
    {
        if (tr[e].size() > 0)
        {
            if (tr[e][0].second == 'l')
            {
                return tr[e][0].first;
            }
            if (tr[e].size() > 1 && tr[e][1].second == 'l')
            {
                return tr[e][1].first;
            }
        }
        return -1;
    }
    int RightChild(int e)
    {
        if (tr[e].size() > 0)
        {
            if (tr[e][0].second == 'r')
            {
                return tr[e][0].first;
            }
            if (tr[e].size() > 1 && tr[e][1].second == 'r')
            {
                return tr[e][1].first;
            }
        }
        return -1;
    }
    int LeftSibling(int e)
    {
        int p = Parent(e);
        if (p != -1)
        {
            int lc = LeftChild(p);
            return lc;
        }
        return -1;
    }
    int RightSibling(int e)
    {
        int p = Parent(e);
        if (p != -1)
        {
            int rc = RightChild(p);
            return rc;
        }
        return -1;
    }
    bool InsertChild(int p, int lr, int e)
    {
        if (lr == 0) // 左孩子
        {
            if (tr[p].size() > 0)
            {
                if (tr[p][0].second == 'l')
                {
                    return false;
                }
                if (tr[p].size() > 1 && tr[p][1].second == 'l')
                {
                    return false;
                }
                tr[p].push_back({e, 'l'});
            }
            else
            {
                tr[p].push_back({e, 'l'});
            }
        }
        else // 右孩子
        {
            if (tr[p].size() > 0)
            {
                if (tr[p][0].second == 'r')
                {
                    return false;
                }
                if (tr[p].size() > 1 && tr[p][1].second == 'r')
                {
                    return false;
                }
                tr[p].push_back({e, 'r'});
            }
            else
            {
                tr[p].push_back({e, 'r'});
            }
        }
        return true;
    }
    bool DeleteChild(int p, int lr)
    {
        if (lr == 0) // 左孩子
        {
            if (tr[p].size() > 0)
            {
                if (tr[p][0].second == 'l')
                {
                    tr[p].erase(tr[p].begin());
                }
                if (tr[p].size() > 1 && tr[p][1].second == 'l')
                {
                    tr[p].erase(tr[p].begin() + 1);
                }
            }
        }
        else // 右孩子
        {
            if (tr[p].size() > 0)
            {
                if (tr[p][0].second == 'r')
                {
                    tr[p].erase(tr[p].begin());
                }
                if (tr[p].size() > 1 && tr[p][1].second == 'r')
                {
                    tr[p].erase(tr[p].begin() + 1);
                }
            }
        }
        return true;
    }
    bool Traverse()
    {
        // 首先，按 'l' < 'r' 排序每个节点的子节点
        for (int i = 1; i < tr.size(); i++)
        {
            if (tr[i].size() > 0)
            {
                std::sort(tr[i].begin(), tr[i].end(), [&](const std::pair<int, char> &a, const std::pair<int, char> &b) -> bool
                          {
                              return a.second < b.second; // 'l' 排在前面，'r' 排在后面
                          });
            }
        }

        // 定义中序遍历的递归 lambda 函数
        std::function<void(int)> inOrderDFS = [&](int node) -> void
        {
            if (node == -1)
                return;

            int leftChild = -1;
            int rightChild = -1;

            // 遍历当前节点的子节点，找到左子节点和右子节点
            for (auto &child : tr[node])
            {
                if (child.second == 'l')
                    leftChild = child.first;
                else if (child.second == 'r')
                    rightChild = child.first;
            }

            // 先遍历左子节点
            if (leftChild != -1)
                inOrderDFS(leftChild);

            // 访问当前节点
            std::cout << node << " ";

            // 再遍历右子节点
            if (rightChild != -1)
                inOrderDFS(rightChild);
        };

        // 假设根节点的编号为 1
        // std::cout << "中序遍历结果: ";
        inOrderDFS(1);
        // std::cout << std::endl;

        return true;
    }
};

#endif // BINARTREE_STL_CPP