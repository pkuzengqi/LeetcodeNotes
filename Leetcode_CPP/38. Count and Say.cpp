class Solution {
public:
    string countAndSay(int n) {
        string last = "1";
        for(int i=2;i<=n;++i){
            string curr = "";
            int count = 0, m=last.length();
            for(int j=0;j<m;++j){
                count++;
                if(j==m-1 || last[j]!=last[j+1]){
                    curr += to_string(count) + last[j];
                    count = 0;
                }
            }
            last = curr;
        }
        return last;
    }
};