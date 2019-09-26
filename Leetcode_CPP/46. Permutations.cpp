// 回溯：不重复整数的全排列
// 从前往后，一位一位枚举，每次选择一个没有被使用过的数
// 选好之后，将该数的状态改成“已被使用”，同时将该数记录在相应位置上，然后递归。
// 递归返回时，不要忘记将该数的状态改成“未被使用”，并将该数从相应位置上删除。


// 复杂度：每个答案记录方案需要 O(n) 的计算量，所以总时间复杂度是 O(n×n!)

class Solution {
public:
    // st表示用没用过
    vector<bool> st;
    vector<vector<int>> ans;
    vector<int> path;
    
    vector<vector<int>> permute(vector<int>& nums) {
        //init st
        for(int i=0;i<nums.size();++i) st.push_back(false);
        dfs(nums,0);
        return ans;
    }
    
    void dfs(vector<int> &nums, int pos){
        if(pos==nums.size()){
            ans.push_back(path);
            return;
        }
        
        for(int i=0;i<nums.size();++i){
            if(!st[i]){
                st[i]=true;
                path.push_back(nums[i]);
                dfs(nums, pos+1);
                path.pop_back();
                st[i]=false;
            }
        }
    }
};