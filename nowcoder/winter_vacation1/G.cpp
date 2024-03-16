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
PII a[N];

void solve() {
    i64 n = 0, m = 0, t1, t2, ans = 0, cnt = 0;
    map<i64, i64> M;
    scanf("%lld%lld", &n, &m); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld%lld", &t1, &t2);
        M[t1] += t2;
	}
    n = M.size();
    i64 i = 0;
    for (auto& t : M) {
        a[i][0] = t.first;
        a[i][1] = t.second;
        i++;
    }
    ans = m;
    if (a[0][0] - a[0][1] <= m) ans = m + a[0][1];
    sort(a, a + n, [](array<i64, 2>& x, array<i64, 2>& y) {return x[0] < y[0];});
    for (i64 i = 1; i < n; i++) {
        a[i][1] += a[i - 1][1];
        if (a[i][0] - a[i][1] <= m) ans = m + a[i][1];
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
