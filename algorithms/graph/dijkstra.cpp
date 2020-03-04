// dijkstra (朴素版 - O(n²))
#include <cstring>
using namespace std;

const int N = 510;
int g[N][N]; // 若是稠密图
bool st[N];  // 记录哪个点已确定好.
int d[N];    // d[i]表示 1 -> i 的距离

void dijkstra(int n)
{   
    memset(d, 0x3f, sizeof d);
    d[1] = 0;  // d[起点] = 0, 其余初始化 ∞

    for (int i = 1; i <= n; i ++ ) // n个点
    {
        int t = -1;
        for (int j = 1; j <= n; j ++ )
            if(!st[j] && (t == -1 || d[t] > d[t]))
                t = j;

        for (int j = 1; j <= n; j ++ )
            d[j] = min(d[j], d[t] + g[t][j]);
    }

    // 具体题目逻辑...
}

// 测试&&调用
int main(){
    int n, m;      
    cin >> n >> m;  // 输入n个点m条边

    // 若存在重边和自环.
    memset(g, 0x3f, sizeof g);
    while(m --)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g[a][b] = min(g[a][b] , w); // 自环不受影响, 重边就只保留最短的那条边即可.
    }

    dijkstra(n);

    return 0;
}