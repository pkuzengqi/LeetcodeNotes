class Solution {
public:
    int longestValidParentheses(string s) {
      int n=s.size(), val=0, i=0, j=0, res=0;
      
      //substr [j,i] , move i=0 --> n-1
      for(i=0,j=0;i<n;++i){
        if(s[i]=='(') ++val; else --val;
        
        if(val==0) res=max(res, i-j+1);
        else if(val<0) {j=i+1;val=0;}
        
      }
      
      //substr [i,j], move i=n-1 -->0
      for(i=n-1,j=n-1,val=0; i>=0; --i){
        if(s[i]==')') ++val; else --val;
        if(val==0) res=max(res, j-i+1);
        else if(val<0) {j=i-1;val=0;}
      }
      
      return res;
    }
};