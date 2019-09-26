class Solution {
public:
    // st[i] == false，表示path[i]存在
    // st[i] == true，表示path[i]不存在；
    // 当st[i] == false时，path[i]下次会被新的值覆盖掉，所以就不需要再remove了
    vector<bool> st;
    vector<int> path;
    vector<vector<int>> ans;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        st = vector<bool>(nums.size(), false);
        path = vector<int>(nums.size());
        dfs(nums, 0, 0);
        return ans;
    }

    // start: 记录上一个相同数存放的位置 start, 我们在枚举当前数时，只枚举 start+1,start+2,…,nstart+1,start+2,…,n 这些位置。
    void dfs(vector<int>& nums, int u, int start)
    {
        if (u == nums.size())
        {
            ans.push_back(path);
            return;
        }
        
        // 从左到右依次枚举每个数，每次将它放在一个空位上
        for (int i = start; i < nums.size(); i ++ )
            if (!st[i])
            {
                st[i] = true;
                path[i] = nums[u];
                if (u + 1 < nums.size() && nums[u + 1] != nums[u])
                    dfs(nums, u + 1, 0);
                else
                    dfs(nums, u + 1, i + 1);
                st[i] = false;
            }
    }
};

