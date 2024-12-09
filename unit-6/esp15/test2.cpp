#include <bits/stdc++.h>
using namespace std;

bool dfs(int now, int target, vector<vector<int>> &adj, vector<bool> &vis)
{
    if (now == target)
        return true;
    vis[now] = true;
    for (int i = 0; i < adj.size(); ++i)
    {
        if (adj[now][i] && !vis[i])
        {
            if (dfs(i, target, adj, vis))
                return true;
        }
    }
    return false;
}

int main()
{
    // 示例邻接矩阵
    vector<vector<int>> adj = {{0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}, {0, 0, 0, 0}};
    int vi = 0, vj = 3;
    vector<bool> vis(adj.size(), false);
    if (dfs(vi, vj, adj, vis))
    {
        cout << "存在路径" << endl;
    }
    else
    {
        cout << "不存在路径" << endl;
    }
}