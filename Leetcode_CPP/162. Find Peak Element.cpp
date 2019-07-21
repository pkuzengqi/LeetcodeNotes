class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size(), l=1, r=n-1;
        if(n==1|| nums[0]>nums[1]) return 0;
        while(l<r){
            int mid=(l+1ll+r)/2;
            if(nums[mid-1]<nums[mid]) l=mid;
            else r=mid-1;
        }
        return l;
    }
};