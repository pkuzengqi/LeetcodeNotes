class Solution {
public:
    int search(vector<int>& nums, int target) {
      int n=nums.size();
      if(n==0) return -1;
      int l=0,r=n-1,mid=0;
      while(l<r){
        mid=l+r>>1;
        if(nums[mid]>=nums[0]){ //0--mid--/--
          if(target>nums[mid] || target<nums[0]) l=mid+1;
          if(target>=nums[0] && target <= nums[mid]) r=mid;
        } 
        else{ //0--/--mid--
          if(target<=nums[mid] || target>=nums[0]) r=mid;
          if(target<nums[0] && target>nums[mid]) l=mid+1;
        }
      }
      return nums[l]==target?l:-1;
    }
};


// 两次二分 应用模板

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int l = 0, r = nums.size() - 1;
        
        if(nums.back()<=nums[0]){
            // first search to get break point l: same as leetcode 153
            while (l < r)
            {
                int mid=(l+0ll+r)/2;
                if(nums[mid]<nums[0]) r=mid;
                else l=mid+1;
            }
            
            //determine which part to search
            if(target<nums[0]) r=nums.size()-1;
            else r=l-1, l=0;
        }
        

        
        // second search to get target: similar to leetcode 74
        while(l<r){
            int mid = (l+1ll+r)/2;
            if(nums[mid]<=target) l=mid;
            else r=mid-1;
        }
        return target==nums[l]?l:-1;
    }
};
