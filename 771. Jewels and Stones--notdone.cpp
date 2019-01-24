/**
Example 1:
Input: J = "aA", S = "aAAbbbb"
Output: 3

Example 2:
Input: J = "z", S = "ZZ"
Output: 0
*/

//20180318
//O(MN)
class Solution {
public:
    int numJewelsInStones(string J, string S) {
    	int count=0;
        for(int i=0;i<S.length();++i){
        	if(J.find(S[i])!=string::npos) 
        		++count;
        }
        return count;
    }
};

//20180318
//O(M+N) using hast set
//这个是discuss版抄下来的，为什么实际上更低了？
int numJewelsInStones(string J, string S) {
        int res = 0;
        set<char> setJ(J.begin(), J.end());
        for (char s : S) if (setJ.count(s)) res++;
        return res;
    }
