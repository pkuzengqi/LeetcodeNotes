class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
      int n=grid.size();
      int xy=0,xz=0,yz=0;
      // xy是非零个数，xz是每列max的和，yz是每行max的和
      for(int i=0;i<n;++i){
        int max_row=0,max_col=0;
        for(int j=0;j<n;++j){
          if(grid[i][j] >0) ++xy; 
          if(grid[i][j]>max_row) max_row=grid[i][j];
          if(grid[j][i]>max_col) max_col=grid[j][i]; //利用方阵同时访问ij和ji
        }
        xz+=max_col;
        yz+=max_row;
      }
      return xy+xz+yz;
    }
};