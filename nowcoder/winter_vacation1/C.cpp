#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e5 + 5;
const i64 MOD = 998244353;
i64 a[N], b[N];

void solve() {
    i64 n = 0, m = 0, q = 0, t = 0, ans = 0, cnt = 0;
    scanf("%lld%lld%lld", &n, &q, &t); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", a + i);
	}
    sort(a, a + n);
    for (i64 i = 0; i < n; i++) {
        a[i] += a[i - 1];
    }

    for (i64 i = 0; i < q; i++) {
        scanf("%lld", &m);
        m /= t;
        printf("%lld\n", (n - 1 - m >= 0 ?  a[n - 1 - m] : 0ll) + t);
    }
	
	printf("%lld\n", ans);
}

int main() {
	i64 _ = 1;
	// scanf("%lld", &_); getchar();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
