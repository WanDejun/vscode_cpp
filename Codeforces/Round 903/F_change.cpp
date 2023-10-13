#include <bits/stdc++.h> //xi为i到其他顶点的总距离，求最小的xi的

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e3 + 5;
const i64 MOD = 998244353;
struct Treenode {
    i64 fa;
    vector<i64> child;
} Tree[N];
bool tag[N];
i64 cnt[N], sum[N];

void top_down(i64 u) {
    for (i64 v : Tree[u].child) if (v != Tree[u].fa) {
        Tree[v].fa = u;
        top_down(v);
    }
}
void botton_up(i64 u) {
    cnt[u] = tag[u];
    for (i64 v : Tree[u].child) if (v != Tree[u].fa) {
        botton_up(v);
        cnt[u] += cnt[v];
        sum[u] += sum[v] + cnt[v];
    }
}
void cal(i64 v) {
    i64 u = Tree[v].fa;
    i64 c = cnt[u] - cnt[v], s = sum[u] - (sum[v] + cnt[v]);
    sum[v] += (c + s);
    cnt[v] += c;
    for (i64 t : Tree[v].child) if (t != Tree[v].fa) {
        cal(t);
    }
}

void solve() {
    i64 n, k, t, ans = LLONG_MAX, u, v;
    Tree[0].fa = -1;
    scanf("%lld%lld", &n, &k); getchar();
    for (i64 i = 0; i < n; i++) {
        Tree[i].child.resize(0);
        cnt[i] = sum[i] = tag[i] = 0;
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
    for (i64 v : Tree[0].child) {
        cal(v);
    }
    for (i64 i = 0; i < n; i++) {
        ans = min(ans, sum[i]);
    }
	printf("%lld\n", ans);
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
