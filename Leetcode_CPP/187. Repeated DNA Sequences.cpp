class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string,int> h;
        for(int i=0;i+10<=s.size();++i)  { // why cannot i<=s.size()-10: size()是unsigned,做减法会溢出
          string str = s.substr(i,10);
          if(h[str]==1) res.push_back(str);
          h[str] ++; //not pushed item can be added
        }
        sort(res.begin(),res.end()); //why sort
        return res;
    }
};