class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(),last=0;
        vector<int> f(n);
        f[0]=0;
        for(int i=1;i<n;++i){
          while(i>last && i>last+nums[last]) ++last;
          if(i==last) return false;
          else f[i]=f[last]+1;
        }
        return true;
    }
};