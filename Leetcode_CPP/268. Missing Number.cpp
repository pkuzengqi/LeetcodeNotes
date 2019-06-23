class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int n=nums.size();
      long long sum=0, m=n*(n+1)/2;
      for(auto x:nums) sum+=x;
      return (int) m-sum;
    }
};