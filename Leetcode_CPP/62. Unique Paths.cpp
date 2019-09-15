
// DP: dp[i][j] = dp[i][j-1] + dp[i-1][j]
class Solution {
public:
    int uniquePaths(int m, int n) {  
        int dp[110][110];
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=m;++i)
            for(int j=1;j<=n;++j)
                if(i==1 || j==1)
                  dp[i][j]=1;
                else
                  dp[i][j]=dp[i][j-1]+dp[i-1][j];
        return dp[m][n];
    }  
};

// dp: 在上面基础上用滚动数组
// 注意dp数组的范围是1--n
class Solution {
public:
    int uniquePaths(int m, int n) {
      int dp[110];
      memset(dp,0,sizeof(dp));
      dp[1]=1;
      for(int i=0;i<m;++i) 
        for(int j=2;j<=n;++j)
          dp[j]+=dp[j-1];
      return dp[n];
    }
};