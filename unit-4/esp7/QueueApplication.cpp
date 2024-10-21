#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    unordered_map<int, deque<int>> mp;
    for (int i = 0; i < n; i++)
        mp[a[i]].push_back(i);
    int ans = 0;
    for (auto &[x, pos] : mp)
    {
        if (pos.size() < 2)
            continue;
        while (pos.size() > 1)
        {
            int first = pos.front();
            pos.pop_front();
            for (auto second : pos)
            {
                bool judge = true;
                for (int k = first + 1; k < second; k++)
                {
                    if (a[k] < x)
                    {
                        judge = false;
                        break;
                    }
                }
                if (judge)
                {
                    ans = max(ans, second - first);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}