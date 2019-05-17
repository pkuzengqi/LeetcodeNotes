class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      if(strs.size()==0) return "";
      int min_len=strs[0].length();
      for(int i=1;i<strs.size();++i)
        min_len=min(min_len,int(strs[i].length()));
      
      for(int i=0; i<min_len; ++i){
        char c=strs[0][i];
        for(int j=1; j<strs.size(); ++j)
          if(strs[j][i]!=c) return strs[0].substr(0,i);
      }
      return strs[0].substr(0,min_len);
    }
};