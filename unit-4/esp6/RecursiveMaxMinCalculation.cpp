#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int r(int l, int r)
{
    return rnd() % (r - l + 1) + l;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = r(1, 10000);
    cout << "Array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    // cout << "Max: " << *max_element(a.begin(), a.end()) << endl;
    // cout << "Min: " << *min_element(a.begin(), a.end()) << endl;
    function<void(int, int, int &, int &)> MaxMin = [&](int l, int r, int &maxx, int &minn)
    {
        if (l == r)
        {
            maxx = a[l];
            minn = a[l];
            return;
        }
        else if (l + 1 == r)
        {
            maxx = max(a[l], a[r]);
            minn = min(a[l], a[r]);
            return;
        }
        int mid = (l + r) >> 1;
        int maxx1, minn1, maxx2, minn2;
        MaxMin(l, mid, maxx1, minn1);
        MaxMin(mid + 1, r, maxx2, minn2);
        maxx = max(maxx1, maxx2);
        minn = min(minn1, minn2);
        return;
    };
    int maxx = INT_MIN, minn = INT_MAX;
    MaxMin(0, n - 1, maxx, minn);
    cout << "Max: " << maxx << endl;
    cout << "Min: " << minn << endl;
}