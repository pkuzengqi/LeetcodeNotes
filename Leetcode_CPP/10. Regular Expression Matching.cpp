// 正则表达式匹配：动态规划

// 给定一个字符串s和模板串p，实现支持通配符'.'和'*'的正则表达式匹配。
// '.' : 可以匹配任意单个字符
// '*' : 表示0个或任意多个前一个字符
// 模板串需要匹配整个字符串。
// 模板串p一定合法，即'*'前面一定有非'*'字符。


// 状态表示：f[i][j]表示p从j开始到结尾，是否能匹配s从i开始到结尾

// 状态转移：
// 如果p[j+1]不是通配符'*'，则f[i][j]是真，当且仅当s[i]可以和p[j]匹配，且f[i+1][j+1]是真；
// 如果p[j+1]是通配符'*'，则下面的情况只要有一种满足，f[i][j]就是真；
// 		f[i][j+2]是真； -->代表0个枚举
// 		s[i]可以和p[j]匹配，且f[i+1][j]是真；-->后面的枚举

// 第1种情况下的状态转移很好理解，那第2种情况下的状态转移怎么理解呢？
// 最直观的转移方式是这样的：枚举通配符'*'可以匹配多少个p[j]，只要有一种情况可以匹配，则f[i][j]就是真；
// 这样做的话，我们发现，f[i][j]除了枚举0个p[j]之外，其余的枚举操作都包含在f[i+1][j]中了，所以我们只需判断
// f[i+1][j]是否为真，以及s[i]是否可以和p[j]匹配即可。

// 时间复杂度分析：n表示s的长度，m表示p的长度，总共 nm个状态，状态转移复杂度 O(1)，所以总时间复杂度是 O(nm).

class Solution {
public:
    vector<vector<int>>f;
    int n, m;

    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();
        f = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
        return dp(0, 0, s, p);
    }

    bool dp(int x, int y, string &s, string &p)
    {
    	//f[i][j]表示s[i:]能否匹配p[j:]
        if (f[x][y] != -1) return f[x][y];
        if (y == m)
            return f[x][y] = x == n; //返回f[x][y]的值(x==n)

        //first_match表示s[x]和p[j]能否匹配
        bool first_match = x < n && (s[x] == p[y] || p[y] == '.');
        bool ans;

        if (y + 1 < m && p[y + 1] == '*')
        {
            ans = dp(x, y + 2, s, p) || first_match && dp(x + 1, y, s, p);
        }
        else
            ans = first_match && dp(x + 1, y + 1, s, p);

        return f[x][y] = ans;
    }
};

