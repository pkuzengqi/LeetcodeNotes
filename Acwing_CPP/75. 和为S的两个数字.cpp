75. 和为S的两个数字

class Solution {
public:
    vector<int> findNumbersWithSum(vector<int>& nums, int target) {
        unordered_set<int> h;
        for(auto x:nums)
            if(h.count(target-x)) 
                return vector<int>{x, target-x};
            else
                h.insert(x);
        
        return vector<int>();
    }
};