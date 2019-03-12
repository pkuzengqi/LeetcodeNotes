class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.length(), m = num2.length();
        vector<int> a(n), b(m), c(n + m);
        for (int i = 0; i < n; i++)
            a[n - i - 1] = num1[i] - '0';
        for (int i = 0; i < m; i++)
            b[m - i - 1] = num2[i] - '0';

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                c[i + j] += a[i] * b[j];
                c[i + j + 1] += c[i + j] / 10;
                c[i + j] %= 10;
            }

        int l = n + m;
        while (l > 1 && c[l - 1] == 0) l--;
        string ans = "";
        for (int i = l - 1; i >= 0; i--)
            ans += c[i] + '0';
        return ans;
    }
};


