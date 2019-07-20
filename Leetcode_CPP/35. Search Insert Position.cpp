class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while (l < r)
        {
            int mid = (l + 1ll + r) / 2;
            if (nums[mid] == target) return mid;
            else if(nums[mid] < target)  l = mid; 
            else r = mid-1;
        }
        return nums[l]<target? l+1:l; //l是最有可能在的位置，但不知左右
    }
};


//follow template
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty() || nums.back()<target) return nums.size();
        int l=0, r=nums.size()-1;
        while(l<r){
            int mid=(l+0ll+r)/2;
            if(nums[mid]>=target) r=mid;
            else l=mid+1;
        }
        return l;
    }
};
