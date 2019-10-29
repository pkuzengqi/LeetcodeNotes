LeetCode 542. 01 Matrix  
BFS

题目描述
给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

样例
输入:
0 0 0
0 1 0
0 0 0

输出:
0 0 0
0 1 0
0 0 0

输入:
0 0 0
0 1 0
1 1 1

输出:
0 0 0
0 1 0
1 2 1

注意

给定矩阵的元素个数不超过 10000。
给定矩阵中至少有一个元素是 0。
矩阵中的元素只在四个方向上相邻: 上、下、左、右。

算法
(宽度优先搜索) O(nm)
定义一个队列，初始时将所有 0 元素的坐标进队；定义答案数组 dis，0 元素位置的值为 0，其余为 -1。
对这个队列开始进行宽度优先搜索，每次扩展上下左右四个方向，
若发现新的位置在 dis 中值为 -1，则更新新位置的答案为当前位置答案加 1。

时间复杂度
宽度优先搜索每个位置仅被遍历一次，故时间复杂度为 O(nm)。


class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dis(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (matrix[i][j] == 0) {
                    dis[i][j] = 0;
                    q.push(make_pair(i, j));
                }

        while (!q.empty()) {
            pair<int, int> sta = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = sta.first + dx[i], y = sta.second + dy[i];
                if (x < 0 || x >= n || y < 0 || y >= m || dis[x][y] != -1)
                    continue;

                dis[x][y] = dis[sta.first][sta.second] + 1;
                q.push(make_pair(x, y));
            }
        }

        return dis;
    }
};
