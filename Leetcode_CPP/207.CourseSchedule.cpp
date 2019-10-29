// 拓扑排序
// https://www.jianshu.com/p/b59db381561a


// 题目描述
// 现在一共有n门课需要学，编号从0到n-1。

// 一些课程可能有先修的要求，例如，为了修课程0，你需要先修课程1，用数对[0, 1]表示。

// 给定课程总数和一些先修要求的数对，问是否有可能学完所有课程？

// 注意
// 先修要求中无重复的数对。
// 样例
// Example 1:

// Input: 2, [[1,0]] 
// Output: true
// 解释: 一共需要修两门课。为了修课程1，需要先修课程0。所以是可能的。


// Example 2:

// Input: 2, [[1,0],[0,1]]
// Output: false
// 解释: 一共需要修两门课。为了修课程1，需要先修课程0，但为了修课程0，需要先修课程1。所以是不可能的。


// 算法
// (拓扑排序) O(n+m)
// 将先修关系构成一张图，由每个数对的第二个数字向第一个数字连边。
// 首先将所有入度为0的点进队，准备拓扑排序。
// 宽搜过程中，将当前结点所关联的结点的入度减1；若发现新的入度为0的结点，则将其进队。
// 最后如果遍历了所有结点，则说明可以满足要求；否则，先修关系存在环。


// 时间复杂度
// nn为点数，mm为边数，拓扑排序仅遍历所有的点和边一次，故总时间复杂度为O(n+m)。



class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      queue<int> q; //q是处理队列
      vector<bool> st(numCourses, false); //st是每门课上了没有
      
      vector<vector<int>> graph(numCourses); //拓扑排序需要的图
      vector<int> in_degree(numCourses,0); //拓扑排序需要的入度（入度为0才能进队列被处理）
      for(auto &p:prerequisites){
        graph[p[1]].push_back(p[0]);
        ++in_degree[p[0]];
      }
      
      for(int i=0;i<numCourses;++i)
        if(in_degree[i]==0) q.push(i);
      
      while(!q.empty()){
        int cur = q.front();
        q.pop();
        st[cur] = true;
        for (int i = 0; i < graph[cur].size(); i++) {
            in_degree[graph[cur][i]]--;
            if (in_degree[graph[cur][i]] == 0)
                q.push(graph[cur][i]);
        }
      }
      
      for(int i=0;i<numCourses;++i)
        if(!st[i]) return false;
      return true;
    }
};