#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
const int N=110, mod = 1e9+7;

unordered_map<int,int> primes;

void get_primes(int x){
    for(int i=2;i<=x/i;++i){
        while(x%i==0){
            x/=i;
            primes[i]++;
        }
    }
    if(x>1) primes[x]++;
}

int main(){
    int n,x;
    scanf("%d",&n);
    
    while(n--){
        scanf("%d",&x);
        get_primes(x);
    }
    
    long long res=1;
    for(auto p:primes)
        res = res*(p.second+1)%mod;
    
    cout<<res<<endl;
    return 0;
}