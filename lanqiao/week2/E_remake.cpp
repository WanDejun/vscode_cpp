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
i64 deepth[N], maxlen;
void dfs(i64 u, i64 fa) {
    i64 m1 = 0, m2 = 0;
    for (PII& v : G[u]) if (v[0] != fa) {
        dfs(v[0], u);
        if (deepth[v[0]] + v[1] >= m1) {
            m2 = m1; m1 = deepth[v[0]] + v[1];
        }
        else if (deepth[v[0]] + v[1] > m2) m2 = deepth[v[0]] + v[1];
    }
    maxlen = max(maxlen, m1 + m2);
    deepth[u] = m1;
}
void solve() {
    i64 n, m, t, u, v, w, ans = 0;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n - 1; i++) {
		scanf("%lld%lld%lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
        ans += w * 2;
	}
    dfs(1, 0);
    ans -= maxlen;
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
