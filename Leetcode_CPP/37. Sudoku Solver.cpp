//数独
//类似于八皇后的框架，之前的限定条件是col,row,diag,antidiag,现在的限定条件是row，col,squ
//相当于36.valid sudoku和51.n-queens的结合体


// dfs:  参数之前是(x,y,s,n), 现在只需要board和xy，
// 返回false那个位置有东西, true表示后面走得动，这一步是对的


// 一个解法
class Solution {
public:
    bool dfs(int x, int y, vector<vector<char>>& board,
            vector<int>& row, vector<int>& col, vector<int>& squ) {
        if (y == 9) {
            x++;
            y = 0;
        }
        if (x == 9)
            return true;
        if (board[x][y] == '.') {
            for (int i = 1; i <= 9; i++)
                if (! (
                    (row[x] & (1 << i)) ||
                    (col[y] & (1 << i)) ||
                    (squ[(x / 3) * 3 + (y / 3)] & (1 << i))
                    )
                   ) {
                    row[x] |= (1 << i);
                    col[y] |= (1 << i);
                    squ[(x / 3) * 3 + (y / 3)] |= (1 << i);
                    board[x][y] = i + '0';
                    if(dfs(x, y + 1, board, row, col, squ))
                        return true;
                    board[x][y] = '.';
                    row[x] -= (1 << i);
                    col[y] -= (1 << i);
                    squ[(x / 3) * 3 + (y / 3)] -= (1 << i);
                }
        }
        else {
            if (dfs(x, y + 1, board, row, col, squ))
                return true;
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {

        vector<int> row(9), col(9), squ(9);
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0';
                row[i] |= (1 << num);
                col[j] |= (1 << num);
                squ[(i / 3) * 3 + (j / 3)] |= (1 << num);
            }

        dfs(0, 0, board, row, col, squ);
    }
};
