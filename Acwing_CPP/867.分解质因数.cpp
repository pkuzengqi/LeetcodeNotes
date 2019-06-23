#include<iostream>
#include<algorithm>
using namespace std;

void divide(int x){
    for(int i=2;i<=x/i;++i)
        if(x%i==0){
            int c=0;
            while(x%i==0){
                x/=i;
                c++;
            }
            cout<<i<<" "<<c<<endl;
        }
    if(x>1)
        cout<<x<<" "<<1<<endl;
    cout<<endl;
}

int main(){
    int n, a;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&a);
        divide(a);
    }
    return 0;
}