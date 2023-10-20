// https://atcoder.jp/contests/abc058/tasks/arc071_b
#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e5 + 5;
const i64 MOD = 1e9 + 7;

void solve() {
    i64 n, m, t, ans = 0, pre, nxt, sx = 0, sy = 0, c = 0;
    scanf("%lld%lld", &n, &m); getchar();
    scanf("%lld", &pre);
	for (i64 i = 1; i < n; i++) {
		scanf("%lld", &nxt);
        (c += i * (nxt - pre)) %= MOD;
        (sx += c) %= MOD;
        pre = nxt;
	}
    c = 0; scanf("%lld", &pre);
    for (i64 i = 1; i < m; i++) {
		scanf("%lld", &nxt);
        (c += i * (nxt - pre)) %= MOD;
        (sy += c) %= MOD;
        pre = nxt;
	}
	
	printf("%lld\n", (sx * sy) % MOD);
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
