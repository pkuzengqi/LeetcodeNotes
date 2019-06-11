// dfs

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
      if(grid.size()==0) return 0;
      int count=0;
      for(int i=0;i<grid.size();++i){
        for(int j=0;j<grid[0].size();++j){
          if(grid[i][j]=='1'){
            ++count;
            dfs(grid,i,j);
          }
        }
      }
      return count;
      
    }
    void dfs(vector<vector<char>>& grid,int i,int j){
        grid[i][j]='0';
        int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
        for(int k=0;k<4;++k){
          int x=i+dx[k],y=j+dy[k];
          if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]=='1'){
            dfs(grid,x,y);
          }
        }
      }
      
    
};



// union find

const int N = 1e5+10;

class Solution {
public:
    int p[N];
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
  
    int find(int x){
      if(x!=p[x]) p[x]=find(p[x]);
      return p[x];
    }
  
    int numIslands(vector<vector<char>>& grid) {
      int m = grid.size();
      if(m==0) return 0;
      int n = grid[0].size();
      
      //init
      for(int i=0;i<m*n;++i) p[i]=i; 
      
      // union
      for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j){
          int fla_ij=i*n+j; //flatten (i,j)
          if(grid[i][j]=='1'){
            for(int k=0;k<4;++k){
              int x=i+dx[k], y=j+dy[k], fla_xy=x*n+y;
              if(x>=0 && x<m && y>=0 && y<n && grid[x][y]=='1')
                p[find(fla_ij)]=find(fla_xy); 
            }
          }
        }
      
      // how many root
      int res=0;
      for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j){
          int fla_ij=i*n+j; //flatten (i,j)
          if(grid[i][j]=='1' && find(fla_ij)==fla_ij )
            ++res;
        } 
      
      return res;
      
    }
};

