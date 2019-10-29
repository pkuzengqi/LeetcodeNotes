// //207的保存路径版本

// 题目描述
// 现在一共有n门课需要学，编号从0到n-1。

// 一些课程可能有先修的要求，例如，为了修课程0，你需要先修课程1，用数对[0, 1]表示。

// 给定课程总数和一些先修要求的数对，返回一个可行的方案。

// 如果有多个可行的方案，返回任意一种；若不存在，则返回空数组。

// 注意
// 先修要求中无重复的数对。

// 样例
// Example 1:

// Input: 2, [[1,0]] 
// Output: [0,1]
// 解释: 一共需要修两门课。为了修课程1，需要先修课程0。所以可行的顺序为[0,1]。



// Example 2:

// Input: 4, [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,1,2,3] or [0,2,1,3]
// 算法
// (拓扑排序) O(n+m)O(n+m)
// 关于拓扑排序算法详见 Course Schedule 。
// 拓扑排序时用的队列的进队顺序就是一个可行的输出方案。

// 时间复杂度
// n为点数，m为边数，拓扑排序仅遍历所有的点和边一次，故总时间复杂度为O(n+m)。

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      queue<int> q; //q是处理队列
      vector<bool> st(numCourses, false); //st是每门课上了没有
      vector<int> path; //diff
      
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
        path.push_back(cur); //diff
        for (int i = 0; i < graph[cur].size(); i++) {
            in_degree[graph[cur][i]]--;
            if (in_degree[graph[cur][i]] == 0)
                q.push(graph[cur][i]);
        }
      }
      
      for(int i=0;i<numCourses;++i)
        if(!st[i]) return vector<int>{}; //diff
      return path;
    }
};

