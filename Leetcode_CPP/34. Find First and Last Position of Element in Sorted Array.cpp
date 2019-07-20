class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(!n) return vector<int>({-1,-1});
        int start=0, end=0, l=0, r=n-1;
        
        while(l<r){
            int mid=(l+0ll+r)/2;
            if(nums[mid]>=target) r=mid;
            else l=mid+1;
        }
        start=l;
        if(nums[l]!=target) return vector<int>({-1,-1});
        
        r=n-1;
        while(l<r){
            int mid=(l+1ll+r)/2;
            if(nums[mid]<=target) l=mid;
            else r=mid-1;
        }
        end=l;
        return vector<int>({start,end});
    }
};
