0. 输入输出
cin cout 代码简单速度慢
scanf printf 速度快

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 加速cin/cout，限制：不能再使用scanf/printf了
    
    // 当输入输出的规模 >= 1000000，建议用scanf/printf，否则建议用cin/cout
    
    cin / cout  // 好处：代码简单，坏处：速度慢
        
    
    scanf/printf  //  好处：速度快， 坏处：难写
}


1， 位运算

源码  
反码 
补码 取反加一


（1）求n的第k位数字: n >> k & 1

（2）返回n的最后一位1：lowbit(n) = n & -n
负数就是按位取反再+1
lowbit输入1010返回10
应用：统计x里1的次数
#include <iostream>

using namespace std;

int lowbit(int x)
{
    return x & -x;
}

int main()
{
    int n;
    cin >> n;
    while (n -- )
    {
        int x;
        cin >> x;
        
        int res = 0;
        while (x) x -= lowbit(x), res ++ ; // 每次减去x的最后一位1
        
        cout << res << ' ';
    }
    
    return 0;
}

2. 双指针算法
	for (int i = 0, j = 0; i < n; i ++ )
	{
		while (j < i && check(i, j)) j ++ ;
		
		// 具体问题的逻辑
	}

常见问题分类：
	(1) 对于一个序列，用两个指针维护一段区间
	(2) 对于两个序列，维护某种次序，比如归并排序中合并两个有序序列的操作
核心思想：
	把O(n^2)的double for loop的暴力做法优化到O(n)，只有O(n)个状态
思路：
先想朴素算法，然后找i/j的规律单调性，

一维的例子：找一个字符串中的用空格隔开的单词

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str[1000];
    
    gets(str);
    
    int n = strlen(str);
    
    for (int i = 0; i < n; i ++ )
    {
        int j = i;
        while (j < n && str[j] != ' ') j ++ ;
        
        // 这道题的具体逻辑
        for (int k = i; k < j; k ++ ) cout << str[k];
        cout << endl;
        
        i = j;
    }
    
    return 0;
}

另一个例子：
#include <iostream>

using namespace std;

const int N = 100010;

int n;
int a[N], s[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    
    int res = 0;
    for (int i = 0, j = 0; i < n; i ++ )
    {
        s[a[i]] ++ ;
        while (s[a[i]] > 1)
        {
            s[a[j]] -- ;
            j ++ ;
        }
        
        res = max(res, i - j + 1);
    }
    
    cout << res << endl;
    
    return 0;
}

3. 离散化

特点：值域大但稀疏
可能有重复元素，需要去重;要求快速算出离散化后的值；要求保序
原来数组是[1,3,100,2000,50000]，要映射成[0,1,2,3,4]

	vector<int> alls; // 存储所有待离散化的值
	sort(alls.begin(), alls.end()); // 将所有值排序
	alls.erase(unique(alls.begin(), alls.end()), alls.end());	// 去掉重复元素
	
	// 二分求出x对应的离散化的值
	int find(int x) //找到第一个大于等于x的位置
	{
		int l = 0, r = alls.size() - 1;
		while (l < r)
		{
			int mid = l + r >> 1;
			if (alls[mid] >= x) r = mid;
			else l = mid + 1;
		}
		return r + 1; //映射到1,2,3,...
	}

例子：
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 300010;

int n, m;
int a[N], s[N];

vector<int> alls;
vector<PII> add, query;

int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++ )
    {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        
        alls.push_back(x);
    }
    
    for (int i = 0; i < m; i ++ )
    {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        
        alls.push_back(l);
        alls.push_back(r);
    }
    
    // 去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    
    // 处理插入
    for (auto item : add)
    {
        int x = find(item.first);
        a[x] += item.second;
    }
    
    // 预处理前缀和
    for (int i = 1; i <= alls.size(); i ++ ) s[i] = s[i - 1] + a[i];
    
    // 处理询问
    for (auto item : query)
    {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
    
    return 0;
}




4. 区间合并
包含关系,交集关系,没有关系
	
	// 将所有存在交集的区间合并
	void merge(vector<PII> &segs)
	{
		vector<PII> res;

		sort(segs.begin(), segs.end());

		int st = -2e9, ed = -2e9;
		for (auto seg : segs)
			if (ed < seg.first)
			{
				if (st != -2e9) res.push_back({st, ed});
				st = seg.first, ed = seg.second;
			}
			else ed = max(ed, seg.second);

		if (st != -2e9) res.push_back({st, ed});

		segs = res;
	}