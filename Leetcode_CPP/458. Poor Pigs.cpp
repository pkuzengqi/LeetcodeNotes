class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int t = minutesToTest/minutesToDie +1;
        int res=0, s=1;
        while(s<buckets) res++, s*=t; //t的多少次方是桶数, s是目前累乘值
        return res;
    }
};