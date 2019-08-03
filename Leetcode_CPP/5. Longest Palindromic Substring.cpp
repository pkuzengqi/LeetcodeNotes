class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        string res;
        int i,j,k,cur_max=0;
        for(i=0;i<n;++i){
            
            // single center [i-j,...,i,...,i+j]
            for(j=0; i-j>=0 &&i+j<n; ++j)
                if(s[i-j]!=s[i+j]) break;
                else if(2*j+1>cur_max){
                    res=s.substr(i-j, j*2+1);
                    cur_max=2*j+1;
                }
            
            // double center [j,...,i,i+1,...,k]
            for(j=i, k=i+1; j>=0 &&k<n; --j,++k)
                if(s[j]!=s[k]) break;
                else if(k-j+1 >cur_max){
                    res=s.substr(j, k-j+1);
                    cur_max=k-j+1;
                }
            
        }
        return res;
    }
};