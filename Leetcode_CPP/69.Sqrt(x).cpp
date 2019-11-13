class Solution {
public:
    int mySqrt(int x) {
        int l=0, r=x;
        while(l<r){
            int mid = (l+ 1ll +r)/2;
            if(mid <= x / mid) l=mid;
            else r=mid-1;
        }
        return l;
    }
};
