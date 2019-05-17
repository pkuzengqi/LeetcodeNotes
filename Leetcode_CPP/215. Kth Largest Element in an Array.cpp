class Solution {
public:
  int solve(int l, int r, vector<int>& nums, int k){
    if(l==r) return nums[l];
    int i=l, j=r, pivot=nums[l];
    while(i<j){
      while(i<j && nums[j]<pivot) --j;
      if(i<j) nums[i++]=nums[j];
      
      while(i<j && nums[i]>=pivot) ++i;
      if(i<j) nums[j--]=nums[i];
    }
    if(i+1==k) return pivot;
    else if(i+1>k) return solve(l,i-1,nums,k);
    else  return solve(i+1,r,nums,k);
  }
  int findKthLargest(vector<int>& nums, int k) {
    int n=nums.size();
    return solve(0,n-1,nums,k);
  }
};
