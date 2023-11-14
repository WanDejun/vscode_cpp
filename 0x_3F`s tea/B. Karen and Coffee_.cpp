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
    i64 n = 0, k = 0, q = 0, ans = 0, cnt = 0, l, r;
    scanf("%lld%lld%lld", &n, &k, &q); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld%lld", &l, &r);
        a[l] += 1;
        a[r + 1] -= 1;
	}
    for (i64 i = 1; i < N; i++) {
        a[i] += a[i - 1];
        b[i] = b[i - 1] + (a[i] >= k ? 1 : 0);
    }
    for (i64 i = 0; i < q; i++) {
        scanf("%lld%lld", &l, &r);
        printf("%lld\n", b[r] - b[l - 1]);
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
