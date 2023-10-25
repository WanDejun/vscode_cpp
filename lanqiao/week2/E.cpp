#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e3 + 5;
const i64 MOD = 998244353;
vector<PII> G[N];
i64 cnt[N], sum_back[N], sum_left[N], ans;

void topo(i64 u, i64 f) {
    cnt[u] = 1;
    i64 t = 0;
    for (PII& v : G[u]) if (v[0] != f) {
        topo(v[0], u);
        cnt[u] += cnt[v[0]];
        sum_back[u] += (sum_back[v[0]] + 2 * v[1]);
        t = max(t, v[1] + sum_back[v[0]] - sum_left[v[0]]);
    }
    sum_left[u] = sum_back[u] - t;
}
void cal(i64 u, i64 f) {
    i64 t = 0;
    for (PII& v : G[u]) if (v[0] != f) {
        sum_back[v[0]] += (sum_back[u] + (cnt[u] - 2 * cnt[v[0]]) * v[1] * 2);
        t = max(v[1] + sum_back[u] - sum_left[u], sum_back[v[0]] - sum_left[v[0]]);
        sum_left[v[0]] -= t;
        ans = min(ans, sum_left[v[0]]);
        cal(v[0], u);
    }
}
void solve() {
    i64 n, m, t, u, v, w;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n - 1; i++) {
		scanf("%lld%lld%lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
	}
	topo(1, 0);
    ans = sum_left[1];
    cal(1, 0);
	printf("%lld\n", ans);
}

int main() {
	i64 _ = 1;
	//scanf("%lld", &_); getchar();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
