class Solution {
public:
    int consecutiveNumbersSum(int N) {
      N += N; //2N=k(2x+k-1), x为首项，k为项数
      int ans=0;
      for(int k=1; k <= N/k; ++k)
        if(N%k==0){
          int x2 = N/k +1 -k;
          if(x2%2==0 and x2>0) ++ans;
        }
      return ans;
    }
};