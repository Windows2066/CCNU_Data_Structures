#include <bits/stdc++.h>
using namespace std;

int mex(vector<int> &nums)
{
    int n = nums.size();
    // 第一步：将非正数和大于n的数替换为n+1
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] <= 0 || nums[i] > n)
        {
            nums[i] = n + 1;
        }
    }
    // 第二步：使用索引标记出现的数字
    for (int i = 0; i < n; ++i)
    {
        int num = nums[i];
        if (num >= 1 && num <= n)
        {
            if (nums[num - 1] > 0)
            {
                nums[num - 1] = -nums[num - 1];
            }
        }
    }
    // 第三步：找到第一个未被标记的位置
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] > 0)
        {
            return i + 1;
        }
    }
    // 如果所有位置都被标记，返回n+1
    return n + 1;
}

int main()
{
    vector<int> nums1 = {-5, 3, 2, 3};
    cout << "未出现的最小正整数是: " << mex(nums1) << endl; // 输出 1

    vector<int> nums2 = {1, 2, 3};
    cout << "未出现的最小正整数是: " << mex(nums2) << endl; // 输出 4

    return 0;
}