class Solution {
public:
    vector<char> num2char[10];
    vector<string> res;
    
    vector<string> letterCombinations(string digits) {
        
        if(digits=="") return res;
        
        // init digit
        char cur='a';
        for(int i=2;i<10;++i){
            for(int j=0;j<3;++j) num2char[i].push_back(cur++);
            if(i==7 ||i==9) num2char[i].push_back(cur++);
        }
        
        dfs(digits, 0, "");
        return res;
    }
    
    void dfs(string digits, int d, string cur){
        if(d == digits.length()){
            res.push_back(cur);
            return;
        }
        int num = digits[d] - '0';
        for(int i=0;i<num2char[num].size();++i)
            dfs(digits, d+1, cur+num2char[num][i]);
    }
};