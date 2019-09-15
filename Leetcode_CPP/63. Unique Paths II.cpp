// DP: dp[i][j] = dp[i][j-1] + dp[i-1][j]
//注意dp[0][0]的初始化，还有dp要用long long
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int m=obstacleGrid.size();
      if(!m) return 0;
      int n=obstacleGrid[0].size();
      if(!n) return 0;
      
      long long dp[101][101]; 
      memset(dp,0,sizeof(dp));
      dp[0][0] = 1;
      for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
          if(obstacleGrid[i][j]==1) dp[i][j]=0;
          else {
            if(i>0) dp[i][j] += dp[i-1][j];
            if(j>0) dp[i][j] += dp[i][j-1];
          }
        }
      }
      return (int) dp[m-1][n-1];
    }
};


//这个写法是对的
// DP: dp[i][j] = dp[i][j-1] + dp[i-1][j]

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0)return 0;
        int n = obstacleGrid[0].size();
        if(n == 0)return 0;
        long long dp[101][101];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1 - obstacleGrid[0][0];
        for(int i = 0; i < m; i++){
            for(int j = 0; j< n; j++){
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else{
                    if(i > 0) dp[i][j] += dp[i-1][j];
                    if(j > 0) dp[i][j] += dp[i][j-1];
                }
            }
        }
        return (int)dp[m-1][n-1];
    }
};