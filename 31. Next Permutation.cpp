class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int n=nums.size();
      if(n<=1) return;
      
      int start=-1, end=n-1;
      for(int i=n-1;i>0;--i)
        if(nums[i]>nums[i-1]) {
          start=i-1;
          break;
        }
      if(start==-1){
        for(int i=0,j=n-1;i<j;++i,--j)
          swap(nums[i],nums[j]);
        return;
      }
      
      
      for(end=start+1;end<n;++end)
        if(nums[end]<=nums[start])
          break;
      swap(nums[start],nums[end-1]);
      for(int i=start+1,j=n-1;i<j;++i,--j)
        swap(nums[i],nums[j]);
      return;
    }
};