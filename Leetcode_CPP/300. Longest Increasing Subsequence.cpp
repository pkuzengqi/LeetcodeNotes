// 题目描述
// 给出一个未排序的整数数组，找出最长递增子序列的长度。

// 样例
// 输入： [10,9,2,5,3,7,101,18]
// 输出：4
// 说明：最长递增子序列为[2,3,7,101]，长度为4，可能有多个可能的最长递增子序列，此题只需要返回长度即可。


// 动态规划 O(n^2)
// 用数组dp[i]记录以nums[i]结尾的最长递增子序列的长度，
// 则递推方程为dp[i]=max(dp[j]+1)
// 其中要求1≤j<i且nums[j]<nums[i]。
// 看哪个j可以作为i的上一个数字

// 时间复杂度分析：每个i(1≤i≤n)，都需要从1遍历到i，则时间复杂度为O(n2)，
// 空间复杂度的话需要一个额外的dp数组，空间复杂度为O(n2)。

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

    	int res = 0;
        int n = nums.size();
        vector<int> f(n);

        for (int i = 0; i < n; i ++ )
        {
            f[i] = 1;
            for (int j = 0; j < i; j ++ )
                if (nums[j] < nums[i])
                    f[i] = max(f[i], f[j] + 1);
             res = max(res, f[i]);
        }

	   return res;

    }
};

