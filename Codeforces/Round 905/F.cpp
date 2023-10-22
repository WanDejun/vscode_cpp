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
i64 a[N];
bool vis_p[N], vis_n[N];
set<i64> S;

void solve() {
    i64 n, m, t, ans = 0, cnt = 0;
    memset(vis_p, 0, sizeof vis_p); memset(vis_n, 0, sizeof vis_n); S.clear();
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", a + i);
        if (!S.count(a[i])) vis_p[i] = 1;
        S.insert(a[i]);
	}
    S.clear();
    for (i64 i = n - 1; i >= 0; i--) {
        if (!S.count(a[i])) vis_n[i] = 1;
        S.insert(a[i]);
    }
    for (i64 i = 0; i < n ;i++) {
        cnt += vis_p[i];
        ans += vis_n[i] * cnt;
    }
	
	printf("%lld\n", ans);
}

int main() {
	i64 _ = 1;
	scanf("%lld", &_); getchar();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
