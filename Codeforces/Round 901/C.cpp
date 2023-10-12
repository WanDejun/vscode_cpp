#include <bits/stdc++.h>

#define PII pair<int, int>
#define MII multimap<int, int>
#define MSI multimap<string, int>
#define SI multiset<int>
#define VI vector<int>
#define i64 long long
#define i32 long

using namespace std;

const i64 N = 1e5;
const i64 MOD = 998244353;
//bool a[N][N], b[N], c[N];

void solve() {
    i64 n, m, t, ans = 0, cnt;
    scanf("%lld%lld", &n, &m); getchar();
	n %= m;
	if (!n) {printf("0\n"); return;}
	cnt = m / __gcd(m, n);
	//cout << (cnt & (-cnt)) << " ";
    if (cnt ^ (cnt & (-cnt))) { printf("-1\n"); return; }
    t = cnt * n / m;
	while (t) {
		if (t & 1) ans += m;
		t >>= 1;
	}
	ans -= n;
	printf("%lld\n", ans);
}

int main() {
	i64 _;
	scanf("%lld", &_); getchar();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
