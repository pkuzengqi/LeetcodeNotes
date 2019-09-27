// 考点：集合的二进制表示
// 题目：给定一个集合，包含互不相同的数，返回它的所有子集（幂集）。
// i的取值范围是0到2^n， 每一个i表示一种path
// j的取值范围是0到n，每一个j代表这一位要不要加进当前path


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> ans;
      int n=nums.size();
      
      for(int i=0;i<(1<<n);++i){
        vector<int> tmp;
        for(int j=0;j<n;++j)
          if(i>>j & 1) tmp.push_back(nums[j]);
        ans.push_back(tmp);
      }
      
      return ans;
    }
};