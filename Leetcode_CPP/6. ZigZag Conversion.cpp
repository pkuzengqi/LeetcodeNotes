class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        string res;
        int n=s.length();
        
        for(int j=0; j<numRows;++j){
            
            if(j==0||j==numRows-1){
                for(int i=j;i<n;i+=2*numRows-2)
                    res+=s[i];
            }
            else{
                for(int i=j,k=numRows*2-2-j; i<n ||k<n; i+=2*numRows-2, k+=2*numRows-2){
                    if(i<n) res+=s[i];
                    if(k<n) res+=s[k];
                }
            }
        }
        
        return res;
    }
};