class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int n=nums.size();
    
      vector<int> f(n+1);
      f[0]=nums[0];
      int res=f[0];
      
      for(int i=1;i<n;++i){
        f[i]=max(f[i-1]+nums[i],nums[i]);
        res = max(f[i],res);
      }
      return res;
    }
};