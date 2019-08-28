const int N=201;
class Solution {
public:
    
    int p[N];
    
    int find(int x){
      if(p[x]!=x) p[x]=find(p[x]);
      return p[x];
    }
  
    int findCircleNum(vector<vector<int>>& M) {
      int n=M.size();
      for(int i=0;i<n;++i) p[i]=i; 
      
      for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){ //j=i+1省掉一些
          if(M[i][j]==1)
            p[find(i)]=find(j);
        }
      }
      
      int res=0;
      for(int i=0;i<n;++i)
        res += (i==find(i));
      return res;
    }
};