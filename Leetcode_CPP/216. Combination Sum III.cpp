// 题目描述
// 给定数字1到9，从中选 k 个数，不考虑顺序，使得它们的和等于 n，返回所有方案。
// 要求方案中不包含相同数字，且答案中不包含相同的方案。

// 样例1
// 输入：k = 3, n = 7
// 输出：[[1,2,4]]

// 样例2
// 输入：k = 3, n = 9
// 输出：[[1,2,6], [1,3,5], [2,3,4]]

// 算法
// (DFS) O(Ck9×k)

// 暴力搜索出所有从9个数中选 kk 个的方案，记录所有和等于 nn 的方案。
// 为了避免重复计数，比如 {1, 2, 3} 和 {1, 3, 2} 是同一个集合，我们对集合中的数定序，
// 每次枚举时，要保证同一方案中的数严格递增，即如果上一个选的数是 x，那我们从 x+1 开始枚举当前数。

// 时间复杂度分析：
// 从9个数中选 k个总共有 Ck9 个方案，将每个方案记录下来需要 O(k) 的时间，所以时间复杂度是 O(Ck9×k)。

// 求组合数一般要记个起始下标，求排列数一般每次从头开始枚举。


class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return ans;
    }

    void dfs(int k, int n, int start)
    {
        if (!k)
        {
            if (!n) ans.push_back(path);
            return;
        }

        for (int i = start; i <= 10 - k; i ++ ) //note：精髓在于i<=10-k
            if (n >= i)
            {
                path.push_back(i);
                dfs(k - 1, n - i, i + 1); //note: 第三个参数是为了保证单调递增
                path.pop_back();
            }
    }
};

