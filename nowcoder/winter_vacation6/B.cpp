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
    i64 n = 0, m = 0, ans = 0, cnt = 0, loc_a, loc_b, mini = LLONG_MAX;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", a + i);
	}
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", b + i);
	}

	sort(a, a + n);

	for (i64 i = 0; i < n; i++) {
		i64 t = static_cast<i64>(lower_bound(a, a + n, b[i]) - a);
		if (t != n && mini > abs(a[t] - b[i])) {
			mini = abs(a[t] - b[i]);
			loc_a = t;
			loc_b = i;
		}
		if (t != 0 && mini > abs(a[t - 1] - b[i])) {
			mini = abs(a[t - 1] - b[i]);
			loc_a = t - 1;
			loc_b = i;
		}
	}
	
	if (loc_b != loc_a) {
		i64 t = a[loc_a];
		a[loc_a] = a[loc_b];
		a[loc_b] = t;
	}

	for (i64 i = 0; i < n; i++) {
		printf("%lld ", a[i]);
	}
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
