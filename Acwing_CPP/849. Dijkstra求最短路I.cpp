#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=510;

int g[N][N];
int dist[N];
bool st[N];
int n, m;

int dijsktra(){
    memset(dist, 0x3f, sizeof dist); 
    dist[1]=0;
    
    for(int i=0;i<n-1;++i){
        int t=-1;
        
        for(int j=1;j<=n;++j)
            if(!st[j] && (t==-1 || dist[t]>dist[j]))
                t=j;
                
        for(int j=1;j<=n;++j)
            dist[j]=min(dist[j], dist[t]+g[t][j]);
        st[t]=true;
    }
    return (dist[n]==0x3f3f3f3f? -1:dist[n]);
    
}

int main(){
    int a, b, c;
    scanf("%d%d",&n,&m);
    memset(g,0x3f, sizeof g);
    while(m--){
        scanf("%d%d%d",&a,&b,&c);
        g[a][b]=min(c,g[a][b]); 
    }
    printf("%d\n",dijsktra());
    return 0;
}