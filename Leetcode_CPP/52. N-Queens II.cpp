// 51题的简化版

class Solution {
public:
    int ans;
    vector<bool> row, col, diag, antidiag;
  
    int totalNQueens(int n) {
      ans = 0;
      row = col = vector<bool>(n, false);
      diag = antidiag = vector<bool>(2*n, false);
      dfs(0,0,0,n);
      return ans;
    }
    
    void dfs(int x, int y, int s, int n){
      if(y==n) ++x,y=0;
      if(x==n){
        if(s==n) ++ans;
        return;
      }
      
      dfs(x,y+1,s,n);
      if(!row[x] && !col[y] && !diag[x+y] && !antidiag[n-1-x+y]){
        row[x] = col[y] = diag[x+y] = antidiag[n-1-x+y] = true;
        dfs(x,y+1,s+1,n);
        row[x] = col[y] = diag[x+y] = antidiag[n-1-x+y] = false;
      }
    }
};