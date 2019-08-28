class Solution {
public:
    vector<int> p; //try using vector instead of array
  
    int find(int x){
      if(p[x]!=x) p[x]=find(p[x]);
      return p[x];
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      int n=edges.size();
      for(int i=0;i<=n;++i) p.push_back(i); //note2:Every integer represented in the 2D-array will be between 1 and N,
      
      for(auto e:edges){
        int a=e[0], b=e[1];
        int pa=find(a), pb=find(b);
        if(pa==pb) return {a,b};
        p[pa]=pb;
      }
        
      return {-1,-1};
    }
};