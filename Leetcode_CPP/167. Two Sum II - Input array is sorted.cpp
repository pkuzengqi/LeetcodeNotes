//最简单的双指针
//167. Two Sum II - Input array is sorted
//题目描述：给定一个按升序排序的数组，请找出两个数，使得它们的和等于 targettarget。
//这道题的坑是返回值是index+1


//(双指针扫描) O(n)O(n)
// 用两个指针 i,ji,j 分别从数组首尾往中间扫描，
// 每次将 ii 后移一位，然后不断前移 jj，
// 直到 numbers[i]+numbers[j]≤target为止。

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      int n=numbers.size();
      for(int i=0,j=n-1;i<j;++i){
        while(numbers[i]+numbers[j] > target) --j;
        if(numbers[i]+numbers[j]==target) return {i+1,j+1};
      }
      return {-1,-1};
    }
};