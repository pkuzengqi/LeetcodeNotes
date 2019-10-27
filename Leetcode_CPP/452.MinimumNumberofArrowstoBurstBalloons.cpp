// 贪心：求不相交区间

// 题目描述
// 有nn个气球，每个气球用一个区间[x_start, x_end]表示，气球之间可能有重叠。
// 一个飞镖可以发射到位置x，其可以戳破满足x_start <= x <= x_end的所有气球。
// 气球最多有104104个。

// 返回最少的飞镖数，使得能戳破所有气球。

// 样例
// Input:
// [[10,16], [2,8], [1,6], [7,12]]

// Output:
// 2

// 解释:
// 一种方式是发射 x = 6 和 x = 11 两个飞镖。


// 算法
// (排序贪心) O(nlogn)
// 此题可以考虑将区间求交集，最后必定是一些不重叠的独立的区间，独立的区间个数就是答案数。具体做法如下：

// 首先将区间按照左端点从小到大排序，左端点相同的按照右端点从小到大排序。
// 设立两个值start和end代表当前飞镖可以放置的范围。
// 每当遇到一个新区间，若end小于新区间的起点，则需要一个新飞镖。否则原飞镖的区间start和新区间的起点取最大值，end和新区间的终点取最小值，即求交集。

// 时间复杂度
// 对所有区间排序一次，遍历一次，故总时间复杂度为O(nlogn)。


bool cmp(vector<int> a, vector<int> b){
  return a[1] < b[1];
} 

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
      sort(points.begin(), points.end(), cmp);
      long long res=0, r=INT_MIN - 1ll;
      for(auto &p:points)
        if(p[0] > r){
          r = p[1];
          ++res;
        }
      return res;
    }
};