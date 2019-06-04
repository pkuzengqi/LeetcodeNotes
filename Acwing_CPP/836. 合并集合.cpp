#include<iostream>
using namespace std;
const int N=100001;

int p[N];

int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

int main(){
    int n, m;
    scanf("%d%d",&n,&m); //注意空格
    for(int i=1;i<=n;++i) p[i]=i;
    while(m--){
        char op[2];
        int a,b;
        scanf("%s%d%d",op,&a,&b); //注意op不需要取地址
        if(*op=='M') p[find(a)]=find(b);
        else find(a)==find(b)? puts("Yes"):puts("No");
    }
    return 0;
}
