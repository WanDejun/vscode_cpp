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
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0;
    i64 maxi1 = -1e6, maxi2 = -1e6, mini1 = INT_MAX, mini2 = INT_MAX;
	for (i64 i = 0; i < 4; i++) {
		scanf("%lld%lld", &n, &m);
        maxi1 = max(maxi1, n);
        mini1 = min(mini1, n);
        maxi2 = max(maxi2, m);
        mini2 = min(mini2, m);
	}
	
	printf("%lld\n", (maxi1 - mini1) * (maxi2 - mini2));
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
