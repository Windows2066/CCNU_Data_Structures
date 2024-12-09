#include <bits/stdc++.h>
using namespace std;

bool dfs(int now, int target, int k, vector<vector<int>> &adj, vector<bool> &vis)
{
    if (k == 0)
        return now == target;
    vis[now] = true;
    for (auto &temp : adj[now])
    {
        if (!vis[temp])
        {
            if (dfs(temp, target, k - 1, adj, vis))
                return true;
        }
    }
    vis[now] = false;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start, end, k;
    cin >> start >> end >> k;
    vector<bool> vis(n, false);
    if (dfs(start, end, k, adj, vis))
        cout << "存在路径" << endl;
    else
        cout << "不存在路径" << endl;
}