#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int N=1e5+10;
typedef pair<int, int> PII;

int n,m;
int h[N],e[N],w[N],ne[N]; 
int dist[N];
bool st[N];
int idx;

void add(int a, int b, int c){
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}

int dijkstra(){

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0,1});
    
    while(heap.size()){
        auto t=heap.top();
        heap.pop();
        
        int dis=t.first, ind=t.second;
        
        if(st[ind]) continue;
        st[ind] = true;
        
        for(int i=h[ind]; i!=-1; i=ne[i]){
            int j=e[i];
            if(dist[j]>dis+w[i]){
                dist[j]=dis+w[i];
                heap.push({dist[j],j});
            }
        }
        
        
    }
    
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
    
}

int main(){
    memset(h,-1,sizeof h);
    memset(dist, 0x3f, sizeof dist);
    dist[1]=0;
    int a,b,c;
    
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    
    printf("%d",dijkstra());
    return 0;
}