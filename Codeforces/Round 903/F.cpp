#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e5 + 5;
const i64 MOD = 998244353;
struct Treenode {
    i64 fa;
    vector<i64> child;
} Tree[N];
bool tag[N];
PII dis[N];
i64 updis[N]; // down & up

void top_down(i64 u) {
    for (i64 v : Tree[u].child) if (v != Tree[u].fa) {
        Tree[v].fa = u;
        top_down(v);
    }
}
void botton_up(i64 u) {
    for (i64 v : Tree[u].child) if (v != Tree[u].fa) {
        botton_up(v);
        i64 d = dis[v][0] ? dis[v][0] + 1 : tag[v];
        if (dis[u][0] < d) {
            dis[u][1] = dis[u][0];
            dis[u][0] = d;
        }
        else if (dis[u][1] < d) {
            dis[u][1] = d;
        }
    }
}
void cal(i64 v) {
    i64 u = Tree[v].fa, d = dis[v][0] ? dis[v][0] + 1 : tag[v];
    updis[v] = dis[u][0] + 1;
    if (d == dis[u][0]) updis[v] = dis[u][1] + 1;
    if (updis[v] == 1) updis[v] = tag[u];
    updis[v] = max(updis[v], (updis[u] ? updis[u] : -1) + 1);
    for (i64 t : Tree[v].child) if (t != u) {
        cal(t);
    }
}

void solve() {
    i64 n, k, t, mini = LLONG_MAX, u, v;
    Tree[0].fa = -1;
    scanf("%lld%lld", &n, &k); getchar();
    for (i64 i = 0; i < n; i++) {
        Tree[i].child.resize(0);
        dis[i][0] = dis[i][1] = updis[i] = tag[i] = 0;
    }
    
    for (i64 i = 0; i < k; i++) {
        scanf("%lld", &u); u--;
        tag[u] = 1;
    }
    for (i64 i = 0; i < n - 1; i++) {
        scanf("%lld%lld", &u, &v);
        u--; v--;
        Tree[u].child.push_back(v);
        Tree[v].child.push_back(u);
    }
    top_down(0);
    botton_up(0);
    updis[0] = -1;
    for (i64 v : Tree[0].child) {
        cal(v);
    }
    for (i64 i = 0; i < n; i++) {
        mini = min(mini, max(updis[i], dis[i][0]));
    }
	printf("%lld\n", mini);
}

int main() {
	i64 _;
	scanf("%lld", &_); getchar();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
