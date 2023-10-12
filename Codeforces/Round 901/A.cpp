#include <bits/stdc++.h>

#define PII pair<int, int>
#define MII multimap<int, int>
#define MSI multimap<string, int>
#define SI multiset<int>
#define VI vector<int>
#define i64 long long

using namespace std;

const i64 N = 1e0;
const i64 MOD = 998244353;
i64 a[N][N], b[N], c[N];

void solve() {
    i64 n, m, k, t, ma = LLONG_MAX, mb = LLONG_MAX, Ma = 0, Mb = 0, sa = 0, sb = 0;
    scanf("%lld%lld%lld", &n, &m, &k); getchar();
    for (i64 i = 0; i < n; i++) {
        scanf("%lld", &t);
        ma = min(t, ma);
        Ma = max(t, Ma);
        sa += t;
    }
    for (i64 i = 0; i < m; i++) {
        scanf("%lld", &t);
        mb = min(t, mb);
        Mb = max(t, Mb);
        sb += t;
    }
    if (k % 2) {
        t = sa - ma + max(ma, Mb);
    }
    else {
        t = sa - ma - Ma + min(ma, mb) + min(Ma, Mb);
    }
	printf("%lld\n", t);
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
