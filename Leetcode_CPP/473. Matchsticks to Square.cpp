// 题目描述
// 给定一些整数，代表火柴棍的长度。求这些火柴棍是否可以组成一个正方形。火柴棍不可以拆分，但是可以拼接。

// 样例
// Input: [1,1,2,2,2]
// Output: true


// 搜索顺序：

// 依次拼正方形的每条边
// 剪枝：
// 从大到小枚举，每次剪枝去掉的分支会更多；
// 每条边内部的木棒长度规定成从大到小；
// 如果当前木棒拼接失败，则跳过接下来所有长度相同的木棒；
// 如果当前木棒拼接失败，且是当前边的第一个，则直接剪掉当前分支；
// 如果当前木棒拼接失败，且是当前边的最后一个，则直接剪掉当前分支；




class Solution {
public:

    vector<bool> st;

    bool makesquare(vector<int>& nums) {
        int sum = 0;
        for (auto num : nums) sum += num;
        if (!sum || sum % 4) return false;

        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());

        st = vector<bool>(nums.size());

        return dfs(nums, 0, 0, 0, sum / 4);
    }

    bool dfs(vector<int>& nums, int u, int cur, int start, int length)
    {
        if (u == 4) return true;
        if (cur == length) return dfs(nums, u + 1, 0, 0, length);

        for (int i = start; i < nums.size(); i ++ )
            if (!st[i] && cur + nums[i] <= length)
            {
                st[i] = true;
                if (dfs(nums, u, cur + nums[i], i + 1, length)) return true;
                st[i] = false;

                //如果当前木棒拼接失败
                while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i ++ ;
                if (!cur) return false;
                if (cur + nums[i] == length) return false;
            }

        return false;
    }
};

