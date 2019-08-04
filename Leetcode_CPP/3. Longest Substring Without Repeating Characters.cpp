class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hash;
        int res=0;
        for(int i=0,j=0;j<s.length();++j){
            // now s[i:j] has no repeated char, move j
            if(++hash[s[j]]>1){
                // s[j] repeats, then move i to find a substring
                while(i<j && hash[s[j]]>1){
                    --hash[s[i++]];
                }
            }
            // find the current longtest substring s[i:j]
            res = max(res, j-i+1);
        }
        return res;
    }
};