// 题目描述
// 给定不同面额的硬币和一个总金额。写函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。

// 注意
// 0 <= amount (总金额) <= 5000
// 1 <= coin (硬币面额) <= 5000
// 硬币种类不超过 500 种。
// 结果在 32 位有符号整数范围内。

// 算法
// (动态规划，完全背包) 
// 将总金额视为背包容量，将硬币的面额视为重量，价值视为 1，此题就是变种的固定容量完全背包问题。

// 设计状态 f(j)表示硬币总面额为 j时的方案数，
// 对于每一种硬币面额 coins(i)，j 从 coins(i) 枚举到 amount，累计转移 f(j)=f(j)+f(j−coins(i))。
// 初始时 f(0)=1，最终答案为 f(amount)。

// 时间复杂度
// 状态数为 O(amount)，转移总数为O(n)，每次转移的时间复杂度为 O(1)，故总时间复杂度为 O(amount⋅n)。

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> f(amount + 1); //f(j)表示硬币总面额为 j时的方案数，
        f[0] = 1;
        for (auto c : coins)
            for (int i = c; i <= amount; i ++ )
                f[i] += f[i - c];
        return f[amount];
    }
};