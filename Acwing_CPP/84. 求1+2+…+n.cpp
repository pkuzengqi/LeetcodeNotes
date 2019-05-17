class Solution {
public:
    int getSum(int n) {
        int res=n;
        (n>0) && (res+=getSum(n-1));
        return res;
    }
};