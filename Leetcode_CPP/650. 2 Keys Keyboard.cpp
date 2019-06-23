class Solution {
public:
    int minSteps(int n) {
        int i=2, ans=0;
        while(n>1){
          while(n%i==0) n/=i,ans+=i;
          ++i;
        }
        return ans;
    }
};