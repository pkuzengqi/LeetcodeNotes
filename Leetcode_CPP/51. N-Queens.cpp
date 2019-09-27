//N皇后：暴搜
//优化:记录每一行、每一列、每条对角线上是否有皇后存在
// 搜索时需要记录4个状态：x,y,s,nx,y,s,n，分别表示横纵坐标、已摆放的皇后个数、棋盘大小。

//对角线编码: x+y
//反对角线：n-1-x+y
//下一步(x,y+1,s+1,n)

//dfs里分两种情况，要不要踩当前点，所以先往右走（不睬的情况,s不变），
//再看有没有条件踩,有的话要s+1

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
    vector<bool> row, col, diag, anti_diag;

    vector<vector<string>> solveNQueens(int n) {
        row = col = vector<bool>(n, false);
        diag = anti_diag = vector<bool>(2 * n, false);
        path = vector<string>(n, string(n, '.'));
        dfs(0, 0, 0, n);
        return ans;
    }

    void dfs(int x, int y, int s, int n)
    {
        if (y == n) x ++ , y = 0;
        if (x == n)
        {
            if (s == n) ans.push_back(path);
            return ;
        }

        dfs(x, y + 1, s, n);
        if (!row[x] && !col[y] && !diag[x + y]
                && !anti_diag[n - 1 - x + y])
        {
            row[x] = col[y] = diag[x + y]
                = anti_diag[n - 1 - x + y] = true;
            path[x][y] = 'Q';
            dfs(x, y + 1, s + 1, n);
            path[x][y] = '.';
            row[x] = col[y] = diag[x + y]
                = anti_diag[n - 1 - x + y] = false;
        }
    }
};

