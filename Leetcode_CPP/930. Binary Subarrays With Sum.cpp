class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
      int n = A.size(), res = 0;
      vector<int> sum(n+1,0), f(n+1,0); //sum是前缀和，f[i] 记录前面有多少个和为i的前缀
      
      for(int i=1;i<=n;++i) sum[i]=sum[i-1]+A[i-1]; //sum[i]不包含A[i]
      f[0]=1;
      
      for(int i=1;i<=n;++i){
        int x = sum[i];
        if(x>=S) res+=f[x-S];
        f[x]++;
      }
      
      return res;
    }
};