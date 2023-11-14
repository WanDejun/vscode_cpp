#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 3e5 + 5;
const i64 MOD = 998244353;
char a[N];
i64 b[N];

void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0, l, r;
    scanf("%lld%lld", &n, &m); getchar();
	for (i64 i = 1; i <= n; i++) {
		scanf("%c", a + i);
	}
	for (i64 i = 1; i < n; i++) {
        b[i] = b[i - 1];
        if (a[i] == a[i + 1]) b[i]++;
    }
    for (i64 i = 0; i < m; i++) {
        scanf("%lld%lld", &l, &r);
        printf("%lld\n", b[r - 1] - b[l - 1]);
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
