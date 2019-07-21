class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size(), l=0, r=n-1;
        if(!n) return 0;
        while(l<r){
            int mid=(l+0ll+r)/2;
            if(citations[mid]>=n-mid) r=mid; //有(n-mid)篇的引用量大于等于citations[mid]
            else l=mid+1;
        }
        return (citations[l]>=n-l?n-l:0); //特判:全0的情况
    }
};