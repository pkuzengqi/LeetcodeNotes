#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int N=210, INF=1e9+10;

int n,m,Q;
int d[N][N];

void floyd(){
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}

int main(){
    scanf("%d%d%d", &n, &m, &Q);
    
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            d[i][j] = (i==j?0:INF);
         
    int a,b,c;   
    while(m--){
        scanf("%d%d%d", &a, &b, &c);
        d[a][b] = min(d[a][b],c);
    }
    
    floyd();
    
    while(Q--){
        scanf("%d%d", &a, &b);
        c=d[a][b];
        if(c>INF/2) printf("impossible\n");
        else printf("%d\n",c);
    }
    return 0;
}