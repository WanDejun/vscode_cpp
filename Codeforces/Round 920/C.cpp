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
i64 arr[N];

void solve() {
    i64 n = 0,f, a, b,  m = 0, pre = 0, nxt = 0, cnt = 0;
    scanf("%lld%lld%lld%lld", &n, &f, &a, &b); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", &nxt);
        cnt += min((nxt - pre) * a, b);
        pre = nxt;
	}
	printf("%s\n", cnt >= f ? "NO" : "YES");
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
