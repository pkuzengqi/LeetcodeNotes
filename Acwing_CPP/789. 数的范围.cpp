

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
        
        // 二分

        int l=0, r=n-1;
        while(l<r){
            int mid = (l+0ll+r)/2;
            if(nums[mid]>=k) r=mid;
            else l=mid+1;
        }
        
        
        if(nums[l]!=k) cout << "-1 -1"<< endl;
        else{
            cout <<l<< ' ';
            //退出循环时l是左边界,需要二分寻找右边界
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






