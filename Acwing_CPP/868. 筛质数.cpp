
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6;

int primes[N], cnt;
bool st[N]; //是否被筛掉

void get_primes_naive(int n){
    for(int i=2;i<=n;++i){
        if(st[i]) continue;
        primes[cnt++]=i;
        for(int j=i;j<=n;j+=i)
            st[j]=true;
    }
}

void get_primes_linear(int n){
    for(int i=2;i<=n;++i){
        if(!st[i]) primes[cnt++]=i;
        for(int j=0;primes[j]<=n/i;++j){
            st[primes[j]*i]=true;
            if(i%primes[j]==0) break;
        } 
    }
}

int main(){
    int n;
    scanf("%d",&n);
    get_primes_linear(n);
    printf("%d",cnt);
}