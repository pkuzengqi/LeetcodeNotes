class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.back()>nums[0]) return nums[0];
        int l=0, r=nums.size()-1;
        while(l<r){
            int mid=(l+0ll+r)/2;
            if(nums[mid]<nums[0]) r=mid;
            else l=mid+1;
        }
        return nums[l];
    }
};
