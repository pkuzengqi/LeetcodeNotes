// 题目描述
// 有台奇怪的打印机有以下两个特殊要求：

// 打印机每次只能打印同一个字符序列。
// 每次可以在任意起始和结束位置打印新字符，并且会覆盖掉原来已有的字符。
// 给定一个只包含小写英文字母的字符串，你的任务是计算这个打印机打印它需要的最少次数。

// 样例
// 输入: "aaabbb"
// 输出: 2
// 解释: 首先打印 "aaa" 然后打印 "bbb"。
// 输入: "aba"
// 输出: 2
// 解释: 首先打印 "aaa" 然后在第二个位置打印 "b" 覆盖掉原来的字符 'a'。
// 提示
// 输入字符串的长度不会超过 100。




// 算法
// (动态规划) O(n^3)
// 动态规划就是状态表示，状态初始化，状态转移和结果表示

// 1. 状态表示： f(i,j)f(i,j) 表示打印区间 [i, j] 所需要的最少步数。

// 2. 状态初始化：dp[i][i] = 1,其余初始化为0。

// 3. 状态转移：

// 	首先考虑初始化将dp[i][j] = dp[i][i] + dp[i + 1][j]，代表s[i]单独打印。

// 	考虑所有的i < k < j，将区间s[i:j]拆分成s[i:k]和s[k + 1:j]两个部分。

// 	如果s[i] == s[k]，说明区间s[k]可以和s[i]同时打印，所以s[i][k] = s[i][k - 1]，那么dp[i][j] = min(dp[i][j],dp[i][k - 1] + dp[k + 1][j])。

// 	最后考虑如果s[i] = s[j]，说明s[j]可以和s[i]一起打印，那么dp[i][j] = min(dp[i][j],dp[i + 1][j])

// 4. 结果表示：dp[0][n - 1]


// 时间复杂度 O(n3)
// 状态数为 O(n2)，转移数为 O(n)，故总时间复杂度为 O(n3)。


class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> f(n + 2, vector<int>(n + 2));
        for (int len = 1; len <= n; len ++ )  //区间长度
            for (int l = 1; l + len - 1 <= n; l ++ ) //当[l,r]有效
            {
                int r = l + len - 1;
                f[l][r] = f[l + 1][r] + 1; //状态初始化，代表s[l]单独打印
                for (int k = l + 1; k <= r; k ++ ) //将区间s[i:j]拆分为s[i:k]和s[k+1:j], 
                	//如果s[l]=s[k]说明这俩字符可以同时打印（之后再被别的覆盖掉），那么dp[l][k]=dp[l][k-1]，拆解的时候可以省略掉dp[i][k]这一项
                    if (s[k - 1] == s[l - 1])
                        f[l][r] = min(f[l][r], f[l][k - 1] + f[k + 1][r]);
            }
        return f[1][n];
    }


    // 对应算法表述的版本
    int strangePrinter(string s) {
        int n = s.length();
        if(n == 0) return 0;
        int dp[n][n];
        memset(dp,0,n * n * sizeof(int));
        for(int i = 0 ; i < n ;i ++) dp[i][i] = 1;
        for(int len = 1; len < n; len ++)
        {
            for(int i = 0 ; i + len < n;i ++)
            {
                int j = i + len;
                dp[i][j] = 1 + dp[i + 1][j];
                for(int k = i + 1;k < j ; k ++)
                    if(s[i] == s[k])
                        dp[i][j] = min(dp[i][j],dp[i][k - 1] + dp[k + 1][j]);
                if(s[i] == s[j]) 
                    dp[i][j] = min(dp[i][j],dp[i + 1][j]);
            }
        }
        return dp[0][n - 1];
    }


};
