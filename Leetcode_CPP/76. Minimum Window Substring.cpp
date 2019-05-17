class Solution {
public:
    string minWindow(string s, string t) {
      unordered_map<char, int> S, T;
      int total=t.size(), satisfy=0;
      string res;
      
      //ini T
      for(auto &c:t){
        ++T[c];
        if(T[c]>1) --total;
      }
      
      for(int i=0,j=0; i<s.size(); ++i){
        //change S
        ++S[s[i]];
        if(S[s[i]]==T[s[i]]) ++satisfy;
        //change j
        while(j<=i && S[s[j]]>T[s[j]]){
          --S[s[j]];
          ++j;
        }
        //change res
        if(satisfy>=total && (res.empty() || i-j+1 < res.size()))
          res = s.substr(j,i-j+1);
      }
      
      
      return res;
    }
};