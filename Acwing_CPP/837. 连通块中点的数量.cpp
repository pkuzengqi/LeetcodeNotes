#include<iostream>
using namespace std;
const int N=100010; // const!

int p[N], size[N];

int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) {
        p[i] = i;
        size[i] = 1;
    }

    while (m -- )
    {
        string op;
        int a, b;
        cin >> op;
        if (op == "C"){  //different input format
            cin >> a >> b;
            a = find(a);
            b = find(b);
            if(a!=b){
                p[a]=b;
                size[b]+=size[a]; //order
            }
        }
        else if (op=="Q1")
        {
            cin >> a >> b;
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
        else{
            cin >> a;
            cout<<size[find(a)]<<endl;
        }
    }

    return 0;
}

