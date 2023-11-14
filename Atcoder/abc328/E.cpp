#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e2 + 5;
const i64 MOD = 998244353;
bool flags[N];
i64 n, m, mini, k, a[N][3];
i64 tree[N];

void init() {
	for (i64 i = 1; i <= n; i++) {
		tree[i] = i;
	}
}
int find(i64 x) {
	if (x == tree[x]) return x;
	tree[x] = find(tree[x]);
	return tree[x];
}
void merge(i64 u, i64 v) {
	tree[find(u)] = find(v);
}

void cal() {
	i64 ans = 0;
	init();
	for (i64 i = 0; i < m; i++) {
		if (flags[i]) {
			(ans += a[i][2]) %= k;
			merge(a[i][0], a[i][1]);
		}
	}
	for (i64 i = 2; i <= n; i++) if (find(i) != find(1)) return;
	mini = min(ans, mini);
}

void dfs(i64 deepth, i64 pre) {
	deepth++;
	for (i64 i = pre + 1; i <= m - n + deepth; i++) {
		flags[i] = 1;
		if (deepth < n - 1) {dfs(deepth, i);}
		else cal();
		flags[i] = 0;
	}
}

void solve() {
	mini = LLONG_MAX;
    scanf("%lld%lld%lld", &n, &m, &k); getchar();
	for (i64 i = 0; i < m; i++) {
		scanf("%lld%lld%lld", &(a[i][0]), &(a[i][1]), &(a[i][2]));
	}
	
	dfs(0, -1);
	printf("%lld\n", mini);
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
