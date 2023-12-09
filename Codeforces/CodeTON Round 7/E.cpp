#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e6 + 5;
const i64 MOD = 998244353;
i64 a[N], b[N], c[N], n;

int cnt(i64 st, i64 ed) {
    if (st == ed) return 0;
    if (st < ed) return b[ed - 1] - b[st];
    return n - (b[st] - b[ed - 1]);
}

void solve() {
    i64 m = 0, t = 0, ans = 0;
    scanf("%lld", &n); getchar();
	for (i64 i = 1; i <= n; i++) {
		scanf("%lld", a + i);
	}
    for (i64 i = 0; i <= n; i++) {
        b[i] = c[i] = 0;
    }
    for (i64 i = 1; i <= n; i++) {
        if (a[i] > i) b[a[i]]++;
        else b[i]++;
    }
    for (i64 i = 1; i <= n; i++) {
        b[i] += b[i - 1];
    }
    printf("#37  ");
    for (i64 i = 1; i <= n; i++) {
        printf("%lld ", b[i]);
    }
    putchar('\n');
	for (i64 i = 1; i <= n; i++) {
        c[a[i]] = a[i] - i;
        if (c[a[i]] < 0) c[a[i]] += n;
        c[a[i]] -= cnt(i, a[i]);
    }

	for (i64 i = 1; i <= n; i++) {
        printf("%lld ", c[a[i]]);
    }
    putchar('\n');
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
