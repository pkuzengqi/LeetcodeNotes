#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> get_divisors(int x){
    vector<int> res;
    for(int i=1;i<=x/i;++i){
        if(x%i==0){
            res.push_back(i);
            if(i!=x/i)
                res.push_back(x/i);
        }
    }
    sort(res.begin(),res.end());
    return res;
}

int main(){
    int n,x;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &x);
        vector<int> res=get_divisors(x);
        for(auto x:res) cout<<x<<' ';
        cout<<endl;
    }
    return 0;
}














