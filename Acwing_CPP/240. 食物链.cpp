
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 50010;

int p[N], d[N]; //d代表ABC三类

int find(int x)
{
    if (p[x] != x) //why not while
    {
        int u = find(p[x]); //祖先的祖先
        d[x] += d[p[x]]; //
        p[x] = u;
    }
    return p[x];
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++ ) p[i] = i; //d数组的初始化呢

    int res = 0;
    while (m -- )
    {
        int t, a, b;
        scanf("%d%d%d", &t, &a, &b);

        if (a > n || b > n) //  当前的话中X或Y比N大，就是假话
        {
            res ++ ;
            continue;
        }

        int pa = find(a), pb = find(b);
        if (t == 1) //X和Y是同类
        {
            if (pa == pb && (d[a] - d[b]) % 3) res ++ ; //
            if (pa != pb)
            {
                p[pa] = pb;
                d[pa] = d[b] - d[a];
            }
        }
        else //X吃Y
        {
            if (pa == pb && ((d[a] - d[b]) % 3 + 3) % 3 != 1) res ++ ; //余数为1说明可吃
            if (pa != pb)
            {
                p[pa] = pb;
                d[pa] = d[b] - d[a] + 1;
            }
        }
    }

    printf("%d\n", res);
    return 0;
}

