

#include<iostream>
using namespace std;
const int N=100010;

int main(){
    int n,q;
    int nums[N];
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;++i) scanf("%d",&nums[i]);
    
    while(q--){
        int k;
        scanf("%d",&k);
        
        // 二分找第一个<=target的元素
        // 用模板一，当判别条件成立时，答案在左区间并且mid也可能是答案
        // 因为分界点左边的元素满足性质，所以按[l, mid], [mid + 1, r]来划分区间
        // 退出循环时l是重复的左边界

        int l=0, r=n-1;
        while(l<r){
            int mid = (l+0ll+r)/2;
            if(nums[mid]>=k) r=mid;
            else l=mid+1;
        }
        
        
        if(nums[l]!=k) cout << "-1 -1"<< endl;
        else{
            cout <<l<< ' ';

            // 二分找最后一个<=target的元素
            // 用模板二，当判别条件成立时，答案在右区间而且mid也可能是答案
            // 因为分界点右边的元素满足性质，所以按[l,mid-1],[mid,r]来划分区间
            // 退出循环时l是重复的右边界
            r=n-1;
            while(l<r){
                int mid=(l+1ll+r)/2;
                if(nums[mid]<=k) l=mid;
                else r=mid-1;
            }
            cout<<l<<endl; //退出循环时l是右边界
        }
    }

    return 0;
}






