
// 91. Decode Ways
// 题目：

// DP: f[i]表示前i个数字有多少种解码方式
// 转移方程： 如果i是1-9，则可以解码成单独一个字母，则方案数f[i-1]；
//如果i-1和i可以组合为10-26，则方案数f[i-2]

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i ++ )
        {
            if (s[i - 1] < '0' || s[i - 1] > '9')
                return 0;
            f[i] = 0;
            if (s[i - 1] != '0') f[i] = f[i - 1];
            if (i > 1)
            {
                int t = (s[i-2]-'0')*10+s[i-1]-'0';
                if (t >= 10 && t <= 26)
                    f[i] += f[i - 2];
            }
        }
        return f[n];
    }
};

