//20190901 只用一个hash的做法

class Solution {
public:
    string minWindow(string s, string t) {
      
      // hash[c]表示的是当前c这个字母还缺多少个，hash[s[j]] == 0 表示 s[j] 这个字母已经足够了
      
      unordered_map<char,int> hash;
      int n=s.size(), m=0, satisfy=0; //m代表t中有多少不同的字母，当satisfy=m时就可以出结果了
      string res="";
      
      // hash 用T中字母初始化
      for(auto &x:t){
        if(!hash[x]) ++m;
        ++hash[x];
      }
      
      //substring[j,i] ,以i为单位遍历
      for(int i=0,j=0;i<n;++i){
        
        //加入 s[i]，同时更新哈希表；
        --hash[s[i]];
        if(hash[s[i]]==0) ++satisfy;
        
        
        //检查 s[j] 是否多余，如果是，则移除 s[j]；
        while (satisfy == m && hash[s[j]] < 0) ++ hash[s[j ++ ]];
        
        //检查当前窗口是否已经满足T中所有字符，如果是，则更新答案；
        if(satisfy==m && (res.empty() || i-j+1<res.size())) res=s.substr(j,i-j+1);
      }
      return res;
    }
};









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