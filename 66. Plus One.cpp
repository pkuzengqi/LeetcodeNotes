class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int t=1;
        for(int i=digits.size()-1;i>=0;--i){
            digits[i]+=t;
            t=digits[i]/10;
            digits[i] %= 10;
        }
        if(t){
          digits.push_back(0);
          for(int i=digits.size()-2;i>=0;--i)
            digits[i+1]=digits[i];
          digits[0]=1;
        }
        return digits;
    }
};