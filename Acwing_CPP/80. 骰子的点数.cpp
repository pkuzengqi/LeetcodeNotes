class Solution {
public:
    vector<int> numberOfDice(int n) {
        vector<int> dp(6*n+1,0);
        for(int i=1;i<=6;++i) dp[i]=1; //1st dice
        for(int i=2;i<=n;++i){ //i-th dice
            for(int j=6*i;j>=0;--j){ //update range[0,6i], not[i,6i]
                dp[j]=0;
                for(int k=6;k>=1;--k){ //current dice may be 1 to 6
                    if(j<k) continue;
                    dp[j]+=dp[j-k];
                }
            }
        }
        vector<int> res(dp.begin()+n,dp.end()); //[n,6n]
        return res;
    }
};
