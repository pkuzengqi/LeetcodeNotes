#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=510, M=10010;
int n, m, k;


int dist[N], backup[N];

struct Edge{
    int a,b,w;
}edges[M];

int bellman_ford(){
    memset(dist, 0x3f, sizeof dist);
    dist[1]=0;
    
    for(int i=0;i<k;++i){
        memcpy(backup, dist, sizeof dist);
        for(int j=0;j<m;++j){
            int a=edges[j].a, b=edges[j].b, w=edges[j].w;
            if(backup[a]!=0x3f3f3f3f && dist[b]>backup[a]+w)
                dist[b]=backup[a]+w;
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    int a,b,w;
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&a,&b,&w);
        edges[i]={a,b,w};
    }
    
    int t=bellman_ford();
    if(t==-1) printf("impossible");
    else printf("%d",t);
    return 0;
}
