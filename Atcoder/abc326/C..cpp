#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 3e5 + 5;
const i64 MOD = 998244353;
i64 a[N], b[N];

void solve() {
    i64 n, m, t, ans = 0;
    scanf("%lld%lld", &n, &m); getchar();
    m--;
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", a + i);
	}
    sort(a, a + n);
	for (i64 i = 0, j = 0; j < n; i++) {
        while (j < n && a[j] - a[i] <= m) {
            j++;
        }
        ans = max(ans, j - i);
    }
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