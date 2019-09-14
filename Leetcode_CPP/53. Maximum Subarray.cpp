
// 动态规划O(n)
//  f(i) 表示以第 i个数字为结尾的最大连续子序列的 和 是多少
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int n=nums.size();
    
      vector<int> f(n+1);
      f[0]=nums[0];
      int res=f[0];
      
      for(int i=1;i<n;++i){
        f[i]=max(f[i-1]+nums[i],nums[i]);
        res = max(f[i],res);
      }
      return res;
    }
};


//分治 O(nlogn)
// 考虑区间 [l, r] 内的答案如何计算，令 mid = (l + r) / 2，则该区间的答案由三部分取最大值，分别是：
// (1). 区间 [l, mid] 内的答案（递归计算）。
// (2). 区间 [mid + 1, r] 内的答案（递归计算）。
// (3). 跨越 mid和mid+1 的连续子序列。
// 其中，第(3)部分只需要从 mid 开始向 l 找连续的最大值，以及从 mid+1 开始向 r 找最大值即可，在线性时间内可以完成。
// 递归终止条件显然是 l==r ，此时直接返回 nums[l]。

class Solution {
public:
    int calc(int l, int r, vector<int>& nums) {
        if (l == r)
            return nums[l];
        int mid = (l + r) >> 1;
        int lmax = nums[mid], lsum = 0, rmax = nums[mid + 1], rsum = 0;
        for (int i = mid; i >= l; i--) {
            lsum += nums[i];
            lmax = max(lmax, lsum);
        }
        for (int i = mid + 1; i <= r; i++) {
            rsum += nums[i];
            rmax = max(rmax, rsum);
        }
        return max(max(calc(l, mid, nums), calc(mid + 1, r, nums)), lmax + rmax);
    }

    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        return calc(0, n - 1, nums);
    }
};

