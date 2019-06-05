
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 50010;

int p[N], d[N]; //d代表到根节点距离，用模三代表ABC三类，余0代表和跟是同类，余1代表可以吃根，余2代表被根吃

int find(int x)
{
    if (p[x] != x) //模板里就是if不是while
    {
        int u = find(p[x]); //祖先的祖先
        d[x] += d[p[x]]; //更新父节点所以更新到根节点的距离
        p[x] = u;
    }
    return p[x];
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++ ) p[i] = i; //d是全局变量 默认为0

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
            if (pa == pb && (d[a] - d[b]) % 3) res ++ ; //余数为0是同类，pa=pb代表是已知树
            if (pa != pb) //新知识
            {
                p[pa] = pb;
                d[pa] = d[b] - d[a]; //把pa和pb连一起，但不知道pa和pb之间的关系，由ab同类得(da+?-db)%3=0,
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

