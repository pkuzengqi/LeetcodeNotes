#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int N=1e5+10;

int n,m;
int h[N],e[N],w[N],ne[N],idx; 
int dist[N], cnt[N];
bool st[N];


void add(int a, int b, int c){
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}

int spfa(){
    memset(dist, 0x3f, sizeof dist);
    dist[1]=0;
    
    queue<int> q;
    for(int i=1;i<=n;++i){
        q.push(i);
        st[i]=true;
    
    }

    while(q.size()){
        auto t=q.front(); //not top()
        q.pop();
        st[t]=false; 
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if(dist[j]>dist[t]+w[i]){
                dist[j]=dist[t]+w[i];
                cnt[j] = cnt[t]+1;
                if(cnt[j]>=n) return true;
                if(!st[j]){
                    q.push(j);
                    st[j]=true;
                }
            }
        }
        
    }
    return false;
}

int main(){
    memset(h,-1,sizeof h);

    int a,b,c;
    
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    if(spfa()) printf("Yes");
    else printf("No");
    return 0;
}