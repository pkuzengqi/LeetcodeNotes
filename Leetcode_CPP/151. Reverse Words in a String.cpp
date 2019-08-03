class Solution {
public:
    string reverseWords(string s) {
        int k=0; //k 代表有效字符个数
        
        for(int i=0;i<s.size();){
            int j = i; //i代表未处理的起点
            while (j < s.size() && s[j] == ' ') j ++ ; //找空格
            if (j == s.size()) break;
            i = j; //i代表未处理的第一个非空格
            while (j < s.size() && s[j] != ' ') j ++ ; // 找到字符串s[i:j]
            reverse(s.begin() + i, s.begin() + j); //翻转当前字符串s[i:j]
            if (k) s[k ++ ] = ' '; //当前字符串前面补一个空格
            while (i < j) s[k ++ ] = s[i ++ ]; //把当前字符串s[i:j]移动上来, 从k开始
        }
        
        s.erase(s.begin() +k, s.end()); //删掉多余的空格
        reverse(s.begin(), s.end()); //翻转整个字符串
        return s;
    }
};