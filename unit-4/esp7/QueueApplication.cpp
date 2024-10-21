#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    unordered_map<int, queue<int>> mp;
    for (int i = 0; i < n; i++)
        mp[a[i]].push(i);
    int ans = 0;
    for (auto [x, q] : mp)
    {
        if (q.size() < 2)
            continue;
        int prev = q.front();
        while (q.size() > 1)
            q.pop();
        int curr = q.front();
        ans = max(ans, curr - prev);
    }
    cout << ans << endl;
}