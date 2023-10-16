#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> PII; // 第一个存距离，第二个存点的编号
const int N = 1000010;
int n, m;
int h[N], w[N], e[N], ne[N], idx;                       // 使用邻接表存储稀疏图
int dist[N];
bool st[N];
void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0; 
    priority_queue<PII, vector<PII>, greater<PII>> heap; // 定义小根堆
    heap.push({0, 1});                              // 先将最短的距离添加到小根堆中
    
    while (heap.size()) {
        auto t = heap.top();                        // 取出当前已经确定的最短距离的点
        heap.pop();
        int ver = t.second;
        if (st[ver]) continue; // 如果已经被标记过，说明当前的点的边是比较长的重边，直接跳过。
        st[ver] = true;
                                                    // 使用当前距离最短的点来更新其出边
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i]; // j 为 ver 出边所到达的点
            if (dist[j] > dist[ver] + w[i]) { 
                dist[j] = dist[ver] + w[i];     // 将下一个距离源点最近的点添加到小根堆中
                heap.push({dist[j], j});
            }
        }
    }
    
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}
int main() {
    scanf("%d%d", &n, &m);
    
    memset(h, -1, sizeof h); // 将每一条边的头结点初始化为 -1
    // 输入 m 条边
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    cout << dijkstra() << endl;
    return 0;
}