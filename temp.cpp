867.分解质因数.cpp


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

868. 筛质数.cpp


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

869.试除法求约数.cpp


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














