class Solution {
public:
    
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